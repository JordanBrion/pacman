#include "Ghost.h"

using namespace std;

Ghost::Ghost(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : Personnage(dest, renderer, sprite), _previousDirection(-1) {

    _stepCounter = 33;

    // Modulo to determinate the color of the ghost
    // 4 different colors
    // _zIndex % 4 => result = from 0 to 3
    int color = _zIndex % 4;

    enum colors {
        RED, PINK, BLUE, ORANGE
    };

    switch(color) {
    case RED:
        _selection.x = 5;
        _selection.y = 84;
        break;
    case PINK:
        _selection.x = 5;
        _selection.y = 104;
        break;
    case BLUE:
        _selection.x = 5;
        _selection.y = 124;
        break;
    case ORANGE:
        _selection.x = 5;
        _selection.y = 144;
        break;

    }

    _selection.w = 17;
    _selection.h = 19;

    show(renderer);

}

void Ghost::loadSpriteCoord() {}

void Ghost::move() {

    // Move Vertically
    if( _goTo == UP || _goTo == DOWN ) {

        bool direction = ( _goTo == UP ) ? true : false;
        moveVertically(direction);

    }
    // Move Horizontally
    else if( _goTo == RIGHT || _goTo == LEFT ){

        bool direction = ( _goTo == LEFT ) ? true : false;
        moveHorizontally(direction);

    }

}

void Ghost::resetValues() {

    // Forbid the previous direction
    // For examples: if the ghost moved to UP, forbid DOWN for the next move
    //               if the ghost moved to RIGHT, forbid LEFT for the next move
    if( _goTo == UP || _goTo == RIGHT ) {
        _previousDirection = _goTo + 1;
    }
    else if( _goTo == DOWN || _goTo == LEFT ) {
        _previousDirection = _goTo - 1;
    }

    Personnage::resetValues();
    _goTo = newRandomDirection();

}

int Ghost::newRandomDirection() const {

    vector<int> temp;

    for( int i(0); i < _directionsPossible.size(); i++ ) {

        // If the character can go to this direction
        // AND if this direction is different from the previous one
        if( _directionsPossible[i] && i != _previousDirection ) {
            // We add to the temp array
            temp.push_back( i );
        }

    }

    // Random value
    int direction = rand() % temp.size();

    return temp[direction];

}

void Ghost::stopMove() {}
void Ghost::checkCollision() {}
void Ghost::deadAnimation() {}
void Ghost::teleportation() {}

void Ghost::returnToWarpZone() {
}

void Ghost::setVulnerable( bool vulnerable ) {
}

