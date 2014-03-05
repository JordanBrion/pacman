#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include "Const.h"
#include "AreaGame.h"
#include "Pacman.h"

class Window {

public:
    Window() throw(std::exception);
    ~Window();
    void initSDL();
    void createAreaGame(char[]);
    void createHUD();
    void createCharacters();
    void loop();
    void quit();
    void startGame();
    void startNewLife();
    void pauseGame();
    void gameOver();
    void quitGame();

private:
    int _screenWidth;
    int _screenHeight;
    SDL_Window *_window;
    SDL_Surface *_windowSurface;
    SDL_Renderer *_renderer;
    AreaGame *_areaGame;
    Pacman *pacman;

};
#endif
