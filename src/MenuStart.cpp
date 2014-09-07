#include "MenuStart.h"
#include <pm/Color.h>

#include <iostream>
using namespace std;

MenuStart::MenuStart( string title, vector<string> elements ) :
    Menu( title, elements ) {

}

MenuStart::~MenuStart() {


}

Uint8 MenuStart::handleEvent( SDL_Event& e ) {

    switch( e.type ) {

    case SDL_KEYDOWN:
        switch( e.key.keysym.sym ) {

        case SDLK_DOWN:
            if( _elementID == MENUSTART_NBR - 1 )
                _elementID = 1;
            else
                _elementID++;
            break;

        case SDLK_UP:
            if( _elementID == 1 )
                _elementID = MENUSTART_NBR - 1;
            else
                _elementID--;
            break;

        case SDLK_RETURN:
        case SDLK_SPACE:
            return _elementID;

        default:
            break;

        }

        break;

    default:
        break;

    }

    return 0;

}

void MenuStart::render( SDL_Renderer* renderer, int const& width, int const& height, TTF_Font* font, SDL_Surface* logo ) {

    SDL_Rect position;

    SDL_RenderClear( renderer );

    // Render the logo
    SDL_Texture* textureLogo = SDL_CreateTextureFromSurface( renderer, logo );
    double ratio = logo->w / logo->h;
    position.w = width * 0.5;
    position.h = position.w / ratio;
    position.x = width / 2 - position.w / 2;
    position.y = height * 0.3;
    SDL_RenderCopy( renderer, textureLogo, NULL, &position );

    // Render the sections of the menu
    position.w = width * 0.2;
    position.h = height * 0.03;
    position.x = width / 2 - position.w / 2;
    position.y += height * 0.20;

    for( vector<string>::iterator it = _elements.begin(); it != _elements.end(); ++it  ) {

        SDL_Color color = ( distance( _elements.begin(), it ) ==  _elementID - 1 ) ?
                    Color::SDL_BLUE : Color::SDL_WHITE;

        SDL_Surface* section = TTF_RenderText_Solid( font, (*it).c_str(), color );
        SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, section );
        position.y += height * 0.03;
        SDL_RenderCopy( renderer, texture, NULL, &position );

    }

    // Render copyrights
    SDL_Surface* details = TTF_RenderText_Solid( font, "PAC-MAN is a trademark or a registered trademark of NAMCO BANDAI Games Inc. All rights reserved.", Color::SDL_WHITE );
    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, details );
    position.w = width * 0.9;
    position.h = height * 0.03;
    position.x = width - position.w - width * 0.01;
    position.y = height - 2 * position.h - height * 0.01;
    SDL_RenderCopy( renderer, texture, NULL, &position );

    // Render more personal informations
    details = TTF_RenderText_Solid( font, "More information about my work on JordanBrion.com", Color::SDL_WHITE );
    texture = SDL_CreateTextureFromSurface( renderer, details );
    position.w = width * 0.6;
    position.h = height * 0.03;
    position.x = width - position.w - width * 0.01;
    position.y = height - position.h - height * 0.01;
    SDL_RenderCopy( renderer, texture, NULL, &position );

    SDL_RenderPresent( renderer );

}
