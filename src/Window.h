#ifndef WINDOW_H
#define WINDOW_H

//!
//! \file Window.h
//! \brief Window and main class of the project.
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

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
#include "MenuStart.h"
#include "MenuPause.h"

///!
//! \brief Enum to know where the player is in the game
//!
enum gameStates {

    GAMESTATE_START,        /*!< The player is in the start menu */
    GAMESTATE_INGAME,       /*!< The player is in the game  */
    GAMESTATE_PAUSE,        /*!< THe player is in the pause menu */
    GAMESTATE_OPTIONS,      /*!< The player is in the options menu */

    GAMESTATE_NBR           /*!< The number of game states */

};

//!
//! \class Window
//! \brief Window and main class of the project.
//!
class Window {

public:
    //!
    //! \brief Window constructor
    //!
    Window() throw(std::exception);
    //!
    //! \brief Window destructor
    //!
    ~Window();
    //!
    //! \brief Method to initialize SDL2 and the required SDL2 libraries
    //!
    void initSDL();
    //!
    //! \brief Method to initialize the media files (images, fonts...)
    //!
    void initRessources();
    //!
    //! \brief Method to create the characters
    //!
    void createCharacters();
    //!
    //! \brief Method to render a splash screen at the start of the game
    //!
    void drawSplashScreen();
    //!
    //! \brief Menu to render the start menu of the game
    //!
    void drawMenuStart();
    //!
    //! \brief Method to draw the top of the window (score panel)
    //!
    void drawHudTop();
    //!
    //! \brief Method to draw the game area
    //!
    void drawAreaGame();
    //!
    //! \brief Method to render the characters
    //!
    void drawCharacters();
    //!
    //! \brief Method to render all the pac-dots to the screen
    //! \return The cumulated points of all the non-eaten pac-dots
    //!
    int drawPacDots();
    //!
    //! \brief Method to draw the bottom of the window (lifes and fruit numbers)
    //!
    void drawHudBottom();
    //!
    //! \brief Method to handle all the events for each instance
    //! \param e : SDL_Event
    //!
    void handleEvent( SDL_Event& e );
    //!
    //! \brief Method to create a thread for the ghosts moves
    //! \param data : ???????
    //! \return 0
    //!
    static int createThread( void* data );
    //!
    //! \brief Method called by the thread and containing the loop for the ghosts actions
    //!
    void threadGhostsLoop();
    ///!
    //! \brief Method to render the inside window
    //!
    void render();
    //!
    //! \brief Method containing the main loop of the game
    //!
    void loop();
    //!
    //! \brief Method to run the game at the targetted number of FPS placed in parameter
    //! \param fps : The number of FPS targetted for the game
    //! \param startLoop : The time at the beginning of the loop
    //! \param endLoop : The time at the end of the loop
    //!
    void calculateFPS( int const& fps, int const& startLoop, int const& endLoop );
    //!
    //! \brief Method to exit the window
    //!
    void quit();
    //!
    //! \brief Method to start a new life and reset to default several values
    //!
    void startNewLife();
    //!
    //! \brief Method to reset the data (after a new/restart game)
    //!
    void resetData();

private:
    bool _quit;                                 /*!< Flag for the SDL loop */
    int _screenWidth;                           /*!< Width of the window */
    int _screenHeight;                          /*!< Height of window */
    SDL_Window *_window;                        /*!< Window */
    SDL_Surface *_windowSurface;                /*!< SDL_Surface of the Window */
    SDL_Renderer *_renderer;                    /*!< Renderer of the window */
    SDL_Thread *_threadGhosts;                  /*!< Thread to manage the ghosts moves */
    Uint8 _gameState;                           /*!< Flag to know where the player is in the game */
    bool _loaded;                               /*!< Flag to know if the level has already been loaded */

    /* Instances of the project classes */
    FilesManager* _fm;                          /*!<  Instance of FilesManager */
    MenuStart* _ms;                             /*!<  Instance of MenuStart */
    MenuPause* _mp;                             /*!<  Instance of MenuPause */
    Game* _game;                                /*!<  Instance of Game */
    AreaTop* _areaTop;                          /*!<  Instance of AreaTop */
    AreaGame* _areaGame;                        /*!<  Instance of AreaGame */
    AreaBottom* _areaBottom;                    /*!<  Instance of AreaBottom */
    PacMan *_pacMan;                            /*!<  Instance of PacMan */
    std::vector<Ghost*> _ghosts;                /*!<  Array containing instances of Ghost */
    std::vector<Fruit*> _fruit;                 /*!<  Array containing instances of Fruit */
    PacDotsManager* _pdm;                       /*!<  Instance of PacDotsManager */

};
#endif
