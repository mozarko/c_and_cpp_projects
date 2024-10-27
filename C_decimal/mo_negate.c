#include "mo_decimal.h"

int mo_negate(mo_decimal value, mo_decimal *result) {
  int code = 0;

  if (!result) {
    code = 1;
  } else {
    // В остальных случаях меняем знак
    *result = value;
    set_sign(result, !get_sign(*result));

    if (!is_correct_decimal(value)) {
      // Если value не является корректными decimal, то выставляем код ошибки
      // Но знак реально при этом мы меняем и у некорректного decimal
      code = 1;
    }
  }

  return code;
}