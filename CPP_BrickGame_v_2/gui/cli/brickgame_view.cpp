#include "brickgame_view.h"

#include "../../controller/controller.h"

namespace mo {
TetrisModel tetris_model;
SnakeModel snake_model;
BrickGameView view;
BrickgameController controller(tetris_model, snake_model);

void start_brickgame() {
  srand((unsigned int)time(NULL));
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, true);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  view.main_menu();
}

UserAction_t BrickGameView::get_action(int action) {
  UserAction_t user_action;
  if (action == KEY_UP)
    user_action = UserAction_t::Up;
  else if (action == KEY_DOWN)
    user_action = UserAction_t::Down;
  else if (action == KEY_LEFT)
    user_action = UserAction_t::Left;
  else if (action == KEY_RIGHT)
    user_action = UserAction_t::Right;
  else if (action == 'q' || action == 'Q')
    user_action = UserAction_t::Terminate;
  else if (action == ENTER_KEY)
    user_action = UserAction_t::Action;
  else if (action == 'p' || action == 'P')
    user_action = UserAction_t::Pause;
  else
    user_action = UserAction_t::Start;
  return user_action;
}

void BrickGameView::tetris_loop() {
  nodelay(stdscr, true);
  bool exit = false;
  game_info = controller.get_game_info_tetris();
  game_state = controller.get_state_tetris();
  while (!exit) {
    if (game_info.exit_logic) {
      exit_menu_logic();
      controller.set_exit_logic_tetris(0);
    }
    switch (game_state) {
      case GameState_t::START:
        game_info = controller.get_game_info_tetris();
        print_game_map();
        print_game_bord();
        print_supp_bord();
        game_state = controller.get_state_tetris();
        break;
      case GameState_t::SPAWN:
        game_info = controller.get_game_info_tetris();
        print_game_map();
        game_state = controller.get_state_tetris();
        figure = controller.get_current_figure();
        break;
      case GameState_t::MOVING:
        game_info = controller.get_game_info_tetris();
        if (game_info.pause) {
          print_pause_menu();
          while (get_action(getch()) != UserAction_t::Pause) {
          }
          controller.set_pause_tetris(0);
        }
        print_game_map();
        print_game_bord();
        print_supp_bord();
        print_next_figure();
        controller.user_input_tetris(get_action(getch()));
        game_state = controller.get_state_tetris();
        break;
      case GameState_t::SHIFTING:
        game_info = controller.get_game_info_tetris();
        print_game_map();
        game_state = controller.get_state_tetris();
        break;
      case GameState_t::ATTACHING:
        game_state = controller.get_state_tetris();
        break;
      case GameState_t::GAME_OVER:
        game_state = controller.get_state_tetris();
        game_info = controller.get_game_info_tetris();
        game_over_logic();
        exit = true;
        break;
      default:
        break;
    }
  }
}

void BrickGameView::snake_loop() {
  nodelay(stdscr, true);
  bool exit = false;
  game_state = controller.get_state_snake();
  game_info = controller.get_game_info_snake();
  while (!exit) {
    if (game_info.exit_logic) {
      exit_menu_logic();
      controller.set_exit_logic_snake(0);
    }
    switch (game_state) {
      case GameState_t::START:
        game_info = controller.get_game_info_snake();
        print_game_map();
        print_game_bord();
        print_supp_bord();
        game_state = controller.get_state_snake();
        break;
      case GameState_t::SPAWN:
        game_info = controller.get_game_info_snake();
        print_game_map();
        game_state = controller.get_state_snake();
        break;
      case GameState_t::MOVING:
        game_info = controller.get_game_info_snake();
        if (game_info.pause) {
          print_pause_menu();
          while (get_action(getch()) != UserAction_t::Pause) {
          }
          controller.set_pause_snake(0);
        }
        print_game_map();
        print_game_bord();
        print_supp_bord();
        controller.user_input_snake(get_action(getch()));
        game_state = controller.get_state_snake();
        break;
      case GameState_t::SHIFTING:
        game_info = controller.get_game_info_snake();
        print_game_map();
        game_state = controller.get_state_snake();
        break;
      case GameState_t::ATTACHING:
        game_state = controller.get_state_snake();
        break;
      case GameState_t::GAME_OVER:
        game_state = controller.get_state_snake();
        game_info = controller.get_game_info_snake();
        game_over_logic();
        exit = true;
        break;
      default:
        break;
    }
  }
}

void BrickGameView::print_game_map() {
  for (int x = 1; x < SIZE_MAX_MAP_X; x++) {
    for (int y = 0; y < SIZE_MAX_MAP_Y; y++) {
      if (game_info.field[x][y] == 1 || game_info.next[x][y] == 1) {
        mvaddch(y + 1, x * 2, ACS_CKBOARD);
        mvaddch(y + 1, x * 2 + 1, ACS_CKBOARD);

      } else {
        mvaddch(y + 1, x * 2, ACS_BULLET);
        mvaddch(y + 1, x * 2 + 1, ' ');
      }
    }
  }
  mvprintw(SUPPORT_BORD_START_Y + 1, SUPPORT_BORD_START_X + 2, "Score : %d",
           game_info.score);
  mvprintw(SUPPORT_BORD_START_Y + 2, SUPPORT_BORD_START_X + 2, "LVL : %d",
           game_info.level);
  mvprintw(SUPPORT_BORD_START_Y + 3, SUPPORT_BORD_START_X + 2,
           "High score : %d", game_info.high_score);
  mvprintw(SUPPORT_BORD_START_Y + 4, SUPPORT_BORD_START_X + 2, "Speed : %d",
           game_info.level * 5);
}

void BrickGameView::print_game_bord() {
  mvaddch(0, 0, ACS_ULCORNER);  // Верхний левый угол
  for (int j = 0; j < SIZE_MAX_MAP_X * 2; ++j) {
    mvaddch(0, j + 1, ACS_HLINE);  // Горизонтальная линия
  }
  mvaddch(0, SIZE_MAX_MAP_X * 2, ACS_URCORNER);  // Верхний правый угол
  // Печать боковых границ и отображение поля
  for (int i = 0; i < SIZE_MAX_MAP_Y + 1; ++i) {
    mvaddch(i + 1, 0, ACS_VLINE);  // Левая граница
    mvaddch(i + 1, SIZE_MAX_MAP_X * 2, ACS_VLINE);
  }  // Правая граница

  // Печать нижней границы
  mvaddch(SIZE_MAX_MAP_Y + 1, 0, ACS_LLCORNER);  // Нижний левый угол
  for (int j = -1; j < SIZE_MAX_MAP_X * 2 - 1; ++j) {
    mvaddch(SIZE_MAX_MAP_Y + 1, j + 2, ACS_HLINE);  // Горизонтальная линия
  }
  mvaddch(SIZE_MAX_MAP_Y + 1, SIZE_MAX_MAP_X * 2,
          ACS_LRCORNER);  // Нижний правый угол
}

void BrickGameView::print_supp_bord() {
  // Печать информационного поля
  attron(A_BOLD);
  for (int j = SUPPORT_BORD_START_X;
       j <= SUPPORT_BORD_START_X + SUPPORT_BORD_SIZE_X; ++j) {
    mvaddch(SUPPORT_BORD_START_Y, j,
            ACS_HLINE);  // Верхняя горизонтальная линия
  }
  for (int i = SUPPORT_BORD_START_Y + 1;
       i < SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y; ++i) {
    mvaddch(i, SUPPORT_BORD_START_X + SUPPORT_BORD_SIZE_X,
            ACS_VLINE);  // Правая граница
  }
  for (int j = SUPPORT_BORD_START_X;
       j <= SUPPORT_BORD_START_X + SUPPORT_BORD_SIZE_X - 1; ++j) {
    mvaddch(SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y / 2 + 3, j,
            ACS_HLINE);  // Средняя линия
  }
  for (int i = SUPPORT_BORD_START_Y + 1;
       i < SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y; ++i) {
    mvaddch(i, SUPPORT_BORD_START_X, ACS_VLINE);  // Левая граница
  }
  for (int j = SUPPORT_BORD_START_X;
       j <= SUPPORT_BORD_START_X + SUPPORT_BORD_SIZE_X; ++j) {
    mvaddch(SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y, j,
            ACS_HLINE);  // Нижняя горизонтальная линия
  }
  mvaddch(SUPPORT_BORD_START_Y, SUPPORT_BORD_START_X, ACS_ULCORNER);
  mvaddch(SUPPORT_BORD_START_Y, SUPPORT_BORD_START_X + SUPPORT_BORD_SIZE_X,
          ACS_URCORNER);
  mvaddch(SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y, SUPPORT_BORD_START_X,
          ACS_LLCORNER);
  mvaddch(SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y,
          SUPPORT_BORD_START_X + SUPPORT_BORD_SIZE_X, ACS_LRCORNER);

  attron(COLOR_PAIR(2));
  mvprintw(SUPPORT_BORD_START_Y - 1,
           SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 3), "BRICK GAME");
  attroff(A_BOLD);
  attroff(COLOR_PAIR(2));
  mvprintw(SUPPORT_BORD_START_Y + 6, SUPPORT_BORD_START_X + 2,
           "Press LEFT/RIGHT for move");
  mvprintw(SUPPORT_BORD_START_Y + 7, SUPPORT_BORD_START_X + 2,
           "Press UP for rotate");
  mvprintw(SUPPORT_BORD_START_Y + 8, SUPPORT_BORD_START_X + 2,
           "Press DOWN to put down");
  mvprintw(SUPPORT_BORD_START_Y + 10, SUPPORT_BORD_START_X + 2,
           "Press P for pause");
  mvprintw(SUPPORT_BORD_START_Y + 11, SUPPORT_BORD_START_X + 2,
           "Press Q for exit");
}

void BrickGameView::print_next_figure() {
  mvprintw(SUPPORT_BORD_START_Y + SUPPORT_BORD_SIZE_Y - 6,
           SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 5), "   Next figure");
  figure = controller.get_current_figure();
  int distance_from_bottom_line = 2;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (figure.next_figure[i][j] == 1) {
        mvaddch(i + SUPPORT_BORD_SIZE_Y - distance_from_bottom_line,
                SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 3) + j * 2,
                ACS_CKBOARD);
        mvaddch(i + SUPPORT_BORD_SIZE_Y - distance_from_bottom_line,
                SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 3) + j * 2 + 1,
                ACS_CKBOARD);
      } else {
        mvaddch(i + SUPPORT_BORD_SIZE_Y - distance_from_bottom_line,
                SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 3) + j * 2, ' ');
        mvaddch(i + SUPPORT_BORD_SIZE_Y - distance_from_bottom_line,
                SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 3) + j * 2 + 1,
                ' ');
      }
    }
  }
}

void BrickGameView::print_exit_menu() {
  clear();
  attron(A_BOLD);
  attron(COLOR_PAIR(2));
  mvprintw(4, 5, "EXIT MENU");
  attroff(COLOR_PAIR(2));
  mvprintw(6, 2, "Do you want exit?");
  mvprintw(8, 2, "Q     - NO");
  mvprintw(9, 2, "ENTER - YES");
  attroff(A_BOLD);
}

void BrickGameView::print_pause_menu() {
  clear();
  attron(A_BOLD);
  attron(COLOR_PAIR(2));
  mvprintw(4, 5, "PAUSE");
  attroff(COLOR_PAIR(2));
  mvprintw(6, 2, "press P to resume");
  attroff(A_BOLD);
}

void BrickGameView::print_lose_banner() {
  clear();
  attron(A_BOLD);
  attron(COLOR_PAIR(2));
  mvprintw(3, 3, "GAME OVER");
  attroff(COLOR_PAIR(2));
  mvprintw(5, 1, "Your Score = %d", game_info.score);
  mvprintw(6, 1, "Your Level = %d", game_info.level);
  mvprintw(7, 1, "Your High score = %d", game_info.high_score);
  mvprintw(8, 1, "Press Q to exit");
  attroff(A_BOLD);
}

void BrickGameView::game_over_logic() {
  bool exit = false;
  print_lose_banner();
  while (!exit) {
    UserAction_t action = get_action(getch());
    switch (action) {
      case UserAction_t::Terminate:
        exit = true;
        main_menu();
        break;
      default:
        break;
    }
  }
}

void BrickGameView::exit_menu_logic() {
  print_exit_menu();
  bool exit = false;
  while (!exit) {
    UserAction_t action = get_action(getch());
    switch (action) {
      case UserAction_t::Action:
        exit = true;
        main_menu();
        break;
      case UserAction_t::Terminate:
        exit = true;
        break;
      default:
        break;
    }
  }
}

void BrickGameView::main_menu() {
  int key;
  int selected_item = 0;
  print_menu(selected_item);
  while ((key = getch()) != ESCAPE) {
    switch (key) {
      case KEY_UP:
        selected_item = (selected_item - 1 >= 0) ? selected_item - 1 : 0;
        break;
      case KEY_DOWN:
        if (selected_item + 1 < 2)
          selected_item++;
        else if (selected_item + 1 < 3)
          selected_item = 2;
        break;
      case '\n':
        execute_menu_item(selected_item);
        break;
      default:
        break;
    }
    print_menu(selected_item);
  }
  endwin();
}

void BrickGameView::print_menu(int selected_item) {
  nodelay(stdscr, false);
  clear();
  refresh();
  attron(COLOR_PAIR(2));
  attron(A_BOLD);
  mvprintw(2, 7, "Main menu");
  attroff(COLOR_PAIR(2));
  for (int i = 0; i < 3; ++i) {
    if (selected_item == i) {
      attron(A_REVERSE);
    }
    switch (i) {
      case 0:
        mvprintw(4 + i, 7, "%d. %s", i + 1, "Tetris");
        break;
      case 1:
        mvprintw(4 + i, 7, "%d. %s", i + 1, "Snake");
        break;
      case 2:
        mvprintw(4 + i, 7, "%d. %s", i + 1, "Exit");
    }
    if (selected_item == i) {
      attroff(A_REVERSE);
    }
  }
  attroff(A_BOLD);
  mvprintw(8, 1, "Use arrows to select item");
  mvprintw(9, 1, "Press ENTER to continue");
  mvprintw(10, 1, "Press ESC to exit");
}

void BrickGameView::execute_menu_item(int item) {
  switch (item) {
    case 0:
      clear();
      refresh();
      controller.tetris_init();
      view.tetris_loop();
      break;
    case 1:
      clear();
      refresh();
      controller.snake_init();
      view.snake_loop();
      break;
    case 2:
      endwin();
      exit(0);
      break;
  }
}
}  // namespace mo