#include "doocs_json_test.h"
#include "doocs_json.h"

#include <iostream>
#include <cfloat>

using namespace std;
using namespace nlohmann;

#define ASSERT_EQUALS(expected, actual)                      \
  if ((expected) != (actual)) {                              \
    cerr << (expected) << " != " << (actual)                 \
              << " in " << __func__                          \
              << "; line: " << __FILE__ << ":" << __LINE__   \
              << endl;                                       \
    return false;                                            \
  }

#define ASSERT_SET_SUCCESS(set_command)              \
auto set_result_ = (set_command);                    \
ASSERT_EQUALS(0, set_result_[ERROR_KEY]);            \
ASSERT_EQUALS(DATA_NULL, set_result_[TYPE_ID_KEY])

#define RUN_TEST(test) passed += (test); total++

constexpr const char *ERROR_KEY = "error";
constexpr const char *TYPE_ID_KEY = "type_id";
constexpr const char *VALUE_KEY = "value";

constexpr const char *STR_VALUE = "string value";

bool test_bool_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_BOOL, result[TYPE_ID_KEY]);
  ASSERT_EQUALS(false, result[VALUE_KEY]);
  return true;
}

bool test_bool_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_BOOL;
  obj[VALUE_KEY] = true;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQUALS(true, result[VALUE_KEY]);
  return true;
}

bool test_bool(string path) {
  path += "/PBOOL";
  return test_bool_get(path) && test_bool_set(path);
}

bool test_short_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_SHORT, result[TYPE_ID_KEY]);
  ASSERT_EQUALS(INT16_MAX, result[VALUE_KEY]);
  return true;
}

bool test_short_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_SHORT;
  obj[VALUE_KEY] = INT16_MIN;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQUALS(INT16_MIN, result[VALUE_KEY]);
  return true;
}

bool test_short(string path) {
  path += "/PSHORT";
  return test_short_get(path) && test_short_set(path);
}

bool test_ushort_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_USHORT, result[TYPE_ID_KEY]);
  ASSERT_EQUALS(UINT16_MAX, result[VALUE_KEY]);
  return true;
}

bool test_ushort_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_USHORT;
  obj[VALUE_KEY] = UINT16_WIDTH;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQUALS(UINT16_WIDTH, result[VALUE_KEY]);
  return true;
}

bool test_ushort(string path) {
  path += "/PUSHORT";
  return test_ushort_get(path) && test_ushort_set(path);
}

bool test_int_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_INT, result[TYPE_ID_KEY]);
  ASSERT_EQUALS(INT32_MAX, result[VALUE_KEY]);
  return true;
}

bool test_int_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_INT;
  obj[VALUE_KEY] = INT32_MIN;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQUALS(INT32_MIN, result[VALUE_KEY]);
  return true;
}

bool test_int(string path) {
  path += "/PINT";
  return test_int_get(path) && test_int_set(path);
}

bool test_uint_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_UINT, result[TYPE_ID_KEY]);
  ASSERT_EQUALS(UINT32_MAX, result[VALUE_KEY]);
  return true;
}

bool test_uint_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_UINT;
  obj[VALUE_KEY] = UINT32_WIDTH;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQUALS(UINT32_WIDTH, result[VALUE_KEY]);
  return true;
}

bool test_uint(string path) {
  path += "/PUINT";
  return test_uint_get(path) && test_uint_set(path);
}

bool test_long_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_LONG, result[TYPE_ID_KEY]);
  ASSERT_EQUALS(INT64_MAX, result[VALUE_KEY]);
  return true;
}

bool test_long_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_LONG;
  obj[VALUE_KEY] = INT64_MIN;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQUALS(INT64_MIN, result[VALUE_KEY]);
  return true;
}

bool test_long(string path) {
  path += "/PLONG";
  return test_long_get(path) && test_long_set(path);
}

bool test_ulong_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_ULONG, result[TYPE_ID_KEY]);
  ASSERT_EQUALS(UINT64_MAX, result[VALUE_KEY]);
  return true;
}

bool test_ulong_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_ULONG;
  obj[VALUE_KEY] = UINT64_WIDTH;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQUALS(UINT64_WIDTH, result[VALUE_KEY]);
  return true;
}

bool test_ulong(string path) {
  path += "/PULONG";
  return test_ulong_get(path) && test_ulong_set(path);
}

bool test_float_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_FLOAT, result[TYPE_ID_KEY]);
  ASSERT_EQUALS(FLT_MAX, result[VALUE_KEY]);
  return true;
}

bool test_float_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_FLOAT;
  obj[VALUE_KEY] = FLT_MIN;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQUALS(FLT_MIN, result[VALUE_KEY]);
  return true;
}

bool test_float(string path) {
  path += "/PFLOAT";
  return test_float_get(path) && test_float_set(path);
}

bool test_double_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_DOUBLE, result[TYPE_ID_KEY]);
  ASSERT_EQUALS(DBL_MAX, result[VALUE_KEY]);
  return true;
}

bool test_double_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_DOUBLE;
  obj[VALUE_KEY] = DBL_MIN;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQUALS(DBL_MIN, result[VALUE_KEY]);
  return true;
}

bool test_double(string path) {
  path += "/PDOUBLE";
  return test_double_get(path) && test_double_set(path);
}

bool test_short_array_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_A_SHORT, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<short>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(INT16_MIN, values[0]);
  ASSERT_EQUALS(INT16_MAX, values[1]);
  return true;
}

bool test_short_array_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_SHORT;
  obj[VALUE_KEY] = vector<short> {INT16_MAX, INT16_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<short>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(INT16_MAX, values[0]);
  ASSERT_EQUALS(INT16_WIDTH, values[1]);
  return true;
}

bool test_short_array(string path) {
  path += "/PASHORT";
  return test_short_array_get(path) && test_short_array_set(path);
}

bool test_ushort_array_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_A_USHORT, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<unsigned short>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(0, values[0]);
  ASSERT_EQUALS(UINT16_MAX, values[1]);
  return true;
}

bool test_ushort_array_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_USHORT;
  obj[VALUE_KEY] = vector<unsigned short> {UINT16_MAX, UINT16_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<unsigned short>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(UINT16_MAX, values[0]);
  ASSERT_EQUALS(UINT16_WIDTH, values[1]);
  return true;
}

bool test_ushort_array(string path) {
  path += "/PAUSHORT";
  return test_ushort_array_get(path) && test_ushort_array_set(path);
}

bool test_int_array_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_A_INT, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<int>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(INT32_MIN, values[0]);
  ASSERT_EQUALS(INT32_MAX, values[1]);
  return true;
}

bool test_int_array_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_INT;
  obj[VALUE_KEY] = vector<int> {INT32_MAX, INT32_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<int>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(INT32_MAX, values[0]);
  ASSERT_EQUALS(INT32_WIDTH, values[1]);
  return true;
}

bool test_int_array(string path) {
  path += "/PAINT";
  return test_int_array_get(path) && test_int_array_set(path);
}

bool test_uint_array_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_A_UINT, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<unsigned int>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(0, values[0]);
  ASSERT_EQUALS(UINT32_MAX, values[1]);
  return true;
}

bool test_uint_array_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_UINT;
  obj[VALUE_KEY] = vector<unsigned int> {UINT32_MAX, UINT32_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<unsigned int>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(UINT32_MAX, values[0]);
  ASSERT_EQUALS(UINT32_WIDTH, values[1]);
  return true;
}

bool test_uint_array(string path) {
  path += "/PAUINT";
  return test_uint_array_get(path) && test_uint_array_set(path);
}

bool test_long_array_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_A_LONG, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<long long>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(INT64_MIN, values[0]);
  ASSERT_EQUALS(INT64_MAX, values[1]);
  return true;
}

bool test_long_array_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_LONG;
  obj[VALUE_KEY] = vector<long long> {INT64_MAX, INT64_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<long long>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(INT64_MAX, values[0]);
  ASSERT_EQUALS(INT64_WIDTH, values[1]);
  return true;
}

bool test_long_array(string path) {
  path += "/PALONG";
  return test_long_array_get(path) && test_long_array_set(path);
}

bool test_ulong_array_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_A_ULONG, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<unsigned long long>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(0, values[0]);
  ASSERT_EQUALS(UINT64_MAX, values[1]);
  return true;
}

bool test_ulong_array_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_ULONG;
  obj[VALUE_KEY] = vector<unsigned long long> {UINT64_MAX, UINT64_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<unsigned long long>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(UINT64_MAX, values[0]);
  ASSERT_EQUALS(UINT64_WIDTH, values[1]);
  return true;
}

bool test_ulong_array(string path) {
  path += "/PAULONG";
  return test_ulong_array_get(path) && test_ulong_array_set(path);
}

bool test_float_array_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_A_FLOAT, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<float>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(FLT_MIN, values[0]);
  ASSERT_EQUALS(FLT_MAX, values[1]);
  return true;
}

bool test_float_array_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_FLOAT;
  obj[VALUE_KEY] = vector<float> {FLT_MAX, FLT_EPSILON};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<float>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(FLT_MAX, values[0]);
  ASSERT_EQUALS(FLT_EPSILON, values[1]);
  return true;
}

bool test_float_array(string path) {
  path += "/PAFLOAT";
  return test_float_array_get(path) && test_float_array_set(path);
}

bool test_double_array_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_A_DOUBLE, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<double>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(DBL_MIN, values[0]);
  ASSERT_EQUALS(DBL_MAX, values[1]);
  return true;
}

bool test_double_array_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_DOUBLE;
  obj[VALUE_KEY] = vector<double> {DBL_MAX, DBL_EPSILON};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<double>>();
  ASSERT_EQUALS(2, values.size());
  ASSERT_EQUALS(DBL_MAX, values[0]);
  ASSERT_EQUALS(DBL_EPSILON, values[1]);
  return true;
}

bool test_double_array(string path) {
  path += "/PADOUBLE";
  return test_double_array_get(path) && test_double_array_set(path);
}

bool test_string_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_STRING, result[TYPE_ID_KEY]);
  ASSERT_EQUALS("Hello string", result[VALUE_KEY]);
  return true;
}

bool test_string_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_STRING;
  obj[VALUE_KEY] = STR_VALUE;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQUALS(STR_VALUE, result[VALUE_KEY]);
  return true;
}

bool test_string(string path) {
  path += "/PSTRING";
  return test_string_get(path) && test_string_set(path);
}

bool test_text_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_TEXT, result[TYPE_ID_KEY]);
  ASSERT_EQUALS("Hello text Hello text Hello text Hello text"
      "Hello text Hello text Hello text Hello text",
      result[VALUE_KEY]);
  return true;
}

bool test_text_set(const string& path) {
  json obj;
  obj[TYPE_ID_KEY] = DATA_TEXT;
  obj[VALUE_KEY] = STR_VALUE;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQUALS(STR_VALUE, result[VALUE_KEY]);
  return true;
}

bool test_text(string path) {
  path += "/PTEXT";
  return test_text_get(path) && test_text_set(path);
}

bool test_ustr_get(const string& path) {
  auto result = get_property(path);
  ASSERT_EQUALS(DATA_A_USTR, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<json>();
  ASSERT_EQUALS(1, values.size());
  ASSERT_EQUALS(1, values[0]["i1"].get<int>());
  ASSERT_EQUALS(2.25, values[0]["f1"].get<float>());
  ASSERT_EQUALS(4.5, values[0]["f2"].get<float>());
  ASSERT_EQUALS(6, values[0]["tm"].get<time_t>());
  ASSERT_EQUALS("Hello world", values[0]["data"]);
  return true;
}

bool test_ustr_set(const string& path) {
  json ustr;
  ustr["i1"] = INT32_MAX;
  ustr["f1"] = FLT_MIN;
  ustr["f2"] = FLT_MAX;
  ustr["tm"] = INT16_WIDTH;
  ustr["data"] = STR_VALUE;

  json obj;
  obj[TYPE_ID_KEY] = DATA_A_USTR;
  obj[VALUE_KEY] = vector<json> {ustr};

  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  auto values = result[VALUE_KEY].get<json>();
  ASSERT_EQUALS(1, values.size());
  ASSERT_EQUALS(INT32_MAX, values[0]["i1"].get<int>());
  ASSERT_EQUALS(FLT_MIN, values[0]["f1"].get<float>());
  ASSERT_EQUALS(FLT_MAX, values[0]["f2"].get<float>());
  ASSERT_EQUALS(INT16_WIDTH, values[0]["tm"].get<int>());
  ASSERT_EQUALS(STR_VALUE, values[0]["data"]);
  return true;
}

bool test_ustr(string path) {
  path += "/PUSTR";
  return test_ustr_get(path) && test_ustr_set(path);
}

void test_all(const string& base_path) {
  int passed = 0;
  int total = 0;

  RUN_TEST(test_bool(base_path));
  RUN_TEST(test_short(base_path));
  RUN_TEST(test_ushort(base_path));
  RUN_TEST(test_int(base_path));
  RUN_TEST(test_uint(base_path));
  RUN_TEST(test_long(base_path));
  RUN_TEST(test_ulong(base_path));
  RUN_TEST(test_float(base_path));
  RUN_TEST(test_double(base_path));
  RUN_TEST(test_short_array(base_path));
  RUN_TEST(test_ushort_array(base_path));
  RUN_TEST(test_int_array(base_path));
  RUN_TEST(test_uint_array(base_path));
  RUN_TEST(test_long_array(base_path));
  RUN_TEST(test_ulong_array(base_path));
  RUN_TEST(test_float_array(base_path));
  RUN_TEST(test_double_array(base_path));
  RUN_TEST(test_string(base_path));
  RUN_TEST(test_text(base_path));
  RUN_TEST(test_ustr(base_path));

  cerr << "Tests passed: " << passed << "/" << total << endl;
}