#include <pm/PacDots.h>
using namespace PacDots;

#include "PacMan.h"
#include "Ghost.h"
#include "../Surfaces/Surface.h"

using namespace std;

PacMan::PacMan( std::map<std::string, int>& dest,
                SDL_Texture* const& texture,
                const SDL_Rect& selection,
                const SDL_Rect& position,
                FilesManager* fm ) :
    Character( dest,
               fm ),
    _deathAnimationCounter( 0 ){

    _eatable = true;

    // Default coord on the characters sprite
    _initialStateSrc["x"] = selection.x;
    _initialStateSrc["y"] = selection.y;
    _surface = new SurfaceSelection( texture, selection, position );

    // Initialize the power-pellet chronometer
    _powerPelletChrono = new Chrono<PacMan>( POWERPELLET_DURATION,
                                             "Power Pellet Chrono",
                                             this,
                                             &PacMan::setEatable );

    // Initialize the chrono for the wait when a ghost is eaten
    _ghostEatenScoreChrono = new Chrono<Chrono<PacMan> >( Ghost::GHOST_EATEN_SCORE_DURATION,
                                                          "Ghost Eaten Score Duration",
                                                          _powerPelletChrono,
                                                          &Chrono<PacMan>::unpause );

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

void PacMan::updateAll() {

    if( isCenteredInTheSquare() ) {

        updatePositionInTheGrid();

        // Check if the updated position is a teleportation position
        const char* to = checkTeleportation();

        // If the updated position is a teleportation position
        if( to != NO_TELEPORTATION ) {

            teleport( to );
            nextSprite(); // Load the sprite

        }

        // No teleportation
        else {

            calculateDirection();
            resetValues();

        }

    }

    _step = -1;

}

void PacMan::nextSprite() {

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

        _eatable = false;

        // Check if the Pac-Man didn't eat a pac-dot
        // If he ate one => reset the chrono
        if( !_powerPelletChrono->isRunning() )
            _powerPelletChrono->start();
        else
            _powerPelletChrono->reset();

    }

}

Chrono<PacMan>* PacMan::getPowerPelletChrono() const {

    return _powerPelletChrono;

}

Chrono<Chrono<PacMan> >* PacMan::getGhostEatenScoreChrono() const {

    return _ghostEatenScoreChrono;

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
