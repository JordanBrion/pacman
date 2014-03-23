#include "Pacman.h"

using namespace std;

Pacman::Pacman(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : Personnage(dest, renderer, sprite), _deadAnimationCounter(0), _superPower(false) {

    // Initialize the sprite coord for the animations
    loadSpriteCoord();

    // Select image on the screen
    _initialStateSrc["x"] = 45;
    _initialStateSrc["y"] = 3;
    _selection.x = 45;
    _selection.y = 3;
    _selection.w = 16;
    _selection.h = 20;

    // Render on the screen
    show(renderer);

}

void Pacman::loadSpriteCoord() {

    vector<vector<int> > temp(2);
    vector<int> coord(2);

    // UP
    coord[0] = 5;
    coord[1] = 43;
    temp[0] = coord;
    coord[0] = 25;
    coord[1] = 43;
    temp[1] = coord;
    _spriteCoord.push_back(temp);

    // DOWN
    coord[0] = 5;
    coord[1] = 63;
    temp[0] = coord;
    coord[0] = 25;
    coord[1] = 63;
    temp[1] = coord;
    _spriteCoord.push_back(temp);

    // RIGHT
    coord[0] = 5;
    coord[1] = 23;
    temp[0] = coord;
    coord[0] = 25;
    coord[1] = 23;
    temp[1] = coord;
    _spriteCoord.push_back(temp);

    // LEFT
    coord[0] = 5;
    coord[1] = 3;
    temp[0] = coord;
    coord[0] = 25;
    coord[1] = 3;
    temp[1] = coord;
    _spriteCoord.push_back(temp);


}

void Pacman::moveVertically(bool up) {

    if( Personnage::moveVertically(up) ) {

        int direction = ( up ) ? UP : DOWN;

        if( _spriteFlag == _spriteCoord[direction].size() - 1 && _stepCounter % 5 == 0 ) {
            _selection.x = 45;
            _selection.y = 3;
            _spriteFlag = -1;
        }
        else {
            nextSprite(direction);
        }


    }

}

void Pacman::moveHorizontally(bool left) {

    if( Personnage::moveHorizontally(left) ) {

        int direction = ( left ) ? LEFT : RIGHT;

        if( _spriteFlag == _spriteCoord[direction].size() - 1 && _stepCounter % 5 == 0 ) {
            _selection.x = 45;
            _selection.y = 3;
            _spriteFlag = -1;
        }
        else {
            nextSprite(direction);
        }

    }

}

bool Pacman::isCenteredInTheSquareWhenKeyUp() {

    if( _stepCounter > 30 - _offset || (_back && _stepCounter < 6 - _offset ) ) {

        return true;

    }

    return false;


}

void Pacman::deadAnimation(SDL_Renderer* const& pRenderer) {

    _selection.w = 19;
    _selection.y = 244;

    _selection.x = ( _deadAnimationCounter * 20 ) + 4;
    show(pRenderer);
    if( _deadAnimationCounter < 10 ) {
        _deadAnimationCounter++;
    }
    else _deadAnimationCounter = 0;
    SDL_Delay(100);


}

void Pacman::teleportation() {}
