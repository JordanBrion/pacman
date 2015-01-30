#include "FruitManager.h"

#include <iostream>
using namespace std;

#include "InteractiveElements/Fruit.h"

FruitManager::FruitManager() :
    _currentFruitLocationGrid( -1 ),
    _currentFruitType( -1 ),
    _betweenFruitChrono( 0 ),
    _currentFruitChrono( 0 ),
    _totalFruitScore( 0 ) {

}

FruitManager::~FruitManager() {}

void FruitManager::initFruit( SDL_Texture* const& sprite,
                              const std::vector<SDL_Rect>& selections ) {

    for(int i(0); i < FRUIT_NBR; i++) {

        _fruits.push_back( new Fruit( i,
                                      sprite,
                                      selections[i] )
                           );

    }

}

vector<Fruit*> FruitManager::getFruit() const {

    return _fruits;

}

Fruit* FruitManager::getOneFruit( int const& type ) const {

    return _fruits[ type ];

}

int FruitManager::getFruitNbr( int const& type ) const {

    _fruits[ type ]->getNbr();

}

void FruitManager::incFruitNbr( int const& type ) {

    _fruits[ type ]->setNbr( _fruits[ type ]->getNbr() +1 );

}

void FruitManager::decFruitNbr( int const& type ) {

    _fruits[ type ]->setNbr( _fruits[ type ]->getNbr() -1 );

}

int FruitManager::getFruitPoints( int const& type ) const {

    _fruits[ type ]->getPoints();

}

void FruitManager::initFruitLocationCoord( const vector<vector<int> >& fruitLocationsGrid ) {

    _fruitLocationsGrid = fruitLocationsGrid;

}

void FruitManager::startCurrentFruit() {

    if( randomFruit() )
        _currentFruitChrono = SDL_GetTicks();
    else
        cout << "Impossible to randomize the next fruit location. Fruit is already in the grid !" << endl;


}

bool FruitManager::randomFruit() {

    if( _currentFruitLocationGrid == -1 ) {

        // Random a fruit location
        _currentFruitLocationGrid = rand() % _fruitLocationsGrid.size();

        // Random a fruit type
        _currentFruitType = rand() % _fruits.size();

        return true;

    }

    else {

        return false;

    }

}

void FruitManager::resetCurrentFruit() {

    _currentFruitLocationGrid = -1;
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
    if( _currentFruitLocationGrid != -1 ) {

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

    if( _fruitLocationsGrid[ _currentFruitLocationGrid ][0] == row
            && _fruitLocationsGrid[ _currentFruitLocationGrid ][1] == col )
        return true;

    return false;

}

Uint16 FruitManager::getTotalFruitScore() {

    return _totalFruitScore;

}

void FruitManager::renderFruit( SDL_Renderer* renderer ) {

    /*
    _fruits[ _currentFruitType ]->initPositionAreaGame(
                _fruitLocationCoord[ _currentFruitLocation ][1] * 30 + AREAGAME_MARGIN,
                _fruitLocationCoord[ _currentFruitLocation ][0] * 30 + AREATOP_HEIGHT
                );
*/

    _fruits[ _currentFruitType ]->initPositionAreaGame(
                _fruitPositions[ _currentFruitType ] );

    _fruits[ _currentFruitType ]->show( renderer );

}
