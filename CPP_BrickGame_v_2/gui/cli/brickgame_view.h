#pragma once
#include <ncurses.h>

#include <iostream>

#include "../../brick_game/defines.h"

namespace mo {

void start_brickgame();

class BrickGameView {
 private:
  GameInfo_t game_info;
  GameState_t game_state;
  Current_Figure figure;

 public:
  /** @brief Основной цикл игры тетрис */
  void tetris_loop();

  /** @brief Основной цикл игры змейка */
  void snake_loop();

  /** @brief Получение нажатия клавиши пользователем */
  UserAction_t get_action(int action);

  /** @brief Функция для печати баннера проигрыша */
  void print_lose_banner();

  /** @brief Функция для печати отображения следующей фигуры */
  void print_next_figure();

  /** @brief Функция для печати меню паузы */
  void print_pause_menu();

  /** @brief Функция для печати меню выхода */
  void print_exit_menu();

  /** @brief Функция для печати игрового поля с фигурами */
  void print_game_map();

  /** @brief Функция для печати рамок поля */
  void print_game_bord();

  /** @brief Функция для печати информационного поля */
  void print_supp_bord();

  /** @brief Логика выхода из игры при завершении игры */
  void game_over_logic();
  /** @brief Логика меню выхода из игры при нажатии кнопки выхода */
  void exit_menu_logic();

  /** @brief Выполнение выбранного пункта меню */
  void execute_menu_item(int item);
  /** @brief Выбор пункта меню */
  void main_menu();
  /** @brief Функция для печати меню */
  void print_menu(int selected_item);
};
}  // namespace mo