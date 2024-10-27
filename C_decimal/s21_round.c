#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int code = 0;

  if (!result) {
  } else if (!is_correct_decimal(value)) {
    code = 1;
    //  *result = s21_decimal_get_inf();
  } else {
    // В остальных случаях округляем
    *result = zero_val;
    int sign = get_sign(value);
    s21_decimal fractional;
    s21_decimal value_unsigned_truncated;
    // Убираем знак
    s21_decimal value_unsigned = abs_val(value);
    // Убираем дробную часть числа
    s21_truncate(value_unsigned, &value_unsigned_truncated);

    // Считаем убранную дробную часть числа
    s21_sub(value_unsigned, value_unsigned_truncated, &fractional);

    // Производим округление, исходя из дробной части числа
    value_unsigned_truncated =
        round_banking(value_unsigned_truncated, fractional);

    *result = value_unsigned_truncated;
    // Возвращаем знак
    set_sign(result, sign);
  }

  return code;
}
