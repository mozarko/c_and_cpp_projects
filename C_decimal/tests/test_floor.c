#include "../tests_includes/s21_tests.h"

START_TEST(test_floor_simple1) {
  float floor_check = 5.01;
  float float_from_decimal = 0;
  s21_decimal result;
  s21_decimal decimal_floor = {{501, 0, 0, 0x20000}};

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST


START_TEST(test_floor_simple2) {
  float floor_check= 5.71;
  s21_decimal decimal_floor = {{571, 0, 0, 0x20000}};
  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_simple3) {
  float floor_check= 5.7185;
  s21_decimal decimal_floor = {{57185, 0, 0, 0x40000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);

}
END_TEST

START_TEST(test_floor_simple4) {
  float floor_check= 2855.00;
  s21_decimal decimal_floor = {{285500, 0, 0, 0x20000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_simple5) {
  float floor_check= 12.741253;
  s21_decimal decimal_floor = {{12741253, 0, 0, 0x60000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_simple_neg1) {
  float floor_check= -5.00;
  s21_decimal decimal_floor = {{500, 0, 0, 0x80020000}};
  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_simple_neg2) {
  float floor_check= -5.16;
  s21_decimal decimal_floor = {{516, 0, 0, 0x80020000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_simple_neg3) {
  float floor_check= -52.7589;
  s21_decimal decimal_floor = {{527589, 0, 0, 0x80040000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow1) {
  float floor_check= 154748.20;
  s21_decimal decimal_floor = {{15474820, 0, 0, 0x20000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow2) {
  float floor_check= 154748.2000;
  s21_decimal decimal_floor = {{1547482000, 0, 0, 0x40000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST


START_TEST(test_floor_pow3) {
  float floor_check= 12.74125377;
  s21_decimal decimal_floor = {{1274125377, 0, 0, 0x80000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow4) {
  float floor_check= 11.24574253;
  s21_decimal decimal_floor = {{1124574253, 0, 0, 0x80000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow5) {
  float floor_check= 0.741253;
  s21_decimal decimal_floor = {{741253, 0, 0, 0x60000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow6) {
  float floor_check= 0.74125389;
  s21_decimal decimal_floor = {{74125389, 0, 0, 0x80000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow7) {
  float floor_check= 0.74125381;
  s21_decimal decimal_floor = {{74125381, 0, 0, 0x80000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow8) {
  float floor_check= 0.7412538;
  s21_decimal decimal_floor = {{7412538, 0, 0, 0x70000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow9) {
  float floor_check= 21.4741253;
  s21_decimal decimal_floor = {{214741253, 0, 0, 0x70000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow10) {
  float floor_check= 2.7412537;
  s21_decimal decimal_floor = {{27412537, 0, 0, 0x70000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow11) {
  float floor_check= -4.7412553;
  s21_decimal decimal_floor = {{47412553, 0, 0, 0x80070000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST


START_TEST(test_floor_pow12) {
  float floor_check= -48.7412153;
  s21_decimal decimal_floor = {{487412153, 0, 0, 0x80070000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow13) {
  float floor_check= -4588524.74;
  s21_decimal decimal_floor = {{458852474, 0, 0, 0x80020000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow14) {
  float floor_check= 145885.74;
  s21_decimal decimal_floor = {{14588574, 0, 0, 0x20000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow15) {
  float floor_check= 145885.7;
  s21_decimal decimal_floor = {{1458857, 0, 0, 0x10000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow16) {
  float floor_check= 145885254.7;
  s21_decimal decimal_floor = {{1458852547, 0, 0, 0x10000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow17) {
  float floor_check= -145885254.7;
  s21_decimal decimal_floor = {{1458852547, 0, 0, 0x80010000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow18) {
  float floor_check= 0.00;
  s21_decimal decimal_floor = {{0, 0, 0, 0x0000000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow19) {
  float floor_check= 0.01;
  s21_decimal decimal_floor = {{1, 0, 0, 0x20000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow20) {
  float floor_check= -0.01;
  s21_decimal decimal_floor = {{1, 0, 0, 0x80020000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow21) {
  float floor_check= 0.0001;
  s21_decimal decimal_floor = {{1, 0, 0, 0x40000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST



START_TEST(test_floor_pow22) {
  float floor_check= 100000.0001;
  s21_decimal decimal_floor = {{1000000001, 0, 0, 0x40000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow23) {
  float floor_check= -0.0001;
  s21_decimal decimal_floor = {{1, 0, 0, 0x80040000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST


START_TEST(test_floor_pow24) {
  float floor_check= 100.2;
  s21_decimal decimal_floor = {{1002, 0, 0, 0x10000}};


  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);
}
END_TEST

START_TEST(test_floor_pow25) {
  float floor_check= 0.00000001;
  s21_decimal decimal_floor = {{1, 0, 0, 0x80000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_floor(decimal_floor, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(floor(floor_check), float_from_decimal);

}
END_TEST





START_TEST(test_floor_simple_check_code1) {
  s21_decimal decimal_floor = {{1, 0, 0, 0x80000}};
  s21_decimal result;

  int res = s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_floor_simple_check_code2) {
  s21_decimal decimal_floor = {{1000000001, 0, 0, 0x80040000}};
  s21_decimal result;

  int res = s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_floor_simple_check_code3) {
  s21_decimal decimal_floor = {{1, 0, 0, 0x20000}};
  s21_decimal result;

  int res = s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_floor_simple_check_code4) {
  s21_decimal decimal_floor = {{458741253, 0, 0, 0x80070000}};
  s21_decimal result;

  int res = s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 0);

}
END_TEST

START_TEST(test_floor_simple_check_code5) {
  s21_decimal decimal_floor = {{214741253, 0, 0, 0x70000}};
  s21_decimal result;

  int res = s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_floor_simple_check_code6) {
  s21_decimal decimal_floor = {{74125389, 0, 0, 0x80000}};
  s21_decimal result;

  int res = s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_floor_simple_check_code7) {
  s21_decimal decimal_floor = {{1124574253, 0, 0, 0x80000}};
  s21_decimal result;

  int res = s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_floor_simple_check_code8) {
  s21_decimal decimal_floor = {{0, 0, 0, 0}};
  s21_decimal result;

  int res = s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_floor_simple_check_code9) {
  s21_decimal decimal_floor = {{0, 0, 0, 0x80000}};
  s21_decimal result;

  int res = s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_floor_simple_check_code10) {
  s21_decimal decimal_floor = {{2741253, 0, 0, 0x70000}};
  s21_decimal result;

  int res = s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_floor_simple_check_code11) {
  s21_decimal decimal_floor = {{1, 0, 0, 0x20000}};
  s21_decimal result;

  int res = s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_error1) {

  // степень 255 (показатель степени должен быть от 0 до 28)
  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b00000000111111110000000000000000;

  s21_decimal decimal_floor = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  s21_decimal result;
  int res =  s21_floor(decimal_floor, &result);

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

  s21_decimal decimal_floor = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  s21_decimal result;
  int res =  s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error3) {

  // все единицы

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b11111111111111111111111111111111;

  s21_decimal decimal_floor = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  s21_decimal result;
  int res =  s21_floor(decimal_floor, &result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error_result_is_null) {
  s21_decimal decimal_floor = {{0, 0, 0, 0}};

  int code = s21_floor(decimal_floor, NULL);

  ck_assert_int_eq(code, 1);
}
END_TEST


Suite *suite_floor(void) {
  Suite *s = suite_create("suite_floor");
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, test_floor_simple1);

  tcase_add_test(tc, test_floor_simple2);
  tcase_add_test(tc, test_floor_simple3);
  tcase_add_test(tc, test_floor_simple4);
  tcase_add_test(tc, test_floor_simple5);
  tcase_add_test(tc, test_floor_simple_neg1);
  tcase_add_test(tc, test_floor_simple_neg2);
  tcase_add_test(tc, test_floor_simple_neg3);

  tcase_add_test(tc, test_floor_pow1);
  tcase_add_test(tc, test_floor_pow2);

  tcase_add_test(tc, test_floor_pow3);
  tcase_add_test(tc, test_floor_pow4);
  tcase_add_test(tc, test_floor_pow5);
  tcase_add_test(tc, test_floor_pow6);
  tcase_add_test(tc, test_floor_pow7);
  tcase_add_test(tc, test_floor_pow8);
  tcase_add_test(tc, test_floor_pow9);
  tcase_add_test(tc, test_floor_pow10);
  tcase_add_test(tc, test_floor_pow11);
  tcase_add_test(tc, test_floor_pow12);
  tcase_add_test(tc, test_floor_pow13);
  tcase_add_test(tc, test_floor_pow14);
  tcase_add_test(tc, test_floor_pow15);
  tcase_add_test(tc, test_floor_pow16);
  tcase_add_test(tc, test_floor_pow17);
  tcase_add_test(tc, test_floor_pow18);
  tcase_add_test(tc, test_floor_pow19);
  tcase_add_test(tc, test_floor_pow20);
  tcase_add_test(tc, test_floor_pow21);
  tcase_add_test(tc, test_floor_pow22);
  tcase_add_test(tc, test_floor_pow23);
  tcase_add_test(tc, test_floor_pow24);
  tcase_add_test(tc, test_floor_pow25);

  tcase_add_test(tc, test_floor_simple_check_code1);
  tcase_add_test(tc, test_floor_simple_check_code2);
  tcase_add_test(tc, test_floor_simple_check_code3);
  tcase_add_test(tc, test_floor_simple_check_code4);
  tcase_add_test(tc, test_floor_simple_check_code5);
  tcase_add_test(tc, test_floor_simple_check_code6);
  tcase_add_test(tc, test_floor_simple_check_code7);
  tcase_add_test(tc, test_floor_simple_check_code8);
  tcase_add_test(tc, test_floor_simple_check_code9);
  tcase_add_test(tc, test_floor_simple_check_code10);
  tcase_add_test(tc, test_floor_simple_check_code11);

  tcase_add_test(tc, test_error1);
  tcase_add_test(tc, test_error2);
  tcase_add_test(tc, test_error3);

  tcase_add_test(tc, test_error_result_is_null);





  suite_add_tcase(s, tc);
  return s;

}