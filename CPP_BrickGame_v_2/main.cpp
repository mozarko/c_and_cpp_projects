#ifdef CLI

#include "gui/cli/brickgame_view.h"

int main() {
  mo::start_brickgame();
  return 0;
}

#endif

#ifdef GUI

#include <QApplication>

#include "gui/desktop/brickgame_desktop.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  mo::QtBrickGame w;
  w.show();
  return a.exec();
}
#endif
