#include "../inc/fsm.h"

GameInfo_t *get_game_info() {
  static GameInfo_t game_info;
  return &game_info;
}
UserAction_t *get_user_status() {
  static UserAction_t userAction;
  return &userAction;
}
void set_user_status(UserAction_t status) {
  UserAction_t *userAction = get_user_status();
  *userAction = status;
}

GameInfo_t *updateCurrentState() { return get_game_info(); }

void init_board() {
  GameInfo_t *game = get_game_info();

  game->field = (int **)calloc(SIZE_MAX_MAP_Y, sizeof(int *));
  game->next = (int **)calloc(SIZE_MAX_MAP_Y, sizeof(int *));
  for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
    game->field[i] = (int *)calloc(SIZE_MAX_MAP_X, sizeof(int));
    game->next[i] = (int *)calloc(SIZE_MAX_MAP_X, sizeof(int));
  }
  for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
      if (i == 0 || i == SIZE_MAX_MAP_Y - 2) {
        game->field[i][j] = 1;
      } else if (j == 0 || j == SIZE_MAX_MAP_X - 1) {
        game->field[i][j] = 1;
      } else {
        game->field[i][j] = 0;
      }
    }
  }
  game->high_score = 0;
  game->level = 0;
  game->pause = 0;
  game->score = 0;
  game->speed = 0;
}
void free_memory() {
  GameInfo_t *game = get_game_info();

  for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
    free(game->field[i]);  // Освобождение строк
    free(game->next[i]);   // Освобождение строк
  }

  free(game->field);  // Освобождение массива указателей
  free(game->next);  // Освобождение массива указателей

  // Обнуление указателей
  game->field = NULL;
  game->next = NULL;
}

void start_game() {
  clear();
  init_board();
  UserAction_t *input;
  user_input(Start, false);
  do {
    int key;
    input = get_user_status();
    GameInfo_t *game = updateCurrentState();
    int buf_lvl = lvl_up(game->score);
    game->level = (buf_lvl == 0) ? 1 : buf_lvl;
    key = GET_USER_INPUT;
    if (my_delay(game->speed, key)) {  // нажата валидная клавиша
      *input = check_key_pressed(key);
      user_input(*input, true);
    } else {  // прошел таймер и валидная клавиша не нажата
      user_input(Down, false);
    }

  } while (*input != Terminate);
}
void init_game_setting() {
  GameInfo_t *game = get_game_info();
  UserAction_t *status_game = get_user_status();
  *status_game = Start;
  set_user_status(*status_game);
  game->level = 1;
  game->score = 0;
  game->speed = 0;
  game->high_score = check_records();
}
void pause_logic() {
  print_pause_menu();
  do {
    int key_pause = GET_USER_INPUT;
    if (IS_Q(key_pause)) {
      off_pause_game();
    }
  } while (checked_pause());
  clear();
  print_game_map();
  print_support_bord();
  print_next_figure();
}
void save_record() {
  GameInfo_t *game = get_game_info();
  int old_record = check_records();
  game->high_score = (game->score > old_record) ? game->score : old_record;
  FILE *file;
  file = fopen("records.txt", "w");
  fprintf(file, "%d", game->high_score);
  fclose(file);
}
void user_input(UserAction_t action, bool hold) {
  switch (action) {
    case Start:
      clear();
      init_game_setting();
      genereated_next_figure();
      create_random_tetromino();
      print_game_map();
      print_support_bord();
      break;
    case Pause:
      on_pause_game();
      pause_logic();
      break;
    case Terminate:
      save_record();
      break;
    case Left:
      move_figure_left();
      update_game_screen();
      print_game_map();
      break;
    case Right:
      move_figure_right();
      update_game_screen();
      print_game_map();
      break;
    case Up:
      rotate_figure();
      update_game_screen();
      print_game_map();
      break;
    case Down:
      if (hold == true) {
        while (1 != check_collision_down()) {
          move_figure_down();
          update_game_screen();
        }
      }
      move_figure_down();
      update_game_screen();
      print_game_map();
      break;
    case Action:
      clear();
      create_random_tetromino();
      print_game_map();
      break;
    case Inaction:
      break;
  }
}
void exit_logic() {
  UserAction_t *input = get_user_status();
  do {
    int key_enter = GET_USER_INPUT;
    if (IS_ENTER(key_enter)) {
      *input = Terminate;
      off_pause_game();
    }
    if (IS_Q(key_enter)) {
      *input = Inaction;
      off_pause_game();
    }
  } while (checked_pause());
  clear();
  print_game_map();
  print_support_bord();
  print_next_figure();
}
UserAction_t check_key_pressed(int key) {
  UserAction_t *input = get_user_status();
  switch (key) {
    case DOWN_ARROW:
      *input = Down;
      break;
    case UP_ARROW:
      *input = Up;
      break;
    case LEFT_ARROW:
      *input = Left;
      break;
    case RIGHT_ARROW:
      *input = Right;
      break;
    case 'P':
      *input = Pause;
      break;
    case 'p':
      *input = Pause;
      break;
    case 'Q':
      print_exit_menu();
      on_pause_game();
      exit_logic();
      break;
    case 'q':
      print_exit_menu();
      on_pause_game();
      exit_logic();
      break;
    default:
      *input = Inaction;
      break;
  }
  return *input;
}