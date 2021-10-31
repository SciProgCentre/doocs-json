#include "doocs_json.h"

#include <cfloat>
#include <gtest/gtest.h>

using namespace std;
using namespace nlohmann;

constexpr const char *TYPE_KEY = "type";
constexpr const char *TYPE_ID_KEY = "type_id";
constexpr const char *VALUE_KEY = "value";
constexpr const char *EVENT_ID_KEY = "event_id";
constexpr const char *ERROR_KEY = "error";
constexpr const char *TIME_KEY = "time";

constexpr const char *STR_VALUE = "string value";
constexpr const char *STR_VALUE_2 = "string value 2";
constexpr const char *TXT_VALUE = "text value text value text value text value"
                                  "text value text value text value text value";

template <typename T>
json create_json(int type_id, const string& type, const T& value) {
  json obj;
  obj[TYPE_ID_KEY] = type_id;
  obj[TYPE_KEY] = type;
  obj[VALUE_KEY] = value;
  obj[ERROR_KEY] = 0;
  obj[EVENT_ID_KEY] = 0;
  obj[TIME_KEY] = 1;
  return obj;
}

void test_self_consistency(const json& obj1) {
  auto eq = eq_data_from_json(obj1);
  auto obj2 = eq_data_to_json(*eq);
  ASSERT_EQ(obj1, obj2);
}

TEST(Bool, True) {
  json obj = create_json(DATA_BOOL, "BOOL", true);
  test_self_consistency(obj);
}

TEST(Short, MaxValue) {
  json obj = create_json(DATA_SHORT, "SHORT", INT16_MAX);
  test_self_consistency(obj);
}

TEST(Ushort, MaxValue) {
  json obj = create_json(DATA_USHORT, "USHORT", UINT16_MAX);
  test_self_consistency(obj);
}

TEST(Int, MaxValue) {
  json obj = create_json(DATA_INT, "INT", INT32_MAX);
  test_self_consistency(obj);
}

TEST(Uint, MaxValue) {
  json obj = create_json(DATA_UINT, "UINT", UINT32_MAX);
  test_self_consistency(obj);
}

TEST(Long, MaxValue) {
  json obj = create_json(DATA_LONG, "LONG", INT64_MAX);
  test_self_consistency(obj);
}

TEST(Ulong, MaxValue) {
  json obj = create_json(DATA_ULONG, "ULONG", UINT64_MAX);
  test_self_consistency(obj);
}

TEST(Float, MaxValue) {
  json obj = create_json(DATA_FLOAT, "FLOAT", FLT_MAX);
  test_self_consistency(obj);
}

TEST(Double, MaxValue) {
  json obj = create_json(DATA_DOUBLE, "DOUBLE", DBL_MAX);
  test_self_consistency(obj);
}

TEST(BoolArray, Values) {
  vector<bool> values = {false, true};
  json obj = create_json(DATA_A_BOOL, "A_BOOL", values);
  test_self_consistency(obj);
}

TEST(ShortArray, Values) {
  vector<short> values = {INT16_MIN, INT16_MAX};
  json obj = create_json(DATA_A_SHORT, "A_SHORT", values);
  test_self_consistency(obj);
}

TEST(UshortArray, Values) {
  vector<unsigned short> values = {0, UINT16_MAX};
  json obj = create_json(DATA_A_USHORT, "A_USHORT", values);
  test_self_consistency(obj);
}

TEST(IntArray, Values) {
  vector<int> values = {INT32_MIN, INT32_MAX};
  json obj = create_json(DATA_A_INT, "A_INT", values);
  test_self_consistency(obj);
}

TEST(UintArray, Values) {
  vector<unsigned int> values = {0, UINT32_MAX};
  json obj = create_json(DATA_A_UINT, "A_UINT", values);
  test_self_consistency(obj);
}

TEST(LongArray, Values) {
  vector<long long> values = {INT64_MIN, INT64_MAX};
  json obj = create_json(DATA_A_LONG, "A_LONG", values);
  test_self_consistency(obj);
}

TEST(UlongArray, Values) {
  vector<unsigned long long> values = {0, UINT64_MAX};
  json obj = create_json(DATA_A_ULONG, "A_ULONG", values);
  test_self_consistency(obj);
}

TEST(FloatArray, Values) {
  vector<float> values = {FLT_MIN, FLT_MAX};
  json obj = create_json(DATA_A_FLOAT, "A_FLOAT", values);
  test_self_consistency(obj);
}

TEST(DoubleArray, Values) {
  vector<double> values = {DBL_MIN, DBL_MAX};
  json obj = create_json(DATA_A_DOUBLE, "A_DOUBLE", values);
  test_self_consistency(obj);
}

TEST(String, ShortStr) {
  json obj = create_json(DATA_STRING, "STRING", STR_VALUE);
  test_self_consistency(obj);
}

TEST(Text, LongStr) {
  json obj = create_json(DATA_TEXT, "TEXT", TXT_VALUE);
  test_self_consistency(obj);
}

TEST(Ustr, Values) {
  json ustr1;
  ustr1["i1"] = INT32_MAX;
  ustr1["f1"] = FLT_MIN;
  ustr1["f2"] = FLT_MAX;
  ustr1["tm"] = INT16_MAX;
  ustr1["data"] = STR_VALUE;

  json ustr2;
  ustr2["i1"] = INT32_MIN;
  ustr2["f1"] = FLT_EPSILON;
  ustr2["f2"] = FLT_DIG;
  ustr2["tm"] = INT32_MAX;
  ustr2["data"] = STR_VALUE_2;

  vector<json> values{ustr1, ustr2};

  json obj = create_json(DATA_A_USTR, "A_USTR", values);
  test_self_consistency(obj);
}

