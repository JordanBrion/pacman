#include "FruitManager.h"

#include <iostream>
using namespace std;

FruitManager::FruitManager() :
    _currentFruitLocation( -1 ),
    _betweenFruitChrono( 0 ),
    _currentFruitChrono( 0 ) {

}

FruitManager::~FruitManager() {}

void FruitManager::initFruit( SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    for(int i(0); i < FRUIT_NBR; i++) {

        _fruit.push_back( new Fruit( i, renderer, sprite ) );

    }

}

vector<Fruit*> FruitManager::getFruit() const {

    return _fruit;

}

Fruit* FruitManager::getOneFruit( int type ) const {

    return _fruit[ type ];

}

int FruitManager::getFruitNbr( int type ) const {

    _fruit[ type ]->getNbr();

}

void FruitManager::incFruitNbr( int type ) {

    _fruit[ type ]->setNbr( _fruit[ type ]->getNbr() +1 );

}

void FruitManager::decFruitNbr( int type ) {

    _fruit[ type ]->setNbr( _fruit[ type ]->getNbr() -1 );

}

int FruitManager::getFruitPoints( int type ) const {

    _fruit[ type ]->getPoints();

}

void FruitManager::initFruitLocationCoord( int* fruitLocationCoord, int const& size ) {

    int *row = new int();
    int *col = new int();

    for( int i(0); i < size; i++ ) {

        row = fruitLocationCoord + (i*2);
        col = fruitLocationCoord + (i*2) + 1;

        _fruitLocationCoord.push_back( {
                                           *row,
                                           *col
                                       } );

    }

}

void FruitManager::startCurrentFruit() {

    if( randomFruitLocation() )
        _currentFruitChrono = SDL_GetTicks();
    else
        cout << "Impossible to randomize the next fruit location. Fruit is already in the grid !" << endl;


}

bool FruitManager::randomFruitLocation() {

    if( _currentFruitLocation == -1 ) {

        _currentFruitLocation = rand() % _fruitLocationCoord.size();
        return true;

    }

    else {

        return false;

    }

}

void FruitManager::resetCurrentFruit() {

    _currentFruitLocation = -1;
    _currentFruitChrono = 0;

}

void FruitManager::startBetweenFruitChrono() {

    _betweenFruitChrono = SDL_GetTicks();

}

void FruitManager::resetBetweenFruitChrono() {

    _betweenFruitChrono = 0;

}

void FruitManager::checkFruitChronos() {

    if( _betweenFruitChrono > 0 ) {

        if( SDL_GetTicks() - _betweenFruitChrono >= FRUIT_BETWEEN_DURATION ) {

            resetBetweenFruitChrono();
            startCurrentFruit();

        }

    }
    else if( _currentFruitChrono > 0 ) {

        if( SDL_GetTicks() - _currentFruitChrono >= FRUIT_SHOWN_DURATION ) {

            resetCurrentFruit();
            startBetweenFruitChrono();

        }

    }
    else
        startBetweenFruitChrono();

}
