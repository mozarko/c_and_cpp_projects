#include "../tests_includes/s21_tests.h"

START_TEST(test_from_decimal_to_int_simple1) {
  int int_from_decimal= 0;
  int check = -5;
  s21_decimal decimal_negate = {{0x5, 0, 0, 0}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple2) {
  int int_from_decimal= 0;
  int check = -580;
  s21_decimal decimal_negate = {{580, 0, 0, 0}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple3) {
  int int_from_decimal= 0;
  int check = -76685;
  s21_decimal decimal_negate = {{76685, 0, 0, 0}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple4) {
  int int_from_decimal= 0;
  int check = -540;
  s21_decimal decimal_negate = {{540, 0, 0, 0}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple5) {
  int int_from_decimal= 0;
  int check = -1;
  s21_decimal decimal_negate = {{1, 0, 0, 0}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_neg1) {
  int int_from_decimal= 0;
  int check = 5;
  s21_decimal decimal_negate = {{5, 0, 0, 0x80000000}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_neg2) {
  int int_from_decimal= 0;
  int check = 15;
  s21_decimal decimal_negate = {{15, 0, 0, 0x80000000}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_neg3) {
  int int_from_decimal= 0;
  int check = 15000;
  s21_decimal decimal_negate = {{15000, 0, 0, 0x80000000}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code1) {
  s21_decimal result;
  s21_decimal decimal_negate = {{15, 0, 0, 0x80000000}};

  int res = s21_negate(decimal_negate, &result);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code2) {
  s21_decimal result;
  s21_decimal decimal_negate = {{0, 0, 0, 0x80000000}};

  int res = s21_negate(decimal_negate, &result);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code3) {
  s21_decimal result;
  s21_decimal decimal_negate = {{1, 0, 0, 0x80000000}};


  int res = s21_negate(decimal_negate, &result);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code4) {
  s21_decimal result;
  s21_decimal decimal_negate = {{2147483647, 0, 0, 0}};

  int res = s21_negate(decimal_negate, &result);
  ck_assert_int_eq(res, 0);

}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code5) {
  s21_decimal result;
  s21_decimal decimal_negate = {{2147483648, 0, 0, 0x80000000}};

  int res = s21_negate(decimal_negate, &result);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code6) {
  s21_decimal result;
  s21_decimal decimal_negate = {{1, 0, 0, 0x80000000}};

  int res = s21_negate(decimal_negate, &result);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code7) {
  s21_decimal result;
  s21_decimal decimal_negate = {{214748, 0, 0, 0}};

  int res = s21_negate(decimal_negate, &result);
  ck_assert_int_eq(res, 0);
}
END_TEST


START_TEST(test_from_decimal_to_int_decimal1) {
  int int_from_decimal= 0;
  int check = -264;
  s21_decimal decimal_negate = {{264, 0, 0, 0}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_decimal2) {
  int int_from_decimal= 0;
  int check = -6024;
  s21_decimal decimal_negate = {{6024, 0, 0, 0}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_decimal3) {
  int int_from_decimal= 0;
  int check = 0;
  s21_decimal decimal_negate = {{0, 0, 0, 0}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_decimal4) {
  int int_from_decimal= 0;
  int check = -2147483647;
  s21_decimal decimal_negate = {{2147483647, 0, 0, 0}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_decimal5) {
  int int_from_decimal= 0;
  int check = 2147483647;
  s21_decimal decimal_negate = {{2147483647, 0, 0, 0x80000000}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_decimal6) {
  int int_from_decimal= 0;
  int check = 0;
  s21_decimal decimal_negate = {{0, 0, 0, 0x80000000}};

  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow1) {
  float float_from_decimal= 0;
  float check = -55.4025;
  s21_decimal decimal_negate = {{554025, 0, 0, 0x40000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow2) {
  float float_from_decimal= 0;
  float check = -5540.25;
  s21_decimal decimal_negate = {{554025, 0, 0, 0x20000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow3) {
  float float_from_decimal= 0;
  float check = -0.554025;
  s21_decimal decimal_negate = {{554025, 0, 0, 0x60000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow4) {
  float float_from_decimal= 0;
  float check = -0.55402585;
  s21_decimal decimal_negate = {{55402585, 0, 0, 0x80000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow5) {
  float float_from_decimal= 0;
  float check = -554025.85;
  s21_decimal decimal_negate = {{55402585, 0, 0, 0x20000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow6) {
  float float_from_decimal= 0;
  float check = 0.00;
  s21_decimal decimal_negate = {{0, 0, 0, 0x20000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow7) {
  float float_from_decimal= 0;
  float check = -1.05;
  s21_decimal decimal_negate = {{105, 0, 0, 0x20000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow8) {
  float float_from_decimal= 0;
  float check = 1.05;
  s21_decimal decimal_negate = {{105, 0, 0, 0x80020000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow9) {
  float float_from_decimal= 0;
  float check = 55.4025;
  s21_decimal decimal_negate = {{554025, 0, 0, 0x80040000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow10) {
  float float_from_decimal= 0;
  float check = 5540.25;
  s21_decimal decimal_negate = {{554025, 0, 0, 0x80020000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow11) {
  float float_from_decimal= 0;
  float check = 0.554025;
  s21_decimal decimal_negate = {{554025, 0, 0, 0x80060000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow12) {
  float float_from_decimal= 0;
  float check = 0.55402585;
  s21_decimal decimal_negate = {{55402585, 0, 0, 0x80080000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_pow13) {
  float float_from_decimal= 0;
  float check = 554025.85;
  s21_decimal decimal_negate = {{55402585, 0, 0, 0x80020000}};
  s21_decimal result;

  s21_negate(decimal_negate, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_int_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_error1) {

  // степень 255 (показатель степени должен быть от 0 до 28)
  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b00000000111111110000000000000000;

  s21_decimal decimal_negate = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  s21_decimal result;
  int res =  s21_negate(decimal_negate, &result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error2) {

  // биты 0-15 не нули
  // биты 24-30 не нули

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b01100000000111000000000000000011;

  s21_decimal decimal_negate = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  s21_decimal result;
  int res =  s21_negate(decimal_negate, &result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error3) {

  // все единицы

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b11111111111111111111111111111111;


  s21_decimal decimal_negate = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  s21_decimal result;
  int res =  s21_negate(decimal_negate, &result);
  ck_assert_int_eq(res, 1);

}
END_TEST

START_TEST(test_error_result_is_null) {
  s21_decimal decimal_negate = {{0, 0, 0, 0}};

  int res =  s21_negate(decimal_negate, NULL);
  ck_assert_int_eq(res, 1);
}

END_TEST




Suite *suite_negate(void) {
  Suite *s = suite_create("suite_negate");
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, test_from_decimal_to_int_simple1);
  tcase_add_test(tc, test_from_decimal_to_int_simple2);
  tcase_add_test(tc, test_from_decimal_to_int_simple3);
  tcase_add_test(tc, test_from_decimal_to_int_simple4);
  tcase_add_test(tc, test_from_decimal_to_int_simple5);
  tcase_add_test(tc, test_from_decimal_to_int_simple_neg1);
  tcase_add_test(tc, test_from_decimal_to_int_simple_neg2);
  tcase_add_test(tc, test_from_decimal_to_int_simple_neg3);
  tcase_add_test(tc, test_from_decimal_to_int_simple_check_code1);
  tcase_add_test(tc, test_from_decimal_to_int_simple_check_code2);
  tcase_add_test(tc, test_from_decimal_to_int_simple_check_code3);
  tcase_add_test(tc, test_from_decimal_to_int_simple_check_code4);
  tcase_add_test(tc, test_from_decimal_to_int_simple_check_code5);
  tcase_add_test(tc, test_from_decimal_to_int_simple_check_code6);
  tcase_add_test(tc, test_from_decimal_to_int_simple_check_code7);
  tcase_add_test(tc, test_from_decimal_to_int_decimal1);
  tcase_add_test(tc, test_from_decimal_to_int_decimal2);
  tcase_add_test(tc, test_from_decimal_to_int_decimal3);
  tcase_add_test(tc, test_from_decimal_to_int_decimal4);
  tcase_add_test(tc, test_from_decimal_to_int_decimal5);
  tcase_add_test(tc, test_from_decimal_to_int_decimal6);
  tcase_add_test(tc, test_from_decimal_to_int_pow1);
  tcase_add_test(tc, test_from_decimal_to_int_pow2);
  tcase_add_test(tc, test_from_decimal_to_int_pow3);
  tcase_add_test(tc, test_from_decimal_to_int_pow4);
  tcase_add_test(tc, test_from_decimal_to_int_pow5);
  tcase_add_test(tc, test_from_decimal_to_int_pow6);
  tcase_add_test(tc, test_from_decimal_to_int_pow7);
  tcase_add_test(tc, test_from_decimal_to_int_pow8);
  tcase_add_test(tc, test_from_decimal_to_int_pow9);
  tcase_add_test(tc, test_from_decimal_to_int_pow10);
  tcase_add_test(tc, test_from_decimal_to_int_pow11);
  tcase_add_test(tc, test_from_decimal_to_int_pow12);
  tcase_add_test(tc, test_from_decimal_to_int_pow13);
  tcase_add_test(tc, test_error1);
  tcase_add_test(tc, test_error2);
  tcase_add_test(tc, test_error3);
  tcase_add_test(tc, test_error_result_is_null);

  suite_add_tcase(s, tc);
  return s;

}