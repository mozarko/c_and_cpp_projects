#include "../tests_includes/s21_tests.h"

START_TEST(test_mul_simple1) {
  s21_decimal decimal1 = {{0x5, 0, 0, 0}};
  s21_decimal decimal2 = {{0x8, 0, 0, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), "40");
}
END_TEST

START_TEST(test_mul_simple2) {
  int simple_decimal1 = 580;
  int simple_decimal2 = 98807;
  int res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  s21_decimal decimal1 = {{simple_decimal1, 0, 0, 0}};
  s21_decimal decimal2 = {{simple_decimal2, 0, 0, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple3) {
  int simple_decimal1 = 5879;
  int simple_decimal2 = 988;
  int res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  s21_decimal decimal1 = {{simple_decimal1, 0, 0, 0}};
  s21_decimal decimal2 = {{simple_decimal2, 0, 0, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple4) {
  int simple_decimal1 = 0;
  int simple_decimal2 = 654498797;
  int res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  s21_decimal decimal1 = {{simple_decimal1, 0, 0, 0}};
  s21_decimal decimal2 = {{simple_decimal2, 0, 0, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple5) {
  int simple_decimal1 = 775604;
  int simple_decimal2 = 0;
  int res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  s21_decimal decimal1 = {{simple_decimal1, 0, 0, 0}};
  s21_decimal decimal2 = {{simple_decimal2, 0, 0, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_neg1) {
  int simple_decimal1 = -5604;
  int simple_decimal2 = 578;
  int simple_decimal1_neg = simple_decimal1 * -1;
  int res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  s21_decimal decimal1 = {{simple_decimal1_neg, 0, 0, 0x80000000}};
  s21_decimal decimal2 = {{simple_decimal2, 0, 0, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_neg2) {
  int simple_decimal1 = -7704;
  int simple_decimal2 = -56;
  int simple_decimal1_neg = simple_decimal1 * -1;
  int simple_decimal2_neg = simple_decimal2 * -1;
  int res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  s21_decimal decimal1 = {{simple_decimal1_neg, 0, 0, 0x80000000}};
  s21_decimal decimal2 = {{simple_decimal2_neg, 0, 0, 0x80000000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_neg3) {
  int simple_decimal1 = 704;
  int simple_decimal2 = -578;
  int simple_decimal2_neg = simple_decimal2 * -1;
  int res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  s21_decimal decimal1 = {{simple_decimal1, 0, 0, 0}};
  s21_decimal decimal2 = {{simple_decimal2_neg, 0, 0, 0x80000000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_check_code1) {
  s21_decimal decimal1 = {{0x5, 0, 0, 0}};
  s21_decimal decimal2 = {{0x8, 0, 0, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_mul_simple_check_code2) {
  s21_decimal decimal1 = {{85070, 0, 0, 0}};
  s21_decimal decimal2 = {{798, 0, 0, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_mul_simple_check_code3) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{798, 0, 0, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_mul_simple_check_code4) {
  s21_decimal decimal1 = {{86798, 0, 0, 0}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_mul_simple_check_code5) {
  s21_decimal decimal1 = {{86798, 0, 0, 0x80000000}};
  s21_decimal decimal2 = {{0, 0, 0, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_mul_simple_check_code6) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{484456, 0, 0, 0x80000000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_mul_simple_check_code7) {
  s21_decimal decimal1 = {{845664, 0, 0, 0x80000000}};
  s21_decimal decimal2 = {{484456, 0, 0, 0x80000000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_mul_simple_float_equal_small_pow1) {
  double simple_decimal1 = 77.56;
  double simple_decimal2 = 589.12;
  double res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.4f", res);

  s21_decimal decimal1 = {{7756, 0, 0, 0x20000}};
  s21_decimal decimal2 = {{58912, 0, 0, 0x20000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_float_equal_small_pow2) {
  double simple_decimal1 = 0.56;
  double simple_decimal2 = 0.12;
  double res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.4f", res);

  s21_decimal decimal1 = {{56, 0, 0, 0x20000}};
  s21_decimal decimal2 = {{12, 0, 0, 0x20000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_float_equal_small_pow3) {
  double simple_decimal1 = 0.56;
  double simple_decimal2 = 58798.12;
  double res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.4f", res);

  s21_decimal decimal1 = {{56, 0, 0, 0x20000}};
  s21_decimal decimal2 = {{5879812, 0, 0, 0x20000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_float_equal_small_pow4) {
  double simple_decimal1 = 549879.55;
  double simple_decimal2 = 0.12;
  double res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.4f", res);

  s21_decimal decimal1 = {{54987955, 0, 0, 0x20000}};
  s21_decimal decimal2 = {{12, 0, 0, 0x20000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_float_neg_equal_small_pow1) {
  double simple_decimal1 = -549879.55;
  double simple_decimal2 = 0.12;
  double res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.4f", res);

  s21_decimal decimal1 = {{54987955, 0, 0, 0x80020000}};
  s21_decimal decimal2 = {{12, 0, 0, 0x20000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_float_neg_equal_small_pow2) {
  double simple_decimal1 = 549879.55;
  double simple_decimal2 = -0.12;
  double res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.4f", res);

  s21_decimal decimal1 = {{54987955, 0, 0, 0x20000}};
  s21_decimal decimal2 = {{12, 0, 0, 0x80020000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_float_neg_equal_small_pow3) {
  double simple_decimal1 = -549879.55;
  double simple_decimal2 = -0.12;
  double res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.4f", res);

  s21_decimal decimal1 = {{54987955, 0, 0, 0x80020000}};
  s21_decimal decimal2 = {{12, 0, 0, 0x80020000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);
  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_float_diff_small_pow1) {
  double simple_decimal1 = 78.569874;
  double simple_decimal2 = 9.48;
  double res = simple_decimal1 * simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.8f", res);

  s21_decimal decimal1 = {{78569874, 0, 0, 0x60000}};
  s21_decimal decimal2 = {{948, 0, 0, 0x20000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_simple_float_diff_small_pow2) {
  char res_to_str[50] = "745.01884831464432";

  s21_decimal decimal1 = {{78569874, 0, 0, 0x60000}};
  s21_decimal decimal2 = {{948224568, 0, 0, 0x80000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}

END_TEST

START_TEST(test_mul_simple_float_neg_diff_small_pow1) {
  char res_to_str[50] = "-745.01884831464432";

  s21_decimal decimal1 = {{78569874, 0, 0, 0x80060000}};
  s21_decimal decimal2 = {{948224568, 0, 0, 0x80000}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal1) {
  int decimal1_1 = 0b100001000;
  int decimal1_2 = 0b1110011100;
  int decimal1_3 = 0b10001;

  int decimal2_1 = 0b1011111001111;
  int decimal2_2 = 0b1111000011100011;
  int decimal2_3 = 0b1111111111;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_mul_decimal2) {
  int decimal1_1 = 0b10111110001000;
  int decimal1_2 = 0b1110011100;
  int decimal1_3 = 0b100111101;

  int decimal2_1 = 0b1011110001001111;
  int decimal2_2 = 0b111001000011100011;
  int decimal2_3 = 0b1111100011111;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_mul_decimal3) {
  int decimal1_1 = 0b1000011111000;
  int decimal1_2 = 0b11100;
  int decimal1_3 = 0b101;

  int decimal2_1 = 0b101001111;
  int decimal2_2 = 0b1111100011;
  int decimal2_3 = 0b111111001;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_mul_decimal_overbig1) {
  int decimal1_1 = 0b11111111111111111111111100001000;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b1011111001111;
  int decimal2_2 = 0b1111000011100011;
  int decimal2_3 = 0b1111111111;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_mul_decimal_overbig2) {
  int decimal1_1 = 0b11111111111111111111111100001000;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b101111111111111001111;
  int decimal2_2 = 0b111100001111111111100011;
  int decimal2_3 = 0b1111111111111111111;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_mul_decimal_overbig3) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b101111111111111001111;
  int decimal2_2 = 0b111100001111111111100011;
  int decimal2_3 = 0b1111111111111111111;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_mul_decimal_overbig4) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;

  int decimal2_1 = 0b11111111111111111111111111111111;
  int decimal2_2 = 0b11111111111111111111111111111111;
  int decimal2_3 = 0b11111111111111111111111111111111;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_mul_decimal_overbig5) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  char res_to_str[] = "0";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0x80000000}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);
  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_overbig1_neg) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b101111111111111001111;
  int decimal2_2 = 0b111100001111111111100011;
  int decimal2_3 = 0b1111111111111111111;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0x80000000}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0x80000000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_mul_decimal_overbig2_neg) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;

  int decimal2_1 = 0b11111111111111111111111111111111;
  int decimal2_2 = 0b11111111111111111111111111111111;
  int decimal2_3 = 0b11111111111111111111111111111111;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0x80000000}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0x80000000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_mul_decimal_big1_neg) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b101111111111111001111;
  int decimal2_2 = 0b111100001111111111100011;
  int decimal2_3 = 0b1111111111111111111;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0x80000000}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(test_mul_decimal_big2_neg) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b101111111111111001111;
  int decimal2_2 = 0b111100001111111111100011;
  int decimal2_3 = 0b1111111111111111111;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0x80000000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(test_mul_decimal_zero1) {
  int decimal1_1 = 0b0;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;

  char res_to_str[50] = "0";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_zero2) {
  int decimal1_1 = 0b0;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b11111111111111111111111111111111;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;

  char res_to_str[50] = "0";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_zero3) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;

  char res_to_str[50] = "0";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_zero4) {
  int decimal1_1 = 0b0;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;

  int decimal2_1 = 0b11111111111111111111111111111111;
  int decimal2_2 = 0b11111111111111111111111111111111;
  int decimal2_3 = 0b11111111111111111111111111111111;

  char res_to_str[50] = "0";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_zero5) {
  int decimal1_1 = 0b1;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;

  char res_to_str[50] = "0";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_oversmall1) {
  int decimal1_1 = 0b1;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b10000000000111000000000000000000;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b0;

  char res_to_str[50] = "0";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_oversmall2) {
  int decimal1_1 = 0b1;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b111000000000000000000;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b0;

  char res_to_str[50] = "0";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_oversmall3) {
  int decimal1_1 = 0b1;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b10000000000111000000000000000000;

  int decimal2_1 = 0b1;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b00000000000111000000000000000000;

  char res_to_str[50] = "0";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_oversmall4) {
  int decimal1_1 = 0b1;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b10000000000001000000000000000000;

  int decimal2_1 = 0b1;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b10000000000001000000000000000000;

  char res_to_str[50] = "0.00000001";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_oversmall5) {
  int decimal1_1 = 0b111111;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b00000000000010000000000000000000;

  int decimal2_1 = 0b111;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b10000000000001000000000000000000;

  char res_to_str[50] = "-0.000000000441";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_oversmall6) {
  int decimal1_1 = 0b111111;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b00000000001111000000000000000000;  // pow is bigger that 28

  int decimal2_1 = 0b111;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b10000000000111000000000000000000;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 4);
}
END_TEST

START_TEST(test_mul_decimal_smallpow1) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;
  int decimal1_4 = 0b00000000000111000000000000000000;

  int decimal2_1 = 0b1;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b10000000000111000000000000000000;

  char res_to_str[50] = "-0.0000000000000000000000000008";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_smallpow2) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;
  int decimal1_4 = 0b00000000000111000000000000000000;

  int decimal2_1 = 0b1;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b00000000000111000000000000000000;

  char res_to_str[50] = "0.0000000000000000000000000008";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_smallpow3) {
  int decimal1_1 = 0b11111111111111111111111111111110;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;
  int decimal1_4 = 0b00000000000111000000000000000000;

  int decimal2_1 = 0b1;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b00000000000111000000000000000000;

  char res_to_str[50] = "0.0000000000000000000000000008";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_smallpow4) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;
  int decimal1_4 = 0b00000000000111000000000000000000;

  int decimal2_1 = 0b11111111111111111111111111111111;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b00000000000111000000000000000000;

  char res_to_str[50] = "0.0000000000000000034028236684";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_mul_decimal_smallpow5) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;
  int decimal1_4 = 0b00000000000111000000000000000000;

  int decimal2_1 = 0b11111111111111111111111111111111;
  int decimal2_2 = 0b11111111111111111111111111111111;
  int decimal2_3 = 0b11111111111111111111111111111111;
  int decimal2_4 = 0b00000000000111000000000000000000;

  char res_to_str[50] = "62.77101735386680763835789423";

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  s21_mul(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_error_result_is_null) {
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0x1, 0, 0, 0}};
  int code = s21_mul(decimal1, decimal2, NULL);

  ck_assert_int_eq(code, 4);
}
END_TEST

START_TEST(test_error1) {
  // степень 255 (показатель степени должен быть от 0 до 28)

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b00000000111111110000000000000000;

  int decimal2_1 = 0b111;
  int decimal2_2 = 0b111;
  int decimal2_3 = 0b111;
  int decimal2_4 = 0b00000000000111000000000000000000;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 4);
}
END_TEST

START_TEST(test_error2) {
  // биты 0-15 не нули
  // биты 24-30 не нули

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b01100000000111000000000000000011;

  int decimal2_1 = 0b111;
  int decimal2_2 = 0b111;
  int decimal2_3 = 0b111;
  int decimal2_4 = 0b00000000000111000000000000000000;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 4);
}
END_TEST

START_TEST(test_error3) {
  // все единицы

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b11111111111111111111111111111111;

  int decimal2_1 = 0b111;
  int decimal2_2 = 0b111;
  int decimal2_3 = 0b111;
  int decimal2_4 = 0b11111111111111111111111111111111;

  s21_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  s21_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 4);
}
END_TEST

Suite *suite_mul(void) {
  Suite *s = suite_create("suite_mul");
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, test_mul_simple1);
  tcase_add_test(tc, test_mul_simple2);
  tcase_add_test(tc, test_mul_simple3);
  tcase_add_test(tc, test_mul_simple4);
  tcase_add_test(tc, test_mul_simple5);
  tcase_add_test(tc, test_mul_simple_neg1);
  tcase_add_test(tc, test_mul_simple_neg2);
  tcase_add_test(tc, test_mul_simple_neg3);
  tcase_add_test(tc, test_mul_simple_check_code1);
  tcase_add_test(tc, test_mul_simple_check_code2);
  tcase_add_test(tc, test_mul_simple_check_code3);
  tcase_add_test(tc, test_mul_simple_check_code4);
  tcase_add_test(tc, test_mul_simple_check_code5);
  tcase_add_test(tc, test_mul_simple_check_code6);
  tcase_add_test(tc, test_mul_simple_check_code7);
  tcase_add_test(tc, test_mul_simple_float_equal_small_pow1);
  tcase_add_test(tc, test_mul_simple_float_equal_small_pow2);
  tcase_add_test(tc, test_mul_simple_float_equal_small_pow3);
  tcase_add_test(tc, test_mul_simple_float_equal_small_pow4);
  tcase_add_test(tc, test_mul_simple_float_neg_equal_small_pow1);
  tcase_add_test(tc, test_mul_simple_float_neg_equal_small_pow2);
  tcase_add_test(tc, test_mul_simple_float_neg_equal_small_pow3);
  tcase_add_test(tc, test_mul_simple_float_diff_small_pow1);
  tcase_add_test(tc, test_mul_simple_float_diff_small_pow2);
  tcase_add_test(tc, test_mul_simple_float_neg_diff_small_pow1);
  tcase_add_test(tc, test_mul_decimal1);
  tcase_add_test(tc, test_mul_decimal2);
  tcase_add_test(tc, test_mul_decimal3);
  tcase_add_test(tc, test_mul_decimal_overbig1);
  tcase_add_test(tc, test_mul_decimal_overbig2);
  tcase_add_test(tc, test_mul_decimal_overbig3);
  tcase_add_test(tc, test_mul_decimal_overbig4);
  tcase_add_test(tc, test_mul_decimal_overbig5);
  tcase_add_test(tc, test_mul_decimal_overbig1_neg);
  tcase_add_test(tc, test_mul_decimal_overbig2_neg);
  tcase_add_test(tc, test_mul_decimal_big1_neg);
  tcase_add_test(tc, test_mul_decimal_big2_neg);
  tcase_add_test(tc, test_mul_decimal_zero1);
  tcase_add_test(tc, test_mul_decimal_zero2);
  tcase_add_test(tc, test_mul_decimal_zero3);
  tcase_add_test(tc, test_mul_decimal_zero4);
  tcase_add_test(tc, test_mul_decimal_zero5);
  tcase_add_test(tc, test_mul_decimal_oversmall1);
  tcase_add_test(tc, test_mul_decimal_oversmall2);
  tcase_add_test(tc, test_mul_decimal_oversmall3);
  tcase_add_test(tc, test_mul_decimal_oversmall4);
  tcase_add_test(tc, test_mul_decimal_oversmall5);
  tcase_add_test(tc, test_mul_decimal_oversmall6);
  tcase_add_test(tc, test_mul_decimal_smallpow1);
  tcase_add_test(tc, test_mul_decimal_smallpow2);
  tcase_add_test(tc, test_mul_decimal_smallpow3);
  tcase_add_test(tc, test_mul_decimal_smallpow4);
  tcase_add_test(tc, test_mul_decimal_smallpow5);
  tcase_add_test(tc, test_error_result_is_null);
  tcase_add_test(tc, test_error1);
  tcase_add_test(tc, test_error2);
  tcase_add_test(tc, test_error3);

  suite_add_tcase(s, tc);
  return s;
}