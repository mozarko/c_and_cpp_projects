#ifndef TESTS_H
#define TESTS_H

#include <check.h>

#include "../brick_game/tetris/inc/tetris.h"

Suite *suite_tetris(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif
