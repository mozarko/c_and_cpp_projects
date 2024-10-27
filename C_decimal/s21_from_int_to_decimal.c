#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int code = 0;

  if (!dst) {
    code = 1;
  } else {
    *dst = zero_val;
    int sign;

    if (src < 0) {
      sign = 1;
      if (src != INT_MIN) {
        // У INT_MIN не надо менять знак, ибо:
        // negation of -2147483648 cannot be represented in type 'int';
        // А при этом битовое представление -2147483648 нас устраивает без
        // дополнительных операций
        src = -src;
      }
    } else {
      sign = 0;
    }

    dst->bits[0] = src;
    // Определяем знак результата, исходя из знака числа src (типа int)
    set_sign(dst, sign);
  }

  return code;
}