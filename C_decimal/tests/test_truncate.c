#include "../tests_includes/mo_tests.h"

START_TEST(test_truncate_simple1) {
  int truncate_check = 5;
  int int_from_decimal = 0;
  mo_decimal result;
  mo_decimal truncate_dec = {{501, 0, 0, 0x20000}};

  mo_truncate(truncate_dec, &result);

  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST


START_TEST(test_truncate_simple2) {
  int truncate_check= 5;
  mo_decimal truncate_dec = {{571, 0, 0, 0x20000}};
  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);



  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_simple3) {
  int truncate_check= 5;
  mo_decimal truncate_dec = {{57185, 0, 0, 0x40000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);

}
END_TEST

START_TEST(test_truncate_simple4) {
  int truncate_check= 2855.00;
  mo_decimal truncate_dec = {{285500, 0, 0, 0x20000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_simple5) {
  int truncate_check= 12;
  mo_decimal truncate_dec = {{12741253, 0, 0, 0x60000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);


  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_simple6) {
  int truncate_check= 5;
  mo_decimal truncate_dec = {{55, 0, 0, 0x10000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);


  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_simple7) {
  int truncate_check= 5;
  mo_decimal truncate_dec = {{54, 0, 0, 0x10000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);


  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_simple8) {
  int truncate_check= 5;
  mo_decimal truncate_dec = {{56, 0, 0, 0x10000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);


  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_simple9) {
  int truncate_check= 5;
  mo_decimal truncate_dec = {{551, 0, 0, 0x20000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);


  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_simple10) {
  int truncate_check= 5;
  mo_decimal truncate_dec = {{549, 0, 0, 0x20000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);


  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_simple_neg1) {
  int truncate_check= -5;
  mo_decimal truncate_dec = {{500, 0, 0, 0x80020000}};
  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_simple_neg2) {
  int truncate_check= -5;
  mo_decimal truncate_dec = {{516, 0, 0, 0x80020000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_simple_neg3) {
  int truncate_check= -52;
  mo_decimal truncate_dec = {{527589, 0, 0, 0x80040000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow1) {
  int truncate_check= 154748;
  mo_decimal truncate_dec = {{15474820, 0, 0, 0x20000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow2) {
  int truncate_check= 154748;
  mo_decimal truncate_dec = {{1547482000, 0, 0, 0x40000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST


START_TEST(test_truncate_pow3) {
  int truncate_check= 12;
  mo_decimal truncate_dec = {{1274125377, 0, 0, 0x80000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow4) {
  int truncate_check= 11;
  mo_decimal truncate_dec = {{1124574253, 0, 0, 0x80000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow5) {
  int truncate_check= 0;
  mo_decimal truncate_dec = {{741253, 0, 0, 0x60000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow6) {
  int truncate_check= 0;
  mo_decimal truncate_dec = {{74125389, 0, 0, 0x80000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow7) {
  int truncate_check= 0;
  mo_decimal truncate_dec = {{74125381, 0, 0, 0x80000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow8) {
  int truncate_check= 0;
  mo_decimal truncate_dec = {{7412538, 0, 0, 0x70000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow9) {
  int truncate_check= 21;
  mo_decimal truncate_dec = {{214741253, 0, 0, 0x70000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow10) {
  int truncate_check= 2;
  mo_decimal truncate_dec = {{27412537, 0, 0, 0x70000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow11) {
  int truncate_check= -4;
  mo_decimal truncate_dec = {{47412553, 0, 0, 0x80070000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST


START_TEST(test_truncate_pow12) {
  int truncate_check= -48;
  mo_decimal truncate_dec = {{487412153, 0, 0, 0x80070000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow13) {
  int truncate_check= -4588524;
  mo_decimal truncate_dec = {{458852474, 0, 0, 0x80020000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow14) {
  int truncate_check= 145885;
  mo_decimal truncate_dec = {{14588574, 0, 0, 0x20000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow15) {
  int truncate_check= 145885;
  mo_decimal truncate_dec = {{1458857, 0, 0, 0x10000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow16) {
  int truncate_check= 145885254;
  mo_decimal truncate_dec = {{1458852547, 0, 0, 0x10000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow17) {
  int truncate_check= -145885254;
  mo_decimal truncate_dec = {{1458852547, 0, 0, 0x80010000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow18) {
  int truncate_check= 0;
  mo_decimal truncate_dec = {{0, 0, 0, 0x0000000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow19) {
  int truncate_check= 0;
  mo_decimal truncate_dec = {{1, 0, 0, 0x20000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow20) {
  int truncate_check= 0;
  mo_decimal truncate_dec = {{1, 0, 0, 0x80020000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow21) {
  int truncate_check= 0;
  mo_decimal truncate_dec = {{1, 0, 0, 0x40000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST



START_TEST(test_truncate_pow22) {
  int truncate_check= 100000;
  mo_decimal truncate_dec = {{1000000001, 0, 0, 0x40000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow23) {
  int truncate_check= 0;
  mo_decimal truncate_dec = {{1, 0, 0, 0x80040000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST


START_TEST(test_truncate_pow24) {
  int truncate_check= 100;
  mo_decimal truncate_dec = {{1002, 0, 0, 0x10000}};


  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);
}
END_TEST

START_TEST(test_truncate_pow25) {
  int truncate_check= 0;
  mo_decimal truncate_dec = {{1, 0, 0, 0x80000}};

  int int_from_decimal = 0;
  mo_decimal result;

  mo_truncate(truncate_dec, &result);
  mo_from_decimal_to_int(result, &int_from_decimal);

  ck_assert_int_eq(truncate_check, int_from_decimal);

}
END_TEST


START_TEST(test_truncate_simple_check_code1) {
  mo_decimal truncate_dec = {{1, 0, 0, 0x80000}};
  mo_decimal result;

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_truncate_simple_check_code2) {
  mo_decimal truncate_dec = {{1000000001, 0, 0, 0x80040000}};
  mo_decimal result;

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_truncate_simple_check_code3) {
  mo_decimal truncate_dec = {{1, 0, 0, 0x20000}};
  mo_decimal result;

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_truncate_simple_check_code4) {
  mo_decimal truncate_dec = {{458741253, 0, 0, 0x80070000}};
  mo_decimal result;

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 0);

}
END_TEST

START_TEST(test_truncate_simple_check_code5) {
  mo_decimal truncate_dec = {{214741253, 0, 0, 0x70000}};
  mo_decimal result;

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_truncate_simple_check_code6) {
  mo_decimal truncate_dec = {{74125389, 0, 0, 0x80000}};
  mo_decimal result;

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_truncate_simple_check_code7) {
  mo_decimal truncate_dec = {{1124574253, 0, 0, 0x80000}};
  mo_decimal result;

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_truncate_simple_check_code8) {
  mo_decimal truncate_dec = {{0, 0, 0, 0}};
  mo_decimal result;

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_truncate_simple_check_code9) {
  mo_decimal truncate_dec = {{0, 0, 0, 0x80000}};
  mo_decimal result;

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_truncate_simple_check_code10) {
  mo_decimal truncate_dec = {{2741253, 0, 0, 0x70000}};
  mo_decimal result;

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_truncate_simple_check_code11) {
  mo_decimal truncate_dec = {{1, 0, 0, 0x20000}};
  mo_decimal result;

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_error1) {

  // степень 255 (показатель степени должен быть от 0 до 28)

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b00000000111111110000000000000000;

  mo_decimal result;
  mo_decimal truncate_dec = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = mo_truncate(truncate_dec, &result);

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

  mo_decimal result;
  mo_decimal truncate_dec = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error3) {

  // все единицы

  int decimal1_1 = 0b111;
  int decimal1_2 = 0b111;
  int decimal1_3 = 0b111;
  int decimal1_4 = 0b11111111111111111111111111111111;

  mo_decimal result;
  mo_decimal truncate_dec = {{decimal1_1, decimal1_2, decimal1_3, decimal1_4}};

  int res = mo_truncate(truncate_dec, &result);

  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(test_error_result_is_null) {
  mo_decimal truncate_dec = {{0, 0, 0, 0}};

  int res =  mo_truncate(truncate_dec, NULL);
  ck_assert_int_eq(res, 1);
}

END_TEST




Suite *suite_truncate(void) {
  Suite *s = suite_create("suite_truncate");
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, test_truncate_simple1);
  tcase_add_test(tc, test_truncate_simple2);

  tcase_add_test(tc, test_truncate_simple3);
  tcase_add_test(tc, test_truncate_simple4);
  tcase_add_test(tc, test_truncate_simple5);
  tcase_add_test(tc, test_truncate_simple6);
  tcase_add_test(tc, test_truncate_simple7);
  tcase_add_test(tc, test_truncate_simple8);
  tcase_add_test(tc, test_truncate_simple9);
  tcase_add_test(tc, test_truncate_simple10);

  tcase_add_test(tc, test_truncate_simple_neg1);
  tcase_add_test(tc, test_truncate_simple_neg2);
  tcase_add_test(tc, test_truncate_simple_neg3);

  tcase_add_test(tc, test_truncate_pow1);
  tcase_add_test(tc, test_truncate_pow2);

  tcase_add_test(tc, test_truncate_pow3);
  tcase_add_test(tc, test_truncate_pow4);
  tcase_add_test(tc, test_truncate_pow5);
  tcase_add_test(tc, test_truncate_pow6);
  tcase_add_test(tc, test_truncate_pow7);
  tcase_add_test(tc, test_truncate_pow8);
  tcase_add_test(tc, test_truncate_pow9);
  tcase_add_test(tc, test_truncate_pow10);
  tcase_add_test(tc, test_truncate_pow11);
  tcase_add_test(tc, test_truncate_pow12);
  tcase_add_test(tc, test_truncate_pow13);
  tcase_add_test(tc, test_truncate_pow14);
  tcase_add_test(tc, test_truncate_pow15);
  tcase_add_test(tc, test_truncate_pow16);
  tcase_add_test(tc, test_truncate_pow17);
  tcase_add_test(tc, test_truncate_pow18);
  tcase_add_test(tc, test_truncate_pow19);
  tcase_add_test(tc, test_truncate_pow20);
  tcase_add_test(tc, test_truncate_pow21);
  tcase_add_test(tc, test_truncate_pow22);
  tcase_add_test(tc, test_truncate_pow23);
  tcase_add_test(tc, test_truncate_pow24);
  tcase_add_test(tc, test_truncate_pow25);

  tcase_add_test(tc, test_truncate_simple_check_code1);
  tcase_add_test(tc, test_truncate_simple_check_code2);
  tcase_add_test(tc, test_truncate_simple_check_code3);
  tcase_add_test(tc, test_truncate_simple_check_code4);
  tcase_add_test(tc, test_truncate_simple_check_code5);
  tcase_add_test(tc, test_truncate_simple_check_code6);
  tcase_add_test(tc, test_truncate_simple_check_code7);
  tcase_add_test(tc, test_truncate_simple_check_code8);
  tcase_add_test(tc, test_truncate_simple_check_code9);
  tcase_add_test(tc, test_truncate_simple_check_code10);
  tcase_add_test(tc, test_truncate_simple_check_code11);

  tcase_add_test(tc, test_error1);
  tcase_add_test(tc, test_error2);
  tcase_add_test(tc, test_error3);
  tcase_add_test(tc, test_error_result_is_null);





  suite_add_tcase(s, tc);
  return s;

}