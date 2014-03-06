TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

# Include SDL
LIBS += -L/usr/lib -lSDL2 -lSDL2_image -lSDL_ttf
INCLUDEPATH = usr/include

SOURCES += main.cpp \
    Window.cpp \
    AreaGame.cpp \
    InteractiveElement.cpp \
    Pacman.cpp \
    Personnage.cpp \
    Ghost.cpp

HEADERS += \
    Window.h \
    Const.h \
    AreaGame.h \
    InteractiveElement.h \
    Pacman.h \
    Personnage.h \
    Ghost.h

