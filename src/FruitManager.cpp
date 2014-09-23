#include "FruitManager.h"

#include <iostream>
using namespace std;

FruitManager::FruitManager() :
    _currentFruitLocation( -1 ),
    _currentFruitType( -1 ),
    _betweenFruitChrono( 0 ),
    _currentFruitChrono( 0 ),
    _totalFruitScore( 0 ) {

}

FruitManager::~FruitManager() {}

void FruitManager::initFruit( SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    for(int i(0); i < FRUIT_NBR; i++) {

        _fruits.push_back( new Fruit( i, renderer, sprite ) );

    }

}

vector<Fruit*> FruitManager::getFruit() const {

    return _fruits;

}

Fruit* FruitManager::getOneFruit( int type ) const {

    return _fruits[ type ];

}

int FruitManager::getFruitNbr( int type ) const {

    _fruits[ type ]->getNbr();

}

void FruitManager::incFruitNbr( int type ) {

    _fruits[ type ]->setNbr( _fruits[ type ]->getNbr() +1 );

}

void FruitManager::decFruitNbr( int type ) {

    _fruits[ type ]->setNbr( _fruits[ type ]->getNbr() -1 );

}

int FruitManager::getFruitPoints( int type ) const {

    _fruits[ type ]->getPoints();

}

void FruitManager::initFruitLocationCoord( vector<vector<int> > fruitLocationCoord ) {

    _fruitLocationCoord = fruitLocationCoord;

}

void FruitManager::startCurrentFruit() {

    if( randomFruit() )
        _currentFruitChrono = SDL_GetTicks();
    else
        cout << "Impossible to randomize the next fruit location. Fruit is already in the grid !" << endl;


}

bool FruitManager::randomFruit() {

    if( _currentFruitLocation == -1 ) {

        // Random a fruit location
        _currentFruitLocation = rand() % _fruitLocationCoord.size();

        // Random a fruit type
        _currentFruitType = rand() % _fruits.size();

        return true;

    }

    else {

        return false;

    }

}

void FruitManager::resetCurrentFruit() {

    _currentFruitLocation = -1;
    _currentFruitType = -1;
    _currentFruitChrono = 0;

}

void FruitManager::startBetweenFruitChrono() {

    _betweenFruitChrono = SDL_GetTicks();

}

void FruitManager::resetBetweenFruitChrono() {

    _betweenFruitChrono = 0;

}

bool FruitManager::checkFruitChronos() {

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
        else
            return true;

    }
    else
        startBetweenFruitChrono();

    return false;

}

bool FruitManager::eatFruit( int const& row, int const& col ) {

    // If a fruit rendered
    if( _currentFruitLocation != -1 ) {

        // If a collision is detected
        if( isThereAFruit( row, col )  ) {

            _totalFruitScore += _fruits[ _currentFruitType ]->getPoints();
            incFruitNbr( _currentFruitType );
            return true;

        }
    }

    return false;

}

bool FruitManager::isThereAFruit( int const& row, int const& col ) {

    if( _fruitLocationCoord[ _currentFruitLocation ][0] == row
            && _fruitLocationCoord[ _currentFruitLocation ][1] == col )
        return true;

    return false;

}

Uint16 FruitManager::getTotalFruitScore() {

    return _totalFruitScore;

}

void FruitManager::renderFruit( SDL_Renderer *renderer ) {

    _fruits[ _currentFruitType ]->initPositionAreaGame(
                _fruitLocationCoord[ _currentFruitLocation ][1] * 30 + AREAGAME_MARGIN,
                _fruitLocationCoord[ _currentFruitLocation ][0] * 30 + AREATOP_HEIGHT
                );

    _fruits[ _currentFruitType ]->show( renderer );

}
