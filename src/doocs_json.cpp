#include "doocs_json.h"

#include <eq_adr.h>
#include <eq_client.h>

#include <iostream>
#include <vector>

constexpr const char *TYPE_KEY = "type";
constexpr const char *TYPE_ID_KEY = "type_id";
constexpr const char *VALUE_KEY = "value";
constexpr const char *EVENT_ID_KEY = "event_id";
constexpr const char *ERROR_KEY = "error";
constexpr const char *TIME_KEY = "time";
constexpr const char *COMMENT_KEY = "message";

using namespace nlohmann;

json eq_data_to_json(const EqData &eqData) {
  json obj;
  switch (eqData.type()) {
    case DATA_NULL:
      break;
    case DATA_BOOL:
      // booleans are encoded as ints, see
      // https://ttfinfo.desy.de/DOOCSWiki/Wiki.jsp?page=C%2B%2B%20Client%20Interface
      obj[VALUE_KEY] = bool(eqData.get_int());
      break;
    case DATA_SHORT:
      obj[VALUE_KEY] = eqData.get_short();
      break;
    case DATA_USHORT:
      obj[VALUE_KEY] = eqData.get_ushort();
      break;
    case DATA_INT:
      obj[VALUE_KEY] = eqData.get_int();
      break;
    case DATA_UINT:
      obj[VALUE_KEY] = eqData.get_uint();
      break;
    case DATA_LONG:
      obj[VALUE_KEY] = eqData.get_long();
      break;
    case DATA_ULONG:
      obj[VALUE_KEY] = eqData.get_ulong();
      break;
    case DATA_FLOAT:
      obj[VALUE_KEY] = eqData.get_float();
      break;
    case DATA_DOUBLE:
      obj[VALUE_KEY] = eqData.get_double();
      break;
    case DATA_A_BOOL: {
      int len = eqData.array_length();
      std::vector<bool> boolean_vector(len);
      for (int i = 0; i < len; i++) {
        boolean_vector[i] = eqData.get_int(i);
      }
      obj[VALUE_KEY] = boolean_vector;
      break;
    }
    case DATA_A_SHORT: {
      short* pointer = eqData.get_short_array();
      int len = eqData.array_length();
      std::vector<short> short_vector(pointer, pointer + len);
      obj[VALUE_KEY] = short_vector;
      break;
    }
    case DATA_A_USHORT: {
      ushort* pointer = eqData.get_ushort_array();
      int len = eqData.array_length();
      std::vector<unsigned short> ushort_vector(pointer, pointer + len);
      obj[VALUE_KEY] = ushort_vector;
      break;
    }
    case DATA_A_INT: {
      int* pointer = eqData.get_int_array();
      int len = eqData.array_length();
      std::vector<int> int_vector(pointer, pointer + len);
      obj[VALUE_KEY] = int_vector;
      break;
    }
    case DATA_A_UINT: {
      uint* pointer = eqData.get_uint_array();
      int len = eqData.array_length();
      std::vector<uint> uint_vector(pointer, pointer + len);
      obj[VALUE_KEY] = uint_vector;
      break;
    }
    case DATA_A_LONG: {
      long long* pointer = eqData.get_long_array();
      int len = eqData.array_length();
      std::vector<long long> long_vector(pointer, pointer + len);
      obj[VALUE_KEY] = long_vector;
      break;
    }
    case DATA_A_ULONG: {
      unsigned long long* pointer = eqData.get_ulong_array();
      int len = eqData.array_length();
      std::vector<unsigned long long> ulong_vector(pointer, pointer + len);
      obj[VALUE_KEY] = ulong_vector;
      break;
    }
    case DATA_A_FLOAT: {
      float* pointer = eqData.get_float_array();
      int len = eqData.array_length();
      std::vector<float> float_vector(pointer, pointer + len);
      obj[VALUE_KEY] = float_vector;
      break;
    }
    case DATA_A_DOUBLE: {
      double* pointer = eqData.get_double_array();
      int len = eqData.array_length();
      std::vector<double> double_vector(pointer, pointer + len);
      obj[VALUE_KEY] = double_vector;
      break;
    }
    case DATA_TEXT:
    case DATA_STRING: {
      obj[VALUE_KEY] = eqData.get_string();
      break;
    }
    case DATA_A_USTR: {
      int len = eqData.array_length();
      std::vector<json> ustr_vector(len);
      for (int i = 0; i < len; i++) {
        USTR *ustr = eqData.get_ustr(i);
        ustr_vector[i]["i1"] = ustr->i1_data;
        ustr_vector[i]["f1"] = ustr->f1_data;
        ustr_vector[i]["f2"] = ustr->f2_data;
        ustr_vector[i]["tm"] = ustr->tm;
        ustr_vector[i]["data"] = std::string(
            ustr->str_data.str_data_val,
            ustr->str_data.str_data_len - 1
        );
      }
      obj[VALUE_KEY] = ustr_vector;
      break;
    }
    default:
      obj[VALUE_KEY] = eqData.get_string();
      obj[COMMENT_KEY] = "Not implemented converter";
  }
  obj[TYPE_ID_KEY] = eqData.type();
  obj[TYPE_KEY] = eqData.type_string();

  obj[EVENT_ID_KEY] = eqData.get_event_id().to_int();
  obj[ERROR_KEY] = eqData.error();
  obj[TIME_KEY] = eqData.time();
  return obj;
}

std::unique_ptr<EqData> eq_data_from_json(const json &obj) {
  auto data = std::make_unique<EqData>();
  if (obj.empty()) {
    return data;
  }
  int value_type = obj[TYPE_ID_KEY];
  data->set_type(value_type);
  switch (value_type) {
    case DATA_BOOL:
      data->set_bool(obj[VALUE_KEY].get<bool>());
      break;
    case DATA_SHORT:
      data->set(obj[VALUE_KEY].get<short>());
      break;
    case DATA_USHORT:
      data->set(obj[VALUE_KEY].get<ushort>());
      break;
    case DATA_INT:
      data->set(obj[VALUE_KEY].get<int>());
      break;
    case DATA_UINT:
      data->set(obj[VALUE_KEY].get<uint>());
      break;
    case DATA_LONG:
      data->set(obj[VALUE_KEY].get<long long>());
      break;
    case DATA_ULONG:
      data->set(obj[VALUE_KEY].get<unsigned long long>());
      break;
    case DATA_FLOAT:
      data->set(obj[VALUE_KEY].get<float>());
      break;
    case DATA_DOUBLE:
      data->set(obj[VALUE_KEY].get<double>());
      break;
    case DATA_A_BOOL: {
      auto vector = obj[VALUE_KEY].get<std::vector<bool>>();
      int len = int(vector.size());
      for (int i = 0; i < len; i++) {
        data->set(vector[i], i);
      }
      data->length(len);
      break;
    }
    case DATA_A_SHORT: {
      auto vector = obj[VALUE_KEY].get<std::vector<short>>();
      int len = int(vector.size());
      for (int i = 0; i < len; i++) {
        data->set(vector[i], i);
      }
      data->length(len);
      break;
    }
    case DATA_A_USHORT: {
      auto vector = obj[VALUE_KEY].get<std::vector<ushort>>();
      int len = int(vector.size());
      for (int i = 0; i < len; i++) {
        data->set(vector[i], i);
      }
      data->length(len);
      break;
    }
    case DATA_A_INT: {
      auto vector = obj[VALUE_KEY].get<std::vector<int>>();
      int len = int(vector.size());
      for (int i = 0; i < len; i++) {
        data->set(vector[i], i);
      }
      data->length(len);
      break;
    }
    case DATA_A_UINT: {
      auto vector = obj[VALUE_KEY].get<std::vector<uint>>();
      int len = int(vector.size());
      for (int i = 0; i < len; i++) {
        data->set(vector[i], i);
      }
      data->length(len);
      break;
    }
    case DATA_A_LONG: {
      auto vector = obj[VALUE_KEY].get<std::vector<long long>>();
      int len = int(vector.size());
      for (int i = 0; i < len; i++) {
        data->set(vector[i], i);
      }
      data->length(len);
      break;
    }
    case DATA_A_ULONG: {
      auto vector = obj[VALUE_KEY].get<std::vector<unsigned long long>>();
      int len = int(vector.size());
      for (int i = 0; i < len; i++) {
        data->set(vector[i], i);
      }
      data->length(len);
      break;
    }
    case DATA_A_FLOAT: {
      auto vector = obj[VALUE_KEY].get<std::vector<float>>();
      int len = int(vector.size());
      for (int i = 0; i < len; i++) {
        data->set(vector[i], i);
      }
      data->length(len);
      break;
    }
    case DATA_A_DOUBLE: {
      auto vector = obj[VALUE_KEY].get<std::vector<double>>();
      int len = int(vector.size());
      for (int i = 0; i < len; i++) {
        data->set(vector[i], i);
      }
      data->length(len);
      break;
    }
    case DATA_TEXT:
    case DATA_STRING: {
      data->set(obj[VALUE_KEY].get<std::string>());
      break;
    }
    case DATA_A_USTR: {
      auto vector = obj[VALUE_KEY].get<std::vector<json>>();
      int len = int(vector.size());
      for (int i = 0; i < len; i++) {
        USTR ustr;
        ustr.i1_data = vector[i]["i1"].get<int>();
        ustr.f1_data = vector[i]["f1"].get<float>();
        ustr.f2_data = vector[i]["f2"].get<float>();
        ustr.tm = vector[i]["tm"].get<time_t>();

        auto str = vector[i]["data"].get<std::string>();
        ustr.str_data.str_data_len = str.size() + 1;
        ustr.str_data.str_data_val = const_cast<char*>(str.c_str());
        data->set(ustr, i);
      }
      data->length(len);
      break;
    }
    default: {
      data->set(obj[VALUE_KEY].get<std::string>());
    }
  }

  if (obj.contains(TIME_KEY)) {
    data->time(obj[TIME_KEY].get<time_t>());
  }


  if (obj.contains(ERROR_KEY)) {
    data->error(obj[ERROR_KEY].get<int>());
  }

  if (obj.contains(EVENT_ID_KEY)) {
    data->set_event_id(doocs::EventId(obj[EVENT_ID_KEY].get<int64_t>()));
  }

  return data;
}

json list_names(const std::string &address) {
  EqCall eq;
  EqAdr ea(address);
  EqData dst;

  // Make the call
  int return_code = eq.names(&ea, &dst);

  if (return_code != 0) {
    std::cerr << "Names failed with code " << return_code << std::endl;
  }

  return eq_data_to_json(dst);
}

json get_property(const std::string &address, const json &data) {
  EqCall eq;
  EqAdr ea(address);
  auto src = eq_data_from_json(data);
  EqData dst;

  // Make the call
  int return_code = eq.get(&ea, src.get(), &dst);

  if (return_code != 0) {
    std::cerr << "Get failed with code " << return_code << std::endl;
  }

  return eq_data_to_json(dst);
}

json set_property(const std::string &address, const json &data) {
  EqCall eq;
  EqAdr ea(address);
  auto src = eq_data_from_json(data);
  EqData dst;

  // Make the call
  int return_code = eq.set(&ea, src.get(), &dst);

  if (return_code != 0) {
    std::cerr << "Set failed with code " << return_code;
  }

  return eq_data_to_json(dst);
}

/*
  "id":"string|number[optional, but desired]",
  "parentId": "string|number[optional]",
  "target":"string[optional]",
  "origin":"string[required]",
  "user":"object[optional]",
  "payload":"object[optional]"
*/

/**
 * Make a response to a magix message with DOOCS payload according to
 * https://github.com/waltz-controls/rfc/blob/master/5/readme.md
 *
 */
json respond_magix(json request, const std::string &endpoint_name) {
  json payload = request["payload"];
  auto address = payload["eq_address"].get<std::string>();
  auto action = payload["action"].get<std::string>();
  json data = payload["eq_data"];
  json responsePayload;
  if (action == "get") {
    responsePayload = get_property(address, data);
  } else if (action == "set") {
    responsePayload = set_property(address, data);
  } else {
    throw std::invalid_argument("Unhandled action");
  }
  json response;

  response["parentId"] = request["id"];
  response["target"] = request["origin"];
  response["origin"] = endpoint_name;
  response["payload"] = responsePayload;
  response["user"] = request["user"];
  return response;
}