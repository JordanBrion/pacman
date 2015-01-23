#include "EventHandler_InGame.h"

EventHandler_InGame::EventHandler_InGame() {}

EventHandler_InGame::~EventHandler_InGame() {}

int8_t EventHandler_InGame::handle( const SDL_Event& evt ) {

    if( evt.type == SDL_KEYDOWN ) {

        switch( evt.key.keysym.sym ) {

        case SDLK_p:
            return MANAGEMENT_PAUSE;

        }

    }

    return NO_MANAGEMENT;

}

int8_t EventHandler_InGame::nextHandlerType( const int& managementType ) {

    switch ( managementType ) {
    case MANAGEMENT_PAUSE:
        return EVENTHANDLER_MENUPAUSE;
    case MANAGEMENT_INGAME:
        return EVENTHANDLER_INGAME;
    default:
        return NO_EVENTHANDLER;
    }

}
