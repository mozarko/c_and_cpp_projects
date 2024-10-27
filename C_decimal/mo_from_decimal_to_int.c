#include "mo_decimal.h"

int mo_from_decimal_to_int(mo_decimal src, int *dst) {
  int code = 0;

  if (!dst) {
    code = 1;
  } else if (!is_correct_decimal(src)) {
    code = 1;
    *dst = 0;
  } else {
    *dst = 0;
    mo_decimal truncated_decimal = zero_val;
    // Отбрасываем дробную часть decimal
    mo_truncate(src, &truncated_decimal);

    if (mo_is_less(truncated_decimal, min_int_val) == 1) {
      // Если decimal меньше -2147483648, то преобразовать нельзя
      code = 1;
    } else if (mo_is_greater(truncated_decimal, max_int_val) == 1) {
      // Если decimal больше 2147483647, то преобразовать нельзя
      code = 1;
    } else {
      // В остальных случаях производим конвертацию
      for (int i = 0; i < 96; i++) {
        if (bit_is_on(truncated_decimal, i) != 0) {
          *dst += pow(2, i);
        }
      }

      // Определяем знак результата, исходя из знака числа src (типа decimal)
      if (get_sign(src) == 1 && *dst != -2147483648) {
        // У INT_MIN не надо менять знак, ибо:
        // negation of -2147483648 cannot be represented in type 'int';
        // А при этом для INT_MIN при расчете мы получили переполнение int и
        // правильное значение
        *dst = -*dst;
      }
    }
  }

  return code;
}