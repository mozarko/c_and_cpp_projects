#include "mo_decimal.h"

mo_decimal binary_sub(mo_decimal num1, mo_decimal num2) {
  mo_decimal result;
  num2 = binary_not(num2);
  num2 = binary_add(num2, one_val);
  result = binary_add(num1, num2);

  return result;
}

big_decimal binary_sub_big(big_decimal num1, big_decimal num2) {
  big_decimal result;
  num2.decimals[0] = binary_not(num2.decimals[0]);
  num2.decimals[1] = binary_not(num2.decimals[1]);

  big_decimal one = decimal_to_big_decimal(one_val);

  num2 = binary_add_big(num2, one);
  result = binary_add_big(num1, num2);

  return result;
}

mo_decimal binary_add(mo_decimal num1, mo_decimal num2) {
  mo_decimal result = num1;
  mo_decimal tmp = num2;

  while (!binary_equal_zero(tmp)) {
    mo_decimal overflow_bits = binary_and(result, tmp);
    overflow_bits = binary_shift_left(overflow_bits, 1);
    result = binary_xor(result, tmp);
    tmp = overflow_bits;
  }

  return result;
}

big_decimal binary_add_big(big_decimal num1, big_decimal num2) {
  big_decimal result = num1;
  big_decimal tmp = num2;

  while (!binary_equal_zero(tmp.decimals[0]) ||
         !binary_equal_zero(tmp.decimals[1])) {
    big_decimal overflow_bits;
    overflow_bits.decimals[0] = binary_and(result.decimals[0], tmp.decimals[0]);
    overflow_bits.decimals[1] = binary_and(result.decimals[1], tmp.decimals[1]);

    overflow_bits = binary_shift_left_big(overflow_bits, 1);
    result.decimals[0] = binary_xor(result.decimals[0], tmp.decimals[0]);
    result.decimals[1] = binary_xor(result.decimals[1], tmp.decimals[1]);

    tmp = overflow_bits;
  }

  return result;
}

mo_decimal binary_xor(mo_decimal num1, mo_decimal num2) {
  mo_decimal result = zero_val;
  result.bits[0] = num1.bits[0] ^ num2.bits[0];
  result.bits[1] = num1.bits[1] ^ num2.bits[1];
  result.bits[2] = num1.bits[2] ^ num2.bits[2];
  result.bits[3] = num1.bits[3] ^ num2.bits[3];

  return result;
}

mo_decimal binary_and(mo_decimal num1, mo_decimal num2) {
  mo_decimal result = zero_val;

  result.bits[0] = num1.bits[0] & num2.bits[0];
  result.bits[1] = num1.bits[1] & num2.bits[1];
  result.bits[2] = num1.bits[2] & num2.bits[2];
  result.bits[3] = num1.bits[3] & num2.bits[3];

  return result;
}

big_decimal binary_mul(mo_decimal num1, mo_decimal num2) {
  big_decimal result = {{zero_val, zero_val}};
  big_decimal tmp = decimal_to_big_decimal(num1);

  int max_bit = check_max_bit(num2);

  for (int i = 0; i <= max_bit; i++) {
    if (bit_is_on(num2, i) != 0) {
      result = binary_add_big(result, tmp);
    }
    tmp = binary_shift_left_big(tmp, 1);
  }

  return result;
}

big_decimal binary_mul_big(big_decimal num1, mo_decimal num2) {
  big_decimal int256_result = decimal_to_big_decimal(zero_val);
  big_decimal int256_tmp1 = num1;

  int max_bit = check_max_bit(num2);

  for (int i = 0; i <= max_bit; i++) {
    if (bit_is_on(num2, i) != 0) {
      int256_result = binary_add_big(int256_result, int256_tmp1);
    }

    int256_tmp1 = binary_shift_left_big(int256_tmp1, 1);
  }

  return int256_result;
}

mo_decimal binary_not(mo_decimal num) {
  mo_decimal result = zero_val;
  result.bits[0] = ~num.bits[0];
  result.bits[1] = ~num.bits[1];
  result.bits[2] = ~num.bits[2];
  result.bits[3] = ~num.bits[3];

  return result;
}

mo_decimal binary_div(mo_decimal num1, mo_decimal num2,
                       mo_decimal *remainder) {
  mo_decimal result;

  // Рассчитываемый в алгоритме частичный остаток при расчетах
  mo_decimal partial_remainder = zero_val;
  // Рассчитываемое в алгоритме частное
  mo_decimal quotient = zero_val;

  if (binary_equal_zero(num1)) {
    // Сначала заполняем результаты для частного случая, когда делимое равно 0
    quotient = zero_val;
    partial_remainder = zero_val;
  } else if (binary_compare(num1, num2) == -1) {
    // Затем заполняем результаты для частного случая, когда делимое меньше
    // делителя
    quotient = zero_val;
    partial_remainder = num1;
  } else {
    // В остальных случаях используем деление двоичных чисел методом без
    // восстановления остатка.

    // Рассчитываем предварительный сдвиг делителя
    int left1 = check_max_bit(num1);
    int left2 = check_max_bit(num2);
    int shift = left1 - left2;

    // Сдвинутый делитель
    mo_decimal shifted_divisor = binary_shift_left(num2, shift);
    // Делимое для промежуточных расчетов, на первом этапе равно decimal1
    mo_decimal dividend = num1;

    // Флаг необходимости проводить вычитание (Шаг 5 алгоритма).
    // На первой итерации всегда требуется вычитать
    int need_subtraction = 1;

    // Повторяем действия k+1 раз (один раз пп.2-3 алгоритма и k раз пп.4-6)
    while (shift >= 0) {
      // Определяем необходимое действие (Прибавлять или вычитать Сдвинутый
      // делитель)
      if (need_subtraction == 1) {
        partial_remainder = binary_sub(dividend, shifted_divisor);
      } else {
        partial_remainder = binary_add(dividend, shifted_divisor);
      }

      // Сдвигаем влево на 1 частное и записываем в младший бит результата 1,
      // если старший бит частичного остатка равен 1
      quotient = binary_shift_left(quotient, 1);
      if (bit_is_on(partial_remainder, 128 - 1) == 0) {
        quotient = set_bit(quotient, 0);
      }

      // Рассчитываем делимое для следующей итерации цикла (сдвиг влево на 1
      // частичного остатка)
      dividend = binary_shift_left(partial_remainder, 1);

      // Если старший бит частичного остатка равен 0, то на следующей итерации
      // необходимо проводить вычитание (Шаг 5 алгоритма)
      if (bit_is_on(partial_remainder, 128 - 1) == 0) {
        need_subtraction = 1;
      } else {
        need_subtraction = 0;
      }
      --shift;
    }
    // Определяем, требуется ли коррекция остатка (п.8 алгоритма)
    if (bit_is_on(partial_remainder, 128 - 1)) {
      partial_remainder = binary_add(partial_remainder, shifted_divisor);
    }
    // Возвращаем на место частичный остаток (п.9 алгоритма)
    partial_remainder = binary_shift_right(partial_remainder, left1 - left2);
  }

  // Заполняем переменные результата (частное и остаток)
  result = quotient;
  if (remainder != NULL) {
    *remainder = partial_remainder;
  }

  return result;
}

big_decimal binary_div_big(big_decimal num1, big_decimal num2,
                           big_decimal *remainder) {
  big_decimal result;

  // Рассчитываемый в алгоритме частичный остаток при расчетах
  big_decimal partial_remainder = decimal_to_big_decimal(zero_val);
  // Рассчитываемое в алгоритме частное
  big_decimal quotient = decimal_to_big_decimal(zero_val);

  if (binary_equal_zero(num1.decimals[0]) &&
      binary_equal_zero(num1.decimals[1])) {
    // Сначала заполняем результаты для частного случая, когда делимое равно 0
    quotient = decimal_to_big_decimal(zero_val);
    partial_remainder = decimal_to_big_decimal(zero_val);
  } else if (binary_compare_big(num1, num2) == -1) {
    // Затем заполняем результаты для частного случая, когда делимое меньше
    // делителя
    quotient = decimal_to_big_decimal(zero_val);
    partial_remainder = num1;
  } else {
    // В остальных случаях используем деление двоичных чисел методом c
    // восстановлением остатка.

    // Рассчитываем предварительный сдвиг делителя
    int left1 = check_max_bit(num1.decimals[1]);
    if (left1 == -1) {
      left1 = check_max_bit(num1.decimals[0]);
    } else {
      left1 = 128 + left1;
    }

    int left2 = check_max_bit(num2.decimals[1]);
    if (left2 == -1) {
      left2 = check_max_bit(num2.decimals[0]);
    } else {
      left2 = 128 + left2;
    }

    int shift = left1 - left2;

    // Сдвинутый делитель
    big_decimal shifted_divisor = binary_shift_left_big(num2, shift);
    // Делимое для промежуточных расчетов, на первом этапе равно num1
    big_decimal dividend = num1;

    // Флаг необходимости проводить вычитание (Шаг 5 алгоритма).
    // На первой итерации всегда требуется вычитать
    int need_subtraction = 1;

    // Повторяем действия k+1 раз (один раз пп.2-3 алгоритма и k раз пп.4-6)
    while (shift >= 0) {
      // Определяем необходимое действие (Прибавлять или вычитать Сдвинутый
      // делитель)
      if (need_subtraction == 1) {
        partial_remainder = binary_sub_big(dividend, shifted_divisor);
      } else {
        partial_remainder = binary_add_big(dividend, shifted_divisor);
      }

      // Сдвигаем влево на 1 частное и записываем в младший бит результата 1,
      // если старший бит частичного остатка равен 1
      quotient = binary_shift_left_big(quotient, 1);
      if (bit_is_on(partial_remainder.decimals[1], 128 - 1) == 0) {
        quotient.decimals[0] = set_bit(quotient.decimals[0], 0);
      }

      // Рассчитываем делимое для следующей итерации цикла (сдвиг влево на 1
      // частичного остатка)
      dividend = binary_shift_left_big(partial_remainder, 1);

      // Если старший бит частичного остатка равен 0, то на следующей итерации
      // необходимо проводить вычитание (Шаг 5 алгоритма)
      if (bit_is_on(partial_remainder.decimals[1], 128 - 1) == 0) {
        need_subtraction = 1;
      } else {
        need_subtraction = 0;
      }
      --shift;
    }
    // Определяем, требуется ли коррекция остатка (п.8 алгоритма)
    if (bit_is_on(partial_remainder.decimals[1], 128 - 1)) {
      partial_remainder = binary_add_big(partial_remainder, shifted_divisor);
    }
    // Возвращаем на место частичный остаток (п.9 алгоритма)
    partial_remainder =
        binary_shift_right_big(partial_remainder, left1 - left2);
  }

  // Заполняем переменные результата (частное и остаток)
  result = quotient;
  if (remainder != NULL) {
    *remainder = partial_remainder;
  }

  return result;
}

int binary_compare(mo_decimal num1, mo_decimal num2) {
  int result = 0;

  for (int i = 128 - 1; i >= 0; i--) {
    int b1 = bit_is_on(num1, i);
    int b2 = bit_is_on(num2, i);

    if (b1 == 0 && b2 != 0) {
      result = -1;
    }

    if (b1 != 0 && b2 == 0) {
      result = 1;
    }

    if (result != 0) {
      break;
    }
  }

  return result;
}

int binary_compare_big(big_decimal num1, big_decimal num2) {
  int compare = binary_compare(num1.decimals[1], num2.decimals[1]);

  if (compare == 0) {
    compare = binary_compare(num1.decimals[0], num2.decimals[0]);
  }

  return compare;
}

int binary_equal_zero(mo_decimal num) {
  return num.bits[0] == 0 && num.bits[1] == 0 && num.bits[2] == 0 &&
         num.bits[3] == 0;
}

mo_decimal binary_shift_right_one(mo_decimal num) {
  mo_decimal result = zero_val;

  int b3 = bit_is_on_int(num.bits[3], 0);
  unsigned int result3 = num.bits[3];
  result3 = result3 >> 1;
  result.bits[3] = result3;

  int b2 = bit_is_on_int(num.bits[2], 0);
  unsigned int result2 = num.bits[2];
  result2 = result2 >> 1;
  result.bits[2] = result2;

  int b1 = bit_is_on_int(num.bits[1], 0);
  unsigned int result1 = num.bits[1];
  result1 = result1 >> 1;
  result.bits[1] = result1;

  unsigned int result0 = num.bits[0];
  result0 = result0 >> 1;
  result.bits[0] = result0;

  if (b3) {
    result.bits[2] = set_bit_int(result.bits[2], 32 - 1);
  }

  if (b2) {
    result.bits[1] = set_bit_int(result.bits[1], 32 - 1);
  }

  if (b1) {
    result.bits[0] = set_bit_int(result.bits[0], 32 - 1);
  }

  return result;
}

mo_decimal binary_shift_right(mo_decimal num, int shift) {
  mo_decimal result = num;
  while (shift > 0) {
    result = binary_shift_right_one(result);
    --shift;
  }

  return result;
}

big_decimal binary_shift_right_big(big_decimal num, int shift) {
  big_decimal result = num;
  while (shift > 0) {
    int b1 = bit_is_on(result.decimals[1], 0);
    result.decimals[0] = binary_shift_right_one(result.decimals[0]);
    result.decimals[1] = binary_shift_right_one(result.decimals[1]);
    if (b1) {
      result.decimals[0] = set_bit(result.decimals[0], 128 - 1);
    }
    --shift;
  }

  return result;
}

mo_decimal binary_shift_left_one(mo_decimal num) {
  mo_decimal result = zero_val;

  int b0 = bit_is_on_int(num.bits[0], 32 - 1);
  unsigned int result0 = num.bits[0];
  result0 = result0 << 1;
  result.bits[0] = result0;

  int b1 = bit_is_on_int(num.bits[1], 32 - 1);
  unsigned int result1 = num.bits[1];
  result1 = result1 << 1;
  result.bits[1] = result1;

  int b2 = bit_is_on_int(num.bits[2], 32 - 1);
  unsigned int result2 = num.bits[2];
  result2 = result2 << 1;
  result.bits[2] = result2;

  unsigned int result3 = num.bits[3];
  result3 = result3 << 1;
  result.bits[3] = result3;

  if (b0) {
    result.bits[1] = set_bit_int(result.bits[1], 0);
  }

  if (b1) {
    result.bits[2] = set_bit_int(result.bits[2], 0);
  }

  if (b2) {
    result.bits[3] = set_bit_int(result.bits[3], 0);
  }

  return result;
}

mo_decimal binary_shift_left(mo_decimal num, int shift) {
  mo_decimal result = num;
  while (shift > 0) {
    result = binary_shift_left_one(result);
    --shift;
  }

  return result;
}

big_decimal binary_shift_left_big(big_decimal num, int shift) {
  big_decimal result = num;
  while (shift > 0) {
    int b0 = bit_is_on(result.decimals[0], 128 - 1);
    result.decimals[0] = binary_shift_left_one(result.decimals[0]);
    result.decimals[1] = binary_shift_left_one(result.decimals[1]);
    if (b0) {
      result.decimals[1] = set_bit(result.decimals[1], 0);
    }
    --shift;
  }

  return result;
}

int get_sign(mo_decimal num) { return (num.bits[3] >> 31) & 1; }

int get_scale(mo_decimal num) { return (num.bits[3] >> 16) & 0xFF; }

int get_shift_to_decimal(big_decimal num) {
  int cnt = 0;

  // Если num содержит только нули, то расчет не производим, резльтат - 0
  if (!(binary_equal_zero(num.decimals[0]) &&
        binary_equal_zero(num.decimals[1]))) {
    // Максимальное 96битное число
    big_decimal max = decimal_to_big_decimal(max_val);
    // Находим число, во сколько раз value больше максимального 96битного числа
    big_decimal quotient = binary_div_big(num, max, NULL);

    // Перебираем все степени 10, чтобы найти ближайшую большую степень, чем
    // quotient делаем так, потому что это гораздо быстрее, чем делить на 10 в
    // цикле
    while (1) {
      int compare = binary_compare(quotient.decimals[0], ten_pows[cnt]);
      if (compare == -1 || compare == 0) {
        break;
      }
      ++cnt;
    }

    // Проверяем, что value впишется в 96 бит, если поделить на 10 в найденной
    // степени
    big_decimal tmp =
        binary_div_big(num, decimal_to_big_decimal(ten_pows[cnt]), NULL);
    // Если не помещается, то берем следующую степень
    if (!binary_equal_zero(tmp.decimals[1]) || tmp.decimals[0].bits[3] != 0) {
      ++cnt;
    }
  }

  return cnt;
}

int check_max_bit(mo_decimal num) {
  int result = -1;
  for (int i = 128 - 1; i >= 0; i--) {
    if (bit_is_on(num, i)) {
      result = i;
      break;
    }
  }

  return result;
}

void set_sign(mo_decimal *num, int sign) {
  num->bits[3] = (num->bits[3] & 0x7FFFFFFF) | ((sign & 1U) << 31);
}

void set_scale(mo_decimal *num, int scale) { num->bits[3] |= scale << 16; }

int set_bit_int(int number, int index) { return number | (1U << index); }

mo_decimal set_bit(mo_decimal num, int index) {
  num.bits[index / 32] = set_bit_int(num.bits[index / 32], index % 32);
  return num;
}

int is_correct_decimal(mo_decimal num) {
  int code = 1;

  if ((num.bits[3] & 0xFFFF) != 0 ||
      ((num.bits[3] >> 24) & 0x7F) !=
          0) {  // Биты от 0 до 15 и от 24 по 30 не используются и должны быть
    // равны нулю.
    code = 0;
  } else {
    int scale = get_scale(num);
    if (scale < 0 || scale > 28) {
      code = 0;
    }
  }

  return code;
}

int bit_is_on(mo_decimal num, int index) {
  return !!(num.bits[index / 32] & (1U << index % 32));
}

int bit_is_on_int(int number, int index) { return !!(number & (1U << index)); }

char *decimal_to_string(mo_decimal num) {
  __int128_t res = 0;
  int sign = get_sign(num);
  int scale = get_scale(num);
  int k = 0;
  char *str = calloc(32, sizeof(char));
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 31; j++) {
      res = res + ((num.bits[i] >> j) & 1) * (__int128_t)pow(2, k);
      k++;
    }
  }
  int count = 0;
  int data[29] = {0};
  while (res) {
    data[count] = res % 10;
    count++;
    res /= 10;
  }
  if (count <= 0) {
    str[0] = '0';
  } else {
    if (scale >= count) {
      count = scale + 1;
    }

    for (int i = 0; count > 0; count--, i++) {
      if (sign && i == 0) {
        str[i] = '-';
        i++;
      }
      if (count == scale) {
        str[i] = '.';
        i++;
      }
      str[i] = data[count - 1] + '0';
    }
  }
  return str;
}

big_decimal decimal_to_big_decimal(mo_decimal num) {
  big_decimal result = {{zero_val, zero_val}};
  num.bits[3] = 0;
  result.decimals[0] = num;
  return result;
}

int float_exp_from_string(char *str) {
  int result = 0;
  char *ptr = str;
  while (*ptr) {
    if (*ptr == 'E') {
      ++ptr;
      result = strtol(ptr, NULL, 10);
      break;
    }
    ++ptr;
  }

  return result;
}

mo_decimal float_string_to_decimal(char *str) {
  int digits_counter = 27;
  mo_decimal result = zero_val;
  char *ptr = str;

  // Получаем в любом случае заново степень float из научной записи, а не
  // передаем полученную ранее в mo_from_float_to_decimal, т.к. она могла
  // измениться из-за округления
  int exp = float_exp_from_string(str);

  while (*ptr) {
    if (*ptr == '.') {
      // Точку игнорируем, итоговую степень decimal мы будем отдельно считать
      ++ptr;
      continue;
    } else if (*ptr >= '0' && *ptr <= '9') {
      // Переводим цифры в строке в decimal, начиная с первой, используя
      // арифметику decimal
      mo_decimal tmp = zero_val;
      mo_mul(decimal_from_char(*ptr), ten_pows[digits_counter], &tmp);
      mo_add(result, tmp, &result);
      --digits_counter;
      ++ptr;
    } else {
      break;
    }
  }
  // Учитываем, что в научной записи степень уже сдвинутая, чтобы далее
  // корректно выставить степень decimal
  exp = exp - 27;

  if (exp > 0) {
    // Для положительной степени производим умножение на 10^exp
    mo_mul(result, ten_pows[exp], &result);
  } else if (exp < 0) {
    // Для отрицательной степени производим деление на 10^exp
    if (exp < -28) {
      // Отдельно обрабатываем очень маленькие степени, т.к. мы не сможем
      // поделить больше чем на 10^28
      mo_div(result, ten_pows[28], &result);
      exp += 28;
    }
    mo_div(result, ten_pows[-exp], &result);
  }

  return result;
}

mo_decimal decimal_from_char(char c) {
  mo_decimal result;

  switch (c) {
    case '0':
      result = zero_val;
      break;
    case '1':
      result = one_val;
      break;
    case '2':
      mo_from_int_to_decimal(2, &result);
      break;
    case '3':
      mo_from_int_to_decimal(3, &result);
      break;
    case '4':
      mo_from_int_to_decimal(4, &result);
      break;
    case '5':
      mo_from_int_to_decimal(5, &result);
      break;
    case '6':
      mo_from_int_to_decimal(6, &result);
      break;
    case '7':
      mo_from_int_to_decimal(7, &result);
      break;
    case '8':
      mo_from_int_to_decimal(8, &result);
      break;
    case '9':
      mo_from_int_to_decimal(9, &result);
      break;
  }

  return result;
}


void print_decimal(mo_decimal num) {
  for (int i = 3; i >= 0; i--) print_binary(num.bits[i]);
  printf("\n");
}

void print_binary(unsigned int num) {
  for (int i = 31; i >= 0; i--) {
    printf("%u", (num >> i) & 1);
    if (i % 32 == 0) printf("  ");
    if (i % 8 == 0) printf(" ");
  }
}

void print_big_decimal(big_decimal num) {
  for (int i = 1; i >= 0; i--) print_decimal(num.decimals[i]);
}

void scaling(mo_decimal value_1, mo_decimal value_2, big_decimal *value_1b,
             big_decimal *value_2b, int scale1, int scale2) {
  mo_decimal tmp1 = value_1;
  mo_decimal tmp2 = value_2;

  tmp1.bits[3] = 0;
  tmp2.bits[3] = 0;

  if (scale1 > scale2) {
    *value_1b = decimal_to_big_decimal(tmp1);
    *value_2b = binary_mul(tmp2, ten_pows[scale1 - scale2]);
  } else if (scale1 < scale2) {
    *value_1b = binary_mul(tmp1, ten_pows[scale2 - scale1]);
    *value_2b = decimal_to_big_decimal(tmp2);
  } else {
    *value_1b = decimal_to_big_decimal(tmp1);
    *value_2b = decimal_to_big_decimal(tmp2);
  }
}

int addition(mo_decimal value_1, mo_decimal value_2, mo_decimal *result) {
  int code = 0;
  int max_power = 0;
  big_decimal value_1b;
  big_decimal value_2b;
  int scale1 = get_scale(value_1);
  int scale2 = get_scale(value_2);
  max_power = (scale1 > scale2) ? scale1 : scale2;

  // Выравниваем масштаб операндов, убираем знак и масштаб, переводим в формат
  // big_decimal.
  scaling(value_1, value_2, &value_1b, &value_2b, scale1, scale2);

  // Производим бинарное сложение двух преобразованных чисел
  big_decimal res = binary_add_big(value_1b, value_2b);

  // Рассчитываем, на сколько необходимо поделить результат, чтобы вписать его в
  // 96бит числа decimal
  int shift = get_shift_to_decimal(res);
  // Рассчитываем степень будущего результата
  int res_power = max_power - shift;

  if (res_power < 0) {
    // Анализируем степень результата на корректность
    code = 1;
    //   *result = mo_decimal_get_inf();
  } else {
    // Если результат надо делить более, чем на 10^28, то уменьшаем его, чтобы
    // далее делить на 10^28
    while (shift > 28) {
      res = binary_div_big(res, decimal_to_big_decimal(ten_val), NULL);
      --shift;
    }

    big_decimal remainder = decimal_to_big_decimal(zero_val);
    big_decimal powerten = decimal_to_big_decimal(ten_pows[shift]);

    // Уменьшаем результат, чтобы он поместился в 96бит числа decimal
    // remainder - остаток от деления при этом
    res = binary_div_big(res, powerten, &remainder);
    // Устанавливаем для остатка степень, чтобы выполнить банковское округление
    // чисел decimal
    set_scale(&remainder.decimals[0], shift);
    // Выполняем банковское округления результата, исходя из остатка от деления
    // remainder
    res.decimals[0] = round_banking(res.decimals[0], remainder.decimals[0]);
    // Устанавливаем степень результата
    set_scale(&res.decimals[0], res_power);

    // Анализируем результат на корректность (переполнение)
    if (!binary_equal_zero(res.decimals[1]) ||
        !is_correct_decimal(res.decimals[0])) {
      code = 1;
      // *result = mo_decimal_get_inf();
    } else {
      *result = res.decimals[0];
    }
  }

  return code;
}

mo_decimal abs_val(mo_decimal num) {
  mo_decimal result = num;
  set_sign(&result, 0);
  return result;
}

mo_decimal remove_trailing_zeros(mo_decimal value) {
  mo_decimal result = value;
  int power = get_scale(value);
  int sign = get_sign(value);

  if (power > 0 && is_correct_decimal(value)) {
    mo_decimal remainder = zero_val;
    mo_decimal tmp = value;
    tmp.bits[3] = 0;

    // Делим число на 10, уменьшая степень decimal, до тех пор, пока остаток от
    // деления равен нулю
    while (power > 0) {
      tmp = binary_div(tmp, ten_pows[1], &remainder);
      if (binary_equal_zero(remainder)) {
        --power;
        result = tmp;
      } else {
        break;
      }
    }
    set_scale(&result, power);
    set_sign(&result, sign);
  }

  return result;
}

int less(mo_decimal value_1, mo_decimal value_2) {
  int code = 0;
  mo_decimal tmp1 = value_1;
  mo_decimal tmp2 = value_2;
  big_decimal tmp1l;
  big_decimal tmp2l;
  int scale1 = get_scale(value_1);
  int scale2 = get_scale(value_2);

  // Выравниваем степени слагаемых (знак и степень при этом будут обнулены)
  scaling(tmp1, tmp2, &tmp1l, &tmp2l, scale1, scale2);

  // Сравниваем выравненные числа
  int compare = binary_compare_big(tmp1l, tmp2l);

  if (compare == -1) {
    code = 1;
  } else {
    code = 0;
  }

  return code;
}

mo_decimal round_banking(mo_decimal integral, mo_decimal fractional) {
  mo_decimal zero_dot_five = zero_dot_five_val;
  mo_decimal result;

  if (mo_is_equal(fractional, zero_dot_five)) {
    // Если дробная часть ровно 0.5
    if ((integral.bits[0] & 1) != 1) {
      // Если целая часть четная, то оставляем её
      result = integral;
    } else {
      // Если целая часть нечетная, то увеличиваем её на 1
      result = binary_add(integral, one_val);
    }
  } else if (mo_is_greater(fractional, zero_dot_five)) {
    // Если дробная часть > 0.5, то увеличиваем целую часть на 1
    result = binary_add(integral, one_val);
  } else {
    // Если дробная часть < 0.5, то оставляем целую часть без изменений
    result = integral;
  }

  return result;
}

int subtraction(mo_decimal num1, mo_decimal num2, mo_decimal *result) {
  int code = 0;
  int max_power;
  big_decimal value_1b;
  big_decimal value_2b;
  int scale1 = get_scale(num1);
  int scale2 = get_scale(num2);
  max_power = (scale1 > scale2) ? scale1 : scale2;

  // Выравниваем степени уменьшаемого и вычитаемого (знак и степень при этом
  // будут обнулены)
  scaling(num1, num2, &value_1b, &value_2b, scale1, scale2);
  // Вычитаем выравненные уменьшаемое и вычитаемое как два огромных целых числа
  big_decimal res = binary_sub_big(value_1b, value_2b);
  // Рассчитываем, на сколько необходимо поделить результат, чтобы вписать его в
  // 96бит числа decimal
  int shift = get_shift_to_decimal(res);
  // Рассчитываем степень будущего результата
  int res_power = max_power - shift;

  if (res_power < 0) {
    // Анализируем степень результата на корректность
    code = 1;
    //  *result = mo_decimal_get_inf();
  } else {
    big_decimal remainder = decimal_to_big_decimal(zero_val);
    big_decimal powerten = decimal_to_big_decimal(ten_pows[shift]);

    // Уменьшаем результат, чтобы он поместился в 96бит числа decimal
    // remainder - остаток от деления при этом
    res = binary_div_big(res, powerten, &remainder);
    // Устанавливаем для остатка степень, чтобы выполнить банковское округление
    // чисел decimal
    set_scale(&remainder.decimals[0], shift);
    // Выполняем банковское округления результата, исходя из остатка от деления
    // remainder
    res.decimals[0] = round_banking(res.decimals[0], remainder.decimals[0]);
    // Устанавливаем степень результата
    set_scale(&res.decimals[0], res_power);

    *result = res.decimals[0];
  }

  return code;
}

int multiplication(mo_decimal num1, mo_decimal num2, mo_decimal *result) {
  int code = 0;
  int power1 = get_scale(num1);
  int power2 = get_scale(num2);

  // зануляем степени чисел (степени получим в конце, анализируя входные данные)
  num1.bits[3] = 0;
  num2.bits[3] = 0;

  // Перемножаем множители без степеней как два огромных целых числа
  big_decimal res = binary_mul(num1, num2);

  // Рассчитываем, на сколько необходимо поделить результат, чтобы вписать его в
  // 96бит числа decimal
  int shift = get_shift_to_decimal(res);
  // Рассчитываем степень будущего результата
  int res_power = power1 + power2 - shift;

  if (res_power < 0) {
    // Анализируем степень результата на корректность
    code = 1;
    //  *result = mo_decimal_get_inf();
  } else {
    // Если результат надо делить более, чем на 10^28, то уменьшаем его, чтобы
    // далее делить на 10^28
    while (shift > 28) {
      res = binary_div_big(res, decimal_to_big_decimal(ten_val), NULL);
      --shift;
    }

    // Если слишком много цифр после запятой получается в результате, то
    // корректируем результат
    if (res_power > 28) {
      big_decimal tmp = res;
      int tmp_power = res_power;
      while (tmp_power > 28) {
        tmp = binary_div_big(tmp, decimal_to_big_decimal(ten_val), NULL);
        --tmp_power;
      }
      shift = res_power - tmp_power + shift;
      res_power = tmp_power;
    }

    big_decimal remainder = decimal_to_big_decimal(zero_val);
    big_decimal powerten = decimal_to_big_decimal(ten_pows[shift]);

    // Уменьшаем результат, чтобы он поместился в 96бит числа decimal
    // remainder - остаток от деления при этом
    res = binary_div_big(res, powerten, &remainder);
    // Устанавливаем для остатка степень, чтобы выполнить банковское округление
    // чисел decimal
    set_scale(&remainder.decimals[0], shift);
    // Выполняем банковское округления результата, исходя из остатка от деления
    // remainder
    res.decimals[0] = round_banking(res.decimals[0], remainder.decimals[0]);
    // Устанавливаем степень результата
    set_scale(&res.decimals[0], res_power);

    // Анализируем результат на корректность (переполнение)
    if (!binary_equal_zero(res.decimals[1]) ||
        !is_correct_decimal(res.decimals[0])) {
      code = 1;
      //  *result = mo_decimal_get_inf();
    } else {
      *result = res.decimals[0];
    }
  }

  return code;
}

int division(big_decimal value_2b, big_decimal res, big_decimal remainder,
             mo_decimal *result) {
  int code = 0;

  // рассчитываем дробную часть нашего результата и получаем в res результат,
  // включая дробную часть после расчетов в remainder останется остаток от
  // деления (который не поместился в дробную часть) power1 - значение степени
  // результата
  int power1 = calc_fractional(&res, value_2b, &remainder);

  big_decimal tmp_res = decimal_to_big_decimal(zero_val);
  // Переводи остаток, полученный в расчете выше, в decimal, чтобы использовать
  // его для округления power2 - значение степени данного decimal
  int power2 = calc_fractional(&tmp_res, value_2b, &remainder);

  // Устанавливаем полученную степень для нашего остатка
  set_scale(&tmp_res.decimals[0], power2);

  if (mo_is_equal(tmp_res.decimals[0], zero_dot_five_val)) {
    if (!binary_equal_zero(remainder.decimals[0]) ||
        !binary_equal_zero(remainder.decimals[1])) {
      // Если остаток от деления в виде decimal получился ровно 0.5, но после
      // вычисления остаток от деления не равен 0, то корректируем остаток, т.к.
      // фактически он больше 0.5: 0.5 + 0.0000000000000000000000000001 =
      // 0.5000000000000000000000000001
      mo_add(tmp_res.decimals[0], min_val, &tmp_res.decimals[0]);
    }
  }
  // Выполняем банковское округления результата, исходя из остатка от деления
  res.decimals[0] = round_banking(res.decimals[0], tmp_res.decimals[0]);
  // Устанавливаем степень результата
  set_scale(&res.decimals[0], power1);
  // Анализируем результат на корректность (переполнение)
  if (!binary_equal_zero(res.decimals[1]) ||
      !is_correct_decimal(res.decimals[0])) {
    code = 1;
    //  *result = mo_decimal_get_inf();
  } else {
    *result = res.decimals[0];
  }

  return code;
}

int calc_fractional(big_decimal *res, big_decimal value_2b,
                    big_decimal *remainder) {
  int power = 0;
  big_decimal number = *res;

  big_decimal tmp;
  big_decimal tmp_remainder = *remainder;

  // Производим расчеты пока остаток не будет полностью равен нулю или пока
  // степень не станет максимально допустимой (28)
  while ((!binary_equal_zero((*remainder).decimals[0]) ||
          !binary_equal_zero((*remainder).decimals[1])) &&
         power < 28) {
    // Сохраняем значения полученных числа и остатка перед дальнейшей итерацией
    // расчетов, чтобы вернуть эти значения в случае переполнения
    big_decimal number_stored = number;
    big_decimal remainder_stored = tmp_remainder;

    // Производим расчеты
    number = binary_mul_big(number, ten_val);
    tmp_remainder = binary_mul_big(tmp_remainder, ten_val);
    tmp = binary_div_big(tmp_remainder, value_2b, &tmp_remainder);
    number = binary_add_big(number, tmp);

    // Возвращаем предварительно сохраненные число и остаток, если произошло
    // переполнение при расчете
    if (!is_correct_decimal(number.decimals[0])) {
      number = number_stored;
      tmp_remainder = remainder_stored;
      break;
    }

    ++power;
  }

  *res = number;
  *remainder = tmp_remainder;

  return power;
}
void decimal_round(mo_decimal *num) {
  mo_decimal integer = zero_val;
  mo_decimal fraction = zero_val;
  float float_fraction = 0;
  char float_str[64];

  mo_truncate(*num, &integer);
  mo_sub(*num, integer, &fraction);
  mo_from_decimal_to_float(fraction, &float_fraction);

  float multiplier = pow(10, 6);
  float_fraction = roundf(float_fraction * multiplier) / multiplier;

  sprintf(float_str, "%.6E", fabsf(float_fraction));
  fraction = float_string_to_decimal(float_str);

  mo_add(fraction, integer, num);
}