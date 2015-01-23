#include "EventHandler_Menu.h"

EventHandler_Menu::EventHandler_Menu() : _selectedID( 0 ) {}

EventHandler_Menu::~EventHandler_Menu() {}

int8_t EventHandler_Menu::handle( const SDL_Event& evt ) {

    if( evt.type == SDL_KEYDOWN ) {

        switch( evt.key.keysym.sym ) {

        case SDLK_UP:
        case SDLK_LEFT:
            _selectedID--;
            break;

        case SDLK_DOWN:
        case SDLK_RIGHT:
            _selectedID++;
            break;

        case SDLK_RETURN:
        case SDLK_SPACE:
            return 1;

        default:
            break;

        }

    }

    return NO_MANAGEMENT;

}
