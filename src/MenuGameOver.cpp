#include "MenuGameOver.h"

#include <pm/Color.h>

using namespace std;

MenuGameOver::MenuGameOver( string title, vector<string> elements ) :
    Menu( title, elements ) {


}

MenuGameOver::~MenuGameOver() {}

Uint8 MenuGameOver::handleEvent( SDL_Event &e ) {

    switch( e.type ) {

    case SDL_KEYDOWN:
        switch( e.key.keysym.sym ) {

        case SDLK_LEFT:
            if( _elementID == MENUGAMEOVER_NBR - 1 )
                _elementID = 1;
            else
                _elementID++;
            break;

        case SDLK_RIGHT:
            if( _elementID == 1 )
                _elementID = MENUGAMEOVER_NBR - 1;
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

void MenuGameOver::render( SDL_Renderer *renderer,
                           const int &width,
                           const int &height,
                           TTF_Font *font,
                           SDL_Surface *logo ) {

    SDL_Rect position;

    SDL_RenderClear( renderer );

    // Render the title
    SDL_Surface* details = TTF_RenderText_Solid( font, _title.c_str(), Color::SDL_WHITE );
    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, details );
    position.w = width * 0.6;
    position.h = height * 0.15;
    position.x = width/2 - position.w/2;
    position.y = (height/2 - position.h/2) * 0.5 ;
    SDL_RenderCopy( renderer, texture, NULL, &position );

    // Render the question
    details = TTF_RenderText_Solid( font, "Do you want to start another game, loser ?", Color::SDL_WHITE );
    texture = SDL_CreateTextureFromSurface( renderer, details );
    position.w = width * 0.6;
    position.h = height * 0.033;
    position.x = width/2 - position.w/2;
    position.y = height/2 - position.h/2;
    SDL_RenderCopy( renderer, texture, NULL, &position );

    // Render the sections of the menu
    position.w = width * 0.11;
    position.h = height * 0.03;
    position.x = 0;
    position.y = height * 0.55;

    for( vector<string>::iterator it = _elements.begin(); it != _elements.end(); ++it  ) {

        SDL_Color color = ( distance( _elements.begin(), it ) ==  _elementID - 1 ) ?
                    Color::SDL_RED : Color::SDL_WHITE;

        SDL_Surface* section = TTF_RenderText_Solid( font, (*it).c_str(), color );
        SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, section );
        position.x += width * 0.30;
        SDL_RenderCopy( renderer, texture, NULL, &position );

    }

    SDL_RenderPresent( renderer );

}
