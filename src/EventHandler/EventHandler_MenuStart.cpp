#include "EventHandler_MenuStart.h"

EventHandler_MenuStart::EventHandler_MenuStart() {}

EventHandler_MenuStart::~EventHandler_MenuStart() {}

int8_t EventHandler_MenuStart::handle( const SDL_Event& evt ) {

    int8_t action = EventHandler_Menu::handle( evt );

    if( action ) {

        switch( _selectedID % 3 ) {

        case 0:
            return MANAGEMENT_START;
        case 2:
            return MANAGEMENT_QUITAPP;

        }

    }

    return NO_MANAGEMENT;

}

int8_t EventHandler_MenuStart::nextHandlerType( const int& managementType ) {

    switch ( managementType ) {
    case MANAGEMENT_START:
        return EVENTHANDLER_INGAME;
    default:
        return NO_MANAGEMENT;
    }

}
