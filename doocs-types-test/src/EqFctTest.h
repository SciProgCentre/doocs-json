#ifndef EQFCTDUMMY_H_
#define EQFCTDUMMY_H_

#include <eq_fct.h>

class EqFctTest : public EqFct
{
public:
  constexpr static int code = 100;

  EqFctTest();

  int fct_code() override { return code; }
  void init() override;

private:
  uint16_t sp_ = 0;
  D_bit bool_prop_;
  D_short short_prop_;
  D_ushort ushort_prop_;
  D_int int_prop_;
  D_uint uint_prop_;
  D_long long_prop_;
  D_ulong ulong_prop_;
  D_float float_prop_;
  D_double double_prop_;
  D_shortarray shortarray_prop_;
  D_ushortarray ushortarray_prop_;
  D_intarray intarray_prop_;
  D_uintarray uintarray_prop_;
  D_longarray longarray_prop_;
  D_ulongarray ulongarray_prop_;
  D_floatarray floatarray_prop_;
  D_doublearray doublearray_prop_;
  D_string string_prop_;
  D_text text_prop_;
  D_ustr ustr_prop_;
};

#endif // EQFCTDUMMY_H_
