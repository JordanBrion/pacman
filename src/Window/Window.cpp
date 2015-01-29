#include "Window.h"

#include <pm/Color.h>
#include <pm/PacDots.h>
using namespace PacDots;

using namespace std;

char _levelString[] =
        "2;1;1;1;1;1;1;1;1;1;1;7;1;1;1;1;1;1;1;1;1;1;5;"
        "0;-14;-14;-14;-14;-3;-3;-3;-3;-3;-6;10;-5;-3;-3;-3;-3;-3;-10;-3;-3;-14;0;"
        "0;-4;26;25;29;-4;26;25;25;29;-4;10;-4;26;25;25;29;-4;26;25;29;-4;0;"
        "0;-4;27;25;28;-4;27;25;25;28;-4;14;-4;27;25;25;28;-4;27;25;28;-4;0;"
        "0;-11;-3;-3;-3;-13;-3;-10;-3;-3;-9;-3;-9;-3;-10;-3;-3;-13;-3;-3;-3;-12;0;"
        "0;-4;12;11;13;-4;15;-4;12;11;11;22;11;11;13;-4;15;-4;12;11;13;-4;0;"
        "0;-14;-3;-3;-3;-12;10;-7;-3;-3;-6;10;-5;-3;-3;-8;10;-11;-3;-3;-3;-14;0;"
        "3; 1; 1; 1; 5;-4;21;11;11;13;0;14;0;12;11;11;20;-4; 2; 1; 1; 1;4;"
        "-2;-2;-2;-2;0;-4;10;#;#;#;#;-2;-2;-2;-14;@;10;-4; 0;-2;-2;-2;-2;"
        " 1; 1; 1; 1;4;-4;14;2;36; 1;35;33;34; 1;39;2;14;-4; 3; 1; 1; 1; 1;"
        "a;-2;-2;-2;0;-4;0;-2; 0;-2;-2;-2;-2;-2; 0;-2;0;-4;0;-2;-2;-2;a;"
        " 1; 1; 1; 1;5;-4;15;-2;37; 1; 1; 1; 1; 1;38;-2;15;-4; 2; 1; 1; 1; 1;"
        "-2;-2;-2;-2;0;-4;10;-2;-2;-2;-2;=;-2;-2;-2;-2;10;-4; 0;-2;-2;-2;-2;"
        "2 ; 1; 1; 1;4;-4;14;0;12;11;11;22;11;11;13;0;14;-4; 3; 1; 1; 1; 5;"
        "0 ;-14;-3;-3;-3;-13;-3;-3;-3;-3;-6;10;-5;-3;-3;-9;-3;-13;-3;-3;-3;-14;0;"
        "0 ;-4;12;11;19;-4;12;11;11;13;-4;14;-4;12;11;11;13;-4;16;11;13;-4;0;"
        "0 ;-7;-3;-6;10;-5;-3;-10;-3;-3;-8;-2;-7;-3;-3;-3;-3;-12;10;-5;-3;-8;0;"
        "9 ;11;13;-4;14;-4;15;-4;12;11;11;22;11;11;13;-4;15;-4;14;-4;12;11;6;"
        "0 ;-5;-3;-9;-3;-8;10;-7;-3;-3;-6;10;-11;-3;-3;-8;10;-7;-3;-3;-3;-6;0;"
        "0 ;-4;12;11;11;11;23;11;11;13;-4;14;-4;12;11;11;23;11;11;11;13;-4;0;"
        "0 ;-14;-3;-3;-3;-3;-3;-3;-3;-3;-9;-3;-7;-3;-3;-3;-3;-3;-3;-3;-3;-14;0;"
        "3;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;4;";

Window::Window() throw( const std::exception& ) :
    _quit(false),
    _screenWidth(900),
    _screenHeight(850),
    _gameState( GAMESTATE_INGAME ),
    _loaded(false) {

    try {

        _initializer = new WindowInitializer();

        if( !_initializer->initSDL(_window, _screenWidth, _screenHeight, _renderer, _windowSurface ) )
            throw std::exception();

        // Initialize the ressources files
        _fm = new FilesManager();
        if( !_initializer->initRessources( _fm ) )
            throw std::exception();

        // Load the level
        _fm->initLevelTable( _levelString );
        _fm->initLevelSpriteCoord();

        // Instanciate the menu start
        vector<string> v;
        v.push_back( "New game" );
        v.push_back( "Options" );
        v.push_back( "Quit game" );
        _ms = new MenuStart( "Start menu", v );

        // Instanciate the menu pause
        v.clear();
        v.push_back( "Resume the game" );
        v.push_back( "Restart the game" );
        v.push_back( "Options" );
        v.push_back( "Return to start menu" );
        _mp = new MenuPause( "Pause", v );

        // Instanciate the game over menu
        v.clear();
        v.push_back( "Yes" );
        v.push_back( "No" );
        _mgo = new MenuGameOver( "Game Over", v );

        // Initialize attributes
        _game = new Game( _fm->getLifesNbr(), _fm->getPacDotsNbr(), _fm->getHighScore() );
        _areaTop = new AreaTop();
        _areaGame = new AreaGame( _renderer, _fm->getSpriteLevel() );
        _areaBottom = new AreaBottom();

        SDL_Texture* textCharac = SDL_CreateTextureFromSurface( _renderer,
                                                                _fm->getSpriteCharacters() );

        std::vector<SDL_Rect> selections;
        selections.push_back( { 173, 164, 18, 18 });
        selections.push_back( { 173, 184, 18, 18 });
        selections.push_back( { 173, 204, 18, 18 });
        selections.push_back( { 173, 224, 18, 18 });
        selections.push_back( { 213, 165, 18, 18 });
        selections.push_back( { 213, 185, 18, 18 });
        selections.push_back( { 213, 205, 18, 18 });
        selections.push_back( { 213, 225, 18, 18 });

        // Initialize the fruit
        _frm = new FruitManager();
        _frm->initFruit( textCharac, selections );
        _frm->initFruitLocationCoord( _fm->getFruitLocationCoord() );

        // Initialize the position of the bubbles
        _pdm = new PacDotsManager( _fm->getLevelTable(), textCharac );

        _initializer->initCharacters( _fm, _renderer, _pacMan, _ghosts );

        //The mutex
        _ghostsLock = SDL_CreateMutex();
        //The conditions
        _ghostsCanMove = SDL_CreateCond();

        // At the start of the game, creation of the thread for the ghosts
        _threadGhosts = SDL_CreateThread( Window::createThread, "Thread for Ghosts moves", (void*) this );

    }
    catch( const std::exception& e) {

        quit();

    }

}

Window::~Window() {

    SDL_DestroyMutex( _ghostsLock );
    SDL_DestroyCond( _ghostsCanMove );

}

void Window::drawSplashScreen() {

    SDL_Rect position;
    Uint8 opacity = 0xFF;

    SDL_Surface* logo = _fm->getLogo();
    SDL_Texture* textureLogo = SDL_CreateTextureFromSurface( _renderer, logo );
    double ratio = logo->w / logo->h;

    SDL_Surface* text = TTF_RenderText_Solid( _fm->getFont(), "A Jordan Brion Game made with love", Color::SDL_WHITE );
    SDL_Texture* textureText = SDL_CreateTextureFromSurface( _renderer, text );

    while ( opacity > 0 ) {

        SDL_RenderClear( _renderer );

        // Render the logo
        SDL_SetTextureAlphaMod( textureLogo, opacity );
        position.w = _screenWidth * 0.5;
        position.h = position.w / ratio;
        position.x = _screenWidth / 2 - position.w / 2;
        position.y = _screenHeight / 2 - position.h / 2;
        SDL_RenderCopy( _renderer, textureLogo, NULL, &position );

        // Render the text
        SDL_SetTextureAlphaMod( textureText, opacity );
        position.w = _screenWidth * 0.5;
        position.h = position.w / 20;
        position.x = _screenWidth / 2 - position.w / 2;
        position.y = _screenHeight * 0.25;
        SDL_RenderCopy( _renderer, textureText, NULL, &position );

        SDL_RenderPresent( _renderer );

        opacity--;

        SDL_Delay( 1 );

    }

}

void Window::drawMenuStart() {

    _ms->render( _renderer, _screenWidth, _screenHeight, _fm->getFont(), _fm->getLogo() );

}

void Window::drawHudTop() {

    _areaTop->drawArea( _renderer, _fm->getFont(), _game->getHighScore(), _game->getScoreP1(), _game->getScoreP2()  );

}

void Window::drawAreaGame() {

    _areaGame->drawArea( _renderer, _fm->getRowsNbr(), _fm->getColsNbr(), _fm->getLevelTable(), _fm->getLevelSpriteCoord() );

}

void Window::drawCharacters() {

    // If pacman is dead
    if( _pacMan->isDead() ) {

        // Load the pacman dead animation
        _pacMan->deathAnimation(_renderer);

        // If the animation is ended
        if( _pacMan->getDeathAnimationCounter() > 11 ) {
            startNewLife();
        }

    }
    else {

        _pacMan->updateAll();
        if( Ghost::eatenBrother == -1 && _pacMan->move() != -1 ) {

            _pacMan->nextSprite();

        }

        Uint16 score = 0;

        // If there is a collision with a fruit (score != 0) > no collision with a pacdots
        if( !_pacMan->checkCollisionWithFruit( _frm ) )
            _pacMan->checkCollisionWithPacDots( _pdm );

        score += _frm->getTotalFruitScore();
        score += drawPacDots();

        _game->setScoreP1( score );

        // If a ghost has been eaten, don't render the pacman => because the score is rendered
        if( Ghost::eatenBrother == -1 )
            _pacMan->show( _renderer );

        // Render the ghosts
        for( int i(0); i < _ghosts.size(); i++ ) {

            // If the ghost has recently been eaten, draw the score
            if( Ghost::eatenBrother == i ) {
                _ghosts[i]->drawScorePowerPellet( _renderer, _game->getComboPowerPellet() );
            }

            // Otherwise, draw the ghost
            else
                _ghosts[i]->show( _renderer );

        }

    }

}

int Window::drawPacDots() {

    return _pdm->render( _renderer );

}

void Window::drawHudBottom() {

    _areaBottom->drawLifesPanel(_renderer, _fm->getSpriteCharacters(), _fm->getFont(), _game->getLifesNbr() );
    _areaBottom->drawFruitPanel(_renderer, _fm->getSpriteCharacters(), _fm->getFont(), _frm->getFruit() );

}

void Window::handleEvent( SDL_Event& e ) {

    switch( _gameState ) {

    case GAMESTATE_START:

        switch( _ms->handleEvent( e ) ) {

        case 0:
            break;

        case MENUSTART_START:
            if( _loaded ) {
                resetData();
                _loaded = false;
            }
            _gameState = GAMESTATE_INGAME;
            // Send the signal to the ghosts thread to unpause it
            SDL_mutexP( _ghostsLock );
            SDL_CondSignal( _ghostsCanMove );
            SDL_mutexV( _ghostsLock );
            break;

        case MENUSTART_OPTIONS:
            _gameState = GAMESTATE_OPTIONS;
            break;

        case MENUSTART_QUIT:
            _quit = true;
            break;

        default:
            break;

        }

        break;

    case GAMESTATE_INGAME:

        if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_a ) {

            _gameState = GAMESTATE_PAUSE;

        }

        else
            _pacMan->handleEvent( e );

        break;

    case GAMESTATE_PAUSE:

        switch( _mp->handleEvent( e ) ) {

        case 0:
            break;

        case MENUPAUSE_RESUME:
            _gameState = GAMESTATE_INGAME;
            // Send the signal to the ghosts thread to unpause it
            SDL_mutexP( _ghostsLock );
            SDL_CondSignal( _ghostsCanMove );
            SDL_mutexV( _ghostsLock );
            break;

        case MENUPAUSE_RESTART:
            resetData();
            _gameState = GAMESTATE_INGAME;
            _mp->setElementID( MENUPAUSE_RESUME );
            // Send the signal to the ghosts thread to unpause it
            SDL_mutexP( _ghostsLock );
            SDL_CondSignal( _ghostsCanMove );
            SDL_mutexV( _ghostsLock );
            break;

        case MENUPAUSE_OPTIONS:
            _gameState = GAMESTATE_OPTIONS;
            break;

        case MENUPAUSE_QUIT:
            _gameState = GAMESTATE_START;
            _loaded = true;
            _mp->setElementID( MENUPAUSE_RESUME );
            break;

        default:
            break;

        }

        break;

    case GAMESTATE_OPTIONS:
        break;

    case GAMESTATE_GAMEOVER:

        switch( _mgo->handleEvent( e ) ) {

        case MENUGAMEOVER_YES:
            resetData();
            _gameState = GAMESTATE_INGAME;
            // Send the signal to the ghosts thread to unpause it
            SDL_mutexP( _ghostsLock );
            SDL_CondSignal( _ghostsCanMove );
            SDL_mutexV( _ghostsLock );
            break;

        case MENUGAMEOVER_NO:
            _gameState = GAMESTATE_START;
            _loaded = true;
            _mgo->setElementID( MENUGAMEOVER_YES );
            break;

        default:
            break;

        }

        break;

    default:
        break;

    }

}

int Window::createThread(void* data) {

    Window *w = (Window*) data;
    w->threadGhostsLoop();

    return 0;

}

void Window::threadGhostsLoop() {

    while( 1 ) {

        // Condition to pause the ghosts thread if the player is in the menus
        if( _gameState != GAMESTATE_INGAME ) {

            cout << "Waiting... Ghosts thread is in pause because the player is in the menus." << endl;

            // Pause the thread
            SDL_mutexP( _ghostsLock );
            SDL_CondWait( _ghostsCanMove, _ghostsLock );
            SDL_mutexV( _ghostsLock );

        }

        // If the pacman didn't ate eat a ghost recently => don't move the ghosts
        else if( Ghost::eatenBrother == -1 ) {

            for( int i(0); i < _fm->getGhostsNbr(); i++ ) {

                // Update the ghost attributes
                _ghosts[i]->updateAll();

                // Move the ghost
                if( _ghosts[i]->move() != -1 ) {

                    // After the move, detect if there is a collision
                    if( _ghosts[i]->checkCollision( _pacMan ) ) {

                        // Eat the pacman... or be eaten by him. Depending the power-pellet chronometer
                        if( !_ghosts[i]->eat( _pacMan )
                                && _pacMan->getPowerPelletChrono()->isRunning() ) {

                            // The pacman eat the ghost
                            Ghost::eatenBrother = i;

                            // Change the combo power-pellet score
                            _game->incComboPowerPellet();

                            _pacMan->getPowerPelletChrono()->pause();
                            _pacMan->getGhostEatenScoreChrono()->start();

                            // The chrono is now running
                            // => wait for the end
                            SDL_WaitThread( _pacMan->getGhostEatenScoreChrono()->getThread(), 0 );
                            break;

                        }

                    }

                    _ghosts[i]->nextSprite();

                }

                // Power pellet behavior
                _ghosts[i]->handlePowerPellet( _pacMan );

            }

        }

        // If the pacman eat a ghost recently => don't move the ghosts and render the score
        else {

            // If the chrono is over
            if( _pacMan->getGhostEatenScoreChrono()->isOver() ) {

                // The power-pellet score chrono is over
                // The eaten ghost has to return to the warpzone
                _ghosts[ Ghost::eatenBrother ]->returnToWarpZone();

                Ghost::eatenBrother = -1;

                // Set the power-pellet multiplicator value to 0
                _game->resetComboPowerPellet();

            }

        }

        SDL_Delay(20);

    }

}

void Window::render() {

    switch( _gameState ) {

    case GAMESTATE_START:
        _ms->render( _renderer, _screenWidth, _screenHeight, _fm->getFont(), _fm->getLogo() );
        break;

    case GAMESTATE_INGAME:

        if( _frm->checkFruitChronos() )
            _frm->renderFruit( _renderer );

        drawCharacters();
        drawHudTop();
        drawAreaGame();
        drawHudBottom();

        break;

    case GAMESTATE_PAUSE:
        _mp->render( _renderer, _screenWidth, _screenHeight, _fm->getFont(), _fm->getLogo() );
        break;

    case GAMESTATE_OPTIONS:
        break;

    case GAMESTATE_GAMEOVER:
        _mgo->render( _renderer, _screenWidth, _screenHeight, _fm->getFont(), _fm->getLogo() );
        break;

    default:
        break;

    }

}

void Window::loop() {

    SDL_Event e;

    // Variables to compare time left in the loop
    int startLoop = 0;
    int endLoop = 0;

    // Flag for blocking of key up infinite loop
    bool stopKeyUp(false);

    while( !_quit ) {

        startLoop = SDL_GetTicks();

        while( SDL_PollEvent(&e) != 0 ) {

            switch( e.type ) {

            case SDL_QUIT:
                _quit = true;
                break;

            case SDL_KEYDOWN:

                switch(e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    _quit = true;
                    break;
                }
                break;

            }

            handleEvent( e );

        }

        SDL_RenderClear(_renderer);

        render();

        // Render changes on the screen
        SDL_RenderPresent(_renderer);

        // Render the game at the targetted FPS
        endLoop = SDL_GetTicks();
        calculateFPS( 60, startLoop, endLoop );


    }
}

void Window::calculateFPS( int const& fps, int const& startLoop, int const& endLoop ) {

    Uint32 oneIteration = 1000 / fps;
    Uint32 timeLeft = endLoop - startLoop;

    if( timeLeft < oneIteration ) {

        Uint32 waiting = oneIteration - timeLeft;
        SDL_Delay( waiting );

    }
    else {

        Uint32 waiting = 0;
        SDL_Delay( waiting );

    }

}

void Window::quit() {

    cout << SDL_GetError() << endl;

}

void Window::startNewLife() {

    _game->decLifesNbr();

    // If there is still one life
    if( _game->getLifesNbr() > 0 ) {

        // Restore Pacman attributes to default
        _pacMan->startValues();
        _pacMan->calculateDirection();
        _pacMan->show( _renderer );

        // Restore ghosts attributes to default
        for(int i(0); i < _ghosts.size(); i++) {
            _ghosts[i]->startValues();
            _ghosts[i]->calculateDirection();
            _ghosts[i]->show( _renderer );
        }

    }

    // Otherwise, the game is over
    else
        _gameState = GAMESTATE_GAMEOVER;

}

void Window::resetData() {

    // Reset HUD top
    _game->setScoreP1(0);
    _game->setScoreP2(0);

    // Reset pac-dots
    _pdm->reinitAllPacDotsEaten();

    // Reset HUD bottom
    _game->setLifesNbr( _fm->getLifesNbr() );
    _game->resetAllFruitNbr();

    // Reset characters positions in the grid
    _pacMan->startValues();
    for( int i(0); i < _ghosts.size(); i++ )
        _ghosts[i]->startValues();

}
