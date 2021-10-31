#include "doocs_json.h"

#include <cfloat>
#include <gtest/gtest.h>

using namespace std;
using namespace nlohmann;

constexpr const char *ERROR_KEY = "error";
constexpr const char *TYPE_ID_KEY = "type_id";
constexpr const char *VALUE_KEY = "value";

constexpr const char *STR_VALUE = "string value";

constexpr const char *BOOL_PROP = "/PBOOL";
constexpr const char *SHORT_PROP = "/PSHORT";
constexpr const char *USHORT_PROP = "/PUSHORT";
constexpr const char *INT_PROP = "/PINT";
constexpr const char *UINT_PROP = "/PUINT";
constexpr const char *LONG_PROP = "/PLONG";
constexpr const char *ULONG_PROP = "/PULONG";
constexpr const char *FLOAT_PROP = "/PFLOAT";
constexpr const char *DOUBLE_PROP = "/PDOUBLE";
constexpr const char *SHORT_ARR_PROP = "/PASHORT";
constexpr const char *USHORT_ARR_PROP = "/PAUSHORT";
constexpr const char *INT_ARR_PROP = "/PAINT";
constexpr const char *UINT_ARR_PROP = "/PAUINT";
constexpr const char *LONG_ARR_PROP = "/PALONG";
constexpr const char *ULONG_ARR_PROP = "/PAULONG";
constexpr const char *FLOAT_ARR_PROP = "/PAFLOAT";
constexpr const char *DOUBLE_ARR_PROP = "/PADOUBLE";
constexpr const char *STRING_PROP = "/PSTRING";
constexpr const char *TEXT_PROP = "/PTEXT";
constexpr const char *USTR_PROP = "/PUSTR";

string base_path;

void ASSERT_SET_SUCCESS(const json &set_result) {
  ASSERT_EQ(0, set_result[ERROR_KEY]);
  ASSERT_EQ(DATA_NULL, set_result[TYPE_ID_KEY]);
}

TEST(Bool, Get) {
  string path = base_path + BOOL_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_BOOL, result[TYPE_ID_KEY]);
  ASSERT_EQ(false, result[VALUE_KEY]);
}

TEST(Bool, Set) {
  string path = base_path + BOOL_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_BOOL;
  obj[VALUE_KEY] = true;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQ(true, result[VALUE_KEY]);
}

TEST(Short, Get) {
  string path = base_path + SHORT_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_SHORT, result[TYPE_ID_KEY]);
  ASSERT_EQ(INT16_MAX, result[VALUE_KEY]);
}

TEST(Short, Set) {
  string path = base_path + SHORT_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_SHORT;
  obj[VALUE_KEY] = INT16_MIN;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQ(INT16_MIN, result[VALUE_KEY]);
}

TEST(Ushort, Get) {
  string path = base_path + USHORT_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_USHORT, result[TYPE_ID_KEY]);
  ASSERT_EQ(UINT16_MAX, result[VALUE_KEY]);
}

TEST(Ushort, Set) {
  string path = base_path + USHORT_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_USHORT;
  obj[VALUE_KEY] = UINT16_WIDTH;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQ(UINT16_WIDTH, result[VALUE_KEY]);
}

TEST(Int, Get) {
  string path = base_path + INT_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_INT, result[TYPE_ID_KEY]);
  ASSERT_EQ(INT32_MAX, result[VALUE_KEY]);
}

TEST(Int, Set) {
  string path = base_path + INT_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_INT;
  obj[VALUE_KEY] = INT32_MIN;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQ(INT32_MIN, result[VALUE_KEY]);
}

TEST(Uint, Get) {
  string path = base_path + UINT_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_UINT, result[TYPE_ID_KEY]);
  ASSERT_EQ(UINT32_MAX, result[VALUE_KEY]);
}

TEST(Uint, Set) {
  string path = base_path + UINT_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_UINT;
  obj[VALUE_KEY] = UINT32_WIDTH;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQ(UINT32_WIDTH, result[VALUE_KEY]);
}

TEST(Long, Get) {
  string path = base_path + LONG_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_LONG, result[TYPE_ID_KEY]);
  ASSERT_EQ(INT64_MAX, result[VALUE_KEY]);
}

TEST(Long, Set) {
  string path = base_path + LONG_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_LONG;
  obj[VALUE_KEY] = INT64_MIN;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQ(INT64_MIN, result[VALUE_KEY]);
}

TEST(Ulong, Get) {
  string path = base_path + ULONG_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_ULONG, result[TYPE_ID_KEY]);
  ASSERT_EQ(UINT64_MAX, result[VALUE_KEY]);
}

TEST(Ulong, Set) {
  string path = base_path + ULONG_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_ULONG;
  obj[VALUE_KEY] = UINT64_WIDTH;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQ(UINT64_WIDTH, result[VALUE_KEY]);
}

TEST(Float, Get) {
  string path = base_path + FLOAT_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_FLOAT, result[TYPE_ID_KEY]);
  ASSERT_EQ(FLT_MAX, result[VALUE_KEY]);
}

TEST(Float, Set) {
  string path = base_path + FLOAT_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_FLOAT;
  obj[VALUE_KEY] = FLT_MIN;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQ(FLT_MIN, result[VALUE_KEY]);
}

TEST(Double, Get) {
  string path = base_path + DOUBLE_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_DOUBLE, result[TYPE_ID_KEY]);
  ASSERT_EQ(DBL_MAX, result[VALUE_KEY]);
}

TEST(Double, Set) {
  string path = base_path + DOUBLE_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_DOUBLE;
  obj[VALUE_KEY] = DBL_MIN;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQ(DBL_MIN, result[VALUE_KEY]);
}

TEST(ShortArray, Get) {
  string path = base_path + SHORT_ARR_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_A_SHORT, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<short>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(INT16_MIN, values[0]);
  ASSERT_EQ(INT16_MAX, values[1]);
}

TEST(ShortArray, Set) {
  string path = base_path + SHORT_ARR_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_SHORT;
  obj[VALUE_KEY] = vector<short> {INT16_MAX, INT16_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<short>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(INT16_MAX, values[0]);
  ASSERT_EQ(INT16_WIDTH, values[1]);
}

TEST(UshortArray, Get) {
  string path = base_path + USHORT_ARR_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_A_USHORT, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<unsigned short>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(0, values[0]);
  ASSERT_EQ(UINT16_MAX, values[1]);
}

TEST(UshortArray, Set) {
  string path = base_path + USHORT_ARR_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_USHORT;
  obj[VALUE_KEY] = vector<unsigned short> {UINT16_MAX, UINT16_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<unsigned short>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(UINT16_MAX, values[0]);
  ASSERT_EQ(UINT16_WIDTH, values[1]);
}

TEST(IntArray, Get) {
  string path = base_path + INT_ARR_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_A_INT, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<int>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(INT32_MIN, values[0]);
  ASSERT_EQ(INT32_MAX, values[1]);
}

TEST(IntArray, Set) {
  string path = base_path + INT_ARR_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_INT;
  obj[VALUE_KEY] = vector<int> {INT32_MAX, INT32_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<int>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(INT32_MAX, values[0]);
  ASSERT_EQ(INT32_WIDTH, values[1]);
}

TEST(UintArray, Get) {
  string path = base_path + UINT_ARR_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_A_UINT, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<unsigned int>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(0, values[0]);
  ASSERT_EQ(UINT32_MAX, values[1]);
}

TEST(UintArray, Set) {
  string path = base_path + UINT_ARR_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_UINT;
  obj[VALUE_KEY] = vector<unsigned int> {UINT32_MAX, UINT32_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<unsigned int>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(UINT32_MAX, values[0]);
  ASSERT_EQ(UINT32_WIDTH, values[1]);
}

TEST(LongArray, Get) {
  string path = base_path + LONG_ARR_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_A_LONG, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<long long>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(INT64_MIN, values[0]);
  ASSERT_EQ(INT64_MAX, values[1]);
}

TEST(LongArray, Set) {
  string path = base_path + LONG_ARR_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_LONG;
  obj[VALUE_KEY] = vector<long long> {INT64_MAX, INT64_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<long long>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(INT64_MAX, values[0]);
  ASSERT_EQ(INT64_WIDTH, values[1]);
}

TEST(UlongArray, Get) {
  string path = base_path + ULONG_ARR_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_A_ULONG, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<unsigned long long>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(0, values[0]);
  ASSERT_EQ(UINT64_MAX, values[1]);
}

TEST(UlongArray, Set) {
  string path = base_path + ULONG_ARR_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_ULONG;
  obj[VALUE_KEY] = vector<unsigned long long> {UINT64_MAX, UINT64_WIDTH};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<unsigned long long>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(UINT64_MAX, values[0]);
  ASSERT_EQ(UINT64_WIDTH, values[1]);
}

TEST(FloatArray, Get) {
  string path = base_path + FLOAT_ARR_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_A_FLOAT, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<float>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(FLT_MIN, values[0]);
  ASSERT_EQ(FLT_MAX, values[1]);
}

TEST(FloatArray, Set) {
  string path = base_path + FLOAT_ARR_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_FLOAT;
  obj[VALUE_KEY] = vector<float> {FLT_MAX, FLT_EPSILON};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<float>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(FLT_MAX, values[0]);
  ASSERT_EQ(FLT_EPSILON, values[1]);
}

TEST(DoubleArray, Get) {
  string path = base_path + DOUBLE_ARR_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_A_DOUBLE, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<vector<double>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(DBL_MIN, values[0]);
  ASSERT_EQ(DBL_MAX, values[1]);
}

TEST(DoubleArray, Set) {
  string path = base_path + DOUBLE_ARR_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_A_DOUBLE;
  obj[VALUE_KEY] = vector<double> {DBL_MAX, DBL_EPSILON};
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto values = get_property(path)[VALUE_KEY].get<vector<double>>();
  ASSERT_EQ(2, values.size());
  ASSERT_EQ(DBL_MAX, values[0]);
  ASSERT_EQ(DBL_EPSILON, values[1]);
}

TEST(String, Get) {
  string path = base_path + STRING_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_STRING, result[TYPE_ID_KEY]);
  ASSERT_EQ("Hello string", result[VALUE_KEY]);
}

TEST(String, Set) {
  string path = base_path + STRING_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_STRING;
  obj[VALUE_KEY] = STR_VALUE;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQ(STR_VALUE, result[VALUE_KEY]);
}

TEST(Text, Get) {
  string path = base_path + TEXT_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_TEXT, result[TYPE_ID_KEY]);
  ASSERT_EQ("Hello text Hello text Hello text Hello text"
      "Hello text Hello text Hello text Hello text",
      result[VALUE_KEY]);
}

TEST(Text, Set) {
  string path = base_path + TEXT_PROP;
  json obj;
  obj[TYPE_ID_KEY] = DATA_TEXT;
  obj[VALUE_KEY] = STR_VALUE;
  ASSERT_SET_SUCCESS(set_property(path, obj));
  auto result = get_property(path);
  ASSERT_EQ(STR_VALUE, result[VALUE_KEY]);
}

TEST(Ustr, Get) {
  string path = base_path + USTR_PROP;
  auto result = get_property(path);
  ASSERT_EQ(DATA_A_USTR, result[TYPE_ID_KEY]);
  auto values = result[VALUE_KEY].get<json>();
  ASSERT_EQ(1, values.size());
  ASSERT_EQ(1, values[0]["i1"].get<int>());
  ASSERT_EQ(2.25, values[0]["f1"].get<float>());
  ASSERT_EQ(4.5, values[0]["f2"].get<float>());
  ASSERT_EQ(6, values[0]["tm"].get<time_t>());
  ASSERT_EQ("Hello world", values[0]["data"]);
}

TEST(Ustr, Set) {
  string path = base_path + USTR_PROP;
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
  ASSERT_EQ(1, values.size());
  ASSERT_EQ(INT32_MAX, values[0]["i1"].get<int>());
  ASSERT_EQ(FLT_MIN, values[0]["f1"].get<float>());
  ASSERT_EQ(FLT_MAX, values[0]["f2"].get<float>());
  ASSERT_EQ(INT16_WIDTH, values[0]["tm"].get<int>());
  ASSERT_EQ(STR_VALUE, values[0]["data"]);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  base_path = argv[1];
  return RUN_ALL_TESTS();
}
