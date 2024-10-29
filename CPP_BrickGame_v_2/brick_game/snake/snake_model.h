#pragma once

#include "../defines.h"

namespace mo {

class SnakeModel {
 private:
  GameInfo_t game_info;
  GameState_t game_state;
  SnakeInfo snake_info;
  Point apple;
  UserAction_t action;

 public:
  /** @brief Функция получения ввода пользователя от модуля view через
   * контроллер */
  void user_input(UserAction_t act);

  /** @brief Установка флага пауза */
  void set_pause(int pause) { game_info.pause = pause; };
  /** @brief установка флага выхода из игры */
  void set_exit_logic(int exit_logic) { game_info.exit_logic = exit_logic; };
  /** @brief Функция обновления текущего состояния игры */
  GameInfo_t UpdateCurrentState() { return game_info; };
  /** @brief Получение текущего состояния конечного автомата */
  GameState_t fsm_states();
  /** @brief Генерация следующей точки головы змеи */
  Point new_head_point();

  /** @brief Функция движения змейки */
  void moving();

  /** @brief Движение фигуры влево
   */
  void move_left();

  /** @brief Движение фиуры вправо
   */
  void move_right();

  /** @brief Передвижение змейки вниз
   */
  void move_down();

  /** @brief Передвижение змейки вверх */
  void move_up();

  /** @brief Обновление поля */
  void update_field();

  /** @brief Добавление яблока на поле */
  void add_apple_to_field();

  /** @brief Инициализация игрового поля */
  void init_board();

  /** @brief Основная функция регулирования скорости игры */
  int is_shift_time();

  /** @brief Яблоки в очки */
  void apples_to_score();

  /** @brief Очистка поля */
  void clear_field();

  /** @brief Получение максимального счета из файла*/
  int get_records();

  /** @brief Обработака состояния SPAWN */
  void spawn_state();

  /** @brief Обработака состояния MOVING */
  void moving_state();

  /** @brief Обработака состояния SHIFTING */
  void shifting_state();

  /** @brief Обработака состояния ATTACHING */
  void attaching_state();

  /** @brief Функция генерации случайного числа для яблока*/

  int get_rand_X();

  /** @brief Функция генерации случайного числа для яблока*/
  int get_rand_Y();

  /** @brief Функция генерации яблока */
  void generated_next_apple();
};
}  // namespace mo