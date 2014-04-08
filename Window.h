#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_thread.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include "Const.h"
#include "FilesManager.h"
#include "AreaGame.h"
#include "Pacman.h"
#include "Ghost.h"

class Window {

public:
    Window() throw(std::exception);
    ~Window();
    void initSDL();
    void initRessources();
    void drawAreaGame();
    void createCharacters();
    void drawHudTop();
    void drawHudBottom();
    static int createThread(void*);
    void threadGhostsLoop();
    void loop();
    void quit();
    void startNewLife();
    void pauseGame();
    void loadMenuPause();
    void unpauseGame();
    void gameOver();
    void quitGame();

private:
    bool _quit;
    int _screenWidth;
    int _screenHeight;
    SDL_Window *_window;
    SDL_Surface *_windowSurface;
    SDL_Renderer *_renderer;
    FilesManager* _fm;
    AreaGame* _areaGame;
    Pacman *_pacman;
    std::vector<Ghost*> _ghosts;
    SDL_Thread *_threadGhosts;

};
#endif
