#include "EventHandler_MenuGameOver.h"

EventHandler_MenuGameOver::EventHandler_MenuGameOver() {}

EventHandler_MenuGameOver::~EventHandler_MenuGameOver() {}

int8_t EventHandler_MenuGameOver::handle( const SDL_Event& evt ) {

    int8_t action = EventHandler_Menu::handle( evt );

    if( action ) {

        switch( _selectedID % 2 ) {

        case 0:
            return MANAGEMENT_RESETTER;
        case 1:
            return MANAGEMENT_QUITGAME;

        }

    }

    return NO_MANAGEMENT;

}

int8_t EventHandler_MenuGameOver::nextHandlerType( const int& managementType ) {

    switch ( managementType ) {
    case MANAGEMENT_RESETTER:
        return EVENTHANDLER_MENUSTART;
    case MANAGEMENT_QUITGAME:
        return EVENTHANDLER_INGAME;
    default:
        return NO_EVENTHANDLER;
    }

}
