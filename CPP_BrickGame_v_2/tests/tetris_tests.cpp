#include <gtest/gtest.h>

#include "../brick_game/tetris/tetris_model.h"
namespace mo {

TEST(tetris, test1) {
  TetrisModel tetris_model;
  tetris_model.init_board();

  GameInfo_t game_info = tetris_model.UpdateCurrentState();
  EXPECT_EQ(game_info.exit_logic, 0);
  EXPECT_EQ(game_info.level, 1);
  for (int i = 1; i < 11; ++i) {
    game_info.field[1][i] = 1;
  }
  EXPECT_EQ(tetris_model.check_lines(), 0);
  EXPECT_EQ(tetris_model.check_collision_x(), 0);
  EXPECT_EQ(tetris_model.check_collision_y(), 0);
}

TEST(tetris, test2) {
  TetrisModel tetris_model;
  tetris_model.init_board();
  tetris_model.lines_to_score(1);
  GameInfo_t game_info = tetris_model.UpdateCurrentState();
  EXPECT_EQ(game_info.score, 100);
  tetris_model.lines_to_score(2);
  game_info = tetris_model.UpdateCurrentState();
  EXPECT_EQ(game_info.score, 400);
  tetris_model.lines_to_score(3);
  game_info = tetris_model.UpdateCurrentState();
  EXPECT_EQ(game_info.score, 1100);
  tetris_model.lines_to_score(4);
  game_info = tetris_model.UpdateCurrentState();
  EXPECT_EQ(game_info.score, 2600);
}
TEST(tetris, test3) {
  TetrisModel tetris_model;
  tetris_model.init_board();
  int *figure_pointer = tetris_model.get_figure(0);
  EXPECT_EQ(figure_pointer[0], 0);
  figure_pointer = tetris_model.get_figure(1);
  EXPECT_EQ(figure_pointer[0], 1);
  figure_pointer = tetris_model.get_figure(2);
  EXPECT_EQ(figure_pointer[0], 0);
  figure_pointer = tetris_model.get_figure(3);
  EXPECT_EQ(figure_pointer[0], 0);
  figure_pointer = tetris_model.get_figure(4);
  EXPECT_EQ(figure_pointer[0], 0);
  figure_pointer = tetris_model.get_figure(5);
  EXPECT_EQ(figure_pointer[0], 0);
  figure_pointer = tetris_model.get_figure(6);
  EXPECT_EQ(figure_pointer[0], 1);
}

TEST(tetris, test4) {
  TetrisModel tetris_model;
  tetris_model.init_board();
  tetris_model.add_figure_to_field();
  GameInfo_t game_info = tetris_model.UpdateCurrentState();
  EXPECT_EQ(game_info.next[4][0], 0);
  tetris_model.rotate_figure();
  EXPECT_EQ(game_info.next[4][0], 0);
  tetris_model.move_figure_down();
  EXPECT_EQ(game_info.next[4][1], 0);
  tetris_model.move_figure_left();
  EXPECT_EQ(game_info.next[4][2], 0);
  tetris_model.move_figure_right();
  EXPECT_EQ(game_info.next[4][3], 0);
}

TEST(tetris, test5) {
  TetrisModel tetris_model;
  tetris_model.init_board();
  tetris_model.check_attaching();
  tetris_model.can_spawn();
  tetris_model.update_field();
  tetris_model.is_fall_time();
  tetris_model.save_figure();
  tetris_model.attaching_state();
  tetris_model.shifting_state();
  GameInfo_t game_info = tetris_model.UpdateCurrentState();
  EXPECT_EQ(game_info.next[4][0], 0);
}

TEST(tetris, test6) {
  TetrisModel tetris_model;
  tetris_model.init_board();
  GameInfo_t game_info = tetris_model.UpdateCurrentState();
  EXPECT_EQ(game_info.exit_logic, 0);
  GameState_t game_state = tetris_model.fsm_states();
  EXPECT_EQ(game_state, GameState_t::SPAWN);
  game_state = tetris_model.fsm_states();
  EXPECT_EQ(game_state, GameState_t::MOVING);
  UserAction_t action = UserAction_t::Up;
  EXPECT_EQ(action, UserAction_t::Up);
  tetris_model.moving_state();
  game_state = tetris_model.fsm_states();
  EXPECT_EQ(game_state, GameState_t::MOVING);
  action = UserAction_t::Terminate;
  tetris_model.user_input(action);
  tetris_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Terminate);
  action = UserAction_t::Up;
  tetris_model.user_input(action);
  tetris_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Up);
}

TEST(tetris, test7) {
  TetrisModel tetris_model;
  tetris_model.init_board();
  UserAction_t action = UserAction_t::Up;
  tetris_model.user_input(action);
  tetris_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Up);
  action = UserAction_t::Down;
  tetris_model.user_input(action);
  tetris_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Down);
  action = UserAction_t::Left;
  tetris_model.user_input(action);
  tetris_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Left);
  action = UserAction_t::Right;
  tetris_model.user_input(action);
  tetris_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Right);
  action = UserAction_t::Pause;
  tetris_model.user_input(action);
  tetris_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Pause);
}
TEST(tetris, test8) {
  TetrisModel tetris_model;
  tetris_model.init_board();
  Current_Figure figure = tetris_model.get_current_figure();
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      figure.current_figure[i][j] = 1;
    }
  }
  EXPECT_EQ(figure.current_figure[0][0], 1);
}

}  // namespace mo