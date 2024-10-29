#include "brickgame_desktop.h"

#include "ui_brickgame_desktop.h"

namespace mo {

TetrisModel tetris_model;
SnakeModel snake_model;

BrickgameController controller(tetris_model, snake_model);

QtBrickGame::QtBrickGame(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::QtBrickGame) {
  srand(static_cast<unsigned int>(time(nullptr)));
  ui->setupUi(this);
  current_game = GameType::None;
  action = UserAction_t::Inaction;
  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &QtBrickGame::update_game);
}

QtBrickGame::~QtBrickGame() { delete ui; }

void QtBrickGame::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_Left:
      action = UserAction_t::Left;
      break;
    case Qt::Key_Right:
      action = UserAction_t::Right;
      break;
    case Qt::Key_Up:
      action = UserAction_t::Up;
      break;
    case Qt::Key_Down:
      action = UserAction_t::Down;
      break;
    case Qt::Key_Q:
      action = UserAction_t::Terminate;
      break;
    case Qt::Key_Escape:
      action = UserAction_t::Action;
      break;
    case Qt::Key_P:
      action = UserAction_t::Pause;
      break;
  }
}

void QtBrickGame::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event)
  QPainter painter(this);
  if (current_game == GameType::Snake) {
    if (game_state != GameState_t::GAME_OVER) {
      if (game_state == GameState_t::START) {
        print_field(painter);
      } else {
        print_game_info(painter);
        print_field(painter);
        if (game_info.pause) {
          print_pause(painter);
        }
        if (game_info.exit_logic) {
          print_exit_logic(painter);
        }
      }
    } else {
      print_game_over(painter);
    }
  } else if (current_game == GameType::Tetris) {
    if (game_state != GameState_t::GAME_OVER) {
      if (game_state == GameState_t::START) {
        print_field(painter);
      } else {
        print_next_figure(painter);
        print_game_info(painter);
        print_field(painter);
        if (game_info.pause) {
          print_pause(painter);
        }
        if (game_info.exit_logic) {
          print_exit_logic(painter);
        }
      }
    } else {
      print_game_over(painter);
    }
  }
}

void QtBrickGame::on_quit_button_clicked() { close(); }

void QtBrickGame::on_snake_button_clicked() {
  controller.snake_init();
  current_game = GameType::Snake;
  game_info = controller.get_game_info_snake();
  game_state = controller.get_state_snake();
  game_state = GameState_t::START;
  action = UserAction_t::Inaction;
  ui->stackedWidget->setCurrentIndex(3);
  timer->start(20);
}

void QtBrickGame::on_tetris_button_clicked() {
  controller.tetris_init();
  current_game = GameType::Tetris;
  game_info = controller.get_game_info_tetris();
  game_state = controller.get_state_tetris();
  game_state = GameState_t::START;
  action = UserAction_t::Inaction;
  ui->stackedWidget->setCurrentIndex(1);
  timer->start(20);
}

void QtBrickGame::on_quit_button_2_clicked() { close(); }

void QtBrickGame::on_menu_button_clicked() {
  current_game = GameType::None;
  ui->stackedWidget->setCurrentIndex(0);
}

void QtBrickGame::update_game() {
  if (current_game == GameType::Tetris) {
    figure = controller.get_current_figure();
    game_info = controller.get_game_info_tetris();
    game_state = controller.get_state_tetris();
    controller.user_input_tetris(action);
    action = UserAction_t::Inaction;
    if (game_state == GameState_t::GAME_OVER) {
      timer->stop();
      game_state = controller.get_state_tetris();
      ui->stackedWidget->setCurrentIndex(2);
    }
  } else if (current_game == GameType::Snake) {
    game_info = controller.get_game_info_snake();
    game_state = controller.get_state_snake();
    controller.user_input_snake(action);
    action = UserAction_t::Inaction;
    if (game_state == GameState_t::GAME_OVER) {
      timer->stop();
      game_state = controller.get_state_snake();
      ui->stackedWidget->setCurrentIndex(2);
    }
  }
  update();
}

void QtBrickGame::print_field(QPainter &painter) {
  QPixmap cube_y("images/1.png");
  for (int x = 1; x < SIZE_MAX_MAP_X; ++x) {
    for (int y = 0; y < SIZE_MAX_MAP_Y; ++y) {
      if (game_info.field[x][y]) {
        painter.drawPixmap((x * 20) + 25, (y * 20) + 50, cube_y.scaled(20, 20));
      } else {
        painter.drawRect((x * 20) + 25, (y * 20) + 50, 20, 20);
      }
    }
  }
  QPixmap cube_b("images/2.png");
  for (int x = 1; x < SIZE_MAX_MAP_X; ++x) {
    for (int y = 0; y < SIZE_MAX_MAP_Y; ++y) {
      if (game_info.next[x][y]) {
        painter.drawPixmap((x * 20) + 25, (y * 20) + 50, cube_b.scaled(20, 20));
      }
    }
  }
}
void QtBrickGame::print_next_figure(QPainter &painter) {
  QPixmap kub("images/2.png");
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (figure.next_figure[i][j]) {
        painter.drawPixmap((j * 20) + 310, (i * 20) + 250, 20, 20,
                           kub.scaled(20, 20));
      }
    }
  }
}

void QtBrickGame::print_game_info(QPainter &painter) {
  QFont font("Ubuntu Sans", 20);
  painter.setFont(font);
  painter.drawText(290, 170, QString::number(game_info.score));
  painter.drawText(394, 170, QString::number(game_info.high_score));
  painter.drawText(420, 415, QString::number(game_info.level));
  painter.drawText(290, 415, QString::number(game_info.speed * 5));
}

void QtBrickGame::print_pause(QPainter &painter) {
  QFont font("Ubuntu Bold", 25);
  painter.setFont(font);
  painter.drawText(50, 250, "TO UNPAUSE");
  painter.drawText(70, 290, "PRESS 'P'");
}

void QtBrickGame::print_exit_logic(QPainter &painter) {
  QFont font("Ubuntu Bold", 20);
  painter.setFont(font);
  painter.drawText(50, 250, "FOR EXIT");
  painter.drawText(50, 290, "PRESS 'ESC'");
  painter.drawText(50, 330, "TO CONTINUE");
  painter.drawText(50, 370, "PRESS 'Q'");
}

void QtBrickGame::print_game_over(QPainter &painter) {
  QFont font("Ubuntu Sans", 30);
  painter.setFont(font);
  painter.drawText(330, 185, QString::number(game_info.level));
  painter.drawText(340, 260, QString::number(game_info.score));
  painter.drawText(270, 340, QString::number(game_info.high_score));
}
}  // namespace mo
