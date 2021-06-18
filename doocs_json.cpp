#include <iostream>
#include <nlohmann/json.hpp>
#include <eq_data.h>
#include <iterator>
#include <vector>

#define PROJECT_NAME "doocs-json"

const std::string TYPE_KEY = "type";
const std::string TYPE_ID_KEY = "type_id";
const std::string VALUE_KEY = "value";

using namespace nlohmann;

json eq_data_to_json(EqData eqData) {
    json obj;
    switch (eqData.type()) {
        case DATA_NULL:
            break;
        case DATA_BOOL:
            //booleans are encoded as ints, see https://ttfinfo.desy.de/DOOCSWiki/Wiki.jsp?page=C%2B%2B%20Client%20Interface
            obj[VALUE_KEY] = eqData.get_int();
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
            std::vector<bool> boolean_vector;
            for (int *pointer = eqData.get_int_array(); *pointer != 0; ++pointer) {
                boolean_vector.push_back((bool) *pointer);
            }
            obj[VALUE_KEY] = boolean_vector;
            break;
        }
        case DATA_A_SHORT: {
            std::vector<short> short_vector;
            for (short *pointer = eqData.get_short_array(); *pointer != 0; ++pointer) {
                short_vector.push_back(*pointer);
            }
            obj[VALUE_KEY] = short_vector;
            break;
        }
        case DATA_A_USHORT: {
            std::vector<ushort> ushort_vector;
            for (ushort *pointer = eqData.get_ushort_array(); *pointer != 0; ++pointer) {
                ushort_vector.push_back(*pointer);
            }
            obj[VALUE_KEY] = ushort_vector;
            break;
        }
        case DATA_A_INT: {
            std::vector<int> int_vector;
            for (int *pointer = eqData.get_int_array(); *pointer != 0; ++pointer) {
                int_vector.push_back(*pointer);
            }
            obj[VALUE_KEY] = int_vector;
            break;
        }
        case DATA_A_UINT: {
            std::vector<uint> uint_vector;
            for (uint *pointer = eqData.get_uint_array(); *pointer != 0; ++pointer) {
                uint_vector.push_back(*pointer);
            }
            obj[VALUE_KEY] = uint_vector;
            break;
        }
        case DATA_A_LONG: {
            std::vector<long long> long_vector;
            for (long long *pointer = eqData.get_long_array(); *pointer != 0; ++pointer) {
                long_vector.push_back(*pointer);
            }
            obj[VALUE_KEY] = long_vector;
            break;
        }
        case DATA_A_ULONG: {
            std::vector<unsigned long long> ulong_vector;
            for (unsigned long long *pointer = eqData.get_ulong_array(); *pointer != 0; ++pointer) {
                ulong_vector.push_back(*pointer);
            }
            obj[VALUE_KEY] = ulong_vector;
            break;
        }
        case DATA_A_FLOAT: {
            std::vector<float> float_vector;
            for (float *pointer = eqData.get_float_array(); *pointer != 0; ++pointer) {
                float_vector.push_back(*pointer);
            }
            obj[VALUE_KEY] = float_vector;
            break;
        }
        case DATA_A_DOUBLE: {
            std::vector<double> double_vector;
            for (auto pointer = eqData.get_double_array(); *pointer != 0; ++pointer) {
                double_vector.push_back(*pointer);
            }
            obj[VALUE_KEY] = double_vector;
            break;
        }
        case DATA_TEXT:
        case DATA_STRING:
        case DATA_STRING16: {
            obj[VALUE_KEY] = eqData.get_string();
            break;
        }
            /*
             * int i1_data
             * float f1_data
             * float f2_data
             * time_t tm
             * char str_data<>
             */
//        case DATA_USTR: {
//            obj[TYPE_KEY] = "Ustr";
//            USTR* ustr = eqData.get_ustr(0)
//            obj[VALUE_KEY + "i1"] = * ustr.i1_data;
//            obj[VALUE_KEY + "f1"] = ustr.f1_data;
//            obj[VALUE_KEY + "f2"] = ustr.f2_data;
//            obj[VALUE_KEY + "tm"] = ustr.tm;
//            obj[VALUE_KEY + "str"] = ustr.str_data;
//            break;
//        }
        default:
            obj[VALUE_KEY] = eqData.get_string();
            obj["message"] = "Not implemented converter";

    }
    obj[TYPE_ID_KEY] = eqData.type();
    obj[TYPE_KEY] = eqData.type_string();

    obj["event_id"] = eqData.get_event_id().to_int();
    obj["error"] = eqData.error();
    obj["time"] = eqData.time();
    return obj;
}

EqData *eq_data_from_json(json obj) {
    int value_type = obj[TYPE_ID_KEY];
    EqData *data = new EqData();
    switch (value_type) {
        case DATA_BOOL:
            data->set(obj[VALUE_KEY].get<bool>());
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
            data->set(obj[VALUE_KEY].get<double>());
            break;
        }
        case DATA_A_SHORT: {
            auto vector = obj[VALUE_KEY].get<std::vector<short>>();
            for (auto i = 0; i < vector.size(); i++) {
                data->set(vector[i], i);
            }
            break;
        }
        case DATA_A_USHORT: {
            auto vector = obj[VALUE_KEY].get<std::vector<ushort>>();
            for (auto i = 0; i < vector.size(); i++) {
                data->set(vector[i], i);
            }
            break;
        }
        case DATA_A_INT: {
            auto vector = obj[VALUE_KEY].get<std::vector<int>>();
            for (auto i = 0; i < vector.size(); i++) {
                data->set(vector[i], i);
            }
            break;
        }
        case DATA_A_UINT: {
            auto vector = obj[VALUE_KEY].get<std::vector<uint>>();
            for (auto i = 0; i < vector.size(); i++) {
                data->set(vector[i], i);
            }
            break;
        }
        case DATA_A_LONG: {
            auto vector = obj[VALUE_KEY].get<std::vector<long long>>();
            for (auto i = 0; i < vector.size(); i++) {
                data->set(vector[i], i);
            }
            break;
        }
        case DATA_A_ULONG: {
            auto vector = obj[VALUE_KEY].get<std::vector<unsigned long long>>();
            for (auto i = 0; i < vector.size(); i++) {
                data->set(vector[i], i);
            }
            break;
        }
        case DATA_A_FLOAT: {
            auto vector = obj[VALUE_KEY].get<std::vector<float>>();
            for (auto i = 0; i < vector.size(); i++) {
                data->set(vector[i], i);
            }
            break;
        }
        case DATA_A_DOUBLE: {
            auto vector = obj[VALUE_KEY].get<std::vector<double>>();
            for (auto i = 0; i < vector.size(); i++) {
                data->set(vector[i], i);
            }
            break;
        }
        case DATA_TEXT:
        case DATA_STRING:
        case DATA_STRING16: {
            data->set(obj[VALUE_KEY].get<std::string>());
            break;
        }
        default: {
            data->set(obj[VALUE_KEY].get<std::string>());
        }
    }
    data->set_type(value_type);
    return data;
}

//int main(int argc, char **argv) {
//    if (argc != 1) {
//        std::cout << argv[0] << "takes no arguments.\n";
//        return 1;
//    }
//    std::cout << "This is project " << PROJECT_NAME << ".\n";
//    return 0;
//}
