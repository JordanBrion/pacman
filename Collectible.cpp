#include "Collectible.h"

using namespace std;

Collectible::Collectible( int const& type, SDL_Renderer* const& renderer, SDL_Surface* const& sprite )
    : InteractiveElement( renderer, sprite ), _type( type ), _nbr(0) {

    // Initialization of sprite coord
    switch( type ) {

    case CHERRY:
        initRect( &_selection, 18, 18, 173, 164);
        break;
    case STRAWBERRY:
        initRect( &_selection, 18, 18, 173, 184);
        break;
    case APRICOT:
        initRect( &_selection, 18, 18, 173, 204);
        break;
    case APPLE:
        initRect( &_selection, 18, 18, 173, 224);
        break;
    case MELON:
        initRect( &_selection, 18, 18, 213, 165);
        break;
    case GALXIAN_BOSS:
        initRect( &_selection, 18, 18, 213, 185);
        break;
    case BELL:
        initRect( &_selection, 18, 18, 213, 205);
        break;
    case KEY:
        initRect( &_selection, 18, 18, 213, 225);
        break;

    }

}

Collectible::~Collectible() {
}

int Collectible::getType() const {

    return _type;

}

void Collectible::setType ( int const& type ) {

    _type = type;

}

int Collectible::getNbr() const {

    return _nbr;

}

void Collectible::setNbr( int const& nbr ) {

    _nbr = nbr;

}

void Collectible::initPositionAreaGame() {

    initRect( &_position, 0, 0, 0, 0);

}

void Collectible::initPositionAreaBottom() {

    int space = 270 + (65 * _type);

    switch( _type ) {

    case CHERRY:
        initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case STRAWBERRY:
        initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case APRICOT:
        initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case APPLE:
        initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case MELON:
        initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case GALXIAN_BOSS:
        initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case BELL:
        initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case KEY:
        initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;

    }

}

