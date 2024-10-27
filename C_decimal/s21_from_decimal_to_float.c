#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int code = 0;
  if (!dst) {
    code = 1;
  } else if (!is_correct_decimal(src)) {
    code = 1;
    *dst = 0.0;
  } else if (s21_is_equal(src, zero_val)) {
    // Отдельно обрабатываем 0 и -0
    int sign = get_sign(src);
    if (sign == 1) {
      *dst = -0.0;
    } else {
      *dst = 0.0;
    }
    code = 0;
  } else {
    // В остальных случаях осуществляем конвертацию
    *dst = 0.0;
    // float и long double не подойдут
    double tmp = 0.0;
    // Запоминаем знак и степень decimal
    int sign = get_sign(src);
    int power = get_scale(src);

    // Каждый бит decimal переводим в double, для этого каждый бит представляем
    // как 2 в степени позиции бита и прибавляет к результату
    for (int i = 0; i < 96; i++) {
      if (bit_is_on(src, i) != 0) {
        tmp += pow(2.0, i);
      }
    }

    // Затем учитываем степень и корректируем итоговый результат
    double powerten = pow(10, power);
    tmp /= powerten;

    if (sign == 1) {
      tmp *= -1.0;
    }

    *dst = (float)tmp;
  }

  return code;
}