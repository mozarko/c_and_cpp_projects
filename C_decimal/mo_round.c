#include "mo_decimal.h"

int mo_round(mo_decimal value, mo_decimal *result) {
  int code = 0;

  if (!result) {
  } else if (!is_correct_decimal(value)) {
    code = 1;
    //  *result = mo_decimal_get_inf();
  } else {
    // В остальных случаях округляем
    *result = zero_val;
    int sign = get_sign(value);
    mo_decimal fractional;
    mo_decimal value_unsigned_truncated;
    // Убираем знак
    mo_decimal value_unsigned = abs_val(value);
    // Убираем дробную часть числа
    mo_truncate(value_unsigned, &value_unsigned_truncated);

    // Считаем убранную дробную часть числа
    mo_sub(value_unsigned, value_unsigned_truncated, &fractional);

    // Производим округление, исходя из дробной части числа
    value_unsigned_truncated =
        round_banking(value_unsigned_truncated, fractional);

    *result = value_unsigned_truncated;
    // Возвращаем знак
    set_sign(result, sign);
  }

  return code;
}
