#include "tests.h"

START_TEST(test_1) {
  GameInfo_t *game = get_game_info();
  add_score(0);
  ck_assert_int_eq(game->score, 0);
  add_score(1);
  ck_assert_int_eq(game->score, 100);
  add_score(2);
  ck_assert_int_eq(game->score, 400);
  add_score(3);
  ck_assert_int_eq(game->score, 1100);
  add_score(4);
  ck_assert_int_eq(game->score, 2600);
  game->score = 0;
  int high_score = check_records();
  ck_assert_int_eq(check_records(), high_score);
}
END_TEST

START_TEST(test_2) {
  ck_assert_int_eq(lvl_up(600), 2);
  ck_assert_int_eq(is_valid_key('q'), 1);
  ck_assert_int_eq(is_valid_key('p'), 1);
  ck_assert_int_eq(is_valid_key('\n'), 1);
}

END_TEST

START_TEST(test_3) {
  GameInfo_t *game = get_game_info();
  on_pause_game();
  ck_assert_int_eq(game->pause, 1);
  off_pause_game();
  ck_assert_int_eq(game->pause, 0);
  ck_assert_int_eq(checked_pause(), 0);
}

END_TEST

START_TEST(test_4) {
  GameInfo_t *game = get_game_info();
  init_board();
  for (int i = 1; i < 11; ++i) {
    game->field[1][i] = 1;
  }
  ck_assert_int_eq(is_full_lines(1), 1);
  ck_assert_int_eq(check_lines(0), 0);
  ck_assert_int_eq(check_collision_left(), 0);
  ck_assert_int_eq(check_collision_right(), 0);
  ck_assert_int_eq(check_collision_down(), 0);
  ck_assert_int_eq(check_collision_rotate(), 0);
  init_game_setting();
  ck_assert_int_eq(game->level, 1);
  free_memory();
}
END_TEST

START_TEST(test_5) {
  init_board();
  UserAction_t *input = get_user_status();
  check_key_pressed(DOWN_ARROW);
  ck_assert_int_eq(*input, Down);
  check_key_pressed(UP_ARROW);
  ck_assert_int_eq(*input, Up);
  check_key_pressed(LEFT_ARROW);
  ck_assert_int_eq(*input, Left);
  check_key_pressed(RIGHT_ARROW);
  ck_assert_int_eq(*input, Right);
  check_key_pressed('P');
  ck_assert_int_eq(*input, Pause);
  check_key_pressed('p');
  ck_assert_int_eq(*input, Pause);
  GameInfo_t *game = get_game_info();
  game->pause = 0;
  exit_logic();
  ck_assert_int_eq(*input, Pause);
  pause_logic();
  ck_assert_int_eq(*input, Pause);
  check_key_pressed('h');
  ck_assert_int_eq(*input, Inaction);
  free_memory();
}
END_TEST

START_TEST(test_6) {
  init_board();
  GameInfo_t *game = get_game_info();

  Current_Figure *figure = get_current_figure();
  figure->dimension = 4;

  int *figure_pointer = get_figure(0);
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figure_pointer + i * figure->dimension + j);
      figure->current_figure[i][j] = value;
    }
  }
  figure->Y = 10;
  figure->X = 5;
  update_game_screen();
  ck_assert_int_eq(game->next[10][6], 1);

  figure_pointer = get_figure(1);
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figure_pointer + i * figure->dimension + j);
      figure->current_figure[i][j] = value;
    }
  }
  figure->Y = 10;
  figure->X = 5;
  update_game_screen();
  ck_assert_int_eq(game->next[12][7], 1);

  figure_pointer = get_figure(2);
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figure_pointer + i * figure->dimension + j);
      figure->current_figure[i][j] = value;
    }
  }
  figure->Y = 10;
  figure->X = 5;
  update_game_screen();
  ck_assert_int_eq(game->next[12][7], 1);

  figure_pointer = get_figure(4);
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figure_pointer + i * figure->dimension + j);
      figure->current_figure[i][j] = value;
    }
  }
  figure->Y = 10;
  figure->X = 5;
  update_game_screen();
  ck_assert_int_eq(game->next[11][6], 1);

  figure_pointer = get_figure(5);
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figure_pointer + i * figure->dimension + j);
      figure->current_figure[i][j] = value;
    }
  }
  figure->Y = 10;
  figure->X = 5;
  update_game_screen();
  ck_assert_int_eq(game->next[11][6], 1);

  figure_pointer = get_figure(6);
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figure_pointer + i * figure->dimension + j);
      figure->current_figure[i][j] = value;
    }
  }
  figure->Y = 10;
  figure->X = 5;
  update_game_screen();
  ck_assert_int_eq(game->next[11][6], 1);

  figure_pointer = get_figure(3);
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figure_pointer + i * figure->dimension + j);
      figure->current_figure[i][j] = value;
    }
  }
  figure->Y = 10;
  figure->X = 5;
  update_game_screen();
  ck_assert_int_eq(game->next[11][7], 1);

  user_input(Up, false);
  ck_assert_int_eq(game->next[11][7], 1);
  figure->Y = 15;
  figure->X = 5;
  update_game_screen();
  user_input(Down, true);
  ck_assert_int_eq(figure->Y, 0);

  figure->Y = 15;
  figure->X = 5;
  update_game_screen();
  user_input(Right, false);
  ck_assert_int_eq(figure->X, 6);

  figure->Y = 15;
  figure->X = 5;
  update_game_screen();
  user_input(Left, false);
  ck_assert_int_eq(figure->X, 4);

  figure->Y = 15;
  figure->X = 5;
  update_game_screen();
  user_input(Action, false);
  ck_assert_int_eq(figure->Y, 0);

  figure->Y = 15;
  figure->X = 5;
  update_game_screen();
  user_input(Terminate, false);
  ck_assert_int_eq(figure->Y, 15);

  figure->Y = 15;
  figure->X = 5;
  update_game_screen();
  user_input(Inaction, false);
  ck_assert_int_eq(figure->Y, 15);

  figure->Y = 15;
  figure->X = 5;
  update_game_screen();
  user_input(Start, false);
  ck_assert_int_eq(figure->Y, 0);
  free_memory();
}

START_TEST(test_7) {
  UserAction_t test = Start;
  set_user_status(test);
  UserAction_t *check = get_user_status();
  ck_assert_int_eq(*check, 0);
}

Suite *suite_tetris(void) {
  Suite *s = suite_create("suite_tetris_tests");
  TCase *tc = tcase_create("add_tc");

  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);

  suite_add_tcase(s, tc);
  return s;
}