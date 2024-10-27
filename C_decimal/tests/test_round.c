#include "../tests_includes/s21_tests.h"

START_TEST(test_round_simple1) {
  float round_check = 5.01;
  float float_from_decimal = 0;
  s21_decimal result;
  s21_decimal round_dec = {{501, 0, 0, 0x20000}};

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST


START_TEST(test_round_simple2) {
  float round_check= 5.71;
  s21_decimal round_dec = {{571, 0, 0, 0x20000}};
  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);



  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_simple3) {
  float round_check= 5.7185;
  s21_decimal round_dec = {{57185, 0, 0, 0x40000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);

}
END_TEST

START_TEST(test_round_simple4) {
  float round_check= 2855.00;
  s21_decimal round_dec = {{285500, 0, 0, 0x20000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_simple5) {
  float round_check= 12.741253;
  s21_decimal round_dec = {{12741253, 0, 0, 0x60000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);


  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_simple6) {
  float round_check= 5.5;
  s21_decimal round_dec = {{55, 0, 0, 0x10000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);


  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_simple7) {
  float round_check= 5.4;
  s21_decimal round_dec = {{54, 0, 0, 0x10000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);


  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_simple8) {
  float round_check= 5.6;
  s21_decimal round_dec = {{56, 0, 0, 0x10000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);


  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_simple9) {
  float round_check= 5.51;
  s21_decimal round_dec = {{551, 0, 0, 0x20000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);


  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_simple10) {
  float round_check= 5.49;
  s21_decimal round_dec = {{549, 0, 0, 0x20000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);


  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_simple_neg1) {
  float round_check= -5.00;
  s21_decimal round_dec = {{500, 0, 0, 0x80020000}};
  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_simple_neg2) {
  float round_check= -5.16;
  s21_decimal round_dec = {{516, 0, 0, 0x80020000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_simple_neg3) {
  float round_check= -52.7589;
  s21_decimal round_dec = {{527589, 0, 0, 0x80040000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow1) {
  float round_check= 154748.20;
  s21_decimal round_dec = {{15474820, 0, 0, 0x20000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow2) {
  float round_check= 154748.2000;
  s21_decimal round_dec = {{1547482000, 0, 0, 0x40000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST


START_TEST(test_round_pow3) {
  float round_check= 12.74125377;
  s21_decimal round_dec = {{1274125377, 0, 0, 0x80000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow4) {
  float round_check= 11.24574253;
  s21_decimal round_dec = {{1124574253, 0, 0, 0x80000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow5) {
  float round_check= 0.741253;
  s21_decimal round_dec = {{741253, 0, 0, 0x60000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow6) {
  float round_check= 0.74125389;
  s21_decimal round_dec = {{74125389, 0, 0, 0x80000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow7) {
  float round_check= 0.74125381;
  s21_decimal round_dec = {{74125381, 0, 0, 0x80000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow8) {
  float round_check= 0.7412538;
  s21_decimal round_dec = {{7412538, 0, 0, 0x70000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow9) {
  float round_check= 21.4741253;
  s21_decimal round_dec = {{214741253, 0, 0, 0x70000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow10) {
  float round_check= 2.7412537;
  s21_decimal round_dec = {{27412537, 0, 0, 0x70000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow11) {
  float round_check= -4.7412553;
  s21_decimal round_dec = {{47412553, 0, 0, 0x80070000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST


START_TEST(test_round_pow12) {
  float round_check= -48.7412153;
  s21_decimal round_dec = {{487412153, 0, 0, 0x80070000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow13) {
  float round_check= -4588524.74;
  s21_decimal round_dec = {{458852474, 0, 0, 0x80020000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow14) {
  float round_check= 145885.74;
  s21_decimal round_dec = {{14588574, 0, 0, 0x20000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow15) {
  float round_check= 145885.7;
  s21_decimal round_dec = {{1458857, 0, 0, 0x10000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow16) {
  float round_check= 145885254.7;
  s21_decimal round_dec = {{1458852547, 0, 0, 0x10000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow17) {
  float round_check= -145885254.7;
  s21_decimal round_dec = {{1458852547, 0, 0, 0x80010000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow18) {
  float round_check= 0.00;
  s21_decimal round_dec = {{0, 0, 0, 0x0000000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow19) {
  float round_check= 0.01;
  s21_decimal round_dec = {{1, 0, 0, 0x20000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow20) {
  float round_check= -0.01;
  s21_decimal round_dec = {{1, 0, 0, 0x80020000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow21) {
  float round_check= 0.0001;
  s21_decimal round_dec = {{1, 0, 0, 0x40000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST



START_TEST(test_round_pow22) {
  float round_check= 100000.0001;
  s21_decimal round_dec = {{1000000001, 0, 0, 0x40000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow23) {
  float round_check= -0.0001;
  s21_decimal round_dec = {{1, 0, 0, 0x80040000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST


START_TEST(test_round_pow24) {
  float round_check= 100.2;
  s21_decimal round_dec = {{1002, 0, 0, 0x10000}};


  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);
}
END_TEST

START_TEST(test_round_pow25) {
  float round_check= 0.00000001;
  s21_decimal round_dec = {{1, 0, 0, 0x80000}};

  float float_from_decimal = 0;
  s21_decimal result;

  s21_round(round_dec, &result);
  s21_from_decimal_to_float(result, &float_from_decimal);

  ck_assert_float_eq(round(round_check), float_from_decimal);

}
END_TEST





START_TEST(test_round_simple_check_code1) {
  s21_decimal round_dec = {{1, 0, 0, 0x80000}};
  s21_decimal result;

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_round_simple_check_code2) {
  s21_decimal round_dec = {{1000000001, 0, 0, 0x80040000}};
  s21_decimal result;

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_round_simple_check_code3) {
  s21_decimal round_dec = {{1, 0, 0, 0x20000}};
  s21_decimal result;

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_round_simple_check_code4) {
  s21_decimal round_dec = {{458741253, 0, 0, 0x80070000}};
  s21_decimal result;

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 0);

}
END_TEST

START_TEST(test_round_simple_check_code5) {
  s21_decimal round_dec = {{214741253, 0, 0, 0x70000}};
  s21_decimal result;

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_round_simple_check_code6) {
  s21_decimal round_dec = {{74125389, 0, 0, 0x80000}};
  s21_decimal result;

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_round_simple_check_code7) {
  s21_decimal round_dec = {{1124574253, 0, 0, 0x80000}};
  s21_decimal result;

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_round_simple_check_code8) {
  s21_decimal round_dec = {{0, 0, 0, 0}};
  s21_decimal result;

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_round_simple_check_code9) {
  s21_decimal round_dec = {{0, 0, 0, 0x80000}};
  s21_decimal result;

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_round_simple_check_code10) {
  s21_decimal round_dec = {{2741253, 0, 0, 0x70000}};
  s21_decimal result;

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_round_simple_check_code11) {
  s21_decimal round_dec = {{1, 0, 0, 0x20000}};
  s21_decimal result;

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_error1) {

  // степень 255 (показатель степени должен быть от 0 до 28)

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b00000000111111110000000000000000;

  s21_decimal result;
  s21_decimal round_dec = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = s21_round(round_dec, &result);

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

  s21_decimal result;
  s21_decimal round_dec = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error3) {

  // все единицы

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b11111111111111111111111111111111;
  s21_decimal result;
  s21_decimal round_dec = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = s21_round(round_dec, &result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error_result_is_null) {
  s21_decimal round_dec = {{0, 0, 0, 0}};

  int res =  s21_round(round_dec, NULL);
  ck_assert_int_eq(res, 1);
}

END_TEST




Suite *suite_round(void) {
  Suite *s = suite_create("suite_round");
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, test_round_simple1);

  tcase_add_test(tc, test_round_simple2);
  tcase_add_test(tc, test_round_simple3);
  tcase_add_test(tc, test_round_simple4);
  tcase_add_test(tc, test_round_simple5);
  tcase_add_test(tc, test_round_simple6);
  tcase_add_test(tc, test_round_simple7);
  tcase_add_test(tc, test_round_simple8);
  tcase_add_test(tc, test_round_simple9);
  tcase_add_test(tc, test_round_simple10);

  tcase_add_test(tc, test_round_simple_neg1);
  tcase_add_test(tc, test_round_simple_neg2);
  tcase_add_test(tc, test_round_simple_neg3);

  tcase_add_test(tc, test_round_pow1);
  tcase_add_test(tc, test_round_pow2);

  tcase_add_test(tc, test_round_pow3);
  tcase_add_test(tc, test_round_pow4);
  tcase_add_test(tc, test_round_pow5);
  tcase_add_test(tc, test_round_pow6);
  tcase_add_test(tc, test_round_pow7);
  tcase_add_test(tc, test_round_pow8);
  tcase_add_test(tc, test_round_pow9);
  tcase_add_test(tc, test_round_pow10);
  tcase_add_test(tc, test_round_pow11);
  tcase_add_test(tc, test_round_pow12);
  tcase_add_test(tc, test_round_pow13);
  tcase_add_test(tc, test_round_pow14);
  tcase_add_test(tc, test_round_pow15);
  tcase_add_test(tc, test_round_pow16);
  tcase_add_test(tc, test_round_pow17);
  tcase_add_test(tc, test_round_pow18);
  tcase_add_test(tc, test_round_pow19);
  tcase_add_test(tc, test_round_pow20);
  tcase_add_test(tc, test_round_pow21);
  tcase_add_test(tc, test_round_pow22);
  tcase_add_test(tc, test_round_pow23);
  tcase_add_test(tc, test_round_pow24);
  tcase_add_test(tc, test_round_pow25);

  tcase_add_test(tc, test_round_simple_check_code1);
  tcase_add_test(tc, test_round_simple_check_code2);
  tcase_add_test(tc, test_round_simple_check_code3);
  tcase_add_test(tc, test_round_simple_check_code4);
  tcase_add_test(tc, test_round_simple_check_code5);
  tcase_add_test(tc, test_round_simple_check_code6);
  tcase_add_test(tc, test_round_simple_check_code7);
  tcase_add_test(tc, test_round_simple_check_code8);
  tcase_add_test(tc, test_round_simple_check_code9);
  tcase_add_test(tc, test_round_simple_check_code10);
  tcase_add_test(tc, test_round_simple_check_code11);

  tcase_add_test(tc, test_error1);
  tcase_add_test(tc, test_error2);
  tcase_add_test(tc, test_error3);
  tcase_add_test(tc, test_error_result_is_null);





  suite_add_tcase(s, tc);
  return s;

}