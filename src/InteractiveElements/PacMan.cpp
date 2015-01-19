#include <pm/PacDots.h>
using namespace PacDots;

#include "PacMan.h"
#include "../Surfaces/Surface.h"

using namespace std;

PacMan::PacMan( std::map<std::string, int>& dest,
                SDL_Texture* const& texture,
                const SDL_Rect& selection,
                const SDL_Rect& position ) :
    Character( dest ),
    _deathAnimationCounter( 0 ),
    _powerPelletChrono( 0 ) {

    _eatable = true;

    // Default coord on the characters sprite
    _initialStateSrc["x"] = selection.x;
    _initialStateSrc["y"] = selection.y;
    _surface = new SurfaceSelection( texture, selection, position );

    // Initialize the sprite coord for the animations
    loadSpriteCoord();

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
        case SDLK_DOWN:
            _velocityY += _velocity;
            break;
        case SDLK_RIGHT:
            _velocityX += _velocity;
            break;
        case SDLK_LEFT:
            _velocityX -= _velocity;
            break;
        }

    }

    else if( e.type == SDL_KEYUP && e.key.repeat == 0 ) {

        switch( e.key.keysym.sym ) {
        case SDLK_UP:
            _velocityY += _velocity;
            break;
        case SDLK_DOWN:
            _velocityY -= _velocity;
            break;
        case SDLK_RIGHT:
            _velocityX -= _velocity;
            break;
        case SDLK_LEFT:
            _velocityX += _velocity;
            break;
        }

    }

}

void PacMan::updateAll( vector<vector<int> > levelTable, map<string, vector<int> > teleportationLocationsCoord ) {

    if( isCenteredInTheSquare() ) {

        updatePositionInTheGrid();

        // Check if the updated position is a teleportation position
        vector<int> teleportationTo = checkTeleportation( teleportationLocationsCoord );

        // If the updated position is a teleportation position
        if( teleportationTo.size() == 2 ) {

            teleport( teleportationTo, levelTable );
            nextSprite(); // Load the sprite

        }

        // No teleportation
        else {

            calculateDirection( levelTable );
            resetValues();

        }

    }

    _step = -1;

}

void PacMan::nextSprite() {

    cout << _step << endl;

    if( _step != -1 ) {

        if( _spriteFlag+1 == _spriteCoord[ _step ].size() && _stepCounter % 5 == 0 ) {

            _surface->setSelection( _surface->getSelection().w, _surface->getSelection().h,
                                    45, 3);
            _spriteFlag = -1;

        }

        else {

            Character::nextSprite();

        }

    }

}

void PacMan::checkCollisionWithPacDots(PacDotsManager *pdm) {

    if( pdm->eatPacDot( _row, _col, _surface->getPosition().x + 10, _surface->getPosition().y + 10 ) ) {

        startPowerPelletChrono();

    }

}

Uint32 PacMan::getPowerPelletChrono() const {

    return _powerPelletChrono;

}

void PacMan::startPowerPelletChrono() {

    _powerPelletChrono = SDL_GetTicks();
    _eatable = false;

}

bool PacMan::checkPowerPelletChrono() {

    if( timeLeftPowerPellet() >= POWERPELLET_DURATION  ) {
        resetPowerPelletChrono();
        return true;
    }

    return false;

}

void PacMan::resetPowerPelletChrono() {

    _powerPelletChrono = 0;
    _eatable = true;

}

Uint32 PacMan::timeLeftPowerPellet() {

    return SDL_GetTicks() - _powerPelletChrono;

}

bool PacMan::checkCollisionWithFruit( FruitManager* frm ) {

    if( frm->eatFruit( _row, _col ) ) {

        frm->resetCurrentFruit();
        return true;

    }

    return false;

}

void PacMan::deathAnimation(SDL_Renderer* const& pRenderer) {

    _surface->setSelectionW( 19 );

    _surface->setSelectionX( ( _deathAnimationCounter * 20 ) + 4 );
    _deathAnimationCounter++;
    _surface->setSelectionY( 244 );

    show(pRenderer);
    SDL_Delay(150);

}

int PacMan::getDeathAnimationCounter() const {

    return _deathAnimationCounter;

}

void PacMan::startValues() {

    Character::startValues();
    _deathAnimationCounter = 0;

}
