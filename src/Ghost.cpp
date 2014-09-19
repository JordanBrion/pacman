#include "Ghost.h"

#include <pm/Directions.h>
using namespace Directions;

using namespace std;

Ghost::Ghost(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : Character(dest, renderer, sprite),
      _forbiddenDirection( -1 ),
      _powerPelletAlmostOver( false ) {

    _eatable = false;

    _stepCounter = 30;

    // Modulo to determinate the color of the ghost
    // 4 different colors
    // _zIndex % 4 => result = from 0 to 3
    int color = _zIndex % 4;

    switch(color) {
    case RED:
        _initialStateSrc["x"] = 5;
        _initialStateSrc["y"] = 84;
        initRect( &_selection, 17, 19, 5, 84 );
        break;
    case PINK:
        _initialStateSrc["x"] = 5;
        _initialStateSrc["y"] = 104;
        initRect( &_selection, 17, 19, 5, 104 );
        break;
    case BLUE:
        _initialStateSrc["x"] = 5;
        _initialStateSrc["y"] = 124;
        initRect( &_selection, 17, 19, 5, 124 );
        break;
    case ORANGE:
        _initialStateSrc["x"] = 5;
        _initialStateSrc["y"] = 144;
        initRect( &_selection, 17, 19, 5, 4 );
        break;

    }

    // Initialize the sprite coord for the animations
    loadSpriteCoord();

    // Initialize the sprite coord for the eatable animations
    loadSpriteCoordEatable();

}

void Ghost::loadSpriteCoord() {

    int color = _zIndex % 4;

    vector<vector<int> > temp(2);
    vector<int> coord(2);

    switch(color) {

    // Red ghost coord
    case RED:
        // UP
        coord[0] = 5;
        coord[1] = 84;
        temp[0] = coord;
        coord[0] = 25;
        coord[1] = 84;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // DOWN
        coord[0] = 45;
        coord[1] = 84;
        temp[0] = coord;
        coord[0] = 65;
        coord[1] = 84;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // RIGHT
        coord[0] = 125;
        coord[1] = 84;
        temp[0] = coord;
        coord[0] = 145;
        coord[1] = 84;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // LEFT
        coord[0] = 85;
        coord[1] = 84;
        temp[0] = coord;
        coord[0] = 105;
        coord[1] = 84;
        temp[1] = coord;
        _spriteCoord.push_back(temp);
        break;

        // Pink ghost coord
    case PINK:
        // UP
        coord[0] = 5;
        coord[1] = 104;
        temp[0] = coord;
        coord[0] = 25;
        coord[1] = 104;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // DOWN
        coord[0] = 45;
        coord[1] = 104;
        temp[0] = coord;
        coord[0] = 65;
        coord[1] = 104;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // RIGHT
        coord[0] = 125;
        coord[1] = 104;
        temp[0] = coord;
        coord[0] = 145;
        coord[1] = 104;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // LEFT
        coord[0] = 85;
        coord[1] = 104;
        temp[0] = coord;
        coord[0] = 105;
        coord[1] = 104;
        temp[1] = coord;
        _spriteCoord.push_back(temp);
        break;

        // Blue ghost coord
    case BLUE:
        // UP
        coord[0] = 5;
        coord[1] = 124;
        temp[0] = coord;
        coord[0] = 25;
        coord[1] = 124;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // DOWN
        coord[0] = 45;
        coord[1] = 124;
        temp[0] = coord;
        coord[0] = 65;
        coord[1] = 124;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // RIGHT
        coord[0] = 125;
        coord[1] = 124;
        temp[0] = coord;
        coord[0] = 145;
        coord[1] = 124;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // LEFT
        coord[0] = 85;
        coord[1] = 124;
        temp[0] = coord;
        coord[0] = 105;
        coord[1] = 124;
        temp[1] = coord;
        _spriteCoord.push_back(temp);
        break;

        // Orange ghost coord
    case ORANGE:
        // UP
        coord[0] = 5;
        coord[1] = 144;
        temp[0] = coord;
        coord[0] = 25;
        coord[1] = 144;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // DOWN
        coord[0] = 45;
        coord[1] = 144;
        temp[0] = coord;
        coord[0] = 65;
        coord[1] = 144;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // RIGHT
        coord[0] = 125;
        coord[1] = 144;
        temp[0] = coord;
        coord[0] = 145;
        coord[1] = 144;
        temp[1] = coord;
        _spriteCoord.push_back(temp);

        // LEFT
        coord[0] = 85;
        coord[1] = 144;
        temp[0] = coord;
        coord[0] = 105;
        coord[1] = 144;
        temp[1] = coord;
        _spriteCoord.push_back(temp);
        break;

    }

}

void Ghost::loadSpriteCoordEatable() {

    int x = 5;
    int y = 164;

    vector<int> temp = { 5, 164 };
    _spriteCoordEatable.push_back( temp );

    for( Uint8 i = 0; i < 3; i++ ) {

        temp[0] += 20;
        _spriteCoordEatable.push_back( temp );

    }

}

void Ghost::updateAll( vector<vector<int> > levelTable ) {

    if( isCenteredInTheSquare() ) {

        updatePositionInTheGrid();
        calculateDirection(levelTable);

        resetValues();

        _goTo = newRandomDirection();

        // Forbid the previous direction
        // For examples: if the ghost moved to UP, forbid DOWN for the next move
        //               if the ghost moved to RIGHT, forbid LEFT for the next move
        if( _goTo == UP || _goTo == RIGHT ) {
            _forbiddenDirection = _goTo + 1;
        }
        else if( _goTo == DOWN || _goTo == LEFT ) {
            _forbiddenDirection = _goTo - 1;
        }

        _step = _goTo;
        defineVelocity();

    }

    _step = -1;

}

void Ghost::nextSprite() {

    // If the ghost can be eaten by the pacman
    if( _eatable && _stepCounter % 5 == 0) {

        // When the power pellet is 50% over, the ghost alternates his color between blue and white
        if( _powerPelletAlmostOver ) {

            // The ghost's eatable animation has 4 parts
            if( _spriteFlag < _spriteCoordEatable.size() -1 ) _spriteFlag++;
            else _spriteFlag = 0;

            initRect( &_selection,
                      _selection.w,
                      _selection.h,
                      _spriteCoordEatable[_spriteFlag][0],
                    _spriteCoordEatable[_spriteFlag][1]);

        }

        else {

            // The ghost's eatable animation has 4 parts
            if( _spriteFlag < 1 ) _spriteFlag++;
            else _spriteFlag = 0;

            initRect( &_selection,
                      _selection.w,
                      _selection.h,
                      _spriteCoordEatable[_spriteFlag][0],
                    _spriteCoordEatable[_spriteFlag][1]);

        }


    }
    // Otherwise, rendering the normal sprites
    else {

        Character::nextSprite();

    }

}

void Ghost::resetValues() {

    // Reset the velocities
    _velocityX = 0;
    _velocityY = 0;

    Character::resetValues();

}

int Ghost::newRandomDirection() const {

    vector<int> temp;

    for( int i(0); i < _directionsPossible.size(); i++ ) {

        // If the character can go to this direction
        // AND if this direction is different from the previous one
        if( _directionsPossible[i] && i != _forbiddenDirection ) {

            // We add to the temp array
            temp.push_back( i );

        }

    }

    // If no direction found > choose the previous direction
    if( temp.size() == 0 ) {
        return  _forbiddenDirection;
    }
    // Random value
    else {
        return temp[ rand() % temp.size() ];
    }

}

void Ghost::defineVelocity() {

    switch( _step ) {

    case UP:
        _velocityY = -_velocity;
        break;
    case DOWN:
        _velocityY = _velocity;
        break;
    case RIGHT:
        _velocityX = _velocity;
        break;
    case LEFT:
        _velocityX = -_velocity;
        break;

    }

}

void Ghost::setPowerPelletAlmostOver( bool powerPelletAlmostOver ) {

    _powerPelletAlmostOver = powerPelletAlmostOver;

}

void Ghost::deathAnimation(SDL_Renderer* const& pRenderer) {}
void Ghost::teleportation() {}

void Ghost::startValues() {

    Character::startValues();
    _stepCounter = 30;

}

void Ghost::returnToWarpZone() {
}
