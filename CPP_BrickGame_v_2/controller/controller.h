#pragma once

#include "../brick_game/snake/snake_model.h"
#include "../brick_game/tetris/tetris_model.h"
#include "../gui/cli/brickgame_view.h"

namespace mo {

class BrickgameController {
 private:
  TetrisModel& tetris_model;
  SnakeModel& snake_model;

 public:
  BrickgameController(TetrisModel& tetris_model, SnakeModel& snake_model)
      : tetris_model(tetris_model), snake_model(snake_model) {}

  void user_input_tetris(UserAction_t action) {
    tetris_model.user_input(action);
  }
  void tetris_init() { tetris_model.init_board(); }
  void set_pause_tetris(int pause) { tetris_model.set_pause(pause); };
  void set_exit_logic_tetris(int exit_logic) {
    tetris_model.set_exit_logic(exit_logic);
  };

  GameInfo_t get_game_info_tetris() {
    return tetris_model.UpdateCurrentState();
  }
  Current_Figure get_current_figure() {
    return tetris_model.get_current_figure();
  }
  GameState_t get_state_tetris() { return tetris_model.fsm_states(); }

  void user_input_snake(UserAction_t action) { snake_model.user_input(action); }
  void snake_init() { snake_model.init_board(); }
  void set_pause_snake(int pause) { snake_model.set_pause(pause); };
  void set_exit_logic_snake(int exit_logic) {
    snake_model.set_exit_logic(exit_logic);
  };
  GameState_t get_state_snake() { return snake_model.fsm_states(); }
  GameInfo_t get_game_info_snake() { return snake_model.UpdateCurrentState(); }
};

}  // namespace mo