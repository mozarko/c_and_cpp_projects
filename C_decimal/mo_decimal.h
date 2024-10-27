#ifndef mo_DECIMAL_H
#define mo_DECIMAL_H

#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct mo_decimal {
  unsigned int bits[4];
} mo_decimal;

typedef struct big_decimal {
  mo_decimal decimals[2];
} big_decimal;

#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

static const mo_decimal zero_val = {{0, 0, 0, 0}};
static const mo_decimal one_val = {{1, 0, 0, 0}};
static const mo_decimal ten_val = {{10, 0, 0, 0}};
static const mo_decimal max_val = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
static const mo_decimal zero_dot_five_val = {{5, 0, 0, 0x10000}};
static const mo_decimal min_val = {{0x1, 0x0, 0x0, 0x1C0000}};
static const mo_decimal max_int_val = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
static const mo_decimal min_int_val = {{0x80000000, 0x0, 0x0, 0x80000000}};

static const mo_decimal ten_pows[39] = {
    [0] = {{0x1, 0x0, 0x0, 0x0}},
    [1] = {{0xA, 0x0, 0x0, 0x0}},
    [2] = {{0x64, 0x0, 0x0, 0x0}},
    [3] = {{0x3E8, 0x0, 0x0, 0x0}},
    [4] = {{0x2710, 0x0, 0x0, 0x0}},
    [5] = {{0x186A0, 0x0, 0x0, 0x0}},
    [6] = {{0xF4240, 0x0, 0x0, 0x0}},
    [7] = {{0x989680, 0x0, 0x0, 0x0}},
    [8] = {{0x5F5E100, 0x0, 0x0, 0x0}},
    [9] = {{0x3B9ACA00, 0x0, 0x0, 0x0}},
    [10] = {{0x540BE400, 0x2, 0x0, 0x0}},
    [11] = {{0x4876E800, 0x17, 0x0, 0x0}},
    [12] = {{0xD4A51000, 0xE8, 0x0, 0x0}},
    [13] = {{0x4E72A000, 0x918, 0x0, 0x0}},
    [14] = {{0x107A4000, 0x5AF3, 0x0, 0x0}},
    [15] = {{0xA4C68000, 0x38D7E, 0x0, 0x0}},
    [16] = {{0x6FC10000, 0x2386F2, 0x0, 0x0}},
    [17] = {{0x5D8A0000, 0x1634578, 0x0, 0x0}},
    [18] = {{0xA7640000, 0xDE0B6B3, 0x0, 0x0}},
    [19] = {{0x89E80000, 0x8AC72304, 0x0, 0x0}},
    [20] = {{0x63100000, 0x6BC75E2D, 0x5, 0x0}},
    [21] = {{0xDEA00000, 0x35C9ADC5, 0x36, 0x0}},
    [22] = {{0xB2400000, 0x19E0C9BA, 0x21E, 0x0}},
    [23] = {{0xF6800000, 0x2C7E14A, 0x152D, 0x0}},
    [24] = {{0xA1000000, 0x1BCECCED, 0xD3C2, 0x0}},
    [25] = {{0x4A000000, 0x16140148, 0x84595, 0x0}},
    [26] = {{0xE4000000, 0xDCC80CD2, 0x52B7D2, 0x0}},
    [27] = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x0}},
    [28] = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}},
    [29] = {{0xA0000000, 0x6D7217CA, 0x431E0FAE, 0x1}},
    [30] = {{0x40000000, 0x4674EDEA, 0x9F2C9CD0, 0xC}},
    [31] = {{0x80000000, 0xC0914B26, 0x37BE2022, 0x7E}},
    [32] = {{0x0, 0x85ACEF81, 0x2D6D415B, 0x4EE}},
    [33] = {{0x0, 0x38C15B0A, 0xC6448D93, 0x314D}},
    [34] = {{0x0, 0x378D8E64, 0xBEAD87C0, 0x1ED09}},
    [35] = {{0x0, 0x2B878FE8, 0x72C74D82, 0x134261}},
    [36] = {{0x0, 0xB34B9F10, 0x7BC90715, 0xC097CE}},
    [37] = {{0x0, 0xF436A0, 0xD5DA46D9, 0x785EE10}},
    [38] = {{0x0, 0x98A2240, 0x5A86C47A, 0x4B3B4CA8}}};

/*-----------------Функции по проекту---------------*/

// Arithmetic Operators
int mo_add(mo_decimal value_1, mo_decimal value_2, mo_decimal *result);
int mo_sub(mo_decimal value_1, mo_decimal value_2, mo_decimal *result);
int mo_mul(mo_decimal value_1, mo_decimal value_2, mo_decimal *result);
int mo_div(mo_decimal value_1, mo_decimal value_2, mo_decimal *result);

// Comparison Operators
int mo_is_less(mo_decimal, mo_decimal);
int mo_is_less_or_equal(mo_decimal, mo_decimal);
int mo_is_greater(mo_decimal, mo_decimal);
int mo_is_greater_or_equal(mo_decimal, mo_decimal);
int mo_is_equal(mo_decimal, mo_decimal);
int mo_is_not_equal(mo_decimal, mo_decimal);

// Convertors and parsers
int mo_from_int_to_decimal(int src, mo_decimal *dst);
int mo_from_float_to_decimal(float src, mo_decimal *dst);
int mo_from_decimal_to_int(mo_decimal src, int *dst);
int mo_from_decimal_to_float(mo_decimal src, float *dst);

// Other functions
int mo_floor(mo_decimal value, mo_decimal *result);
int mo_round(mo_decimal value, mo_decimal *result);
int mo_truncate(mo_decimal value, mo_decimal *result);
int mo_negate(mo_decimal value, mo_decimal *result);

/*---------------------Вспомогательные функции---------------------*/

//Арифметические
int addition(mo_decimal value_1, mo_decimal value_2, mo_decimal *result);
int subtraction(mo_decimal num1, mo_decimal num2, mo_decimal *result);
int division(big_decimal value_2b, big_decimal res, big_decimal remainder,
             mo_decimal *result);
int multiplication(mo_decimal num1, mo_decimal num2, mo_decimal *result);

//Бинарные
mo_decimal binary_sub(mo_decimal num1, mo_decimal num2);
big_decimal binary_sub_big(big_decimal num1, big_decimal num2);
mo_decimal binary_add(mo_decimal num1, mo_decimal num2);
big_decimal binary_add_big(big_decimal num1, big_decimal num2);
mo_decimal binary_xor(mo_decimal num1, mo_decimal num2);
mo_decimal binary_and(mo_decimal num1, mo_decimal num2);
big_decimal binary_mul(mo_decimal num1, mo_decimal num2);
big_decimal binary_mul_big(big_decimal num1, mo_decimal num2);
mo_decimal binary_not(mo_decimal num);
mo_decimal binary_div(mo_decimal num1, mo_decimal num2,
                       mo_decimal *remainder);
big_decimal binary_div_big(big_decimal num1, big_decimal num2,
                           big_decimal *remainder);
int binary_compare(mo_decimal num1, mo_decimal num2);
int binary_compare_big(big_decimal num1, big_decimal num2);
int binary_equal_zero(mo_decimal num);
mo_decimal binary_shift_right_one(mo_decimal num);
mo_decimal binary_shift_right(mo_decimal num, int shift);
big_decimal binary_shift_right_big(big_decimal num, int shift);
mo_decimal binary_shift_left_one(mo_decimal num);
mo_decimal binary_shift_left(mo_decimal num, int shift);
big_decimal binary_shift_left_big(big_decimal num, int shift);

//Геттеры
int get_sign(mo_decimal num);
int get_scale(mo_decimal num);
int get_shift_to_decimal(big_decimal num);
int check_max_bit(mo_decimal num);

//Сеттеры
void set_sign(mo_decimal *num, int sign);
void set_scale(mo_decimal *num, int scale);
int set_bit_int(int number, int index);
mo_decimal set_bit(mo_decimal num, int index);

//Булевы
int is_correct_decimal(mo_decimal num);
int bit_is_on(mo_decimal num, int index);
int bit_is_on_int(int number, int index);

//Конверторы
char *decimal_to_string(mo_decimal num);
big_decimal decimal_to_big_decimal(mo_decimal num);
int float_exp_from_string(char *str);
mo_decimal float_string_to_decimal(char *str);
mo_decimal decimal_from_char(char c);

//Печать
void print_decimal(mo_decimal num);
void print_binary(unsigned int num);
void print_big_decimal(big_decimal num);

//Другие
void scaling(mo_decimal value_1, mo_decimal value_2, big_decimal *value_1b,
             big_decimal *value_2b, int scale1, int scale2);  // масштабирование
mo_decimal abs_val(mo_decimal num);                         // модуль
mo_decimal remove_trailing_zeros(mo_decimal value);  // удаление нулей в конце
int less(mo_decimal value_1, mo_decimal value_2);  // сравнение
mo_decimal round_banking(mo_decimal integral,
                          mo_decimal fractional);  // банковское округление
int calc_fractional(big_decimal *res, big_decimal value_2b,
                    big_decimal *remainder);  // вычисление дробной части
void decimal_round(mo_decimal *num);  // округление дробной части

#endif