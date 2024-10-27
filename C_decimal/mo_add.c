#include "mo_decimal.h"

int mo_add(mo_decimal value_1, mo_decimal value_2, mo_decimal *result) {
  int code = 0;
  if (!result) {
    code = 4;
  } else if (!is_correct_decimal(value_1) || !is_correct_decimal(value_2)) {
    code = 4;
    // *result = mo_decimal_get_inf();
  } else {
    // В остальных случаях считаем сумму
    *result = zero_val;
    mo_decimal res = zero_val;

    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);

    if (sign1 == 0 && sign2 == 0) {
      // Если оба слагаемых положительные
      // вызываем суммирование
      // result = = value_1 + value_2
      code = addition(value_1, value_2, &res);
    } else if (sign1 == 0 && sign2 == 1) {
      // Если первое - положительное, второе - отрицательное
      // вызываем вычитание (используя abs)
      // result = value_1 - abs(value_2)
      code = mo_sub(value_1, abs_val(value_2), &res);
    } else if (sign1 == 1 && sign2 == 0) {
      // Если первое - отрицательное, второе - положительное
      // вызываем вычитание (используя abs), у результата меняем знак
      // result  = -(abs(value_1) - value_2)
      code = mo_sub(abs_val(value_1), value_2, &res);
      mo_negate(res, &res);
    } else if (sign1 == 1 && sign2 == 1) {
      // Если оба слагаемых отрицательные
      // вызываем суммирование (используя abs), у результата меняем знак
      // result = -(abs(value_1) + abs(value_2))
      code = addition(abs_val(value_1), abs_val(value_2), &res);
      mo_negate(res, &res);
    }

    if (get_sign(res) == 1 && code == 1) {
      code = 2;
    }

    *result = res;
  }

  return code;
}