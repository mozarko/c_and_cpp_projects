#include "../tests_includes/mo_tests.h"

START_TEST(test_add_simple1) {
  mo_decimal decimal1 = {{0x5, 0, 0, 0}};
  mo_decimal decimal2 = {{0x8, 0, 0, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), "13");
}
END_TEST

START_TEST(test_add_simple2) {
  int simple_decimal1 = 580;
  int simple_decimal2 = 98807487;
  int res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  mo_decimal decimal1 = {{simple_decimal1, 0, 0, 0}};
  mo_decimal decimal2 = {{simple_decimal2, 0, 0, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple3) {
  int simple_decimal1 = 58798700;
  int simple_decimal2 = 98807487;
  int res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  mo_decimal decimal1 = {{simple_decimal1, 0, 0, 0}};
  mo_decimal decimal2 = {{simple_decimal2, 0, 0, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple4) {
  int simple_decimal1 = 0;
  int simple_decimal2 = 654498797;
  int res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  mo_decimal decimal1 = {{simple_decimal1, 0, 0, 0}};
  mo_decimal decimal2 = {{simple_decimal2, 0, 0, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple5) {
  int simple_decimal1 = 775604;
  int simple_decimal2 = 0;
  int res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  mo_decimal decimal1 = {{simple_decimal1, 0, 0, 0}};
  mo_decimal decimal2 = {{simple_decimal2, 0, 0, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_neg1) {
  int simple_decimal1 = -775604;
  int simple_decimal2 = 56578;
  int simple_decimal1_neg = simple_decimal1 * -1;
  int res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  mo_decimal decimal1 = {{simple_decimal1_neg, 0, 0, 0x80000000}};
  mo_decimal decimal2 = {{simple_decimal2, 0, 0, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_neg2) {
  int simple_decimal1 = -775604;
  int simple_decimal2 = -56578;
  int simple_decimal1_neg = simple_decimal1 * -1;
  int simple_decimal2_neg = simple_decimal2 * -1;
  int res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  mo_decimal decimal1 = {{simple_decimal1_neg, 0, 0, 0x80000000}};
  mo_decimal decimal2 = {{simple_decimal2_neg, 0, 0, 0x80000000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_neg3) {
  int simple_decimal1 = 775604;
  int simple_decimal2 = -56578;
  int simple_decimal2_neg = simple_decimal2 * -1;
  int res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%d", res);

  mo_decimal decimal1 = {{simple_decimal1, 0, 0, 0}};
  mo_decimal decimal2 = {{simple_decimal2_neg, 0, 0, 0x80000000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_check_code1) {
  mo_decimal decimal1 = {{0x5, 0, 0, 0}};
  mo_decimal decimal2 = {{0x8, 0, 0, 0}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_add_simple_check_code2) {
  mo_decimal decimal1 = {{85070, 0, 0, 0}};
  mo_decimal decimal2 = {{798, 0, 0, 0}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_add_simple_check_code3) {
  mo_decimal decimal1 = {{0, 0, 0, 0}};
  mo_decimal decimal2 = {{798, 0, 0, 0}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_add_simple_check_code4) {
  mo_decimal decimal1 = {{86798, 0, 0, 0}};
  mo_decimal decimal2 = {{0, 0, 0, 0}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_add_simple_check_code5) {
  mo_decimal decimal1 = {{86798, 0, 0, 0x80000000}};
  mo_decimal decimal2 = {{0, 0, 0, 0}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_add_simple_check_code6) {
  mo_decimal decimal1 = {{0, 0, 0, 0}};
  mo_decimal decimal2 = {{484456, 0, 0, 0x80000000}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_add_simple_check_code7) {
  mo_decimal decimal1 = {{845664, 0, 0, 0x80000000}};
  mo_decimal decimal2 = {{484456, 0, 0, 0x80000000}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_add_simple_float_equal_small_pow1) {
  double simple_decimal1 = 77.56;
  double simple_decimal2 = 589.12;
  double res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.2f", res);

  mo_decimal decimal1 = {{7756, 0, 0, 0x20000}};
  mo_decimal decimal2 = {{58912, 0, 0, 0x20000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_float_equal_small_pow2) {
  double simple_decimal1 = 0.56;
  double simple_decimal2 = 0.12;
  double res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.2f", res);

  mo_decimal decimal1 = {{56, 0, 0, 0x20000}};
  mo_decimal decimal2 = {{12, 0, 0, 0x20000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_float_equal_small_pow3) {
  double simple_decimal1 = 0.56;
  double simple_decimal2 = 58798.12;
  double res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.2f", res);

  mo_decimal decimal1 = {{56, 0, 0, 0x20000}};
  mo_decimal decimal2 = {{5879812, 0, 0, 0x20000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_float_equal_small_pow4) {
  double simple_decimal1 = 549879.55;
  double simple_decimal2 = 0.12;
  double res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.2f", res);

  mo_decimal decimal1 = {{54987955, 0, 0, 0x20000}};
  mo_decimal decimal2 = {{12, 0, 0, 0x20000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_float_neg_equal_small_pow1) {
  double simple_decimal1 = -549879.55;
  double simple_decimal2 = 0.12;
  double res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.2f", res);

  mo_decimal decimal1 = {{54987955, 0, 0, 0x80020000}};
  mo_decimal decimal2 = {{12, 0, 0, 0x20000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_float_neg_equal_small_pow2) {
  double simple_decimal1 = 549879.55;
  double simple_decimal2 = -0.12;
  double res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.2f", res);

  mo_decimal decimal1 = {{54987955, 0, 0, 0x20000}};
  mo_decimal decimal2 = {{12, 0, 0, 0x80020000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_float_neg_equal_small_pow3) {
  double simple_decimal1 = -549879.55;
  double simple_decimal2 = -0.12;
  double res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.2f", res);

  mo_decimal decimal1 = {{54987955, 0, 0, 0x80020000}};
  mo_decimal decimal2 = {{12, 0, 0, 0x80020000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);
  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_float_diff_small_pow1) {
  double simple_decimal1 = 78.569874;
  double simple_decimal2 = 9.48;
  double res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.6f", res);

  mo_decimal decimal1 = {{78569874, 0, 0, 0x60000}};
  mo_decimal decimal2 = {{948, 0, 0, 0x20000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_float_diff_small_pow2) {
  double simple_decimal1 = 78.569874;
  double simple_decimal2 = 9.48224568;
  double res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.8f", res);

  mo_decimal decimal1 = {{78569874, 0, 0, 0x60000}};
  mo_decimal decimal2 = {{948224568, 0, 0, 0x80000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_simple_float_neg_diff_small_pow1) {
  double simple_decimal1 = -78.569874;
  double simple_decimal2 = 9.48224568;
  double res = simple_decimal1 + simple_decimal2;
  char res_to_str[50];
  sprintf(res_to_str, "%.8f", res);

  mo_decimal decimal1 = {{78569874, 0, 0, 0x80060000}};
  mo_decimal decimal2 = {{948224568, 0, 0, 0x80000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal1) {
  int decimal1_1 = 0b100001000;
  int decimal1_2 = 0b1110011100;
  int decimal1_3 = 0b10001;

  int decimal2_1 = 0b1011111001111;
  int decimal2_2 = 0b1111000011100011;
  int decimal2_3 = 0b1111111111;

  char res_to_str[50] = "19184614105484231710935";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal2) {
  int decimal1_1 = 0b10111110001000;
  int decimal1_2 = 0b1110011100;
  int decimal1_3 = 0b100111101;

  int decimal2_1 = 0b1011110001001111;
  int decimal2_2 = 0b111001000011100011;
  int decimal2_3 = 0b1111100011111;

  char res_to_str[50] = "152812828914308037536727";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal3) {
  int decimal1_1 = 0b1000011111000;
  int decimal1_2 = 0b11100;
  int decimal1_3 = 0b101;

  int decimal2_1 = 0b101001111;
  int decimal2_2 = 0b1111100011;
  int decimal2_3 = 0b111111001;

  char res_to_str[50] = "9407839481985622872647";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_overbig1) {
  int decimal1_1 = 0b11111111111111111111111100001000;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b1011111001111;
  int decimal2_2 = 0b1111000011100011;
  int decimal2_3 = 0b1111111111;

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_add_decimal_overbig2) {
  int decimal1_1 = 0b11111111111111111111111100001000;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b101111111111111001111;
  int decimal2_2 = 0b111100001111111111100011;
  int decimal2_3 = 0b1111111111111111111;

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_add_decimal_overbig3) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b101111111111111001111;
  int decimal2_2 = 0b111100001111111111100011;
  int decimal2_3 = 0b1111111111111111111;

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_add_decimal_overbig4) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;

  int decimal2_1 = 0b11111111111111111111111111111111;
  int decimal2_2 = 0b11111111111111111111111111111111;
  int decimal2_3 = 0b11111111111111111111111111111111;

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_add_decimal_overbig5) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  char res_to_str[] = "-79228162514264337593543950335";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0x80000000}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);
  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_overbig1_neg) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b101111111111111001111;
  int decimal2_2 = 0b111100001111111111100011;
  int decimal2_3 = 0b1111111111111111111;

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0x80000000}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0x80000000}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(test_add_decimal_overbig2_neg) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;

  int decimal2_1 = 0b11111111111111111111111111111111;
  int decimal2_2 = 0b11111111111111111111111111111111;
  int decimal2_3 = 0b11111111111111111111111111111111;

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0x80000000}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0x80000000}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);
  ck_assert_int_eq(code, 2);
}
END_TEST

START_TEST(test_add_decimal_big1_neg) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b101111111111111001111;
  int decimal2_2 = 0b111100001111111111100011;
  int decimal2_3 = 0b1111111111111111111;

  char res_to_str[50] = "-79218486569740542021904891952";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0x80000000}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_big2_neg) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111100001000;
  int decimal1_3 = 0b11111111111111111111111100001000;

  int decimal2_1 = 0b101111111111111001111;
  int decimal2_2 = 0b111100001111111111100011;
  int decimal2_3 = 0b1111111111111111111;

  char res_to_str[50] = "79218486569740542021904891952";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0x80000000}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_zero1) {
  int decimal1_1 = 0b0;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;

  char res_to_str[50] = "0";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_zero2) {
  int decimal1_1 = 0b0;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b11111111111111111111111111111111;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;

  char res_to_str[50] = "79228162495817593519834398720";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_zero3) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;

  char res_to_str[50] = "79228162514264337593543950335";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_zero4) {
  int decimal1_1 = 0b0;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;

  int decimal2_1 = 0b11111111111111111111111111111111;
  int decimal2_2 = 0b11111111111111111111111111111111;
  int decimal2_3 = 0b11111111111111111111111111111111;

  char res_to_str[50] = "79228162514264337593543950335";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_zero5) {
  int decimal1_1 = 0b1;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;

  char res_to_str[50] = "1";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, 0}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, 0}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_oversmall1) {
  int decimal1_1 = 0b1;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b10000000000111000000000000000000;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b0;

  char res_to_str[50] = "-0.0000000000000000000000000001";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_oversmall2) {
  int decimal1_1 = 0b1;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b111000000000000000000;

  int decimal2_1 = 0b0;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b0;

  char res_to_str[50] = "0.0000000000000000000000000001";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_oversmall3) {
  int decimal1_1 = 0b1;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b10000000000111000000000000000000;

  int decimal2_1 = 0b1;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b00000000000111000000000000000000;

  char res_to_str[50] = "0";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_oversmall4) {
  int decimal1_1 = 0b1;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b10000000000111000000000000000000;

  int decimal2_1 = 0b1;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b10000000000111000000000000000000;

  char res_to_str[50] = "-0.0000000000000000000000000002";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_oversmall5) {
  int decimal1_1 = 0b111111;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b00000000000111000000000000000000;

  int decimal2_1 = 0b111;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b10000000000111000000000000000000;

  char res_to_str[50] = "0.0000000000000000000000000056";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_oversmall6) {
  int decimal1_1 = 0b111111;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b00000000001111000000000000000000;  // pow is bigger that 28

  int decimal2_1 = 0b111;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b10000000000111000000000000000000;

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 4);
}
END_TEST

START_TEST(test_add_decimal_smallpow1) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;
  int decimal1_4 = 0b00000000000111000000000000000000;

  int decimal2_1 = 0b1;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b10000000000111000000000000000000;

  char res_to_str[50] = "7.9228162514264337593543950334";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_smallpow2) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;
  int decimal1_4 = 0b00000000000111000000000000000000;

  int decimal2_1 = 0b1;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b00000000000111000000000000000000;

  char res_to_str[50] = "7.922816251426433759354395034";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_smallpow3) {
  int decimal1_1 = 0b11111111111111111111111111111110;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;
  int decimal1_4 = 0b00000000000111000000000000000000;

  int decimal2_1 = 0b1;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b00000000000111000000000000000000;

  char res_to_str[50] = "7.9228162514264337593543950335";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_smallpow4) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;
  int decimal1_4 = 0b00000000000111000000000000000000;

  int decimal2_1 = 0b11111111111111111111111111111111;
  int decimal2_2 = 0b0;
  int decimal2_3 = 0b0;
  int decimal2_4 = 0b00000000000111000000000000000000;

  char res_to_str[50] = "7.922816251426433759783891763";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_add_decimal_smallpow5) {
  int decimal1_1 = 0b11111111111111111111111111111111;
  int decimal1_2 = 0b11111111111111111111111111111111;
  int decimal1_3 = 0b11111111111111111111111111111111;
  int decimal1_4 = 0b00000000000111000000000000000000;

  int decimal2_1 = 0b11111111111111111111111111111111;
  int decimal2_2 = 0b11111111111111111111111111111111;
  int decimal2_3 = 0b11111111111111111111111111111111;
  int decimal2_4 = 0b00000000000111000000000000000000;

  char res_to_str[50] = "15.845632502852867518708790067";

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  mo_add(decimal1, decimal2, &result);

  ck_assert_str_eq(decimal_to_string(result), res_to_str);
}
END_TEST

START_TEST(test_error_result_is_null) {
  mo_decimal decimal1 = {{0, 0, 0, 0}};
  mo_decimal decimal2 = {{0x1, 0, 0, 0}};
  int code = mo_add(decimal1, decimal2, NULL);

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

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

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

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

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

  mo_decimal decimal1 = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};
  mo_decimal decimal2 = {{decimal2_1, decimal2_2, decimal2_3, decimal2_4}};
  mo_decimal result;
  int code = mo_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, 4);
}
END_TEST

Suite *suite_add(void) {
  Suite *s = suite_create("suite_add");
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, test_add_simple1);
  tcase_add_test(tc, test_add_simple2);
  tcase_add_test(tc, test_add_simple3);
  tcase_add_test(tc, test_add_simple4);
  tcase_add_test(tc, test_add_simple5);
  tcase_add_test(tc, test_add_simple_neg1);
  tcase_add_test(tc, test_add_simple_neg2);
  tcase_add_test(tc, test_add_simple_neg3);
  tcase_add_test(tc, test_add_simple_check_code1);
  tcase_add_test(tc, test_add_simple_check_code2);
  tcase_add_test(tc, test_add_simple_check_code3);
  tcase_add_test(tc, test_add_simple_check_code4);
  tcase_add_test(tc, test_add_simple_check_code5);
  tcase_add_test(tc, test_add_simple_check_code6);
  tcase_add_test(tc, test_add_simple_check_code7);
  tcase_add_test(tc, test_add_simple_float_equal_small_pow1);
  tcase_add_test(tc, test_add_simple_float_equal_small_pow2);
  tcase_add_test(tc, test_add_simple_float_equal_small_pow3);
  tcase_add_test(tc, test_add_simple_float_equal_small_pow4);
  tcase_add_test(tc, test_add_simple_float_neg_equal_small_pow1);
  tcase_add_test(tc, test_add_simple_float_neg_equal_small_pow2);
  tcase_add_test(tc, test_add_simple_float_neg_equal_small_pow3);
  tcase_add_test(tc, test_add_simple_float_diff_small_pow1);
  tcase_add_test(tc, test_add_simple_float_diff_small_pow2);
  tcase_add_test(tc, test_add_simple_float_neg_diff_small_pow1);
  tcase_add_test(tc, test_add_decimal1);
  tcase_add_test(tc, test_add_decimal2);
  tcase_add_test(tc, test_add_decimal3);
  tcase_add_test(tc, test_add_decimal_overbig1);
  tcase_add_test(tc, test_add_decimal_overbig2);
  tcase_add_test(tc, test_add_decimal_overbig3);
  tcase_add_test(tc, test_add_decimal_overbig4);
  tcase_add_test(tc, test_add_decimal_overbig5);
  tcase_add_test(tc, test_add_decimal_overbig1_neg);
  tcase_add_test(tc, test_add_decimal_overbig2_neg);
  tcase_add_test(tc, test_add_decimal_big1_neg);
  tcase_add_test(tc, test_add_decimal_big2_neg);
  tcase_add_test(tc, test_add_decimal_zero1);
  tcase_add_test(tc, test_add_decimal_zero2);
  tcase_add_test(tc, test_add_decimal_zero3);
  tcase_add_test(tc, test_add_decimal_zero4);
  tcase_add_test(tc, test_add_decimal_zero5);
  tcase_add_test(tc, test_add_decimal_oversmall1);
  tcase_add_test(tc, test_add_decimal_oversmall2);
  tcase_add_test(tc, test_add_decimal_oversmall3);
  tcase_add_test(tc, test_add_decimal_oversmall4);
  tcase_add_test(tc, test_add_decimal_oversmall5);
  tcase_add_test(tc, test_add_decimal_oversmall6);
  tcase_add_test(tc, test_add_decimal_smallpow1);
  tcase_add_test(tc, test_add_decimal_smallpow2);
  tcase_add_test(tc, test_add_decimal_smallpow3);
  tcase_add_test(tc, test_add_decimal_smallpow4);
  tcase_add_test(tc, test_add_decimal_smallpow5);
  tcase_add_test(tc, test_error_result_is_null);
  tcase_add_test(tc, test_error1);
  tcase_add_test(tc, test_error2);
  tcase_add_test(tc, test_error3);

  suite_add_tcase(s, tc);
  return s;
}