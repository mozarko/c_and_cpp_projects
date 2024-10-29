#include "snake_model.h"

#include <chrono>
#include <random>

#include "../../controller/controller.h"

namespace mo {

extern BrickgameController controller;

void SnakeModel::user_input(UserAction_t act) { action = act; }

GameState_t SnakeModel::fsm_states() {
  switch (game_state) {
    case GameState_t::START:
      game_state = GameState_t::SPAWN;
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
void SnakeModel::spawn_state() {
  update_field();
  add_apple_to_field();
  game_state = GameState_t::MOVING;
}

void SnakeModel::moving_state() {
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
      move_up();
      break;
    case UserAction_t::Down:
      move_down();
      break;
    case UserAction_t::Left:
      move_left();
      break;
    case UserAction_t::Right:
      move_right();
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
    if (is_shift_time()) {
      game_state = GameState_t::SHIFTING;
    }
  }
}

void SnakeModel::shifting_state() {
  game_state = GameState_t::MOVING;
  moving();
}

void SnakeModel::attaching_state() {
  game_info.next[apple.X][apple.Y] = 0;
  Point new_segment = snake_info.body[snake_info.body.size()];
  snake_info.body.push_back(new_segment);
  apples_to_score();
  update_field();
  game_state = GameState_t::SPAWN;
}

void SnakeModel::init_board() {
  game_info.field.resize(SIZE_MAX_MAP_X, std::vector<int>(SIZE_MAX_MAP_Y));
  game_info.next.resize(SIZE_MAX_MAP_X, std::vector<int>(SIZE_MAX_MAP_Y));
  for (int i = 0; i < SIZE_MAX_MAP_X; ++i) {
    for (int j = 0; j < SIZE_MAX_MAP_Y; ++j) {
      game_info.field[i][j] = 0;
      game_info.next[i][j] = 0;
    }
  }
  game_info.exit_logic = 0;
  game_info.high_score = get_records();
  game_info.level = 1;
  game_info.pause = 0;
  game_info.score = 0;
  game_info.speed = 1;
  snake_info.body = {{4, 8}, {4, 9}, {4, 10}, {4, 11}};
  snake_info.direction = Direction::UP;
  game_state = GameState_t::START;
}

void SnakeModel::generated_next_apple() {
  do {
    apple.X = get_rand_X();
    apple.Y = get_rand_Y();
  } while (game_info.field[apple.X][apple.Y] == 1);
}

int SnakeModel::get_rand_X() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(2, 9);
  return dis(gen);
}

int SnakeModel::get_rand_Y() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 18);
  return dis(gen);
}

void SnakeModel::update_field() {
  clear_field();
  for (size_t i = 0; i < snake_info.body.size(); ++i) {
    game_info.field[snake_info.body[i].X][snake_info.body[i].Y] = 1;
  }
}

int SnakeModel::get_records() {
  FILE *file;
  file = fopen("records_snake.txt", "r");
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

void SnakeModel::moving() {
  Point new_head = new_head_point();
  if (new_head.X < 1 || new_head.X > SIZE_MAX_MAP_X - 1 || new_head.Y < 0 ||
      new_head.Y > SIZE_MAX_MAP_Y - 1 ||
      game_info.field[new_head.X][new_head.Y] == 1) {
    game_state = GameState_t::GAME_OVER;
    return;
  }
  if (new_head == apple) {
    game_state = GameState_t::ATTACHING;
  }
  snake_info.body.insert(snake_info.body.begin(), new_head);
  snake_info.body.pop_back();
  update_field();
}

void SnakeModel::move_down() {
  if (snake_info.direction != Direction::UP) {
    snake_info.direction = Direction::DOWN;
    moving();
  }
}

void SnakeModel::move_up() {
  if (snake_info.direction != Direction::DOWN) {
    snake_info.direction = Direction::UP;
    moving();
  }
}

void SnakeModel::move_left() {
  if (snake_info.direction != Direction::RIGHT) {
    snake_info.direction = Direction::LEFT;
    moving();
  }
}

void SnakeModel::move_right() {
  if (snake_info.direction != Direction::LEFT) {
    snake_info.direction = Direction::RIGHT;
    moving();
  }
}

void SnakeModel::apples_to_score() {
  game_info.score += 1;
  if (game_info.score >= 200) {
    game_state = GameState_t::GAME_OVER;
  }
  if (game_info.score > game_info.high_score) {
    game_info.high_score = game_info.score;
    FILE *highScore;
    highScore = fopen("records_snake.txt", "w");
    if (highScore) {
      fprintf(highScore, "%d", game_info.high_score);
      fclose(highScore);
    }
  }
  if (game_info.score / 5 > 9) {
    game_info.level = 10;
  } else {
    game_info.level = game_info.score / 5 + 1;
  }
  game_info.speed = game_info.level;
}

void SnakeModel::add_apple_to_field() {
  generated_next_apple();
  game_info.next[apple.X][apple.Y] = 1;
}

Point SnakeModel::new_head_point() {
  Point current_point = snake_info.body[0];
  Point new_point;
  switch (snake_info.direction) {
    case Direction::UP:
      new_point.X = current_point.X;
      new_point.Y = current_point.Y - 1;
      break;
    case Direction::DOWN:
      new_point.X = current_point.X;
      new_point.Y = current_point.Y + 1;
      break;
    case Direction::LEFT:
      new_point.X = current_point.X - 1;
      new_point.Y = current_point.Y;
      break;
    case Direction::RIGHT:
      new_point.X = current_point.X + 1;
      new_point.Y = current_point.Y;
      break;
    default:
      break;
  }
  return new_point;
}

int SnakeModel::is_shift_time() {
  static auto clock_start = std::chrono::steady_clock::now();
  auto clock_now = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_time = clock_now - clock_start;

  int shift_time = 0;
  if (elapsed_time.count() >= 1.5 / static_cast<double>(game_info.speed)) {
    clock_start = clock_now;
    shift_time = 1;
  }
  return shift_time;
}

void SnakeModel::clear_field() {
  for (int x = 1; x < SIZE_MAX_MAP_X; ++x) {
    for (int y = 0; y < SIZE_MAX_MAP_Y; ++y) {
      game_info.field[x][y] = 0;
    }
  }
}
}  // namespace mo