#include "../inc/tetris_backend.h"

int valid_keys[NUMBER_OF_KEYS] = {LEFT_ARROW, RIGHT_ARROW, UP_ARROW, DOWN_ARROW,
                                  '\n'};

int check_records() {
  FILE *file;
  file = fopen("records.txt", "r");
  int record;
  if (file != NULL) {
    char buffer[20];
    fgets(buffer, 20, file);

    fclose(file);

    record = atoi(buffer);
  } else {
    record = 0;
  }

  return record;
}

int lvl_up(int score) {
  int lvll = 0;
  GameInfo_t *game = get_game_info();
  game->speed = 11;
  for (int i = 0; i < (score / 600) + 2 && i <= 10; ++i) {
    lvll = i;
  }
  for (int i = lvll; i > 0; --i) {
    game->speed -= 1;
  }
  return lvll;
}

/*Проверка нажатой клавиши на валидность*/
bool is_valid_key(int ch) {
  bool bl = false;
  for (int i = 0; i < NUMBER_OF_KEYS; ++i) {
    if (ch == valid_keys[i]) {
      bl = true;
    }
  }
  if (IF_INPUT(ch)) {
    bl = true;
  }
  return bl;
}
bool my_delay(int milliseconds, int ch) {
  milliseconds *= 100;
  bool check_valid = false;
  clock_t start_time = clock();
  do {
    check_valid = is_valid_key(ch);
  } while (((clock() - start_time) * 1000 / CLOCKS_PER_SEC) < milliseconds &&
           !check_valid);
  return check_valid;
}

void move_figure_down() {
  Current_Figure *figure = get_current_figure();
  if (check_collision_down()) {
    save_next_map_in_field_map();
    int count_true = 0;
    count_true = check_lines(count_true);
    add_score(count_true);
    create_random_tetromino();
  } else {
    figure->Y++;
  }
}
void move_figure_left() {
  Current_Figure *figure = get_current_figure();
  if (check_collision_left()) {
    move_figure_down();
  } else {
    figure->X--;
    update_game_screen();
    if (check_collision_down()) {
      figure->X++;
      move_figure_down();
    } else {
      move_figure_down();
    }
  }
}

void move_figure_right() {
  Current_Figure *figure = get_current_figure();
  if (check_collision_right()) {
    move_figure_down();
  } else {
    figure->X++;
    update_game_screen();
    if (check_collision_down()) {
      figure->X--;
      move_figure_down();
    } else {
      move_figure_down();
    }
  }
}

void rotate_figure() {
  if (!check_collision_rotate()) {
    Current_Figure *figure = get_current_figure();
    GameInfo_t *game = get_game_info();
    int temp[4][4];
    for (int y = 0; y < figure->dimension; ++y) {
      for (int x = 0; x < figure->dimension; ++x) {
        temp[y][x] = figure->current_figure[y][x];
      }
    }
    for (int y = 0; y < figure->dimension; ++y) {
      for (int x = 0; x < figure->dimension; ++x) {
        figure->current_figure[y][x] = 0;
      }
    }
    for (int y = 0; y < figure->dimension; ++y) {
      for (int x = 0; x < figure->dimension; ++x) {
        figure->current_figure[y][x] = temp[figure->dimension - 1 - x][y];
      }
    }
    clear_old_next_map();
    for (int y = figure->Y; y < (figure->Y + figure->dimension); ++y) {
      for (int x = figure->X; x < (figure->X + figure->dimension); ++x) {
        game->next[y][x] = figure->current_figure[y - figure->Y][x - figure->X];
      }
    }
  }
}

void on_pause_game() {
  GameInfo_t *game = get_game_info();
  game->pause = 1;
}
void off_pause_game() {
  GameInfo_t *game = get_game_info();
  game->pause = 0;
}
bool checked_pause() {
  const GameInfo_t *game = updateCurrentState();
  return game->pause;
}

void add_score(int count_true) {
  GameInfo_t *game = get_game_info();
  count_true = (count_true > 4) ? 4 : count_true;
  switch (count_true) {
    case 4:
      game->score += 1500;
      break;
    case 3:
      game->score += 700;
      break;
    case 2:
      game->score += 300;
      break;
    case 1:
      game->score += 100;
      break;
    default:
      break;
  }
}
int check_lines(int count_true) {
  for (int y = SIZE_MAX_MAP_Y - 3; y >= 2; y--) {
    if (is_full_lines(y)) {  // return true
      remove_lines(y);
      count_true++;
      count_true = check_lines(count_true);
    }
  }
  print_game_map();
  return count_true;
}
void remove_lines(int remove_lines_y) {
  GameInfo_t *game = get_game_info();
  for (int y = remove_lines_y; y > 1; --y) {
    for (int x = 1; x < SIZE_MAX_MAP_X - 1; ++x) {
      game->field[y][x] = game->field[y - 1][x];
    }
  }
}

bool is_full_lines(int Y) {
  const GameInfo_t *game = get_game_info();
  bool is_full = false;
  int count_true = 0;
  for (int x = 1; x < SIZE_MAX_MAP_X - 1; ++x) {
    if (game->field[Y][x] == 1) {
      count_true++;
      if (count_true == SIZE_MAX_MAP_X - 2) {
        is_full = true;
      }
    }
  }
  return is_full;
}

void create_random_tetromino() {
  swap_figure_old_to_new();
  apperance_figure_to_next_field();
}

void apperance_figure_to_next_field() {
  GameInfo_t *game = get_game_info();
  Current_Figure *current_game_figure = get_current_figure();
  current_game_figure->X = ((SIZE_MAX_MAP_X - current_game_figure->dimension) /
                            2);  // стартовые позиции фигуры
  current_game_figure->Y = 0;
  if (check_collision_down() == false) {
    for (int i = 0; i < current_game_figure->dimension; ++i) {
      for (int j = 0; j < current_game_figure->dimension; ++j) {
        int value = current_game_figure->current_figure[i][j];
        game->next[current_game_figure->Y + i][current_game_figure->X + j] =
            value;
      }
    }
    genereated_next_figure();
    print_next_figure();
  } else {
    UserAction_t *check_start = get_user_status();
    if (*check_start != Start) {
      print_lose_banner();
      *check_start = Terminate;
      set_user_status(*check_start);
    }
  }
}

bool check_collision_right() {
  const GameInfo_t *game = get_game_info();
  const Current_Figure *figure = get_current_figure();
  bool check_collission = false;
  for (int y = figure->Y; y < (figure->Y + figure->dimension); ++y) {
    for (int x = figure->X; x < (figure->X + figure->dimension); ++x) {
      if ((game->next[y][x] == 1)) {
        if (game->field[y][x + 1] == 1) {
          check_collission = true;
        }
      }
    }
  }
  return check_collission;
}
bool check_collision_left() {
  const GameInfo_t *game = get_game_info();
  const Current_Figure *figure = get_current_figure();
  bool check_collission = false;
  for (int y = figure->Y; y < (figure->Y + figure->dimension); ++y) {
    for (int x = figure->X; x < (figure->X + figure->dimension); ++x) {
      if ((game->next[y][x] == 1)) {
        if (game->field[y][x - 1] == 1) {
          check_collission = true;
        }
      }
    }
  }

  return check_collission;
}

bool check_collision_down() {
  const GameInfo_t *game = get_game_info();
  const Current_Figure *figure = get_current_figure();
  bool check_collission = false;

  for (int y = figure->Y; y < (figure->Y + figure->dimension); ++y) {
    for (int x = figure->X; x < (figure->X + figure->dimension); ++x) {
      if ((game->next[y][x] == 1)) {
        if (game->field[y + 1][x] == 1) {
          check_collission = true;
        }
      }
    }
  }

  return check_collission;
}

bool check_collision_rotate() {
  const GameInfo_t *game = get_game_info();
  const Current_Figure *figure = get_current_figure();
  bool check_rotate = false;
  int temp[4][4];
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      temp[i][j] = figure->current_figure[j][i];
    }
  }
  int i = 0;
  int j = 0;
  for (int y = figure->Y; y < (figure->Y + figure->dimension); ++y) {
    for (int x = figure->X; x < (figure->X + figure->dimension); ++x) {
      if (game->field[y][x] == 1) {
        if (temp[i][j + 1] == 1) {
          check_rotate = true;
        }
      }
    }
    i++;
  }
  return check_rotate;
}

void save_next_map_in_field_map() {
  GameInfo_t *game = get_game_info();
  for (int y = 0; y < SIZE_MAX_MAP_Y; ++y) {
    for (int x = 0; x < SIZE_MAX_MAP_X; ++x) {
      if (game->next[y][x] == 1) {
        game->field[y][x] = game->next[y][x];
      }
    }
  }
}