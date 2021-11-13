#include <ctime>
#include "EqFctTest.h"
#include <cstdint>
#include <cfloat>

EqFctTest::EqFctTest()
    : EqFct("NAME location name")
    , bool_prop_("PBOOL bool", 0, &sp_, this)
    , short_prop_("PSHORT short", this)
    , ushort_prop_("PUSHORT ushort", this)
    , int_prop_("PINT int", this)
    , uint_prop_("PUINT uint", this)
    , long_prop_("PLONG long", this)
    , ulong_prop_("PULONG ulong", this)
    , float_prop_("PFLOAT float", this)
    , double_prop_("PDOUBLE double", this)
    , shortarray_prop_("PASHORT short[]", this)
    , ushortarray_prop_("PAUSHORT ushort[]", this)
    , intarray_prop_("PAINT int[]", this)
    , uintarray_prop_("PAUINT uint[]", this)
    , longarray_prop_("PALONG long[]", this)
    , ulongarray_prop_("PAULONG ulong[]", this)
    , floatarray_prop_("PAFLOAT float[]", this)
    , doublearray_prop_("PADOUBLE double[]", this)
    , string_prop_("PSTRING string", this)
    , text_prop_("PTEXT text", this)
    , ustr_prop_(this, "PUSTR ustr")
{ }

void EqFctTest::init() {
  short_prop_.set_value(short(INT16_MAX));
  ushort_prop_.set_value((unsigned short)(UINT16_MAX));
  int_prop_.set_value(INT32_MAX);
  uint_prop_.set_value(UINT32_MAX);
  long_prop_.set_value(INT64_MAX);
  ulong_prop_.set_value(UINT64_MAX);
  float_prop_.set_value(FLT_MAX);
  double_prop_.set_value(DBL_MAX);

  shortarray_prop_.set_value(short(INT16_MIN), 0);
  shortarray_prop_.set_value(short(INT16_MAX), 1);
  shortarray_prop_.set_length(2);

  ushortarray_prop_.set_value(0, 0);
  ushortarray_prop_.set_value((unsigned short)(UINT16_MAX), 1);
  ushortarray_prop_.set_length(2);

  intarray_prop_.set_value(INT32_MIN, 0);
  intarray_prop_.set_value(INT32_MAX, 1);
  intarray_prop_.set_length(2);

  uintarray_prop_.set_value(0, 0);
  uintarray_prop_.set_value(UINT32_MAX, 1);
  uintarray_prop_.set_length(2);

  longarray_prop_.set_value(INT64_MIN, 0);
  longarray_prop_.set_value(INT64_MAX, 1);
  longarray_prop_.set_length(2);

  ulongarray_prop_.set_value(0, 0);
  ulongarray_prop_.set_value(UINT64_MAX, 1);
  ulongarray_prop_.set_length(2);

  floatarray_prop_.set_value(FLT_MIN, 0);
  floatarray_prop_.set_value(FLT_MAX, 1);
  floatarray_prop_.set_length(2);

  doublearray_prop_.set_value(DBL_MIN, 0);
  doublearray_prop_.set_value(DBL_MAX, 1);
  doublearray_prop_.set_length(2);

  string_prop_.set_value("Hello string");

  text_prop_.set_value("Hello text Hello text Hello text Hello text"
                       "Hello text Hello text Hello text Hello text");

  ustr_prop_.set_value(1);
  ustr_prop_.set_f1(2.25);
  ustr_prop_.set_f2(4.5);
  ustr_prop_.set_value(time_t(6));
  ustr_prop_.set_value("Hello world");
}
