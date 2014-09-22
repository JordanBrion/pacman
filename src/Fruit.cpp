#include "Fruit.h"

using namespace std;

Fruit::Fruit( int const& type, SDL_Renderer* const& renderer, SDL_Surface* const& sprite )
    : InteractiveElement( renderer, sprite ), _type( type ), _nbr(0) {

    // Initialization of sprite coord
    switch( type ) {

    case CHERRY:
        _points = 100;
        initRect( &_selection, 18, 18, 173, 164);
        break;
    case STRAWBERRY:
        _points = 300;
        initRect( &_selection, 18, 18, 173, 184);
        break;
    case APRICOT:
        _points = 500;
        initRect( &_selection, 18, 18, 173, 204);
        break;
    case APPLE:
        _points = 700;
        initRect( &_selection, 18, 18, 173, 224);
        break;
    case MELON:
        _points = 1000;
        initRect( &_selection, 18, 18, 213, 165);
        break;
    case GALXIAN_BOSS:
        _points = 2000;
        initRect( &_selection, 18, 18, 213, 185);
        break;
    case BELL:
        _points = 3000;
        initRect( &_selection, 18, 18, 213, 205);
        break;
    case KEY:
        _points = 5000;
        initRect( &_selection, 18, 18, 213, 225);
        break;

    }

}

Fruit::~Fruit() {
}

int Fruit::getType() const {

    return _type;

}

void Fruit::setType ( int const& type ) {

    _type = type;

}

int Fruit::getNbr() const {

    return _nbr;

}

void Fruit::setNbr( int const& nbr ) {

    _nbr = nbr;

}

int Fruit::getPoints() const {

    return _points;

}


void Fruit::initPositionAreaGame( int const& x, int const& y ) {

    initRect( &_position, 30, 30, x, y);

}

void Fruit::initPositionAreaBottom() {

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

