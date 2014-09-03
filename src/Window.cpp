#include "Window.h"

#include <pm/Color.h>

using namespace std;

char _levelString[] =
        "2;1;1;1;1;1;1;1;1;1;1;7;1;1;1;1;1;1;1;1;1;1;5;"
        "0;-5;-3;-3;-3;-10;-3;-3;-3;-3;-6;10;-5;-3;-3;-3;-3;-3;-10;-3;-3;-6;0;"
        "0;-4;26;25;29;-4;26;25;25;29;-4;10;-4;26;25;25;29;-4;26;25;29;-4;0;"
        "0;-4;27;25;28;-4;27;25;25;28;-4;14;-4;27;25;25;28;-4;27;25;28;-4;0;"
        "0;-11;-3;-3;-3;-13;-3;-10;-3;-3;-9;-3;-9;-3;-10;-3;-3;-13;-3;-3;-3;-12;0;"
        "0;-4;12;11;13;-4;15;-4;12;11;11;22;11;11;13;-4;15;-4;12;11;13;-4;0;"
        "0;-7;-3;-3;-3;-12;10;-7;-3;-3;-6;10;-5;-3;-3;-8;10;-11;-3;-3;-3;-8;0;"
        "3; 1; 1; 1; 5;-4;21;11;11;13;0;14;0;12;11;11;20;-4; 2; 1; 1; 1;4;"
        "-2;-2;-2;-2;0;-4;10;-2;-2;-2;-2;-2;-2;-2;-2;-2;10;-4; 0;-2;-2;-2;-2;"
        " 1; 1; 1; 1;4;-4;14;-2;36; 1;35;33;34; 1;39;-2;14;-4; 3; 1; 1; 1; 1;"
        "-2;-2;-2;-2;0;-4;0;-2; 0;-2;-2;-2;-2;-2; 0;-2;0;-4;0;-2;-2;-2;-2;"
        " 1; 1; 1; 1;5;-4;15;-2;37; 1; 1; 1; 1; 1;38;-2;15;-4; 2; 1; 1; 1; 1;"
        "-2;-2;-2;-2;0;-4;10;-2;#;#;#;#;-2;-2;-2;-2;10;-4; 0;-2;-2;-2;-2;"
        "2 ; 1; 1; 1;4;-4;14;0;12;11;11;22;11;11;13;0;14;-4; 3; 1; 1; 1; 5;"
        "0 ;-5;-3;-3;-3;-13;-3;-3;-3;-3;-6;10;-5;-3;-3;-9;-3;-13;-3;-3;-3;-6;0;"
        "0 ;-4;12;11;19;-4;12;11;11;13;-4;14;-4;12;11;11;13;-4;16;11;13;-4;0;"
        "0 ;-7;-3;-6;10;-5;-3;-10;-3;-3;-8;@;-7;-3;-3;-3;-3;-12;10;-5;-3;-8;0;"
        "9 ;11;13;-4;14;-4;15;-4;12;11;11;22;11;11;13;-4;15;-4;14;-4;12;11;6;"
        "0 ;-5;-3;-9;-3;-8;10;-7;-3;-3;-6;10;-11;-3;-3;-8;10;-7;-3;-3;-3;-6;0;"
        "0 ;-4;12;11;11;11;23;11;11;13;-4;14;-4;12;11;11;23;11;11;11;13;-4;0;"
        "0 ;-7;-3;-3;-3;-3;-3;-3;-3;-3;-9;-3;-7;-3;-3;-3;-3;-3;-3;-3;-3;-8;0;"
        "3;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;1;4;";

Window::Window() throw(exception) :
    _quit(false),
    _screenWidth(900),
    _screenHeight(850) {
    
    try {
        
        // Initialize all the needed SDL libraries
        initSDL();
        
        // Initialize the ressources files
        _fm = new FilesManager();
        initRessources();
        
        // Load the level
        _fm->initLevelTable( _levelString );
        _fm->initLevelSpriteCoord();
        
        // Initialize attributes
        _game = new Game( _fm->getLifesNbr(), _fm->getPacDotsNbr(), _fm->getHighScore() );
        _areaTop = new AreaTop();
        _areaGame = new AreaGame( _renderer, _fm->getSpriteLevel() );
        _areaBottom = new AreaBottom();
        
        for(int i(0); i < FRUIT_NBR; i++) {
            
            _fruit.push_back( new Fruit( i, _renderer, _fm->getSpriteCharacters()  ) );
            
        }
        
        // Initialize the position of the bubbles
        _pdm = new PacDotsManager( _fm->getLevelTable(), _renderer, _fm->getSpriteCharacters() );
        
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
    _threadGhosts = SDL_CreateThread( Window::createThread, "Thread for Ghosts moves", (void*) this );
    
}

void Window::drawSplashScreen() {

    SDL_Rect position;
    Uint8 opacity = 0xFF;

    SDL_Surface* logo = IMG_Load( "../media/img/logo.bmp" );
    SDL_SetColorKey( logo, SDL_TRUE, SDL_MapRGB( logo->format, 255, 255, 255) );
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

void Window::drawHudTop() {
    
    _areaTop->drawArea( _renderer, _fm->getFont(), _game->getHighScore(), _game->getScoreP1(), _game->getScoreP2()  );
    
}

void Window::drawAreaGame() {
    
    _areaGame->drawArea( _renderer, _fm->getRowsNbr(), _fm->getColsNbr(), _fm->getLevelTable(), _fm->getLevelSpriteCoord() );
    
}

int Window::drawPacDots() {
    
    return _pdm->render( _renderer );
    
}

void Window::drawHudBottom() {
    
    _areaBottom->drawLifesPanel(_renderer, _fm->getSpriteCharacters(), _fm->getFont(), _game->getLifesNbr() );
    _areaBottom->drawFruitPanel(_renderer, _fm->getSpriteCharacters(), _fm->getFont(), _fruit );
    
}

int Window::createThread(void* data) {
    
    Window w = *( Window *) data;
    
    w.threadGhostsLoop();
    
    return 0;
    
}

void Window::threadGhostsLoop() {
    
    // The ghosts move while Pacman is not dead
    while( !_pacMan->isDead() ) {
        
        for( int i(0); i < _fm->getGhostsNbr(); i++ ) {
            if( _ghosts[i]->isCenteredInTheSquare() ) {
                
                _ghosts[i]->updatePositionInTheGrid();
                _ghosts[i]->calculateDirection(_fm->getLevelTable());
                _ghosts[i]->resetValues();
            }
            _ghosts[i]->move();
            
            // After the move, detect if there is a collision
            if( _ghosts[i]->checkCollision(_pacMan) ) {
                
                // If collision detected, pacman is dead
                if( !_pacMan->isDead() ) {
                    _pacMan->setDead();
                }
                
            }
            
        }
        SDL_Delay(20);
        
    }
    
}

void Window::loop() {

    SDL_Event e;
    
    int score(0);
    
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
            _pacMan->handleEvent(e);
            
        }

        _pacMan->move( _fm->getLevelTable() );
        SDL_RenderClear(_renderer);

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
        
            _pacMan->checkCollisionWithPacDots( _pdm );
            score = drawPacDots();
            _game->setScoreP1( score );
            
            _pacMan->show(_renderer);
            
            // Copy new ghosts positions in the renderer
            for( int i(0); i < _ghosts.size(); i++ ) {
            
                _ghosts[i]->show(_renderer);
                
            }
            
        }
        
        drawHudTop();
        drawAreaGame();
        drawHudBottom();

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
    
    // Restore Pacman attributes to default
    _pacMan->defaultValues();
    _pacMan->calculateDirection(_fm->getLevelTable());
    _pacMan->show(_renderer);
    
    // Restore ghosts attributes to default
    for(int i(0); i < _ghosts.size(); i++) {
        _ghosts[i]->defaultValues();
        _ghosts[i]->calculateDirection(_fm->getLevelTable());
        _ghosts[i]->show(_renderer);
    }
    
    // Restart of the Ghosts thread
    _threadGhosts = SDL_CreateThread( Window::createThread, "Thread for Ghosts moves", (void*) this );
    
}

void Window::pauseGame() {}
void Window::loadMenuPause() {}
void Window::unpauseGame() {}
void Window::gameOver() {}
void Window::quitGame() {}
