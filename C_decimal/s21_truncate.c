#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int code = 0;

  if (!result) {
    code = 1;
  } else if (!is_correct_decimal(value)) {
    code = 1;
    *result = max_val;
  } else {
    // В остальных случаях производим расчет
    *result = zero_val;
    int power = get_scale(value);
    s21_decimal tmp = value;
    tmp.bits[3] = 0;

    tmp = binary_div(tmp, ten_pows[power], NULL);

    *result = tmp;
    if (get_sign(value) == 1) {
      set_sign(result, 1);
    }
  }

  return code;
}