#include "Collectible.h"

using namespace std;

Collectible::Collectible( int const& type, map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite )
    : InteractiveElement( dest, renderer, sprite ), _type( type ) {

    // Initialization of sprite coord
    switch( type ) {

    case CHERRY:
        initRect( _selection, 0, 0, 0, 0);
        break;
    case STRAWBERRY:
        initRect( _selection, 0, 0, 0, 0);
        break;
    case APRICOT:
        initRect( _selection, 0, 0, 0, 0);
        break;
    case APPLE:
        initRect( _selection, 0, 0, 0, 0);
        break;
    case MELON:
        initRect( _selection, 0, 0, 0, 0);
        break;
    case GALXIAN_BOSS:
        initRect( _selection, 0, 0, 0, 0);
        break;
    case BELL:
        initRect( _selection, 0, 0, 0, 0);
        break;
    case KEY:
        initRect( _selection, 0, 0, 0, 0);
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

    initRect(_position, 0, 0, 0, 0);

}

void Collectible::initPositionAreaBottom() {

    switch( _type ) {

    case CHERRY:
        initRect(_position, 0, 0, 0, 0);
        break;
    case STRAWBERRY:
        initRect(_position, 0, 0, 0, 0);
        break;
    case APRICOT:
        initRect(_position, 0, 0, 0, 0);
        break;
    case APPLE:
        initRect(_position, 0, 0, 0, 0);
        break;
    case MELON:
        initRect(_position, 0, 0, 0, 0);
        break;
    case GALXIAN_BOSS:
        initRect(_position, 0, 0, 0, 0);
        break;
    case BELL:
        initRect(_position, 0, 0, 0, 0);
        break;
    case KEY:
        initRect(_position, 0, 0, 0, 0);
        break;

    }

}

void Collectible::initRect(SDL_Rect rect, int const& w, int const& h, int const& x, int const&  y) {

    rect.w = w;
    rect.h = h;
    rect.x = x;
    rect.y = y;

}

