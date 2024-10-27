#ifndef FSM_H
#define FSM_H

#include "tetris.h"

/** @brief Перечисление с параметрами действий в игре
 */
typedef enum {
  Start,      ///< Начиначем играть
  Pause,      ///< Пауза
  Terminate,  ///< Меню выхода
  Left,       ///< Движение влево
  Right,      ///< Движение вправо
  Up,         ///< Поворот фигуры
  Down,       ///< Опустить фигуры
  Action,     ///< Генерация фиуры
  Inaction    ///< Бездействие
} UserAction_t;

/** @brief Структура для хранения информации о игре
 */
typedef struct {
  int **field;     ///< Основное поле
  int **next;      ///< Поле с фигурой
  int score;       ///< Текущий счет
  int high_score;  ///< Максимальный счет
  int level;       ///< Уровень
  int speed;       ///< Скорость
  int pause;       ///< Флаг паузы
} GameInfo_t;

/** @brief Функция для инициализации структуры и выделения динамической памяти
 * под матрицу игры
 */
void init_board();

/** @brief Очищение выделенной динамической памяти */
void free_memory();

/** @brief Старт игры, бесконечный цикл до заврешния или выполнения выхода
                       из игры */
void start_game();

/** @brief Инициализация игровых настроек */
void init_game_setting();

/** @brief Реализаци действий в игре, в зависимости от того, какая нажата
 * клавиша пользователем */
void user_input(UserAction_t action, bool hold);

/**
 * @brief Получение текущей информации об игре */
GameInfo_t *get_game_info();

/**@brief Получение текущего состояния игры */
UserAction_t *get_user_status();

/** @brief Устанавливает текущий статус игры */
void set_user_status(UserAction_t status);

/** @brief Принимает значение ввода и проверяет его на соответствие нажатию
 * клавиш */
UserAction_t check_key_pressed(int key);

/** @brief Указана в library specification. Обновляет текущее состояние игры */
GameInfo_t *updateCurrentState();  // указана в library specification

/** @brief Сохраняет рекорд в файл случае, если новый результат больше текущего
 * рекорда */
void save_record();

/** @brief Реализация логики паузы */
void pause_logic();

/** @brief Реализация логики выхода из текущей игры */
void exit_logic();

#endif