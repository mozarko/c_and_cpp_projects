#pragma once

#include <vector>

namespace mo {

/** @brief Стрелка вверх*/
#define UP_ARROW KEY_UP
/** @brief Стрелка вниз */
#define DOWN_ARROW KEY_DOWN
/** @brief Стрелка влево */
#define LEFT_ARROW KEY_LEFT
/** @brief Стрелка вправо */
#define RIGHT_ARROW KEY_RIGHT

/// @brief Определяем клавишу ESCAPE
#define ESCAPE 27
/// @brief Определяем клавишу ENTER
#define ENTER_KEY 10
/// @brief Определяем клавишу SPACE
#define SPACE 32

/** @brief Размеры и положение информационного поля */
#define SUPPORT_BORD_START_Y 2   ///<  Начальная позиция по Y
#define SUPPORT_BORD_START_X 28  ///< Начальная позиция по X
#define SUPPORT_BORD_SIZE_X 28   ///< Ширина поля
#define SUPPORT_BORD_SIZE_Y 19   ///< Высота поля

/** @brief
 * Размер карты по высоте
 */
#define SIZE_MAX_MAP_Y 20
/** @brief
 * Размер карты по ширине
 */
#define SIZE_MAX_MAP_X 11

/// @brief Перечисление игр, которые можно запустить
enum class GameType { Tetris, Snake, None, Console };

/** @brief Перечисление с параметрами действий в игре
 */
enum class UserAction_t {
  Start,      ///< Начиначем играть
  Pause,      ///< Пауза
  Terminate,  ///< Меню выхода
  Left,       ///< Движение влево
  Right,      ///< Движение вправо
  Up,         ///< Поворот фигуры
  Down,       ///< Опустить фигуры
  Action,     ///< Действие
  Inaction    ///< Бездействие
};

/** @brief Стадии конечного автомата */
enum class GameState_t {
  START,  ///< это состояние, в котором игра ожидает, пока игрок нажмет кнопку
  ///< готовности.
  SPAWN,  ///< это состояние, в которое переходит игра, когда создается блок и
  ///< выбирается следующий блок для спавна.
  MOVING,  ///< это основное состояние игры с обработкой пользовательского ввода
  ///< - вращение блоков / перемещение блоков по горизонтали
  SHIFTING,  ///< это состояние, в которое переходит игра после истечения
  ///< таймер. Он перемещает текущий блок на один уровень ниже. Если
  ///< блок остановлен в верхнем ряду, игра переходит в состояние
  ///< "игра окончена".
  ATTACHING,  ///< это состояние, в которое переходит игра после того, как
  ///< текущий блок "касается" уже упавших блоков или земли. Если
  ///< создаются полные ряды, он уничтожается, а оставшиеся блоки
  ///< перемещаются вниз.
  GAME_OVER  ///< это Конец игры

};

/** @brief Структура для хранения информации о игре
 */
struct GameInfo_t {
  std::vector<std::vector<int>> field;  ///< Основное поле
  std::vector<std::vector<int>> next;   ///< Поле с фигурой
  int score;                            ///< Текущий счет
  int high_score;                       ///< Максимальный счет
  int level;                            ///< Уровень
  int speed;                            ///< Скорость
  int pause;                            ///< Флаг паузы
  int exit_logic;                       ///< Флаг выхода
};

/** @brief Структура положения фигуры
 */
struct Current_Figure {
  int Y;                     ///< Координата по Y
  int X;                     ///< Координата по Х
  int current_figure[4][4];  ///< текущая фигура на игровом поле
  int next_figure[4][4];  ///< следущая фигура на поле
};

/** @brief Перечисление фигур
 */
enum FigureType {
  LINE,        ///< Линия
  G_LEFT,      ///< Г-образная фигура левая
  G_RIGHT,     ///< Г-образная фигура правая
  CUBE,        ///< Куб
  Z_RIGHT_UP,  ///< Z-образная фигура верх вправо
  CROSS,       ///< Т-образная фигура
  Z_LEFT_UP,   ///< Z- образная фигура верх влево
};

/** @brief Перечисление направлений движения змейки */
enum class Direction { LEFT, RIGHT, UP, DOWN };

/** @brief Структура для хранения координат элементов змейки и яблока */
struct Point {
  int X;
  int Y;
  bool operator==(const Point& other) const {
    return (X == other.X) && (Y == other.Y);
  }
};

/** @brief Структура для хранения змейки и напраления ее движения */
struct SnakeInfo {
  std::vector<Point> body;
  Direction direction;
};

}  // namespace mo