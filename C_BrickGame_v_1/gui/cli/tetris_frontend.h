#ifndef TETRIS_FRONTEND_H
#define TETRIS_FRONTEND_H

#include "../../brick_game/tetris/inc/tetris.h"

/** @brief Главная функция */
void game_loop();

/** @brief Инициализация игры */
int win_init_function(int time);

/** @brief Основной цикл игры */
int game_function();

/** @brief Завершение игры */
void exit_game();

/** @brief Выбор пункта меню */
void menu_selected_item();

/** @brief Функция для печати баннера проигрыша */
void print_lose_banner();

/** @brief Функция для печати отображения следующей фигуры */
void print_next_figure();

/** @brief Обновление игрового экрана */
void update_game_screen();

/** @brief Функция для очистки предыдущей игровой карты */
void clear_old_next_map();

/** @brief Функция для печати меню */
void print_menu(int selected_item);

/** @brief Функция для печати меню паузы */
void print_pause_menu();

/** @brief Функция для печати меню выхода */
void print_exit_menu();

/** @brief Функция для печати игрового поля с фигурами */
void print_game_map();

/** @brief Функция для печати информационного поля */
void print_support_bord();

/** @brief Выполнение выбранного пункта меню */
void execute_menu_item(int item);

#endif
