#include "tetris_model.h"

#include <chrono>
#include <random>

#include "../../controller/controller.h"

namespace mo {

extern BrickgameController controller;

void TetrisModel::user_input(UserAction_t act) { action = act; }

GameState_t TetrisModel::fsm_states() {
  switch (game_state) {
    case GameState_t::START:
      start_state();
      break;
    case GameState_t::SPAWN:
      spawn_state();
      break;
    case GameState_t::MOVING:
      moving_state();
      break;
    case GameState_t::SHIFTING:
      shifting_state();
      break;
    case GameState_t::ATTACHING:
      attaching_state();
      break;
    case GameState_t::GAME_OVER:
      break;
  }
  return game_state;
}

void TetrisModel::start_state() {
  genereated_next_figure();
  game_state = GameState_t::SPAWN;
}

void TetrisModel::spawn_state() {
  if (!can_spawn()) {
    add_figure_to_field();
    update_field();
    game_state = GameState_t::MOVING;
  } else {
    game_state = GameState_t::GAME_OVER;
  }
}

void TetrisModel::moving_state() {
  if (game_info.pause && action != UserAction_t::Pause) {
    return;
  }
  if (game_info.exit_logic && action == UserAction_t::Action) {
    game_state = GameState_t::GAME_OVER;
  }
  if (game_info.exit_logic && action != UserAction_t::Terminate &&
      game_state != GameState_t::GAME_OVER) {
    return;
  }
  switch (action) {
    case UserAction_t::Up:
      rotate_figure();
      update_field();
      break;
    case UserAction_t::Down:
      move_figure_down();
      update_field();
      break;
    case UserAction_t::Left:
      move_figure_left();
      update_field();
      break;
    case UserAction_t::Right:
      move_figure_right();
      update_field();
      break;
    case UserAction_t::Terminate:
      game_info.exit_logic = !game_info.exit_logic;
      break;
    case UserAction_t::Pause:
      game_info.pause = !game_info.pause;
      break;
    default:
      break;
  }
  if (game_state != GameState_t::GAME_OVER) {
    if (is_fall_time()) {
      game_state = GameState_t::SHIFTING;
    }
  }
}

void TetrisModel::shifting_state() {
  if (check_attaching()) {
    game_state = GameState_t::ATTACHING;
  } else {
    move_figure_down();
    update_field();
    game_state = GameState_t::MOVING;
  }
}

void TetrisModel::attaching_state() {
  save_figure();
  lines_to_score(check_lines());
  game_state = GameState_t::SPAWN;
}

void TetrisModel::init_board() {
  game_info.field.resize(SIZE_MAX_MAP_X, std::vector<int>(SIZE_MAX_MAP_Y));
  game_info.next.resize(SIZE_MAX_MAP_X, std::vector<int>(SIZE_MAX_MAP_Y));
  for (int i = 0; i < SIZE_MAX_MAP_X; ++i) {
    for (int j = 0; j < SIZE_MAX_MAP_Y; ++j) {
      game_info.field[i][j] = 0;
      game_info.next[i][j] = 0;
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      figure.current_figure[i][j] = 0;
      figure.next_figure[i][j] = 0;
    }
  }
  game_info.exit_logic = 0;
  game_info.high_score = get_records();
  game_info.level = 1;
  game_info.pause = 0;
  game_info.score = 0;
  game_info.speed = 1;
  game_state = GameState_t::START;
}

bool TetrisModel::check_attaching() {
  bool collision = false;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (figure.current_figure[i][j] == 1) {
        int x = figure.X + j;
        int y = figure.Y + i;
        // Проверка выхода за пределы массива
        if (x < 1 || x >= SIZE_MAX_MAP_X || y < 0 || y >= SIZE_MAX_MAP_Y) {
          collision = true;
        } else if (y + 1 >= SIZE_MAX_MAP_Y || game_info.field[x][y + 1] == 1) {
          collision = true;
        }
      }
    }
  }
  return collision;
}

void TetrisModel::update_field() {
  clear_next();
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int x = figure.X + j;
      int y = figure.Y + i;
      if (figure.current_figure[i][j] == 1) {
        game_info.next[x][y] = figure.current_figure[i][j];
      }
    }
  }
}

bool TetrisModel::can_spawn() {
  bool collision = false;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (figure.current_figure[i][j] == 1) {
        int x = figure.X + j;
        int y = figure.Y + i;
        if (y == 0 && game_info.field[x][y] == 1) {
          collision = true;
        }
      }
    }
  }
  return collision;
}

int TetrisModel::get_records() {
  FILE *file;
  file = fopen("records.txt", "r");
  int record = 0;
  if (file != NULL) {
    char buffer[20];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
      record = atoi(buffer);
    }
    fclose(file);
  }
  return record;
}

void TetrisModel::move_figure_down() {
  figure.Y++;
  if (check_collision_y()) {
    figure.Y--;
    game_state = GameState_t::ATTACHING;
  }
}

void TetrisModel::move_figure_left() {
  figure.X--;
  if (check_collision_x()) figure.X++;
}

void TetrisModel::move_figure_right() {
  figure.X++;
  if (check_collision_x()) figure.X--;
}

void TetrisModel::rotate_figure() {
  int tempo[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      tempo[i][j] = figure.current_figure[i][j];
    }
  }
  if ((figure.current_figure[0][1] == 1 && figure.current_figure[0][2] == 1) &&
      (figure.current_figure[1][1] == 1 && figure.current_figure[1][2] == 1))
    return;

  if (figure.current_figure[3][1] == 1 || figure.current_figure[3][2] == 1 ||
      figure.current_figure[1][3] == 1 || figure.current_figure[2][3] == 1) {
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        int temp = figure.current_figure[i][j];
        figure.current_figure[i][j] = figure.current_figure[j][i];
        figure.current_figure[j][i] = temp;
      }
    }
  } else {
    int temp[3][3];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        temp[i][j] = figure.current_figure[i][j];
      }
    }
    figure.current_figure[0][0] = temp[2][0];
    figure.current_figure[0][1] = temp[1][0];
    figure.current_figure[0][2] = temp[0][0];
    figure.current_figure[1][0] = temp[2][1];
    figure.current_figure[1][2] = temp[0][1];
    figure.current_figure[2][0] = temp[2][2];
    figure.current_figure[2][1] = temp[1][2];
    figure.current_figure[2][2] = temp[0][2];
  }
  if (check_collision_x()) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        figure.current_figure[i][j] = tempo[i][j];
      }
    }
  }
}

int TetrisModel::check_lines() {
  int lines = 0;
  for (int y = 0; y < SIZE_MAX_MAP_Y; y++) {
    bool is_full = true;
    for (int x = 1; x < SIZE_MAX_MAP_X; x++) {
      if (game_info.field[x][y] == 0) {
        is_full = false;
        break;
      }
    }
    if (is_full) {
      lines++;
      for (int y1 = y; y1 > 0; y1--) {
        for (int x1 = 1; x1 < SIZE_MAX_MAP_X; x1++) {
          game_info.field[x1][y1] = game_info.field[x1][y1 - 1];
        }
      }
      for (int x1 = 1; x1 < SIZE_MAX_MAP_X; x1++) {
        game_info.field[x1][0] = 0;
      }
    }
  }
  return lines;
}

bool TetrisModel::check_collision_x() {
  bool collision = false;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (figure.current_figure[i][j] == 1) {
        int x = figure.X + j;
        int y = figure.Y + i;
        if (x < 1 || x >= SIZE_MAX_MAP_X) {
          collision = true;
        } else {
          if (game_info.field[x][y] == 1) {
            collision = true;
          }
        }
      }
    }
  }
  return collision;
}

bool TetrisModel::check_collision_y() {
  bool collision = false;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (figure.current_figure[i][j] == 1) {
        int x = figure.X + j;
        int y = figure.Y + i;
        if (game_info.field[x][y] == 1) {
          collision = true;
        } else if (y >= SIZE_MAX_MAP_Y) {
          collision = true;
        }
      }
    }
  }
  return collision;
}

void TetrisModel::lines_to_score(int lines) {
  if (lines == 1) {
    game_info.score += 100;
  }
  if (lines == 2) {
    game_info.score += 300;
  }
  if (lines == 3) {
    game_info.score += 700;
  }
  if (lines >= 4) {
    game_info.score += 1500;
  }
  if (game_info.score > game_info.high_score) {
    game_info.high_score = game_info.score;
    FILE *highScore;
    highScore = fopen("records.txt", "w");
    if (highScore) {
      fprintf(highScore, "%d", game_info.high_score);
      fclose(highScore);
    }
  }
  if (game_info.score / 600 > 9) {
    game_info.level = 10;
  } else {
    game_info.level = game_info.score / 600 + 1;
  }
  game_info.speed = game_info.level;
}

void TetrisModel::add_figure_to_field() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      figure.current_figure[i][j] = figure.next_figure[i][j];
    }
  }
  figure.X = 4;
  figure.Y = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int value = figure.current_figure[i][j];
      game_info.next[figure.X + j][figure.Y + i] = value;
    }
  }
  genereated_next_figure();
}

void TetrisModel::genereated_next_figure() {
  int *figure_pointer = get_figure(get_rand_number_figures());
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int value = *(figure_pointer + i * 4 + j);
      figure.next_figure[i][j] = value;
    }
  }
}

void TetrisModel::save_figure() {
  clear_next();
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int x = figure.X + j;
      int y = figure.Y + i;
      if (figure.current_figure[i][j] == 1) {
        game_info.field[x][y] = figure.current_figure[i][j];
      }
    }
  }
}

/*получение фигуры*/
int *TetrisModel::get_figure(int type) {
  static int figure_line[4][4] = {
      {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};

  static int figure_G_left[4][4] = {
      {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  static int figure_G_right[4][4] = {
      {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  static int figure_Cube[4][4] = {
      {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  static int figure_Z_right_up[4][4] = {
      {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  static int figure_cross[4][4] = {
      {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  static int figure_Z_left_up[4][4] = {
      {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  int(*figure)[4] = nullptr;

  if (type == LINE) {
    figure = figure_line;
  } else if (type == G_LEFT) {
    figure = figure_G_left;
  } else if (type == G_RIGHT) {
    figure = figure_G_right;
  } else if (type == CUBE) {
    figure = figure_Cube;
  } else if (type == Z_RIGHT_UP) {
    figure = figure_Z_right_up;
  } else if (type == CROSS) {
    figure = figure_cross;
  } else if (type == Z_LEFT_UP) {
    figure = figure_Z_left_up;
  }
  return (int *)figure;  // Возвращаем указатель на массив
}

int TetrisModel::get_rand_number_figures() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 6);
  return dis(gen);
}

int TetrisModel::is_fall_time() {
  static auto clock_start = std::chrono::steady_clock::now();
  auto clock_now = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_time = clock_now - clock_start;

  int fall_time = 0;
  if (elapsed_time.count() >= 1.5 / static_cast<double>(game_info.speed)) {
    clock_start = clock_now;
    fall_time = 1;
  }
  return fall_time;
}

void TetrisModel::clear_next() {
  for (int x = 1; x < SIZE_MAX_MAP_X; ++x) {
    for (int y = 0; y < SIZE_MAX_MAP_Y; ++y) {
      game_info.next[x][y] = 0;
    }
  }
}
}  // namespace mo