#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int code = 0;
  if (!dst) {
    code = 1;
  } else if (src == 0.0) {
    // Отдельно обрабатываем 0.0, чтобы не выполнять лишних вычислений
    code = 0;
    *dst = zero_val;
    if (signbit(src) != 0) {
      // Добавляем знак для -0.0
      set_sign(dst, 1);
    }
  } else if (isinf(src) || isnan(src)) {
    // Отдельно обрабатываем +inf, -inf, +nan, и -nan
    code = 1;
    // *dst = s21_decimal_get_inf();
    if (signbit(src) != 0) {
      // Добавляем знак для -nan и -inf
      set_sign(dst, 1);
    }
  } else if (fabsf(src) > MAX_FLOAT_TO_CONVERT) {
    // MAX_FLOAT_TO_CONVERT - максимальное число, которое можно сконвертировать
    // в decimal
    code = 1;
    // *dst = s21_decimal_get_inf();
    if (signbit(src) != 0) {
      // Добавляем знак для для отрицательного числа
      set_sign(dst, 1);
    }
  } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    // MIN_FLOAT_TO_CONVERT - минимальное число, которое можно сконвертировать в
    // decimal
    code = 1;
    *dst = zero_val;
  } else {
    *dst = zero_val;
    s21_decimal result;
    char flt[64];

    // Приводим float в научную запись - одна цифра до запятой и 6 цифр после
    // запятой В итоге мы получаем 7 значащих цифр, которые нам и нужно
    // перевести по заданию из float в decimal
    sprintf(flt, "%.27E", fabsf(src));
    // Получаем степень float из научной записи.
    int exp = float_exp_from_string(flt);
    // Анализируем полученную степень.
    if (exp <= -23) {
      // Если степень слишком маленькая, то не все значащие цифры поместятся в
      // decimal Поэтому корректируем точность и заново приводим float в научную
      // запись уже с новой точностью
      int float_precision = exp + 28;
      sprintf(flt, "%.*E", float_precision, fabsf(src));
    }

    // Переводим строку с научной нотацией в decimal
    result = float_string_to_decimal(flt);
    decimal_round(&result);

    // Определяем знак результата, исходя из знака числа src (типа float)
    if (signbit(src) != 0) {
      set_sign(&result, 1);
    }

    *dst = result;
  }

  return code;
}