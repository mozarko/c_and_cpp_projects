#ifndef DEFINES_H
#define DEFINES_H

/** @brief Колличествово валидных значений */
#define NUMBER_OF_KEYS 5
/** @brief Стрелка вверх*/
#define UP_ARROW KEY_UP
/** @brief Стрелка вниз */
#define DOWN_ARROW KEY_DOWN
/** @brief Стрелка влево */
#define LEFT_ARROW KEY_LEFT
/** @brief Стрелка вправо */
#define RIGHT_ARROW KEY_RIGHT
/** @brief Макросы для игнорирования регистра
 * @return true, если значение равно Q или q / P или p
 */
#define IS_Q(c) ((c == 'q') || (c == 'Q'))
#define IS_P(c) ((c == 'p') || (c == 'P'))
/** @brief Макрос для проверки ввода
 * @return true, если нажата клавиша ENTER
 */
#define IS_ENTER(c) (c == '\n')
/** @brief Макрос для проверки ввода
 * @return true, если нажаты нужные клавиши
 */
#define IF_INPUT(c) ((IS_Q(c) == true || IS_P(c) == true))

/** @brief Размеры и положение информационного поля */
#define SUPPORT_BORD_START_Y 2    ///<  Начальная позиция по Y
#define SUPPORT_BORD_START_X 28   ///< Начальная позиция по X
#define SUPPORT_BORD_SIZE_X 28    ///< Ширина поля
#define SUPPORT_BORD_SIZE_Y_1 12  ///< Высота первого поля
#define SUPPORT_BORD_SIZE_Y_2 10  ///< Высота второго поля

/** @brief Отображение информации на информационном поле*/
#define TITLE_PRINT                                          \
  mvprintw(SUPPORT_BORD_START_Y - 1,                         \
           SUPPORT_BORD_START_X + (SUPPORT_BORD_SIZE_X / 3), \
           "TETRIS GAME")  ///< Название игры
#define SCORE_PRINT(c)                                                       \
  mvprintw(SUPPORT_BORD_START_Y + 1, SUPPORT_BORD_START_X + 2, "Score : %d", \
           c)  ///< Счёт
#define LEVEL_PRINT(c)                                                     \
  mvprintw(SUPPORT_BORD_START_Y + 2, SUPPORT_BORD_START_X + 2, "LVL : %d", \
           c)  ///< Уровень
#define RECORD_PRINT(c)                                        \
  mvprintw(SUPPORT_BORD_START_Y + 3, SUPPORT_BORD_START_X + 2, \
           "High score : %d", c)  ///< Рекорд
#define SPEED_PRINT(c)                                                       \
  mvprintw(SUPPORT_BORD_START_Y + 4, SUPPORT_BORD_START_X + 2, "Speed : %d", \
           c)  ///< Скорость

#define ARROW_PRINT_1                                          \
  mvprintw(SUPPORT_BORD_START_Y + 6, SUPPORT_BORD_START_X + 2, \
           "Press LEFT/RIGHT for move")  ///< Информация о перемещении
#define ARROW_PRINT_2                                          \
  mvprintw(SUPPORT_BORD_START_Y + 7, SUPPORT_BORD_START_X + 2, \
           "Press UP for rotate")  ///< Информация о повороте
#define ARROW_PRINT_3                                     \
  mvprintw(                                               \
      SUPPORT_BORD_START_Y + 8, SUPPORT_BORD_START_X + 2, \
      "Press DOWN to put down")  ///< Информация о том как опустить фигуру
#define PAUSE_PRINT                                             \
  mvprintw(SUPPORT_BORD_START_Y + 10, SUPPORT_BORD_START_X + 2, \
           "Press P for pause")  ///< Информация о паузе
#define EXIT_PRINT                                              \
  mvprintw(SUPPORT_BORD_START_Y + 11, SUPPORT_BORD_START_X + 2, \
           "Press Q for exit")  ///< Информация о выходе из игры

/** @brief Макcимальный размер фигуру*/
#define MAX_DEMISION 4

/**
 * @brief Макрос для получения ввода пользователя
 */
#define GET_USER_INPUT getch()
/** @brief
 * Размер карты по высоте
 */
#define SIZE_MAX_MAP_Y 23
/** @brief
 * Размер карты по ширине
 */
#define SIZE_MAX_MAP_X 12

#endif