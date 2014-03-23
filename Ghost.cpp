#include "Ghost.h"

using namespace std;

Ghost::Ghost(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : Personnage(dest, renderer, sprite), _previousDirection(-1) {

    _stepCounter = 33;

    // Modulo to determinate the color of the ghost
    // 4 different colors
    // _zIndex % 4 => result = from 0 to 3
    int color = _zIndex % 4;

    switch(color) {
    case RED:
        _initialStateSrc["x"] = 5;
        _initialStateSrc["y"] = 84;
        _selection.x = 5;
        _selection.y = 84;
        break;
    case PINK:
        _initialStateSrc["x"] = 5;
        _initialStateSrc["y"] = 104;
        _selection.x = 5;
        _selection.y = 104;
        break;
    case BLUE:
        _initialStateSrc["x"] = 5;
        _initialStateSrc["y"] = 124;
        _selection.x = 5;
        _selection.y = 124;
        break;
    case ORANGE:
        _initialStateSrc["x"] = 5;
        _initialStateSrc["y"] = 144;
        _selection.x = 5;
        _selection.y = 144;
        break;

    }

    _selection.w = 17;
    _selection.h = 19;

    // Initialize the sprite coord for the animations
    loadSpriteCoord();

    show(renderer);

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

void Ghost::move() {

    // Move Vertically
    if( _goTo == UP || _goTo == DOWN ) {

        bool direction = ( _goTo == UP ) ? true : false;
        if( moveVertically(direction) ) {
            nextSprite(_goTo);
        }

    }
    // Move Horizontally
    else if( _goTo == RIGHT || _goTo == LEFT ){

        bool direction = ( _goTo == LEFT ) ? true : false;
        if( moveHorizontally(direction) ) {
            nextSprite(_goTo);
        }

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

    int direction = -1;

    // If no direction found > choose the previous direction
    if( temp.size() == 0 ) {
        direction = _previousDirection;
    }
    // Random value
    else {
        direction = rand() % temp.size();
    }

    return temp[direction];

}

void Ghost::deadAnimation(SDL_Renderer* const& pRenderer) {}
void Ghost::teleportation() {}

void Ghost::defaultValues() {

    Personnage::defaultValues();
    _stepCounter = 33;

}

void Ghost::returnToWarpZone() {
}

void Ghost::setVulnerable( bool vulnerable ) {
}

