TEMPLATE = app
CONFIG -= console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

# Include SDL
INCLUDEPATH += usr/include
LIBS += -L/usr/lib64 -L/usr/local/lib64 -lSDL2 -lSDL2_image -lSDL2_ttf

SOURCES += main.cpp \
    Window.cpp \
    AreaGame.cpp \
    InteractiveElement.cpp \
    PacMan.cpp \
    Ghost.cpp \
    Character.cpp \
    Area.cpp \
    AreaBottom.cpp \
    AreaTop.cpp \
    FilesManager.cpp \
    Game.cpp \
    Fruit.cpp \
    PacDot.cpp \
    PacDotsCase.cpp \
    PacDotsManager.cpp

HEADERS += \
    Window.h \
    Const.h \
    AreaGame.h \
    InteractiveElement.h \
    PacMan.h \
    Ghost.h \
    Character.h \
    Area.h \
    AreaBottom.h \
    AreaTop.h \
    FilesManager.h \
    Game.h \
    Fruit.h \
    PacDot.h \
    PacDotsCase.h \
    PacDotsManager.h

