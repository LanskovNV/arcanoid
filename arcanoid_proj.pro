TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QT += gl
LIBS += /usr/lib/libglut.so /usr/lib/libGL.so

SOURCES += \
    ./src/ball_cl.cpp \
    ./src/brick_cl.cpp \
    ./src/button_cl.cpp \
    ./src/game_cl.cpp \
    ./src/glut_callbacks.cpp \
    ./src/level_cl.cpp \
    ./src/list_cl.cpp \
    ./src/main.cpp \
    ./src/platform_cl.cpp

DISTFILES += \
    ./src/game_menu_list.txt \
    ./src/help_menu_list.txt \
    ./src/start_menu_list.txt

HEADERS += \
    ./src/ball_cl.h \
    ./src/brick_cl.h \
    ./src/button_cl.h \
    ./src/color_class.h \
    ./src/game_cl.h \
    ./src/glut_callbacks.h \
    ./src/level_cl.h \
    ./src/list_cl.h \
    ./src/platform_cl.h \
    ./src/point_cl.h
