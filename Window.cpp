#include "Window.h"

using namespace std;

Window::Window() throw(exception) : _screenWidth(900), _screenHeight(800) {

    try {

        char _levelString[] =
                "2;1;1;1;1;1;1;1;1;1;1;7;1;1;1;1;1;1;1;1;1;1;5;"
                "0;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;10;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;0;"
                "0;-1;26;25;29;-1;26;25;25;29;-1;10;-1;26;25;25;29;-1;26;25;29;-1;0;"
                "0;-1;27;25;28;-1;27;25;25;28;-1;14;-1;27;25;25;28;-1;27;25;28;-1;0;"
                "0;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;0;"
                "0;-1;12;11;13;-1;15;-1;12;11;11;22;11;11;13;-1;15;-1;12;11;13;-1;0;"
                "0;-1;-1;-1;-1;-1;10;-1;-1;-1;-1;10;-1;-1;-1;-1;10;-1;-1;-1;-1;-1;0;"
                "3; 1; 1; 1; 5;-1;21;11;11;13;-1;14;-1;12;11;11;20;-1; 2; 1; 1; 1;4;"
                "-1;-1;-1;-1;0;-1;10;-1;-1;-1;-1;-1;-1;-1;-1;-1;10;-1; 0;-1;-1;-1;-1;"
                " 1; 1; 1; 1;4;-1;14;-1;36; 1;35;33;34; 1;39;-1;14;-1; 3; 1; 1; 1; 1;"
                "-1;-1;-1;-1;-1;-1;-1;-1; 0;#;#;-1;#;#; 0;-1;-1;-1;-1;-1;-1;-1;-1;"
                " 1; 1; 1; 1;5;-1;15;-1;37; 1; 1; 1; 1; 1;38;-1;15;-1; 2; 1; 1; 1; 1;"
                "-1;-1;-1;-1;0;-1;10;-1;-1;-1;-1;-1;-1;-1;-1;-1;10;-1; 0;-1;-1;-1;-1;"
                "2 ; 1; 1; 1;4;-1;14;-1;12;11;11;22;11;11;13;-1;14;-1; 3; 1; 1; 1; 5;"
                "0 ;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;10;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;0;"
                "0 ;-1;12;11;19;-1;12;11;11;13;-1;14;-1;12;11;11;13;-1;16;11;13;-1;0;"
                "0 ;-1;-1;-1;10;-1;-1;-1;-1;-1;-1;@;-1;-1;-1;-1;-1;-1;10;-1;-1;-1;0;"
                "9 ;11;13;-1;14;-1;15;-1;12;11;11;22;11;11;13;-1;15;-1;14;-1;12;11;6;"
                "0 ;-1;-1;-1;-1;-1;10;-1;-1;-1;-1;10;-1;-1;-1;-1;10;-1;-1;-1;-1;-1;0;"
                "0 ;-1;12;11;11;11;23;11;11;13;-1;14;-1;12;11;11;23;11;11;11;13;-1;0;"
                "0 ;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;-1;0;"
                "3;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;4;";

        int rows(22);
        int cols(23);
        _areaGame = new AreaGame(rows, cols);

        initSDL();

        SDL_RenderClear(_renderer);

        createAreaGame(_levelString);
        createCharacters();

        SDL_RenderPresent(_renderer);

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
                SDL_SetRenderDrawColor( _renderer, 0, 0, 0, 0 );

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

    map<string, int> dest;

    // Pacman creation
    dest["x"] = ( _areaGame->getCharacterCoordX("Pacman") * 30);
    dest["y"] = ( _areaGame->getCharacterCoordY("Pacman") * 30);
    pacman = new Pacman( dest, _renderer, _areaGame->getSpriteAnim() );

}

void Window::loop() {

    bool quit(false);
    SDL_Event e;

    while( !quit ) {

        SDL_WaitEvent(&e);

        switch( e.type ) {
        case SDL_QUIT:
            quit = true;
            break;
        case SDL_KEYDOWN:
            switch(e.key.keysym.sym) {
            case SDLK_ESCAPE:
                quit = true;
                break;
            }
            break;
        }

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
