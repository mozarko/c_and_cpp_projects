#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int code = 0;

  int sign1 = get_sign(value_1);
  int sign2 = get_sign(value_2);

  if (s21_is_equal(value_1, zero_val) && s21_is_equal(value_2, zero_val)) {
    // Если оба 0, то всегда false
    code = 0;
  } else if (sign1 == 1 && sign2 == 0) {
    // Отрицательное число (value_1) всегда меньше положительного (value_2)
    code = 1;
  } else if (sign1 == 0 && sign2 == 1) {
    // Положительное число (value_1) всегда не меньше отрицательного (value_2)
    code = 0;
  } else if (sign1 == 1 && sign2 == 1) {
    // Отрицательные числа делаем положительными и сравниваем наоборот
    code = less(abs_val(value_2), abs_val(value_1));
  } else {
    // В остальных случаях просто сравниваем
    code = less(value_1, value_2);
  }

  return code;
}