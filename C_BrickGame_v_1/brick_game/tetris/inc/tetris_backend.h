#ifndef TETRIS_BACKEND_H
#define TETRIS_BACKEND_H

#include "tetris.h"

/** @brief Повышение уровня по счету. Каждые 600 очков повышает уровень и
 * повышает скорость
 */
int lvl_up(int score);

/** @brief Проверка состояния паузы
 */
bool checked_pause();

/** @brief Включить паузу */
void on_pause_game();

/** @brief Выключить паузу */
void off_pause_game();

/** @brief Проверка нажатой клавиши на валидность
 */
bool is_valid_key(int ch);

/** @brief Ожидание ввода, если ввода нет ждет указанное время
 */
bool my_delay(int milliseconds, int ch);

/** @brief Перевород фигуры
 */
void rotate_figure();

/** @brief Проверка края поля при повороте
 */
bool check_collision_rotate();

/** @brief Передвижение фигуры вниз. Если фигуры внизу не оказалось, то
 * двигаемся вниз, до конца поля, в случае полного ряда добавляем счет в
 * зависимости от того, сколько рядов удалось заполнить и создаем новую фигуру
 */
void move_figure_down();

/** @brief Проверка заполненности рядов внизи или конца поля */
bool check_collision_down();

/** @brief Движение фигуры влево
 */
void move_figure_left();

/** @brief Проверка края поля или фигуры слева
 */
bool check_collision_left();

/** @brief Движение фиуры вправо
 */
void move_figure_right();

/** @brief Проверка края поля или фигуры справа
 */
bool check_collision_right();

/**
 * @brief Передача управления новой фигурой. Обнуляет координаты старой фигуры.
 * В случае заполненности поля, заканчивает игру
 */
void apperance_figure_to_next_field();

/** @brief Обновляет фигуру и создает следующую
 */
void create_random_tetromino();

/** @brief Передает игровую карту в функции печати карты на экран
 */
void save_next_map_in_field_map();

/** @brief Счет заполненых линий
 */
int check_lines();

/** @brief Удаление линии по указанному Y в ряд
 */
void remove_lines(int remove_lines_y);

/**  @brief Проверка полная ли линия по указаному Y
 */
bool is_full_lines(int Y);

/**
 * @brief Добавление очков к счету */
void add_score(int countTrue);

/** @brief Проверка существующих рекордов с прошлых игр
 */
int check_records();
#endif