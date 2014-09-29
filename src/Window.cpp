#include "Window.h"

#include <pm/Color.h>
#include <pm/PacDots.h>
using namespace PacDots;

using namespace std;

char _levelString[] =
        "2;1;1;1;1;1;1;1;1;1;1;7;1;1;1;1;1;1;1;1;1;1;5;"
        "0;-14;-14;-14;-14;@;-3;-3;-3;-3;-6;10;-5;-3;-3;-3;-3;-3;-10;-3;-3;-14;0;"
        "0;-4;26;25;29;-4;26;25;25;29;-4;10;-4;26;25;25;29;-4;26;25;29;-4;0;"
        "0;-4;27;25;28;-4;27;25;25;28;-4;14;-4;27;25;25;28;-4;27;25;28;-4;0;"
        "0;-11;-3;-3;-3;-13;-3;-10;-3;-3;-9;-3;-9;-3;-10;-3;-3;-13;-3;-3;-3;-12;0;"
        "0;-4;12;11;13;-4;15;-4;12;11;11;22;11;11;13;-4;15;-4;12;11;13;-4;0;"
        "0;-14;-3;-3;-3;-12;10;-7;-3;-3;-6;10;-5;-3;-3;-8;10;-11;-3;-3;-3;-14;0;"
        "3; 1; 1; 1; 5;-4;21;11;11;13;0;14;0;12;11;11;20;-4; 2; 1; 1; 1;4;"
        "-2;-2;-2;-2;0;-4;10;#;#;#;#;-2;-2;-2;-14;-2;10;-4; 0;-2;-2;-2;-2;"
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

Window::Window() throw(exception) :
    _quit(false),
    _screenWidth(900),
    _screenHeight(850),
    _gameState( GAMESTATE_GAMEOVER ),
    _loaded(false) {

    try {

        // Initialize all the needed SDL libraries
        initSDL();

        // Initialize the ressources files
        _fm = new FilesManager();
        initRessources();

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

        // Initialize the fruit
        _frm = new FruitManager();
        _frm->initFruit( _renderer, _fm->getSpriteCharacters() );
        _frm->initFruitLocationCoord( _fm->getFruitLocationCoord() );

        // Initialize the position of the bubbles
        _pdm = new PacDotsManager( _fm->getLevelTable(), _renderer, _fm->getSpriteCharacters() );

        createCharacters();

    }
    catch(const exception &e) {

        quit();

    }

}

Window::~Window() {

    SDL_DestroyMutex( _ghostsLock );
    SDL_DestroyCond( _ghostsCanMove );

}

void Window::initSDL() {

    // if error, we throw an exception
    if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
        throw exception();

    // SDL initialization is ok
    else {

        // Enable VSync
        if( !SDL_SetHint( SDL_HINT_RENDER_VSYNC, "1" ) )
            throw exception();

        // Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
            throw exception();

        // Create window
        _window = SDL_CreateWindow( "Pac-Man", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenWidth, _screenHeight, SDL_WINDOW_BORDERLESS );

        if( _window == NULL )
            throw exception();

        else {

            // Create renderer for window
            _renderer = SDL_CreateRenderer( _window, -1, SDL_RENDERER_ACCELERATED );
            if( _renderer == NULL )
                throw exception();

            else {

                _windowSurface = SDL_GetWindowSurface(_window);

                //Initialize renderer color
                SDL_SetRenderDrawColor( _renderer, 13, 13, 11, 0 );

                // Disable mouse cursor
                SDL_ShowCursor(SDL_DISABLE);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                    throw exception();

                else {

                    // Load SDL_ttf and the font
                    if( TTF_Init() == -1 ) {
                        throw exception();
                    }

                }

            }
        }

    }

}

void Window::initRessources() {

    // Load the images
    // If error when loading
    if( !_fm->loadIMG() ) {
        throw exception();
    }

    // Load SDL_ttf and the font
    if( !_fm->loadFont() ) {
        throw exception();
    }

}

void Window::createCharacters() {

    SDL_SetColorKey( _fm->getSpriteCharacters() , SDL_TRUE, SDL_MapRGB( _fm->getSpriteCharacters()->format, 0, 0, 0) );

    map<string, int> dest;

    // Pacman creation
    dest["row"] = _fm->getCharacterCoordRow("Pacman");
    dest["col"] = _fm->getCharacterCoordCol("Pacman");
    _pacMan = new PacMan( dest, _renderer, _fm->getSpriteCharacters() );
    _pacMan->calculateDirection(_fm->getLevelTable());

    // Ghosts creation
    stringstream ss;
    for(int i(0); i < _fm->getGhostsNbr(); i++) {

        ss << "Ghost" << i+1;
        dest["row"] = _fm->getCharacterCoordRow( ss.str() );
        dest["col"] = _fm->getCharacterCoordCol( ss.str() );
        _ghosts.push_back( new Ghost(dest, _renderer, _fm->getSpriteCharacters()) );
        _ghosts[i]->calculateDirection( _fm->getLevelTable() );
        ss.str(""); // Clear the string stream

    }

    //The mutex
    _ghostsLock = SDL_CreateMutex();
    //The conditions
    _ghostsCanMove = SDL_CreateCond();

    // At the start of the game, creation of the thread for the ghosts
    _threadGhosts = SDL_CreateThread( Window::createThread, "Thread for Ghosts moves", (void*) this );

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

        _pacMan->updateAll( _fm->getLevelTable(), _fm->getTeleportationLocationsCoord() );
        if( _pacMan->move() != -1 ) {

            _pacMan->nextSprite();

        }

        Uint16 score = 0;

        // If there is a collision with a fruit (score != 0) > no collision with a pacdots
        if( !_pacMan->checkCollisionWithFruit( _frm ) )
            _pacMan->checkCollisionWithPacDots( _pdm );

        score += _frm->getTotalFruitScore();
        score += drawPacDots();

        _game->setScoreP1( score );

        _pacMan->show(_renderer);

        // Render the ghosts
        for( int i(0); i < _ghosts.size(); i++ )
            _ghosts[i]->show(_renderer);

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

    // The ghosts move while Pacman is not dead
    while( !_pacMan->isDead() ) {

        // Condition to pause the ghosts thread if the player is in the menus
        if( _gameState != GAMESTATE_INGAME ) {

            cout << "Waiting... Ghosts thread is in pause because the player is in the menus." << endl;

            // Pause the thread
            SDL_mutexP( _ghostsLock );
            SDL_CondWait( _ghostsCanMove, _ghostsLock );
            SDL_mutexV( _ghostsLock );

        }

        for( int i(0); i < _fm->getGhostsNbr(); i++ ) {

            // Update the ghost attributes
            _ghosts[i]->updateAll( _fm->getLevelTable(), _fm->getTeleportationLocationsCoord() );

            // Move the ghost
            if( _ghosts[i]->move() != -1 ) {               

                // After the move, detect if there is a collision
                if( _ghosts[i]->checkCollision( _pacMan ) ) {

                    // Eat the pacman... or be eaten by him. Depending the power-pellet chronometer
                    _ghosts[i]->eat( _pacMan );

                }
                _ghosts[i]->nextSprite();

            }

            // Power pellet behavior
            _ghosts[i]->handlePowerPellet( _pacMan );

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
        _pacMan->calculateDirection(_fm->getLevelTable());
        _pacMan->show(_renderer);

        // Restore ghosts attributes to default
        for(int i(0); i < _ghosts.size(); i++) {
            _ghosts[i]->startValues();
            _ghosts[i]->calculateDirection(_fm->getLevelTable());
            _ghosts[i]->show(_renderer);
        }

        // Restart of the Ghosts thread
        _threadGhosts = SDL_CreateThread( Window::createThread, "Thread for Ghosts moves", (void*) this );

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
