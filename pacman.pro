TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

# Include SDL
INCLUDEPATH += usr/include
INCLUDEPATH += usr/lib/include
LIBS += -L/usr/lib -L/usr/local/lib -lSDL2 -lSDL2_image -lSDL2_ttf

SOURCES += main.cpp \
    Window.cpp \
    AreaGame.cpp \
    InteractiveElement.cpp \
    Pacman.cpp \
    Ghost.cpp \
    Character.cpp \
    Area.cpp \
    AreaBottom.cpp \
    AreaTop.cpp \
    FilesManager.cpp \
    Game.cpp \
    Collectible.cpp \
    Bubble.cpp \
    BubblesCase.cpp \
    BubblesManager.cpp

HEADERS += \
    Window.h \
    Const.h \
    AreaGame.h \
    InteractiveElement.h \
    Pacman.h \
    Ghost.h \
    Character.h \
    Area.h \
    AreaBottom.h \
    AreaTop.h \
    FilesManager.h \
    Game.h \
    Collectible.h \
    Bubble.h \
    BubblesCase.h \
    BubblesManager.h

