QT += core gui widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += GUI

SOURCES += \
    ../../main.cpp \
    brickgame_desktop.cpp \
    ../../brick_game/snake/snake_model.cpp \
    ../../brick_game/tetris/tetris_model.cpp

HEADERS += \
    brickgame_desktop.h \
    ../../brick_game/snake/snake_model.h \
    ../../brick_game/tetris/tetris_model.h \
    ../../brick_game/defines.h \
    ../../controller/controller.h


FORMS += \
    brickgame_desktop.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
