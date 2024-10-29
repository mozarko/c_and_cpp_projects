#include <gtest/gtest.h>

#include "../brick_game/snake/snake_model.h"

namespace mo {

TEST(snake, test1) {
  SnakeModel snake_model;
  snake_model.init_board();
  GameState_t game_state = snake_model.fsm_states();
  EXPECT_EQ(game_state, GameState_t::SPAWN);
  game_state = snake_model.fsm_states();
  EXPECT_EQ(game_state, GameState_t::MOVING);
  game_state = snake_model.fsm_states();
  snake_model.shifting_state();
  snake_model.attaching_state();

  EXPECT_EQ(game_state, GameState_t::MOVING);
}

TEST(snake, test2) {
  SnakeModel snake_model;
  snake_model.init_board();
  UserAction_t action = UserAction_t::Up;
  snake_model.user_input(action);
  snake_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Up);
  action = UserAction_t::Down;
  snake_model.user_input(action);
  snake_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Down);
  action = UserAction_t::Left;
  snake_model.user_input(action);
  snake_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Left);
  action = UserAction_t::Right;
  snake_model.user_input(action);
  snake_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Right);
  action = UserAction_t::Terminate;
  snake_model.user_input(action);
  snake_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Terminate);
  action = UserAction_t::Pause;
  snake_model.user_input(action);
  snake_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Pause);
}

TEST(snake, test3) {
  SnakeModel snake_model;
  snake_model.init_board();
  UserAction_t action = UserAction_t::Pause;
  snake_model.user_input(action);
  snake_model.moving_state();
  EXPECT_EQ(action, UserAction_t::Pause);
}

}  // namespace mo