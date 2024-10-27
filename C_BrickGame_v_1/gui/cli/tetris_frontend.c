#include "tetris_frontend.h"

void game_loop() {
  win_init_function(1000);
  game_function();
  exit_game();
  free_memory();
}

void exit_game() {
  endwin();
  exit(0);
}

int win_init_function(int time) {
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  timeout(time);
  return 0;
}

int game_function() {
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  menu_selected_item();
  return 0;
}

void print_game_map() {
  const GameInfo_t *game = updateCurrentState();
  const Current_Figure *current_game_figure =
      get_current_figure();  // Получаем текущую фигуру
  // Печать отображение поля
  for (int i = 1; i < SIZE_MAX_MAP_Y - 1; ++i) {
    for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
      bool is_occupied = false;
      // Проверяем, находится ли текущая фигура в данной позиции
      for (int fi = 0; fi < current_game_figure->dimension; ++fi) {
        for (int fj = 0; fj < current_game_figure->dimension; ++fj) {
          if (current_game_figure->current_figure[fi][fj] == 1 &&
              i == current_game_figure->Y + fi &&
              j == current_game_figure->X + fj) {
            is_occupied = true;
            break;
          }
        }
        if (is_occupied) break;
      }
      // Если позиция занята фигурой, отображаем квадрат
      if (is_occupied) {
        mvaddch(i + 1, j * 2 + 2, ACS_CKBOARD);  // добавление квадрата
        mvaddch(i + 1, j * 2 + 3, ACS_CKBOARD);
      } else if (game->field[i][j] == 1) {
        // Печать состояния поля, если оно занято, но не на границах
        if (j >= 1 && j < SIZE_MAX_MAP_X - 1) {
          mvaddch(i + 1, j * 2 + 2, ACS_CKBOARD);
          mvaddch(i + 1, j * 2 + 3, ACS_CKBOARD);
        }
      } else {
        mvaddch(i + 1, j * 2 + 2, ACS_BULLET);  // Отображаем пустую позицию
        mvaddch(i + 1, j * 2 + 3, ' ');
        mvaddch(SIZE_MAX_MAP_Y - 1, j + 2, ACS_HLINE);
      }
    }
  }
  for (int j = 1; j < SIZE_MAX_MAP_X * 2; ++j) {
    mvaddch(SIZE_MAX_MAP_Y - 1, j + 2, ACS_HLINE);  // Горизонтальная линия
  }
  mvaddch(SIZE_MAX_MAP_Y - 1, SIZE_MAX_MAP_X * 2 + 1,
          ACS_LRCORNER);  // Нижний правый угол
  SCORE_PRINT(game->score);
  LEVEL_PRINT(game->level);
  RECORD_PRINT(game->high_score);
  SPEED_PRINT(game->level * 5);
}

void print_support_bord() {
  // Печать верхней границы
  mvaddch(1, 2, ACS_ULCORNER);  // Верхний левый угол
  for (int j = 2; j < SIZE_MAX_MAP_X * 2 + 1; ++j) {
    mvaddch(1, j + 1, ACS_HLINE);  // Горизонтальная линия
  }
  mvaddch(1, SIZE_MAX_MAP_X * 2 + 1, ACS_URCORNER);  // Верхний правый угол
  // Печать боковых границ и отображение поля
  for (int i = 1; i < SIZE_MAX_MAP_Y - 1; ++i) {
    mvaddch(i + 1, 2, ACS_VLINE);  // Левая граница
    mvaddch(i + 1, SIZE_MAX_MAP_X * 2 + 1, ACS_VLINE);
  }  // Правая граница
  // Печать нижней границы
  mvaddch(SIZE_MAX_MAP_Y - 1, 2, ACS_LLCORNER);  // Нижний левый угол
  for (int j = 1; j < SIZE_MAX_MAP_X * 2; ++j) {
    mvaddch(SIZE_MAX_MAP_Y - 1, j + 2, ACS_HLINE);  // Горизонтальная линия
  }
  mvaddch(SIZE_MAX_MAP_Y - 1, SIZE_MAX_MAP_X * 2 + 1,
          ACS_LRCORNER);  // Нижний правый угол
  attron(A_BOLD);
  for (int j = SUPPORT_BORD_START_X;
       j <= SUPPORT_BORD_START_X + SUPPORT_BORD_SIZE_X; ++j) {
    mvaddch(SUPPORT_BORD_START_Y, j, '-');
  }
  for (int i = SUPPORT_BORD_START_Y + 1;
       i < SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y_1;
       ++i) {  // Правая граница верхнего блока
    mvaddch(i, SUPPORT_BORD_START_X + SUPPORT_BORD_SIZE_X, '|');
  }
  for (int j = SUPPORT_BORD_START_X;
       j <= SUPPORT_BORD_START_X + SUPPORT_BORD_SIZE_X; ++j) {
    mvaddch(SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y_1, j, '-');
  }
  for (int i = SUPPORT_BORD_START_Y + 1;
       i < SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y_1;
       ++i) {  // Левая граница верхнего блока
    mvaddch(i, SUPPORT_BORD_START_X, '|');
  }
  attron(COLOR_PAIR(2));
  TITLE_PRINT;
  attroff(A_BOLD);
  attroff(COLOR_PAIR(2));
  ARROW_PRINT_1;
  ARROW_PRINT_2;
  ARROW_PRINT_3;
  PAUSE_PRINT;
  EXIT_PRINT;
}

void print_next_figure() {
  const Current_Figure *figure = get_current_figure();
  attron(A_BOLD);
  for (int i = SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y_2;
       i < SUPPORT_BORD_START_Y + (SUPPORT_BORD_SIZE_Y_2 * 2);
       ++i) {  // Правая граница верхнего блока
    mvaddch(i, SUPPORT_BORD_START_X + SUPPORT_BORD_SIZE_X, '|');
  }
  for (int j = SUPPORT_BORD_START_X;
       j <= SUPPORT_BORD_START_X + SUPPORT_BORD_SIZE_X; ++j) {
    mvaddch(SUPPORT_BORD_START_Y + (SUPPORT_BORD_SIZE_Y_2 * 2), j, '-');
  }
  for (int i = SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y_2;
       i < SUPPORT_BORD_START_Y + (SUPPORT_BORD_SIZE_Y_2 * 2);
       ++i) {  // Левая граница верхнего блока
    mvaddch(i, SUPPORT_BORD_START_X, '|');
  }
  mvprintw(SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y_1 + 1,
           SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 5), "   Next figure");
  attroff(A_BOLD);
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      if (figure->next_figure[i][j] == 1) {
        mvaddch(i + SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y_1 + 3,
                SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 3) + j * 2,
                ACS_CKBOARD);
        mvaddch(i + SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y_1 + 3,
                SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 3) + j * 2 + 1,
                ACS_CKBOARD);
      } else {
        mvaddch(i + SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y_1 + 3,
                SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 3) + j * 2, ' ');
        mvaddch(i + SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y_1 + 3,
                SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 3) + j * 2 + 1,
                ' ');
      }
    }
  }
}

void print_exit_menu() {
  clear();
  attron(A_BOLD);
  attron(COLOR_PAIR(2));
  mvprintw(4, 5, "EXIT MENU");
  attroff(COLOR_PAIR(2));
  mvprintw(6, 0, "Do you really want exit?");
  mvprintw(8, 0, "Q     - NO");
  mvprintw(9, 0, "ENTER - YES");
  attroff(A_BOLD);
}

void print_pause_menu() {
  clear();
  attron(A_BOLD);
  attron(COLOR_PAIR(2));
  mvprintw(4, 5, "PAUSE");
  attroff(COLOR_PAIR(2));
  mvprintw(6, 0, "press Q to resume");
  attroff(A_BOLD);
}

void print_lose_banner() {
  clear();
  int key_input;
  attron(A_BOLD);
  do {
    GameInfo_t *game = get_game_info();
    attron(COLOR_PAIR(2));
    mvprintw(3, 3, "GAME OVER");
    attroff(COLOR_PAIR(2));
    mvprintw(5, 1, "Your Score = %d", game->score);
    mvprintw(6, 1, "Your Level = %d", game->level);
    mvprintw(7, 1, "Your High score = %d", game->high_score);
    mvprintw(8, 1, "Press Q to exit");
    key_input = GET_USER_INPUT;
  } while (!IS_Q(key_input));
  attroff(A_BOLD);
  save_record();
}

void update_game_screen() {
  const GameInfo_t *game = get_game_info();
  Current_Figure *current_game_figure = get_current_figure();
  clear_old_next_map();
  for (int i = 0; i < current_game_figure->dimension; ++i) {
    for (int j = 0; j < current_game_figure->dimension; ++j) {
      int value = current_game_figure->current_figure[i][j];
      game->next[current_game_figure->Y + i][current_game_figure->X + j] =
          value;
    }
  }
}

void clear_old_next_map() {
  GameInfo_t *game = get_game_info();
  for (int i = 0; i < SIZE_MAX_MAP_Y; ++i) {
    for (int j = 0; j < SIZE_MAX_MAP_X; ++j) {
      game->next[i][j] = 0;
    }
  }
}

void execute_menu_item(int item) {
  switch (item) {
    case 0:
      start_game();
      clear();
      break;
    case 1:
      exit_game();
      break;
    default:
      break;
  }
}

void menu_selected_item() {
  int key;
  int selected_item = 0;
  print_menu(selected_item);
  while ((key = getch()) != 27) {
    switch (key) {
      case KEY_UP:
        selected_item = (selected_item - 1 >= 0) ? selected_item - 1 : 0;
        break;
      case KEY_DOWN:
        selected_item = (selected_item + 1 < 2) ? selected_item + 1 : 2 - 1;
        break;
      case '\n':
        execute_menu_item(selected_item);
        break;
      default:
        break;
    }
    print_menu(selected_item);
  }
}

void print_menu(int selected_item) {
  attron(COLOR_PAIR(2));
  attron(A_BOLD);
  mvprintw(2, 7, "Main menu");
  attroff(COLOR_PAIR(2));
  for (int i = 0; i < 2; ++i) {
    if (selected_item == i) {
      attron(A_REVERSE);
    }
    mvprintw(4 + i, 7, "%d. %s", i + 1, (i == 0) ? "Start" : "Exit");
    if (selected_item == i) {
      attroff(A_REVERSE);
    }
  }
  attroff(A_BOLD);
  mvprintw(7, 1, "Use arrows to select item");
  mvprintw(8, 1, "Press ENTER to continue");
  mvprintw(9, 1, "Press ESC to exit");
}
