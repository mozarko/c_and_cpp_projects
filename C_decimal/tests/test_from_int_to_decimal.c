#include "../tests_includes/mo_tests.h"

START_TEST(test_from_int_to_decimal_simple1) {
  int int_to_decimal= 5;
  mo_decimal result;
  mo_decimal decimal_check = {{0x5, 0, 0, 0}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple2) {
   int int_to_decimal= 580;
  mo_decimal result;
  mo_decimal decimal_check = {{580, 0, 0, 0}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple3) {
  int int_to_decimal= 76685;
  mo_decimal result;
  mo_decimal decimal_check = {{76685, 0, 0, 0}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple4) {
  int int_to_decimal= 5;
  mo_decimal result;
  mo_decimal decimal_check = {{6, 0, 0, 0}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple5) {
  int int_to_decimal= 15;
  mo_decimal result;
  mo_decimal decimal_check = {{16, 0, 0, 0}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple_neg1) {
  int int_to_decimal= -5;
  mo_decimal result;
  mo_decimal decimal_check = {{5, 0, 0, 0x80000000}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple_neg2) {
  int int_to_decimal= -15;
  mo_decimal result;
  mo_decimal decimal_check = {{16, 0, 0, 0x80000000}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple_neg3) {
  int int_to_decimal= -6;
  mo_decimal result;
  mo_decimal decimal_check = {{6, 0, 0, 0x80000000}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple_check_code1) {
  int int_to_decimal= 5;
  mo_decimal result;

  int res = mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple_check_code2) {
  int int_to_decimal= 5589;
  mo_decimal result;

  int res = mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple_check_code3) {
  int int_to_decimal= 54687535;
  mo_decimal result;

  int res = mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple_check_code4) {
  int int_to_decimal= 2147483647;
  mo_decimal result;

  int res = mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(res, 0);

}
END_TEST

START_TEST(test_from_int_to_decimal_simple_check_code5) {
  int int_to_decimal= -2147483648;
  mo_decimal result;

  int res = mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple_check_code6) {
  int int_to_decimal= 1;
  mo_decimal result;

  int res = mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_int_to_decimal_simple_check_code7) {
  int int_to_decimal= 0;
  mo_decimal result;

  int res = mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST


START_TEST(test_from_int_to_decimal_decimal1) {
  int int_to_decimal = 264;
  mo_decimal result;
  int decimal1_1 = 0b100001000;
  mo_decimal decimal_check = {{decimal1_1, 0, 0, 0}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_decimal2) {
  int int_to_decimal = 6024;
  mo_decimal result;
  int decimal1_1 = 0b1011110001000;
  mo_decimal decimal_check = {{decimal1_1, 0, 0, 0}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_decimal3) {
  int int_to_decimal = 259976;
  mo_decimal result;
  int decimal1_1 = 0b111111011110001000;
  mo_decimal decimal_check = {{decimal1_1, 0, 0, 0}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_decimal4) {
  int int_to_decimal = 2147483647;
  mo_decimal result;
  int decimal1_1 = 0b1111111111111111111111111111111;
  mo_decimal decimal_check = {{decimal1_1, 0, 0, 0}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_int_to_decimal_decimal5) {
  int int_to_decimal = -2147483648;
  mo_decimal result;
  int decimal1_1 = 0b10000000000000000000000000000000;
  mo_decimal decimal_check = {{decimal1_1, 0, 0, 0x80000000}};

  mo_from_int_to_decimal(int_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_error_result_is_null) {
  int int_to_decimal = 5;

  int code = mo_from_int_to_decimal(int_to_decimal, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST



Suite *suite_from_int_to_decimal(void) {
  Suite *s = suite_create("suite_from_int_to_decimal");
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, test_from_int_to_decimal_simple1);
  tcase_add_test(tc, test_from_int_to_decimal_simple2);
  tcase_add_test(tc, test_from_int_to_decimal_simple3);
  tcase_add_test(tc, test_from_int_to_decimal_simple4);
  tcase_add_test(tc, test_from_int_to_decimal_simple5);
  tcase_add_test(tc, test_from_int_to_decimal_simple_neg1);
  tcase_add_test(tc, test_from_int_to_decimal_simple_neg2);
  tcase_add_test(tc, test_from_int_to_decimal_simple_neg3);
  tcase_add_test(tc, test_from_int_to_decimal_simple_check_code1);
  tcase_add_test(tc, test_from_int_to_decimal_simple_check_code2);
  tcase_add_test(tc, test_from_int_to_decimal_simple_check_code3);
  tcase_add_test(tc, test_from_int_to_decimal_simple_check_code4);
  tcase_add_test(tc, test_from_int_to_decimal_simple_check_code5);
  tcase_add_test(tc, test_from_int_to_decimal_simple_check_code6);
  tcase_add_test(tc, test_from_int_to_decimal_simple_check_code7);
  tcase_add_test(tc, test_from_int_to_decimal_decimal1);
  tcase_add_test(tc, test_from_int_to_decimal_decimal2);
  tcase_add_test(tc, test_from_int_to_decimal_decimal3);
  tcase_add_test(tc, test_from_int_to_decimal_decimal4);
  tcase_add_test(tc, test_from_int_to_decimal_decimal5);
  tcase_add_test(tc, test_error_result_is_null);


  suite_add_tcase(s, tc);
  return s;

}