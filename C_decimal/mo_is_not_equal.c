#include "mo_decimal.h"

int mo_is_not_equal(mo_decimal value_1, mo_decimal value_2) {
  return !mo_is_equal(value_1, value_2);
}