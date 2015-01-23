#include "EventHandler_MenuPause.h"

EventHandler_MenuPause::EventHandler_MenuPause() {}

EventHandler_MenuPause::~EventHandler_MenuPause() {}

int8_t EventHandler_MenuPause::handle( const SDL_Event& evt ) {

    int8_t action = EventHandler_Menu::handle( evt );

    if( action ) {

        switch( _selectedID % 4 ) {

        case 0:
            return MANAGEMENT_INGAME;
        case 1:
            return MANAGEMENT_RESETTER;
        case 3:
            return MANAGEMENT_QUITGAME;

        }

    }

    return NO_MANAGEMENT;

}

int8_t EventHandler_MenuPause::nextHandlerType( const int& managementType ) {

    switch ( managementType ) {
    case MANAGEMENT_INGAME:
    case MANAGEMENT_RESETTER:
        return EVENTHANDLER_INGAME;
    case MANAGEMENT_QUITGAME:
        return EVENTHANDLER_MENUSTART;
    default:
        return NO_EVENTHANDLER;
    }

}
