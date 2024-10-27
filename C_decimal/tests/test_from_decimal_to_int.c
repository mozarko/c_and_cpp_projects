#include "../tests_includes/s21_tests.h"

START_TEST(test_from_decimal_to_int_simple1) {
  int int_from_decimal= 0;
  int check = 5;
  s21_decimal decimal_to_int = {{0x5, 0, 0, 0}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple2) {
  int int_from_decimal= 0;
  int check = 580;
  s21_decimal decimal_to_int = {{580, 0, 0, 0}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple3) {
  int int_from_decimal= 0;
  int check = 76685;
  s21_decimal decimal_to_int = {{76685, 0, 0, 0}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple4) {
  int int_from_decimal= 0;
  int check = 540;
  s21_decimal decimal_to_int = {{540, 0, 0, 0}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple5) {
  int int_from_decimal= 0;
  int check = 1;
  s21_decimal decimal_to_int = {{1, 0, 0, 0}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_neg1) {
  int int_from_decimal= 0;
  int check = -5;
  s21_decimal decimal_to_int = {{5, 0, 0, 0x80000000}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_neg2) {
  int int_from_decimal= 0;
  int check = -15;
  s21_decimal decimal_to_int = {{15, 0, 0, 0x80000000}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_neg3) {
  int int_from_decimal= 0;
  int check = -15000;
  s21_decimal decimal_to_int = {{15000, 0, 0, 0x80000000}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code1) {
  int int_from_decimal= 0;
  s21_decimal decimal_to_int = {{15, 0, 0, 0x80000000}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code2) {
  int int_from_decimal= 0;
  s21_decimal decimal_to_int = {{0, 0, 0, 0x80000000}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code3) {
  int int_from_decimal= 0;
  s21_decimal decimal_to_int = {{1, 0, 0, 0x80000000}};


  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code4) {
  int int_from_decimal= 0;
  s21_decimal decimal_to_int = {{2147483647, 0, 0, 0}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);
  ck_assert_int_eq(res, 0);

}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code5) {
  int int_from_decimal= 0;
  s21_decimal decimal_to_int = {{2147483648, 0, 0, 0x80000000}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code6) {
  int int_from_decimal= 0;
  s21_decimal decimal_to_int = {{1, 0, 0, 0x80000000}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_int_simple_check_code7) {
  int int_from_decimal= 0;
  s21_decimal decimal_to_int = {{214748, 0, 0, 0}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST


START_TEST(test_from_decimal_to_int_decimal1) {
  int int_from_decimal= 0;
  int check = 264;
  s21_decimal decimal_to_int = {{264, 0, 0, 0}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_decimal2) {
  int int_from_decimal= 0;
  int check = 6024;
  s21_decimal decimal_to_int = {{6024, 0, 0, 0}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_decimal3) {
  int int_from_decimal= 0;
  int check = 0;
  s21_decimal decimal_to_int = {{0, 0, 0, 0}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_decimal4) {
  int int_from_decimal= 0;
  int check = 2147483647;
  s21_decimal decimal_to_int = {{2147483647, 0, 0, 0}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_int_decimal5) {
  int int_from_decimal= 0;
  int check = -2147483648;
  s21_decimal decimal_to_int = {{2147483648, 0, 0, 0x80000000}};

  s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(int_from_decimal, check);
}
END_TEST


START_TEST(test_error_result_is_null) {

  s21_decimal decimal_to_int = {{1, 0, 0, 0}};

  int res = s21_from_decimal_to_int(decimal_to_int, NULL);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error1) {
  int int_from_decimal= 0;

  s21_decimal decimal_to_int = {{1, 0, 0, 0b11111111111111111111111111111111}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error2) {
    //меньше -2147483648,
  int int_from_decimal= 0;
  int decimal1_1 = 0b10000000000000000000000000000010;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b10000000000000000000000000000000;

  s21_decimal decimal_to_int = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);


  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error3) {
// больше 2147483647
  int int_from_decimal= 0;
  int decimal1_1 = 0b10000000000000000000000000000010;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;
  int decimal1_4 = 0b0;

  s21_decimal decimal_to_int = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);


  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error4) {

  // биты 0-15 не нули
  // биты 24-30 не нули

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b01100000000111000000000000000011;
  int int_from_decimal= 0;
  s21_decimal decimal_to_int = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error5) {

  // степень 255 (показатель степени должен быть от 0 до 28)

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b00000000111111110000000000000000;

  int int_from_decimal= 0;
  s21_decimal decimal_to_int = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error6) {

  // любая степень

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b00000000000000010000000000000000;

  int int_from_decimal= 0;
  s21_decimal decimal_to_int = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = s21_from_decimal_to_int(decimal_to_int, &int_from_decimal);

  ck_assert_int_eq(res, 1);
}
END_TEST

Suite *suite_from_decimal_to_int(void) {
  Suite *s = suite_create("suite_from_decimal_to_int");
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
  tcase_add_test(tc, test_error_result_is_null);
  tcase_add_test(tc, test_error1);
  tcase_add_test(tc, test_error2);
  tcase_add_test(tc, test_error3);
  tcase_add_test(tc, test_error4);
  tcase_add_test(tc, test_error5);
  tcase_add_test(tc, test_error6);


  suite_add_tcase(s, tc);
  return s;

}