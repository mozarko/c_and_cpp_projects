#ifndef OBJECTS_H
#define OBJECTS_H

#include "tetris.h"

/** @brief Структура положения фигуры
 */
typedef struct {
  int Y;          ///< Координата по Y
  int X;          ///< Координата по Х
  int dimension;  ///< Размер фигуры
  int current_figure[MAX_DEMISION]
                    [MAX_DEMISION];  ///< текущая фигура на игровом поле
  int next_figure[MAX_DEMISION][MAX_DEMISION];  ///< следущая фигура на поле
} Current_Figure;

/** @brief Перечисление фигур
 */
typedef enum {
  LINE,         ///< Линия
  G_LEFT,       ///< Г-образная фигура левая
  G_RIGHT,      ///< Г-образная фигура правая
  CUBE,         ///< Куб
  Z_RIGHT_UP,   ///< Z-образная фигура верх вправо
  CROSS,        ///< Т-образная фигура
  Z_LEFT_UP,    ///< Z- образная фигура верх влево
  FIGURE_COUNT  ///< Количество фигур
} FigureType;

/** @brief Функция для получения текущей структуры с фигурой */
Current_Figure *get_current_figure();

/** @brief Генерация следующей фигуры */
void genereated_next_figure();

/** @brief Генерация рандомного числа от 0 до 6 для выбора случайной фигуры  */
int get_rand_number_figures();

/** @brief Возвращает указатель на матрицу с нужной фигурой */
int *get_figure(FigureType type);

/**
 * @brief Меняет местами следущую структуру с текущей, осле вызова функции, в
 * структуре Current_Figure следущая фигура будет храниться в текущей */
void swap_figure_old_to_new();

#endif