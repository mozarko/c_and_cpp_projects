#pragma once

#include "../defines.h"

namespace mo {

class TetrisModel {
 private:
  GameInfo_t game_info;
  GameState_t game_state;
  Current_Figure figure;
  UserAction_t action;

 public:
  /** @brief Функция получения ввода пользователя от модуля view через
   * контроллер */
  void user_input(UserAction_t act);
  /** @brief Установка флага пауза */
  void set_pause(int pause) { game_info.pause = pause; };
  /** @brief установка флага выхода из игры */
  void set_exit_logic(int exit_logic) { game_info.exit_logic = exit_logic; };
  /** @brief Функция для получения текущей структуры с фигурой */
  Current_Figure get_current_figure() { return figure; };

  /** @brief Указана в library specification. Возвращает объект стурктуры с
   * информацией о полях игры и переменных (уровень, скорость, счет)
   */
  GameInfo_t UpdateCurrentState() { return game_info; };
  /** @brief Получение текущего состояния конечного автомата */
  GameState_t fsm_states();

  /** @brief Переворот фигуры
   */
  void rotate_figure();

  /** @brief Передвижение фигуры вниз. Если фигуры внизу не оказалось, то
   * двигаемся вниз, до конца поля, в случае полного ряда добавляем счет в
   * зависимости от того, сколько рядов удалось заполнить и создаем новую фигуру
   */
  void move_figure_down();

  /** @brief Проверка коллизии по Y */
  bool check_collision_y();

  /** @brief Проверка коллизии по X
   */
  bool check_collision_x();

  /** @brief Движение фигуры влево
   */
  void move_figure_left();

  /** @brief Движение фиуры вправо
   */
  void move_figure_right();

  /** @brief Проверка наличия заполненных рядов */
  int check_lines();

  /** @brief Генерация следующей фигуры */
  void genereated_next_figure();

  /** @brief Генерация рандомного числа от 0 до 6 для выбора случайной фигуры */
  int get_rand_number_figures();

  /** @brief Возвращает указатель на матрицу с нужной фигурой */
  int *get_figure(int type);

  /** @brief Сохранение текущей фигуры */
  void save_figure();

  /** @brief Проверка наложения фигуры на поле */
  bool check_attaching();

  /** @brief Обновление поля */
  void update_field();

  /** @brief Добавление фигуры в поле */
  void add_figure_to_field();

  /** @brief Проверка возможности стадии SPAWN, для определения продолжения или
   * конца игры */
  bool can_spawn();

  /** @brief Инициализация игрового поля */
  void init_board();

  /** @brief Основная функция регулирования скорости игры */
  int is_fall_time();

  /** @brief Перевод количество заполненных линий в очки */
  void lines_to_score(int lines);

  /** @brief Очистка поля с фигурой (next) */
  void clear_next();

  /** @brief Получение максимального счета из файла*/
  int get_records();

  /** @brief Обработака состояния START */
  void start_state();

  /** @brief Обработака состояния SPAWN */
  void spawn_state();

  /** @brief Обработака состояния MOVING */
  void moving_state();

  /** @brief Обработака состояния SHIFTING */
  void shifting_state();

  /** @brief Обработака состояния ATTACHING */
  void attaching_state();
};
}  // namespace mo