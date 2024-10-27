#include "mo_decimal.h"

int mo_is_equal(mo_decimal value_1, mo_decimal value_2) {
  int code = 1;

  mo_decimal tmp1 = remove_trailing_zeros(value_1);
  mo_decimal tmp2 = remove_trailing_zeros(value_2);

  if (tmp1.bits[0] == 0 && tmp1.bits[1] == 0 && tmp1.bits[2] == 0 &&
      tmp2.bits[0] == 0 && tmp2.bits[1] == 0 && tmp2.bits[2] == 0) {
    // Считаем -0 == 0, поэтому знаковый бит не проверяем, степени уже будут
    // равны после отбрасывания конечных нулей
    code = 1;
  } else {
    code = tmp1.bits[0] == tmp2.bits[0] && tmp1.bits[1] == tmp2.bits[1] &&
           tmp1.bits[2] == tmp2.bits[2] && tmp1.bits[3] == tmp2.bits[3];
  }

  return code;
}