#pragma once

#include <QApplication>
#include <QKeyEvent>
#include <QMainWindow>
#include <QPainter>
#include <QPushButton>
#include <QStackedWidget>
#include <QString>
#include <QThread>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

#include "../../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class QtBrickGame;
}
QT_END_NAMESPACE

namespace mo {

class QtBrickGame : public QMainWindow {
  Q_OBJECT

 public:
  QtBrickGame(QWidget *parent = nullptr);
  ~QtBrickGame();

 protected:
  void paintEvent(QPaintEvent *event) override;
  void keyPressEvent(QKeyEvent *event) override;

 private slots:
  void on_quit_button_clicked();
  void on_snake_button_clicked();
  void on_tetris_button_clicked();
  void on_quit_button_2_clicked();
  void on_menu_button_clicked();

 private:
  GameInfo_t game_info;
  GameState_t game_state;
  Current_Figure figure;
  UserAction_t action;
  GameType current_game;

  QTimer *timer;
  Ui::QtBrickGame *ui;

  void update_game();
  void print_field(QPainter &painter);
  void print_next_figure(QPainter &painter);
  void print_game_info(QPainter &painter);
  void print_pause(QPainter &painter);
  void print_game_over(QPainter &painter);
  void print_exit_logic(QPainter &painter);
};
}  // namespace mo
