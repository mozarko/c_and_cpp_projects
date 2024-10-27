#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;

  if (!result) {
    code = 4;
  } else if (!is_correct_decimal(value_1) || !is_correct_decimal(value_2)) {
    code = 4;
    //  *result = s21_decimal_get_inf();
  } else if (s21_is_equal(value_2, zero_val)) {
    // Проверяем случай, когда value_2 является нулем
    code = 3;
    // *result = s21_decimal_get_inf();
  } else {
    // В остальных случаях считаем частное
    *result = zero_val;
    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);
    big_decimal value_1b;
    big_decimal value_2b;
    int scale1 = get_scale(value_1);
    int scale2 = get_scale(value_2);
    // Выравниваем степени делимого и делителя (знак и степень при этом будут
    // обнулены)
    scaling(value_1, value_2, &value_1b, &value_2b, scale1, scale2);

    big_decimal remainder = decimal_to_big_decimal(zero_val);
    big_decimal res;

    // Делим выравненное делимое на выравненный делитель, остаток от деления
    // будет записан в remainder
    res = binary_div_big(value_1b, value_2b, &remainder);

    if (res.decimals[0].bits[3] != 0 || !binary_equal_zero(res.decimals[1])) {
      // Если целый результат деления уже не помещается в decimal
      // (переполнение), то возвращаем соответствующие ошибки
      if (sign1 != sign2) {
        code = 2;
      } else {
        code = 1;
      }
      // *result = s21_decimal_get_inf();
    } else {
      // В остальных случаях продолжаем вычисления и вызываем вспомогательную
      // функцию для расчетов
      code = division(value_2b, res, remainder, result);
      // Если знаки делимого и делителя отличаются, то необходимо сделать
      // результат отрицательным
      if (sign1 != sign2) {
        set_sign(result, 1);
      }
      // Корректируем код ответа от вспомогательной функции в случае ошибки и
      // отрицательного результата
      if (get_sign(*result) == 1 && code == 1) {
        code = 2;
      }
      // Обрабатываем ситуацию, что результат получился слишком маленький (0 <
      // |x| < 1e-28)
      if (code == 0 && s21_is_not_equal(value_1, zero_val) &&
          s21_is_equal(*result, zero_val)) {
        code = 2;
      }
    }
  }

  return code;
}