#include "mo_decimal.h"

int mo_sub(mo_decimal value_1, mo_decimal value_2, mo_decimal *result) {
  int code = 0;
  if (!result) {
    code = 4;
  } else if (!is_correct_decimal(value_1) || !is_correct_decimal(value_2)) {
    code = 4;
    //  *result = mo_decimal_get_inf();
  } else {
    // В остальных случаях считаем разность
    *result = zero_val;
    mo_decimal res = zero_val;
    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);

    if (sign1 == 0 && sign2 == 0) {
      // Если уменьшаемое и вычитаемое положительные
      if (mo_is_greater_or_equal(value_1, value_2)) {
        // Если уменьшаемое больше или равно вычитаемому
        // Вычитаем из уменьшаемого вычитаемое
        // result = value_1 - value_2
        code = subtraction(value_1, value_2, &res);
      } else {
        // Если уменьшаемое меньше вычитаемомого
        // Вычитаем из вычитаемого уменьшаемое, у результата меняем знак
        // result = -(value_2 - value_1)
        code = subtraction(value_2, value_1, &res);
        mo_negate(res, &res);
      }
    } else if (sign1 == 0 && sign2 == 1) {
      // Если уменьшаемое положительное, а вычитаемое отрицательное
      // вызываем суммирование (используя abs)
      // result = value_1 + abs(value_2)
      code = mo_add(value_1, abs_val(value_2), &res);
    } else if (sign1 == 1 && sign2 == 0) {
      // Если уменьшаемое отрицательное, а вычитаемое положительное
      // вызываем суммирование (используя abs), у результата меняем знак
      // result = - (abs(value_1) + value_2)
      code = mo_add(abs_val(value_1), value_2, &res);
      mo_negate(res, &res);
    } else if (sign1 == 1 && sign2 == 1) {
      // Если уменьшаемое и вычитаемое отрицательные
      if (mo_is_greater_or_equal(value_1, value_2)) {
        // Если уменьшаемое больше или равно вычитаемому
        // Вычитаем из вычитаемого уменьшаемое (используя abs)
        // result = abs(value_2) - abs(value_1)
        code = subtraction(abs_val(value_2), abs_val(value_1), &res);
      } else {
        // Если уменьшаемое меньше вычитаемомого
        // Вычитаем из уменьшаемого вычитаемое (используя abs), у результата
        // меняем знак result = - (abs(value_1) - abs(value_2))
        code = subtraction(abs_val(value_1), abs_val(value_2), &res);
        mo_negate(res, &res);
      }
    }

    if (get_sign(res) == 1 && code == 1) {
      code = 2;
    }

    *result = res;
  }

  return code;
}