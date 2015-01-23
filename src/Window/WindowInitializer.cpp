#include "WindowInitializer.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

WindowInitializer::WindowInitializer() {}

WindowInitializer::~WindowInitializer() {}

bool WindowInitializer::initSDL( SDL_Window* &window,
                                 int const& width,
                                 int const& height,
                                 SDL_Renderer* &renderer,
                                 SDL_Surface* &windowSurface ) throw ( const std::exception& ) {

    try {

        // if error, we throw an exception
        if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
            throw std::exception();

        // SDL initialization is ok
        else {

            // Enable VSync
            if( !SDL_SetHint( SDL_HINT_RENDER_VSYNC, "1" ) )
                throw std::exception();

            // Set texture filtering to linear
            if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
                throw std::exception();

            // Create window
            window = SDL_CreateWindow( "Pac-Man", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_BORDERLESS );

            if(  window == NULL )
                throw std::exception();

            else {

                // Create renderer for window
                renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
                if( renderer == NULL )
                    throw std::exception();

                else {

                    windowSurface = SDL_GetWindowSurface( window);

                    //Initialize renderer color
                    SDL_SetRenderDrawColor( renderer, 13, 13, 11, 0 );

                    // Disable mouse cursor
                    SDL_ShowCursor(SDL_DISABLE);

                    //Initialize PNG loading
                    int imgFlags = IMG_INIT_PNG;
                    if( !( IMG_Init( imgFlags ) & imgFlags ) )
                        throw std::exception();

                    else {

                        // Load SDL_ttf and the font
                        if( TTF_Init() == -1 ) {
                            throw std::exception();
                        }

                    }

                }
            }

        }
    }
    catch( const std::exception& e ) {

        std::cerr << "Window initializer error: " << SDL_GetError() << std::endl;
        return false;

    }

    return true;

}

bool WindowInitializer::initRessources( FilesManager* fm ) throw( const char* ) {

    try {

        // Load the images
        // If error when loading
        if( !fm->loadIMG() ) {
            throw "Images not loaded.";
        }

        // Load SDL_ttf and the font
        if( !fm->loadFont() ) {
            throw "Fonts not loaded.";
        }

    }
    catch( const char* error ) {

        std::cerr << error << std::endl;
        return false;

    }

    return true;

}

void WindowInitializer::initCharacters( FilesManager* fm,
                                        SDL_Renderer* renderer,
                                        PacMan* &pacMan,
                                        std::vector<Ghost*>& ghosts ) {

    SDL_SetColorKey( fm->getSpriteCharacters() ,
                     SDL_TRUE,
                     SDL_MapRGB( fm->getSpriteCharacters()->format, 0, 0, 0) );
    SDL_Texture* text = SDL_CreateTextureFromSurface( renderer,
                                                      fm->getSpriteCharacters() );

    std::map<std::string, int> dest;

    // Pacman creation
    dest["row"] = fm->getCharacterCoordRow("Pacman");
    dest["col"] = fm->getCharacterCoordCol("Pacman");
    SDL_Rect selection = { 45, 3, 16, 20 };
    int x = dest["col"] * 30 + AREAGAME_MARGIN;
    int y = dest["row"] * 30 + AREATOP_HEIGHT;
    SDL_Rect position = { x, y, 30, 30 };
    pacMan = new PacMan( dest,
                         text,
                         selection, position );
    pacMan->calculateDirection( fm->getLevelTable() );

    // Ghosts creation
    std::stringstream ss;
    for(int i(0); i < fm->getGhostsNbr(); i++) {

        int color = i % 4;

        switch(color) {
        case RED:
            selection = { 5, 84, 17, 19 };
            break;
        case PINK:
            selection = { 5, 104, 17, 19 };
            break;
        case BLUE:
            selection = { 5, 124, 17, 19 };
            break;
        case ORANGE:
            selection = { 5, 144, 17, 19 };
            break;
        }

        ss << "Ghost" << i+1;
        dest["row"] = fm->getCharacterCoordRow( ss.str() );
        dest["col"] = fm->getCharacterCoordCol( ss.str() );
        x = dest["col"] * 30 + AREAGAME_MARGIN;
        y = dest["row"] * 30 + AREATOP_HEIGHT;
        position = { x, y, 30, 30 };
        ghosts.push_back( new Ghost( dest,
                                     text,
                                     selection,
                                     position ));
        ghosts[i]->calculateDirection( fm->getLevelTable() );
        ss.str(""); // Clear the string stream

    }

}
