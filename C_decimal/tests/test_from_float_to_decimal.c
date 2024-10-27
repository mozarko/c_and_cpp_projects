#include "../tests_includes/mo_tests.h"


START_TEST(test_from_float_to_decimal_simple1) {

  float float_to_decimal= 5.00;
  mo_decimal result;
  mo_decimal decimal_check = {{500, 0, 0, 0x20000}};

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple2) {
  float float_to_decimal= 5.71;
  mo_decimal result;
  mo_decimal decimal_check = {{571, 0, 0, 0x20000}};

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple3) {
  float float_to_decimal= 5.7185;
  mo_decimal result;
  mo_decimal decimal_check = {{57185, 0, 0, 0x40000}};

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple4) {
  float float_to_decimal= 2855.00;
  mo_decimal result;
  mo_decimal decimal_check = {{285500, 0, 0, 0x20000}};

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple5) {
  float float_to_decimal= 12.741253;
  mo_decimal result;
  mo_decimal decimal_check = {{12741253, 0, 0, 0x60000}};

  char res[50] = {0};
  strcpy(res, decimal_to_string(decimal_check));
  strcat(res, "000000000000000000000");

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_neg1) {
  float float_to_decimal= -5.00;
  mo_decimal result;
  mo_decimal decimal_check = {{500, 0, 0, 0x80020000}};

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_neg2) {
  float float_to_decimal= -5.16;
  mo_decimal result;
  mo_decimal decimal_check = {{516, 0, 0, 0x80020000}};

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_neg3) {
  float float_to_decimal= -52.7589;
  mo_decimal result;
  mo_decimal decimal_check = {{527589, 0, 0, 0x80040000}};

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_neg4) {
  float float_to_decimal= -5;
  mo_decimal result;
  mo_decimal decimal_check = {{5, 0, 0, 0x80000000}};

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(mo_is_equal(result, decimal_check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow1) {
  float float_to_decimal= 154748.20;
  mo_decimal result;

  char res[50] = "154748.203125";
  strcat(res, "00000000000000000");

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow2) {
  float float_to_decimal= 154748.200000;
  mo_decimal result;

  char res[50] = "154748.203125";
  strcat(res, "00000000000000000");

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow3) {
  float float_to_decimal= 12.74125377;
  mo_decimal result;

  char res[50] = "12.741254";
  strcat(res, "000000000000000000000");

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_str_eq(decimal_to_string(result), res);

}
END_TEST

START_TEST(test_from_float_to_decimal_pow4) {
  float float_to_decimal= 1551245.741253;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "1551245.75";
  strcat(res, "00000000000000000000");

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow5) {
  float float_to_decimal= 0.741253;
  int decimal1 = 0b10110100111110000101;
  int decimal2 = 0b0;
  mo_decimal result;
  mo_decimal decimal_check = {{decimal1, decimal2, 0, 0x60000}};
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = {0};
  strcpy(res, decimal_to_string(decimal_check));
  strcat(res, "0000000000000000000000");

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow6) {
  float float_to_decimal= 0.74125389;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "0.741254";
  strcat(res, "0000000000000000000000");

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow7) {
  float float_to_decimal= 0.74125381;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "0.741254";
  strcat(res, "0000000000000000000000");

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow8) {
  float float_to_decimal= 0.7412538;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "0.741254";
  strcat(res, "0000000000000000000000");

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow9) {
  float float_to_decimal= 21474836.741253;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "21474836";

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow10) {
  mo_decimal result;
  mo_from_float_to_decimal(MAX_FLOAT_TO_CONVERT, &result);

  char res[50] = "79228157791897854723898736640";

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow11) {
  mo_decimal result;
  mo_from_float_to_decimal(MIN_FLOAT_TO_CONVERT, &result);

  char res[50] = "0";

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST


START_TEST(test_from_float_to_decimal_pow12) {
  float float_to_decimal= -1551245.741253;
  mo_decimal result;

  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "-1551245.75";
  strcat(res, "00000000000000000000");

  mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow13) {
  float float_to_decimal= -0.741253;
  int decimal1 = 0b10110100111110000101;
  int decimal2 = 0b0;
  mo_decimal result;
  mo_decimal decimal_check = {{decimal1, decimal2, 0, 0x80060000}};
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = {0};
  strcpy(res, decimal_to_string(decimal_check));
  strcat(res, "0000000000000000000000");

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow14) {
  float float_to_decimal= -0.74125389;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "-0.741254";
  strcat(res, "0000000000000000000000");

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow15) {
  float float_to_decimal= -0.74125381;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "-0.741254";
  strcat(res, "0000000000000000000000");

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow16) {
  float float_to_decimal= -0.7412538;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "-0.741254";
  strcat(res, "0000000000000000000000");

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow17) {
  float float_to_decimal= -21474836.741253;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "-21474836";

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow18) {
  float float_to_decimal= 0.00;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "0";

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow19) {
  float float_to_decimal= 0.01;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "0.0100000000000000000000000000";

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow20) {
  float float_to_decimal= -0.01;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "-0.0100000000000000000000000000";

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow21) {
  float float_to_decimal= 0.0001;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "0.0001000000000000000000000000";

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST



START_TEST(test_from_float_to_decimal_pow22) {
  float float_to_decimal= 100000.0001;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "100000";

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow23) {
  float float_to_decimal= -0.0001;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "-0.0001000000000000000000000000";

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST


START_TEST(test_from_float_to_decimal_pow24) {
  float float_to_decimal= -100000.0001;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "-100000";

  ck_assert_str_eq(decimal_to_string(result), res);
}
END_TEST

START_TEST(test_from_float_to_decimal_pow25) {
  float float_to_decimal = 1312312412421124312.0058;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "1312312345166348288";

  ck_assert_str_eq(decimal_to_string(result), res);

}
END_TEST

START_TEST(test_from_float_to_decimal_pow26) {
  float float_to_decimal = -0.0;
  mo_decimal result;
  mo_from_float_to_decimal(float_to_decimal, &result);

  char res[50] = "0";

  ck_assert_str_eq(decimal_to_string(result), res);

}
END_TEST



START_TEST(test_from_float_to_decimal_simple_check_code1) {
  float float_to_decimal= 5.01;
  mo_decimal result;

  int res = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_check_code2) {
  float float_to_decimal= 5589.458915;
  mo_decimal result;

  int res = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_check_code3) {
  float float_to_decimal= 546875.125687;
  mo_decimal result;

  int res = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_check_code4) {
  float float_to_decimal= 2147483647.1;
  mo_decimal result;

  int res = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(res, 0);

}
END_TEST

START_TEST(test_from_float_to_decimal_simple_check_code5) {
  float float_to_decimal= -2147483648.1;
  mo_decimal result;

  int res = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_check_code6) {
  float float_to_decimal= 85687.458962547;
  mo_decimal result;

  int res = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_check_code7) {
  float float_to_decimal= 0;
  mo_decimal result;

  int res = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_check_code8) {
  float float_to_decimal= 0.468748484847;
  mo_decimal result;

  int res = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_check_code9) {
  float float_to_decimal= -0.468748484847;
  mo_decimal result;

  int res = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_check_code10) {
  float float_to_decimal= -498546570.468748484847;
  mo_decimal result;

  int res = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_from_float_to_decimal_simple_check_code11) {

  float float_to_decimal= 498546570.468748484847;
  mo_decimal result;

  int res = mo_from_float_to_decimal(float_to_decimal, &result);
  ck_assert_int_eq(res, 0);

}
END_TEST

START_TEST(test_error_result_is_null) {
  float float_to_decimal = 5.00;

  int code = mo_from_float_to_decimal(float_to_decimal, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_error1) {
  float float_to_decimal = MAX_FLOAT_TO_CONVERT+MAX_FLOAT_TO_CONVERT;
  mo_decimal result;

  int code = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_error2) {
  mo_decimal result;

  int code = mo_from_float_to_decimal(INFINITY, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_error3) {
  mo_decimal result;

  int code = mo_from_float_to_decimal(-INFINITY, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_error4) {
  mo_decimal result;

  int code = mo_from_float_to_decimal(NAN, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_error5) {
  mo_decimal result;

  int code = mo_from_float_to_decimal(-NAN, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_error6) {
  float float_to_decimal = 0.00000000000000000000000000000000001;
  mo_decimal result;

  int code = mo_from_float_to_decimal(float_to_decimal, &result);

  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *suite_from_float_to_decimal(void) {
  Suite *s = suite_create("suite_from_float_to_decimal");
  TCase *tc = tcase_create("add_tc");


  tcase_add_test(tc, test_from_float_to_decimal_simple1);
  tcase_add_test(tc, test_from_float_to_decimal_simple2);
  tcase_add_test(tc, test_from_float_to_decimal_simple3);
  tcase_add_test(tc, test_from_float_to_decimal_simple4);
  tcase_add_test(tc, test_from_float_to_decimal_simple5);
  tcase_add_test(tc, test_from_float_to_decimal_simple_neg1);
  tcase_add_test(tc, test_from_float_to_decimal_simple_neg2);
  tcase_add_test(tc, test_from_float_to_decimal_simple_neg3);
  tcase_add_test(tc, test_from_float_to_decimal_simple_neg4);


  tcase_add_test(tc, test_from_float_to_decimal_pow1);
  tcase_add_test(tc, test_from_float_to_decimal_pow2);
  tcase_add_test(tc, test_from_float_to_decimal_pow3);
  tcase_add_test(tc, test_from_float_to_decimal_pow4);
  tcase_add_test(tc, test_from_float_to_decimal_pow5);
  tcase_add_test(tc, test_from_float_to_decimal_pow6);
  tcase_add_test(tc, test_from_float_to_decimal_pow7);
  tcase_add_test(tc, test_from_float_to_decimal_pow8);
  tcase_add_test(tc, test_from_float_to_decimal_pow9);
  tcase_add_test(tc, test_from_float_to_decimal_pow10);
  tcase_add_test(tc, test_from_float_to_decimal_pow11);
  tcase_add_test(tc, test_from_float_to_decimal_pow12);
  tcase_add_test(tc, test_from_float_to_decimal_pow13);
  tcase_add_test(tc, test_from_float_to_decimal_pow14);
  tcase_add_test(tc, test_from_float_to_decimal_pow15);
  tcase_add_test(tc, test_from_float_to_decimal_pow16);
  tcase_add_test(tc, test_from_float_to_decimal_pow17);
  tcase_add_test(tc, test_from_float_to_decimal_pow18);
  tcase_add_test(tc, test_from_float_to_decimal_pow19);
  tcase_add_test(tc, test_from_float_to_decimal_pow20);
  tcase_add_test(tc, test_from_float_to_decimal_pow21);
  tcase_add_test(tc, test_from_float_to_decimal_pow22);
  tcase_add_test(tc, test_from_float_to_decimal_pow23);
  tcase_add_test(tc, test_from_float_to_decimal_pow24);
  tcase_add_test(tc, test_from_float_to_decimal_pow25);
  tcase_add_test(tc, test_from_float_to_decimal_pow26);


  tcase_add_test(tc, test_from_float_to_decimal_simple_check_code1);
  tcase_add_test(tc, test_from_float_to_decimal_simple_check_code2);
  tcase_add_test(tc, test_from_float_to_decimal_simple_check_code3);
  tcase_add_test(tc, test_from_float_to_decimal_simple_check_code4);
  tcase_add_test(tc, test_from_float_to_decimal_simple_check_code5);
  tcase_add_test(tc, test_from_float_to_decimal_simple_check_code6);
  tcase_add_test(tc, test_from_float_to_decimal_simple_check_code7);
  tcase_add_test(tc, test_from_float_to_decimal_simple_check_code8);
  tcase_add_test(tc, test_from_float_to_decimal_simple_check_code9);
  tcase_add_test(tc, test_from_float_to_decimal_simple_check_code10);
  tcase_add_test(tc, test_from_float_to_decimal_simple_check_code11);

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