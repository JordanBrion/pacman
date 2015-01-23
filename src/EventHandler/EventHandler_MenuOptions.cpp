#include "EventHandler_MenuOptions.h"

EventHandler_MenuOptions::EventHandler_MenuOptions() {}

EventHandler_MenuOptions::~EventHandler_MenuOptions() {}

int8_t EventHandler_MenuOptions::handle( const SDL_Event& evt ) {

    int8_t action = EventHandler_Menu::handle( evt );

    if( action ) {

        switch( _selectedID % 3 ) {

        }

    }

    return NO_MANAGEMENT;

}

int8_t EventHandler_MenuOptions::nextHandlerType( const int& managementType ) {

    switch ( managementType ) {
    default:
        return NO_EVENTHANDLER;
    }

}
