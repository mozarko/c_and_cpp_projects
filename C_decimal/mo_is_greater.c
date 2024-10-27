#include "mo_decimal.h"

int mo_is_greater(mo_decimal value_1, mo_decimal value_2) {
  return mo_is_less(value_2, value_1);
}