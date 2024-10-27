#include "../tests_includes/mo_tests.h"

START_TEST(test_from_decimal_to_float_simple1) {
  float float_from_decimal= 0.00;
  float check = 5.01;
  mo_decimal decimal_to_float = {{501, 0, 0, 0x20000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple2) {
  float float_from_decimal= 0;
  float check = 5.80;
  mo_decimal decimal_to_float = {{580, 0, 0, 0x20000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple3) {
  float float_from_decimal= 0;
  float check = 7.6685;
  mo_decimal decimal_to_float = {{76685, 0, 0, 0x40000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple4) {
  float float_from_decimal= 0;
  float check = 5.40;
  mo_decimal decimal_to_float = {{540, 0, 0, 0x20000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple5) {
  float float_from_decimal= 0;
  float check = 1;
  mo_decimal decimal_to_float = {{1, 0, 0, 0}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple_neg1) {
  float float_from_decimal= 0;
  float check = -5;
  mo_decimal decimal_to_float = {{5, 0, 0, 0x80000000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple_neg2) {
  float float_from_decimal= 0;
  float check = -1.50;
  mo_decimal decimal_to_float = {{150, 0, 0, 0x80020000}};


  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple_neg3) {
  float float_from_decimal= 0;
  float check = -15000;
  mo_decimal decimal_to_float = {{15000, 0, 0, 0x80000000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple_check_code1) {
  float float_from_decimal= 0;
  mo_decimal decimal_to_float = {{15, 0, 0, 0x80000000}};

  int res = mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple_check_code2) {
  float float_from_decimal= 0;
  mo_decimal decimal_to_float = {{0, 0, 0, 0x80000000}};

  int res = mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple_check_code3) {
  float float_from_decimal= 0;
  mo_decimal decimal_to_float = {{152, 0, 0, 0x80020000}};


  int res = mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple_check_code4) {
  float float_from_decimal= 0;
  mo_decimal decimal_to_float = {{2147483647, 0, 0, 0x60000}};

  int res = mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);
  ck_assert_int_eq(res, 0);

}
END_TEST

START_TEST(test_from_decimal_to_float_simple_check_code5) {
  float float_from_decimal= 0;
  mo_decimal decimal_to_float = {{2147483648, 0, 0, 0x80060000}};

  int res = mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple_check_code6) {
  float float_from_decimal= 0;
  mo_decimal decimal_to_float = {{1, 0, 0, 0x80000000}};

  int res = mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_decimal_to_float_simple_check_code7) {
  float float_from_decimal= 0;
  mo_decimal decimal_to_float = {{214748, 0, 0, 0x40000}};

  int res = mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);
  ck_assert_int_eq(res, 0);
}
END_TEST


START_TEST(test_from_decimal_to_float_decimal1) {
  float float_from_decimal= 0;
  float check = 2.647856;
  mo_decimal decimal_to_float = {{2647856, 0, 0, 0x60000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal2) {
  float float_from_decimal= 0;
  float check = 60.248958;
  mo_decimal decimal_to_float = {{60248958, 0, 0, 0x60000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal3) {
  float float_from_decimal= 0;
  float check = 0;
  mo_decimal decimal_to_float = {{0, 0, 0, 0}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal4) {
  float float_from_decimal= 0;
  float check = 2147.483647;
  mo_decimal decimal_to_float = {{2147483647, 0, 0, 0x60000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal5) {
  float float_from_decimal= 0;
  float check = -2147.483648;
  mo_decimal decimal_to_float = {{2147483648, 0, 0, 0x80060000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal6) {
  float float_from_decimal= 0;
  float check = 465489754647.987879;
  int decimal1_1 = 0b00110000011000001000011010100111;
  int decimal1_2 = 0b00000110011101011100000001110111;
  int decimal1_3 = 0b0;

  mo_decimal decimal_to_float = {{decimal1_1, decimal1_2, decimal1_3, 0x60000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal7) {
  float float_from_decimal= 0;
  float check = 2568045494967156166.657703;
  int decimal1_1 = 0b00110000011000001000011010100111;
  int decimal1_2 = 0b00000110011101011100000001110111;
  int decimal1_3 = 0b0100001111111001110;

  mo_decimal decimal_to_float = {{decimal1_1, decimal1_2, decimal1_3, 0x60000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal8) {
  float float_from_decimal= 0;
  float check = 0.657703;
  int decimal1_1 = 0b10100000100100100111;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;

  mo_decimal decimal_to_float = {{decimal1_1, decimal1_2, decimal1_3, 0x60000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal9) {
  float float_from_decimal= 0;
  float check = 0.6577;
  int decimal1_1 = 0b1100110110001;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;

  mo_decimal decimal_to_float = {{decimal1_1, decimal1_2, decimal1_3, 0x40000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal10) {
  float float_from_decimal= 0;
  float check = -0.6577;
  int decimal1_1 = 0b1100110110001;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;

  mo_decimal decimal_to_float = {{decimal1_1, decimal1_2, decimal1_3, 0x80040000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal11) {
  float float_from_decimal= 0;
  float check = -0.657703;
  int decimal1_1 = 0b10100000100100100111;
  int decimal1_2 = 0b0;
  int decimal1_3 = 0b0;

  mo_decimal decimal_to_float = {{decimal1_1, decimal1_2, decimal1_3, 0x80060000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal12) {
  float float_from_decimal= 0;
  float check = -0.001;

  mo_decimal decimal_to_float = {{1, 0, 0, 0x80030000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal13) {
  float float_from_decimal= 0;
  float check = -0.000001;

  mo_decimal decimal_to_float = {{1, 0, 0, 0x80060000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);


  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal14) {
  float float_from_decimal= 0;
  float check = -0.00000001;

  mo_decimal decimal_to_float = {{1, 0, 0, 0x80080000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);


  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST

START_TEST(test_from_decimal_to_float_decimal15) {
  float float_from_decimal= 0;
  float check = 0.00000001;

  mo_decimal decimal_to_float = {{1, 0, 0, 0x00080000}};

  mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_float_eq(float_from_decimal, check);
}
END_TEST




START_TEST(test_error1) {

    // степень 255 (показатель степени должен быть от 0 до 28)
  float float_from_decimal= 0;
  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b00000000111111110000000000000000;

  mo_decimal decimal_to_float = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

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
  float float_from_decimal= 0;

  mo_decimal decimal_to_float = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error3) {

  // все единицы

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b11111111111111111111111111111111;
  float float_from_decimal= 0;

  mo_decimal decimal_to_float = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = mo_from_decimal_to_float(decimal_to_float, &float_from_decimal);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error_result_is_null) {
  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b11111111111111111111111111111111;

  mo_decimal decimal_to_float = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = mo_from_decimal_to_float(decimal_to_float, NULL);

  ck_assert_int_eq(res, 1);
}
END_TEST



Suite *suite_from_decimal_to_float(void) {
  Suite *s = suite_create("suite_from_decimal_to_float");
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, test_from_decimal_to_float_simple1);
  tcase_add_test(tc, test_from_decimal_to_float_simple2);
  tcase_add_test(tc, test_from_decimal_to_float_simple3);
  tcase_add_test(tc, test_from_decimal_to_float_simple4);
  tcase_add_test(tc, test_from_decimal_to_float_simple5);
  tcase_add_test(tc, test_from_decimal_to_float_simple_neg1);
  tcase_add_test(tc, test_from_decimal_to_float_simple_neg2);
  tcase_add_test(tc, test_from_decimal_to_float_simple_neg3);
  tcase_add_test(tc, test_from_decimal_to_float_simple_check_code1);
  tcase_add_test(tc, test_from_decimal_to_float_simple_check_code2);
  tcase_add_test(tc, test_from_decimal_to_float_simple_check_code3);
  tcase_add_test(tc, test_from_decimal_to_float_simple_check_code4);
  tcase_add_test(tc, test_from_decimal_to_float_simple_check_code5);
  tcase_add_test(tc, test_from_decimal_to_float_simple_check_code6);
  tcase_add_test(tc, test_from_decimal_to_float_simple_check_code7);
  tcase_add_test(tc, test_from_decimal_to_float_decimal1);
  tcase_add_test(tc, test_from_decimal_to_float_decimal2);
  tcase_add_test(tc, test_from_decimal_to_float_decimal3);
  tcase_add_test(tc, test_from_decimal_to_float_decimal4);
  tcase_add_test(tc, test_from_decimal_to_float_decimal5);
  tcase_add_test(tc, test_from_decimal_to_float_decimal6);
  tcase_add_test(tc, test_from_decimal_to_float_decimal7);
  tcase_add_test(tc, test_from_decimal_to_float_decimal8);
  tcase_add_test(tc, test_from_decimal_to_float_decimal9);
  tcase_add_test(tc, test_from_decimal_to_float_decimal10);
  tcase_add_test(tc, test_from_decimal_to_float_decimal11);
  tcase_add_test(tc, test_from_decimal_to_float_decimal12);
  tcase_add_test(tc, test_from_decimal_to_float_decimal13);
  tcase_add_test(tc, test_from_decimal_to_float_decimal14);
  tcase_add_test(tc, test_from_decimal_to_float_decimal15);

  tcase_add_test(tc, test_error1);
  tcase_add_test(tc, test_error2);
  tcase_add_test(tc, test_error3);
  tcase_add_test(tc, test_error_result_is_null);


  suite_add_tcase(s, tc);
  return s;

}