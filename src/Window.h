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
#include "AreaTop.h"
#include "AreaGame.h"
#include "AreaBottom.h"
#include "PacMan.h"
#include "Ghost.h"
#include "Fruit.h"
#include "PacDotsManager.h"
#include "Game.h"

class Window {

public:
    Window() throw(std::exception);
    ~Window();
    void initSDL();
    void initRessources();
    void createCharacters();
    void drawHudTop();
    void drawAreaGame();
    int drawBubbles();
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
    bool _quit;                                 // Flag for the SDL loop
    int _screenWidth;                           // Width of the window
    int _screenHeight;                          // Height of window
    SDL_Window *_window;                        // Window
    SDL_Surface *_windowSurface;                // SDL_Surface of the Window
    SDL_Renderer *_renderer;                    // Renderer of the window
    SDL_Thread *_threadGhosts;                  // Thread to manage the ghosts moves

    /* Instances of the project classes */
    FilesManager* _fm;
    Game* _game;
    AreaTop* _areaTop;
    AreaGame* _areaGame;
    AreaBottom* _areaBottom;
    PacMan *_pacMan;
    std::vector<Ghost*> _ghosts;
    std::vector<Fruit*> _fruit;
    PacDotsManager* _pdm;

};
#endif
