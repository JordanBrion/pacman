#include "Fruit.h"
#include "../Surfaces/Surface.h"

using namespace std;

Fruit::Fruit( const int& type,
              SDL_Texture* const& sprite,
              const SDL_Rect& selection ) :
    _type( type ),
    _nbr(0) {

    _surface = new SurfaceSelection( sprite, selection, { 0, 0, 0, 0 } );

    // Initialization of sprite coord
    switch( type ) {

    case CHERRY:
        _points = 100;
        break;
    case STRAWBERRY:
        _points = 300;
        break;
    case APRICOT:
        _points = 500;
        break;
    case APPLE:
        _points = 700;
        break;
    case MELON:
        _points = 1000;
        break;
    case GALXIAN_BOSS:
        _points = 2000;
        break;
    case BELL:
        _points = 3000;
        break;
    case KEY:
        _points = 5000;
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


void Fruit::initPositionAreaGame( const SDL_Rect& position ) {

    /*
     *
     * // MAZE
    Surface::initRect( &_position, 30, 30, x, y);


// AREA BOTTOM
    int space = 270 + (65 * _type);

    switch( _type ) {

    case CHERRY:
        Surface::initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case STRAWBERRY:
        Surface::initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case APRICOT:
        Surface::initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case APPLE:
        Surface::initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case MELON:
        Surface::initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case GALXIAN_BOSS:
        Surface::initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case BELL:
        Surface::initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;
    case KEY:
        Surface::initRect( &_position,  30, 30, space, AREAGAME_HEIGHT);
        break;

    }

    */

}

void Fruit::initPositionAreaBottom() {



}

