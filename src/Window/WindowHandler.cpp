#include <typeinfo>

#include "WindowHandler.h"
#include "../EventHandler/EventHandler_MenuStart.h"
#include "../EventHandler/EventHandler_InGame.h"
#include "../EventHandler/EventHandler_MenuOptions.h"
#include "../EventHandler/EventHandler_MenuPause.h"
#include "../EventHandler/EventHandler_MenuGameOver.h"

WindowHandler::WindowHandler() : _currentManagementType( -1 ) {

    // Initialize all the handlers
    _handlers.push_back( new EventHandler_MenuStart() );
    _handlers.push_back( new EventHandler_InGame() );
    _handlers.push_back( new EventHandler_MenuOptions() );
    _handlers.push_back( new EventHandler_MenuPause() );
    _handlers.push_back( new EventHandler_MenuGameOver() );

    // The default handler at the start is the one for the start menu
    _currentHandler = _handlers[EVENTHANDLER_MENUSTART];

}

WindowHandler::~WindowHandler() {

    for( std::vector<EventHandler*>::iterator it = _handlers.begin();
         it != _handlers.end();
         ++it ) {

        delete (*it);

    }

    _handlers.clear();
    _currentHandler = 0;

}

int8_t WindowHandler::handle( const SDL_Event& evt ) {

    _currentManagementType = _currentHandler->handle( evt );
    return _currentManagementType;

}

void WindowHandler::nextHandler() {

    const int& type = _currentHandler->nextHandlerType( _currentManagementType );

    if( type != NO_EVENTHANDLER ) {
        _currentHandler = _handlers[ type ];
        _currentManagementType = -1;
    }

}

