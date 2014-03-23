#include "Window.h"

using namespace std;

char _levelString[] =
        "2;1;1;1;1;1;1;1;1;1;1;7;1;1;1;1;1;1;1;1;1;1;5;"
        "0;#;-1;-1;-1;-1;-1;-1;-1;-1;-1;10;-1;-1;-1;-1;-1;-1;-1;-1;-1;#;0;"
        "0;-1;26;25;29;-1;26;25;25;29;-1;10;-1;26;25;25;29;-1;26;25;29;-1;0;"
        "0;-1;27;25;28;-1;27;25;25;28;-1;14;-1;27;25;25;28;-1;27;25;28;-1;0;"
        "0;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;0;"
        "0;-1;12;11;13;-1;15;-1;12;11;11;22;11;11;13;-1;15;-1;12;11;13;-1;0;"
        "0;-1;-1;-1;-1;-1;10;-1;-1;-1;-1;10;-1;-1;-1;-1;10;-1;-1;-1;-1;-1;0;"
        "3; 1; 1; 1; 5;-1;21;11;11;13;-1;14;-1;12;11;11;20;-1; 2; 1; 1; 1;4;"
        "-1;-1;-1;-1;0;-1;10;-1;-1;-1;-1;-1;-1;-1;-1;-1;10;-1; 0;-1;-1;-1;-1;"
        " 1; 1; 1; 1;4;-1;14;-1;36; 1;35;33;34; 1;39;-1;14;-1; 3; 1; 1; 1; 1;"
        "-1;-1;-1;-1;0;-1;-1;-1; 0;-1;-1;-1;-1;-1; 0;-1;-1;-1;0;-1;-1;-1;-1;"
        " 1; 1; 1; 1;5;-1;15;-1;37; 1; 1; 1; 1; 1;38;-1;15;-1; 2; 1; 1; 1; 1;"
        "-1;-1;-1;-1;0;-1;10;-1;-1;-1;-1;-1;-1;-1;-1;-1;10;-1; 0;-1;-1;-1;-1;"
        "2 ; 1; 1; 1;4;-1;14;-1;12;11;11;22;11;11;13;-1;14;-1; 3; 1; 1; 1; 5;"
        "0 ;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;10;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;0;"
        "0 ;-1;12;11;19;-1;12;11;11;13;-1;14;-1;12;11;11;13;-1;16;11;13;-1;0;"
        "0 ;-1;-1;-1;10;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;10;-1;-1;-1;0;"
        "9 ;1;1;1;1;1;1;1;1;1;1;22;11;11;13;-1;15;-1;14;-1;12;11;6;"
        "0 ;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;10;-1;-1;-1;-1;10;-1;-1;-1;-1;-1;0;"
        "0 ;-1;12;11;11;11;23;11;11;13;-1;14;-1;12;11;11;23;11;11;11;13;-1;0;"
        "0 ;#;-1;-1;-1;-1;-1;-1;-1;-1;@;1;-1;-1;-1;-1;-1;-1;-1;-1;-1;#;0;"
        "3;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;4;";

Window::Window() throw(exception) : _quit(false), _screenWidth(900), _screenHeight(800) {

    try {

        int rows(22);
        int cols(23);
        _areaGame = new AreaGame(rows, cols);

        initSDL();

        SDL_RenderClear(_renderer);

        createAreaGame(_levelString);
        createCharacters();

    }
    catch(const exception &e) {

        quit();

    }

}

Window::~Window() {}

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
        _windowSurface = SDL_GetWindowSurface(_window);

        if( _window == NULL || _windowSurface == NULL)
            throw exception();

        else {

            // Create renderer for window
            _renderer = SDL_CreateRenderer( _window, -1, SDL_RENDERER_ACCELERATED );
            if( _renderer == NULL )
                throw exception();

            else {

                //Initialize renderer color
                SDL_SetRenderDrawColor( _renderer, 13, 13, 11, 0 );

                // Disable mouse cursor
                SDL_ShowCursor(SDL_DISABLE);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                    throw exception();

                else {

                    // Load the images
                    // If error when loading
                    if( !_areaGame->imgLoad() ) {
                        throw exception();
                    }

                }

            }
        }

    }

}

void Window::createAreaGame(char pLevel[]) {

    _areaGame->initArea(pLevel, _renderer);

}

void Window::createHUD() {}

void Window::createCharacters() {

    SDL_SetColorKey( _areaGame->getSpriteAnim() , SDL_TRUE, SDL_MapRGB( _areaGame->getSpriteAnim()->format, 0, 0, 0) );

    map<string, int> dest;

    // Pacman creation
    dest["x"] = _areaGame->getCharacterCoordX("Pacman");
    dest["y"] = _areaGame->getCharacterCoordY("Pacman");
    _pacman = new Pacman( dest, _renderer, _areaGame->getSpriteAnim() );
    _pacman->calculateDirection(_areaGame->getLevelTable());

    // Ghosts creation
    stringstream ss;
    for(int i(0); i < 4; i++) {

        ss << "Ghost" << i+1;
        dest["x"] = _areaGame->getCharacterCoordX(ss.str());
        dest["y"] = _areaGame->getCharacterCoordY(ss.str());
        _ghosts.push_back( new Ghost(dest, _renderer, _areaGame->getSpriteAnim()) );
        _ghosts[i]->calculateDirection(_areaGame->getLevelTable());
        ss.str(""); // Clear the string stream

    }
    _threadGhosts = SDL_CreateThread( Window::createThread, "Thread for Ghosts moves", (void*) this );

}

int Window::createThread(void* data) {

    Window w = *( Window *) data;

    w.threadGhostsLoop();

    return 0;

}

void Window::threadGhostsLoop() {

    // The ghosts move while Pacman is not dead
    while( !_pacman->isDead() ) {

        for( int i(0); i < _ghosts.size(); i++ ) {
            if( _ghosts[i]->isCenteredInTheSquare() ) {

                _ghosts[i]->updatePositionInTheGrid();
                _ghosts[i]->calculateDirection(_areaGame->getLevelTable());
                _ghosts[i]->calculateOffset(false);
                _ghosts[i]->resetValues();
            }
            _ghosts[i]->move();
        }
        SDL_Delay(20);

    }

}

void Window::loop() {

    SDL_Event e;

    // Variables to compare time left
    int start = SDL_GetTicks();
    int later = 0;

    // Flag for blocking of key up infinite loop
    bool stopKeyUp(false);

    while( !_quit ) {

        SDL_PollEvent(&e);

        later = SDL_GetTicks();

        // If 10 ms down between the 2 keys pressed
        // else > nothing to do
        if( later - start >= 10 ) {

            start = later;
            later = 0;

            switch( e.type ) {

            case SDL_QUIT:
                _quit = true;
                break;

            // Key Down
            case SDL_KEYDOWN:

                SDL_RenderClear(_renderer);
                createAreaGame(_levelString);

                switch(e.key.keysym.sym) {
                case SDLK_ESCAPE:
                    _quit = true;
                    break;

                // Pacman controls
                case SDLK_UP:
                    if( _pacman->isCenteredInTheSquare() ) {

                        _pacman->updatePositionInTheGrid();
                        _pacman->calculateDirection(_areaGame->getLevelTable());
                        _pacman->calculateOffset(true);
                        _pacman->resetValues();

                    }
                    _pacman->moveVertically(true);
                    stopKeyUp = false;
                    break;

                case SDLK_DOWN:
                    if( _pacman->isCenteredInTheSquare() ) {
                        _pacman->updatePositionInTheGrid();
                        _pacman->calculateDirection(_areaGame->getLevelTable());
                        _pacman->calculateOffset(true);
                        _pacman->resetValues();

                    }
                    _pacman->moveVertically(false);
                    stopKeyUp = false;
                    break;

                case SDLK_RIGHT:
                    if( _pacman->isCenteredInTheSquare() ) {

                        _pacman->updatePositionInTheGrid();
                        _pacman->calculateDirection(_areaGame->getLevelTable());
                        _pacman->calculateOffset(false);
                        _pacman->resetValues();

                    }
                    _pacman->moveHorizontally(false);
                    stopKeyUp = false;
                    break;

                case SDLK_LEFT:
                    if( _pacman->isCenteredInTheSquare() ) {

                        _pacman->updatePositionInTheGrid();
                        _pacman->calculateDirection(_areaGame->getLevelTable());
                        _pacman->calculateOffset(false);
                        _pacman->resetValues();

                    }
                    _pacman->moveHorizontally(true);
                    stopKeyUp = false;
                    break;
                }
                /* END Pacman controls */
                break;

            // Key Up
            case SDL_KEYUP:

                // Once the key is down and when the user releases this key,
                // the programm goes through this case in an infinite loop
                // So we freeze this loop with a flag
                if( !stopKeyUp ) {

                    stopKeyUp = true;

                    switch(e.key.keysym.sym) {

                    case SDLK_UP:
                        if (_pacman->isCenteredInTheSquareWhenKeyUp() ) {

                            _pacman->updatePositionInTheGrid();
                            _pacman->calculateDirection(_areaGame->getLevelTable());
                            _pacman->calculateOffset(true);
                            _pacman->resetValues();
                        }
                        break;

                    case SDLK_DOWN:
                        if (_pacman->isCenteredInTheSquareWhenKeyUp() ) {

                            _pacman->updatePositionInTheGrid();
                            _pacman->calculateDirection(_areaGame->getLevelTable());
                            _pacman->calculateOffset(true);
                            _pacman->resetValues();
                        }
                        break;

                    case SDLK_RIGHT:
                        if (_pacman->isCenteredInTheSquareWhenKeyUp() ) {

                            _pacman->updatePositionInTheGrid();
                            _pacman->calculateDirection(_areaGame->getLevelTable());
                            _pacman->calculateOffset(false);
                            _pacman->resetValues();
                        }
                        break;

                    case SDLK_LEFT:
                        if (_pacman->isCenteredInTheSquareWhenKeyUp() ) {

                            _pacman->updatePositionInTheGrid();
                            _pacman->calculateDirection(_areaGame->getLevelTable());
                            _pacman->calculateOffset(false);
                            _pacman->resetValues();
                        }
                        break;
                    }
                }
                break;

            }
        }

        SDL_RenderClear(_renderer);

        createAreaGame(_levelString);
        _pacman->show(_renderer);

        // Copy new ghosts positions in the renderer
        for( int i(0); i < _ghosts.size(); i++ ) {
            _ghosts[i]->show(_renderer);
            // Detect if there is a collision
            if( _ghosts[i]->checkCollision(_pacman) ) {
                // If collision detected, pacman is dead
                if( !_pacman->isDead() ) {
                    _pacman->setDead();
                }

            }
        }

        // Render changes on the screen
        SDL_RenderPresent(_renderer);
    }
}

void Window::quit() {

    cout << SDL_GetError() << endl;

}

void Window::startGame() {}
void Window::startNewLife() {}
void Window::pauseGame() {}
void Window::gameOver() {}
void Window::quitGame() {}
