#include "MenuStart.h"
#include <pm/Color.h>

using namespace std;

MenuStart::MenuStart( string title, vector<string> elements ) :
    Menu( title, elements ) {

}

MenuStart::~MenuStart() {


}

void MenuStart::handleEvent( SDL_Event& e ) {



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

    for( vector<string>::const_iterator it = _elements.begin(); it != _elements.end(); ++it  ) {

        SDL_Surface* section = TTF_RenderText_Solid( font, (*it).c_str(), Color::SDL_WHITE );
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
