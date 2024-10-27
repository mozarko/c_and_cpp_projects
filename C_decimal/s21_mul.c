#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = 0;

  if (!result) {
    code = 4;
  } else if (!is_correct_decimal(value_1) || !is_correct_decimal(value_2)) {
    code = 4;
    // *result = s21_decimal_get_inf();
  } else {
    // В остальных случаях считаем произведение
    *result = zero_val;
    s21_decimal res = zero_val;

    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);

    if (sign1 == 0 && sign2 == 0) {
      // Если оба множителя положительные
      // вызываем перемножение
      // result = value_2 * value_1
      code = multiplication(value_1, value_2, &res);
    } else if (sign1 == 0 && sign2 == 1) {
      // Если первый - положительный, второй - отрицательный
      // вызываем перемножение (используя abs), у результата меняем знак
      // result = -(value_1 * abs(value_2))
      code = multiplication(value_1, abs_val(value_2), &res);
      s21_negate(res, &res);
    } else if (sign1 == 1 && sign2 == 0) {
      // Если первый - отрицательный, второй - положительный
      // вызываем перемножение (используя abs), у результата меняем знак
      // result = -(abs(value_1) * value_2)
      code = multiplication(abs_val(value_1), value_2, &res);
      s21_negate(res, &res);
    } else if (sign1 == 1 && sign2 == 1) {
      // Если оба множителя отрицательные
      // вызываем перемножение (используя abs)
      // result = abs(value_1) * abs(value_2)
      code = multiplication(abs_val(value_1), abs_val(value_2), &res);
    }

    if (code == 1) {
      if (get_sign(res) == 1) {
        code = 2;
      }
    }

    // Обрабатываем ситуацию, что результат получился слишком маленький (0 < |x|
    // < 1e-28)
    if (code == 0 && s21_is_not_equal(value_1, zero_val) &&
        s21_is_not_equal(value_2, zero_val) && s21_is_equal(res, zero_val)) {
      code = 2;
    }

    *result = res;
  }

  return code;
}