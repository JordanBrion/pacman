#include "PacMan.h"

using namespace std;

PacMan::PacMan(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : Character(dest, renderer, sprite),
      _directionKey(-1), _deathAnimationCounter(0), _powerPellet(false), _stopKeyUp(false) {

    // Initialize the sprite coord for the animations
    loadSpriteCoord();

    // Select image on the screen
    _initialStateSrc["x"] = 45;
    _initialStateSrc["y"] = 3;
    initRect( &_selection, 16, 20, 45, 3 );

}

PacMan::~PacMan() {}

void PacMan::loadSpriteCoord() {

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

void PacMan::handleEvent(SDL_Event& e ) {

    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 ) {

        switch( e.key.keysym.sym ) {
        case SDLK_UP:
            _velocityY -= _velocity;
            break;
        case SDLK_DOWN :
            _velocityY += _velocity;
            break;
        case SDLK_RIGHT :
            _velocityX += _velocity;
            break;
        case SDLK_LEFT :
            _velocityX -= _velocity;
            break;
        }

    }

    else if( e.type == SDL_KEYUP && e.key.repeat == 0 ) {

        switch( e.key.keysym.sym ) {
        case SDLK_UP:
            _velocityY += _velocity;
            break;
        case SDLK_DOWN :
            _velocityY -= _velocity;
            break;
        case SDLK_RIGHT :
            _velocityX -= _velocity;
            break;
        case SDLK_LEFT :
            _velocityX += _velocity;
            break;
        }

    }

}

void PacMan::move( vector<vector<int> > levelTable ) {

    int temp = -1;

    if( isCenteredInTheSquare() ) {

        temp = _goTo;

        updatePositionInTheGrid();
        calculateDirection(levelTable);
        resetValues();

    }

    bool vertical = ( _velocityY != 0 ) ? true : false;
    bool horizontal = ( _velocityX != 0 ) ? true : false;

    // Check if the previous direction ( before the reset ) is a vertical direction
    if( temp == UP || temp == DOWN ) {

        // First we check if the user is holding LEFT or RIGHT
        // If yes, We move in one of these directions
        if( horizontal ) {
            bool left = ( _velocityX < 0 ) ? true : false;
            moveHorizontally(left);
        }
        else if( vertical ) {
            bool up = ( _velocityY < 0 ) ? true : false;
            moveVertically(up);
        }

    }

    // Check if the previous direction ( before the reset ) is an horizontal direction
    else if( temp == LEFT || temp == RIGHT ) {

        // First we check if the user is holding UP or DOWN
        // If yes, We move in one of these directions
        if( vertical ) {
            bool up = ( _velocityY < 0 ) ? true : false;
            moveVertically(up);
        }
        else if( horizontal ) {
            bool left = ( _velocityX < 0 ) ? true : false;
            moveHorizontally(left);
        }

    }
    else {

        // Default behavior
        // Not else because the user can hold for example UP and LEFT, or DOWN and RIGHT
        // So we need to move vertically AND horizontally !
        // The authorized moves are checked in the methods

        if( vertical ) {
            bool up = ( _velocityY < 0 ) ? true : false;
            moveVertically(up);
        }
        if( horizontal ) {
            bool left = ( _velocityX < 0 ) ? true : false;
            moveHorizontally(left);
        }
    }

}

void PacMan::moveVertically(bool up) {

    if( Character::moveVertically(up) ) {

        int direction = ( up ) ? UP : DOWN;

        if( _spriteFlag == _spriteCoord[direction].size() - 1 && _stepCounter % 5 == 0 ) {
            initRect(&_selection, _selection.w, _selection.h, 45, 3);
            _spriteFlag = -1;
        }
        else {
            nextSprite(direction);
        }

    }

}

void PacMan::moveHorizontally(bool left) {

    if( Character::moveHorizontally(left) ) {

        int direction = ( left ) ? LEFT : RIGHT;

        if( _spriteFlag == _spriteCoord[direction].size() - 1 && _stepCounter % 5 == 0 ) {
            initRect(&_selection, _selection.w, _selection.h, 45, 3);
            _spriteFlag = -1;
        }
        else {
            nextSprite(direction);
        }

    }

}

void PacMan::checkCollisionWithPacDots(PacDotsManager *pdm) {

    pdm->eatPacDot( _row, _col, _position.x + 10, _position.y + 10 );

}

void PacMan::deathAnimation(SDL_Renderer* const& pRenderer) {

    _selection.w = 19;
    _selection.y = 244;

    _selection.x = ( _deathAnimationCounter * 20 ) + 4;

    _deathAnimationCounter++;

    show(pRenderer);
    SDL_Delay(150);


}

int PacMan::getDeathAnimationCounter() const {

    return _deathAnimationCounter;

}

void PacMan::teleportation() {}

void PacMan::defaultValues() {

    Character::defaultValues();
    _deathAnimationCounter = 0;

}
