#include "../inc/objects.h"

void genereated_next_figure() {
  Current_Figure *figure = get_current_figure();
  int figure_number = get_rand_number_figures();
  int *figure_pointer = get_figure(figure_number);
  figure->dimension = 4;
  for (int i = 0; i < figure->dimension; ++i) {
    for (int j = 0; j < figure->dimension; ++j) {
      int value = *(figure_pointer + i * figure->dimension + j);
      figure->next_figure[i][j] = value;
    }
  }
}
Current_Figure *get_current_figure() {
  static Current_Figure figure;
  return &figure;
}
/*получение фигуры*/
int *get_figure(FigureType type) {
  static int figure_line[4][4] = {
      {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}};

  static int figure_G_left[4][4] = {
      {0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};

  static int figure_G_right[4][4] = {
      {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};

  static int figure_Cube[4][4] = {
      {0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};

  static int figure_Z_right_up[4][4] = {
      {0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}};

  static int figure_cross[4][4] = {
      {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}};

  static int figure_Z_left_up[4][4] = {
      {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};

  switch (type) {
    case LINE:
      return (int *)figure_line;
      break;
    case G_LEFT:
      return (int *)figure_G_left;
      break;
    case G_RIGHT:
      return (int *)figure_G_right;
      break;
    case CUBE:
      return (int *)figure_Cube;
      break;
    case Z_RIGHT_UP:
      return (int *)figure_Z_right_up;
      break;
    case CROSS:
      return (int *)figure_cross;
      break;
    case Z_LEFT_UP:
      return (int *)figure_Z_left_up;
      break;
    default:
      return NULL;
  }
}
void swap_figure_old_to_new() {
  Current_Figure *GameFigure = get_current_figure();
  for (int i = 0; i < GameFigure->dimension; ++i) {
    for (int j = 0; j < GameFigure->dimension; ++j) {
      GameFigure->current_figure[i][j] = GameFigure->next_figure[i][j];
    }
  }
}
int get_rand_number_figures() {
  int min = 0;
  int max = 6;
  int random_value = rand() % (max - min + 1) + min;
  random_value %= 10;
  return random_value;
}