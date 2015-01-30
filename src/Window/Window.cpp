#include "Window.h"

using namespace std;

#include "../InteractiveElements/PacDot.h"

#include <pm/Color.h>
#include <pm/Directions.h>

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
    _screenWidth( 900 ),
    _screenHeight( 850 ),
    _gameState( GAMESTATE_INGAME ),
    _loaded(false) {

    try {

        _quitApp = new bool();
        _quitGame = new bool();

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

        _initializer->initCharacters( this, _pacMan, _ghosts );

        //The mutex
        _ghostsLock = SDL_CreateMutex();
        //The conditions
        _ghostsCanMove = SDL_CreateCond();

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
        if( !_pacMan->getGhostEatenScoreChrono()->isRunning()
                && _pacMan->move() != NO_DIRECTION ) {

            _pacMan->nextSprite();

        }

        Uint16 score = 0;

        // If there is a collision with a fruit (score != 0) > no collision with a pacdots
        if( !_pacMan->checkCollisionWithFruit( _frm ) )
            _pacMan->checkCollisionWithPacDots( _pdm );

        score += _frm->getTotalFruitScore();
        score += drawPacDots();

        _game->setScoreP1( score );
        _game->incComboPowerPellet();

        auto funcPacMan = []( PacMan* pacMan, SDL_Renderer* renderer ) {

            // If a ghost has been eaten, don't render the pacman => because the score is rendered
            if( !pacMan->getGhostEatenScoreChrono()->isRunning() )
                pacMan->show( renderer );

        };

        auto funcGhosts = []( Ghost* ghost, SDL_Renderer* renderer, Game* game ) {

            // Render the ghost
            switch( ghost->getBehavior()->getState() ) {

            // If the ghost has recently been eaten, draw the score
            case SHOW_SCORE:
                ghost->drawScorePowerPellet( renderer, game->getComboPowerPellet() );
                break;
            case HUNTER:
            case HUNTED:
            case RETURN_TO_WARPZONE:
            case DEFAULT_WARPZONE:
            case ENTER_WARPZONE:
            case EXIT_WARPZONE:
                ghost->show( renderer );
                break;

            }

        };

        // If the Pac-Man as eaten a power-pellet
        // => render the gosts first rather than him (for the superposition of the sprites)
        if( _pacMan->getPowerPelletChrono()->isRunning() ) {

            for( int i(0); i < _ghosts.size(); i++ )
                funcGhosts( _ghosts[i], _renderer, _game );
            funcPacMan( _pacMan, _renderer );

        }

        // Otherwise, render the Pac-Man first
        else {

            funcPacMan( _pacMan, _renderer );
            for( int i(0); i < _ghosts.size(); i++ )
                funcGhosts( _ghosts[i], _renderer, _game );

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
            *_quitApp = true;
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

    while( !*_quitApp ) {

        startLoop = SDL_GetTicks();

        while( SDL_PollEvent(&e) != 0 ) {

            switch( e.type ) {

            case SDL_QUIT:
                *_quitApp = true;
                break;

            case SDL_KEYDOWN:

                switch(e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    *_quitApp = true;
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

bool* Window::getQuitApp() const { return _quitApp; }

bool* Window::getQuitGame() const { return _quitGame; }

SDL_Renderer* Window::getRenderer() const { return _renderer; }

FilesManager* Window::getFm() const { return _fm; }

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
