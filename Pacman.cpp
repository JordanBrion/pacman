#include "Pacman.h"

using namespace std;

Pacman::Pacman(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : Character(dest, renderer, sprite), _deadAnimationCounter(0), _superPower(false), _stopKeyUp(false) {

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

void Pacman::handleEvent(SDL_Event const& e, vector<vector<int> > levelTable) {

    switch(e.type) {

    // Key Down
    case SDL_KEYDOWN:
    {
        SDL_Keycode code = e.key.keysym.sym;

        if( code == SDLK_UP ||
                code == SDLK_DOWN ||
                code == SDLK_LEFT ||
                code == SDLK_RIGHT ) {

            bool vertical = ( code == SDLK_UP || code == SDLK_DOWN ) ? true : false;

            if( isCenteredInTheSquare() ) {

                updatePositionInTheGrid();
                calculateDirection(levelTable);
                if( vertical ) calculateOffset(true);
                else calculateOffset(false);
                resetValues();

            }

            if( vertical) {
                bool up = ( code == SDLK_UP ) ? true : false;
                moveVertically(up);
            }
            else {
                bool left = ( code == SDLK_LEFT ) ? true : false;
                moveHorizontally(left);
            }

            _stopKeyUp = false;

        }
    }
        break;

    // Key Up
    case SDL_KEYUP:

        // Once the key is down and when the user releases this key,
        // the programm goes through this case in an infinite loop
        // So we freeze this loop with a flag
        if( !_stopKeyUp ) {

            _stopKeyUp = true;

            switch(e.key.keysym.sym) {

            case SDLK_UP:
            case SDLK_DOWN:
                if (isCenteredInTheSquareWhenKeyUp() ) {

                    updatePositionInTheGrid();
                    calculateDirection(levelTable);
                    calculateOffset(true);
                    resetValues();
                }
                break;

            case SDLK_RIGHT:
            case SDLK_LEFT:
                if (isCenteredInTheSquareWhenKeyUp() ) {

                    updatePositionInTheGrid();
                    calculateDirection(levelTable);
                    calculateOffset(false);
                    resetValues();
                }
                break;

            }
        }
        break;

    }

}

void Pacman::moveVertically(bool up) {

    if( Character::moveVertically(up) ) {

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

    if( Character::moveHorizontally(left) ) {

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

    _deadAnimationCounter++;

    show(pRenderer);
    SDL_Delay(150);


}

int Pacman::getDeadAnimationCounter() const {

    return _deadAnimationCounter;

}

void Pacman::teleportation() {}

void Pacman::defaultValues() {

    Character::defaultValues();
    _deadAnimationCounter = 0;

}
