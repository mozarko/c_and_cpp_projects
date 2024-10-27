#include "mo_decimal.h"

int mo_floor(mo_decimal value, mo_decimal *result) {
  int code = 0;

  if (!result) {
    code = 1;
  } else if (!is_correct_decimal(value)) {
    code = 1;
    // *result = mo_decimal_get_inf();
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

    // Если дробная часть была больше нуля и число было отрицательным, то
    // прибавляем 1
    if (sign == 1 && mo_is_greater(fractional, zero_val)) {
      mo_add(value_unsigned_truncated, one_val, &value_unsigned_truncated);
    }

    *result = value_unsigned_truncated;
    // Возвращаем знак
    set_sign(result, sign);
  }

  return code;
}