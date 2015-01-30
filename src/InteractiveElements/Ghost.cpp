#include "Ghost.h"

using namespace std;

#include "../GhostAlgo/Behavior_EnterWarpzone.h"
#include "../GhostAlgo/Behavior_ExitWarpzone.h"
#include "../GhostAlgo/Behavior_Hunted.h"
#include "../GhostAlgo/Behavior_Hunter.h"
#include "../GhostAlgo/Behavior_InWarpzone.h"
#include "../GhostAlgo/Behavior_ReturnToWarpzone.h"
#include "../Surfaces/Surface.h"
#include "PacDot.h"

#include <pm/Color.h>
#include <pm/Directions.h>
#include <pm/Arithmetic.h>
#include <pm/Points.h>

Ghost::Ghost( std::map<std::string, int>& dest,
              SDL_Texture* const& sprite,
              const SDL_Rect& selection,
              const SDL_Rect& position,
              PacMan* const& pacMan,
              bool* const& quitGame,
              FilesManager* fm ) :
    Character( dest,
               fm ),
    _forbiddenDirection( -1 ),
    _powerPelletAlmostOver( false ) {

    _eatable = false;
    _stepCounter = 30;

    _initialStateSrc["x"] = selection.x;
    _initialStateSrc["y"] = selection.y;
    _surface = new SurfaceSelection( sprite, selection, position );

    // Initialize the sprite coord for the animations
    loadSpriteCoord();

    // Initialize the sprite coord for the eatable animations
    loadSpriteCoordEatable();

    _behavior = new Behavior_Hunter( this, pacMan );
    _thread = new GhostThread( this, _instanceID, quitGame );

}

void Ghost::loadSpriteCoord() {

    Uint8 color = _instanceID % 4;

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

void Ghost::updateAll() {

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

            _surface->setSelection(
                        _surface->getSelection().w,
                        _surface->getSelection().h,
                        _spriteCoordEatable[_spriteFlag][0],
                    _spriteCoordEatable[_spriteFlag][1]);

        }

        else {

            // The ghost's eatable animation has 4 parts
            if( _spriteFlag < 1 ) _spriteFlag++;
            else _spriteFlag = 0;

            _surface->setSelection(
                        _surface->getSelection().w,
                        _surface->getSelection().h,
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

bool Ghost::checkCollision( PacMan* const& pacMan ) const {

    SDL_Rect pman = pacMan->getPosition();
    SDL_Rect me = _surface->getPosition();

    if( ( me.x >= pman.x - 15 && me.x <= pman.x + 15)
            && ( me.y - 15 && me.y <= pman.y + 15 ) )  {

        // Collision detected
        return true;

    }

    return false;

}

bool Ghost::eat( PacMan* pacman ) {

    // If the pacman ate a power pellet, he is not eatable
    // AND if the ghost is not dead yet
    if( !pacman->isEatable() && !_dead ) {

        _dead = true;
        return false;

    }

    // Otherwise, pacman is dead
    else if( pacman->isEatable() && !pacman->isDead() ) {

        pacman->setDead();
        return true;

    }

    return false;

}

void Ghost::handlePowerPellet( PacMan* pacMan ) {

    if( !pacMan->isEatable() ) {

        if( !pacMan->getPowerPelletChrono()->isOver() && !pacMan->getGhostEatenScoreChrono()->isRunning() ) {

            _eatable = true;

            // If the power pellet duration is equal or less than 50%
            if( Arithmetic::valueInPercent(
                        pacMan->getPowerPelletChrono()->getRemainingTimeInMillis(),
                        POWERPELLET_DURATION )
                    <= 50 )
                _powerPelletAlmostOver = true;

            // Set the value to false in case pacman pick up another power-pellet before the chronometer is finished
            else
                _powerPelletAlmostOver = false;

        }

    }

    // The power pellet duration is over (we check if we don't stop it before)
    // => Ghosts can't be eaten
    else if( _eatable ){
        _eatable = false;
        _powerPelletAlmostOver = false;
    }

}

void Ghost::setPowerPelletAlmostOver( bool powerPelletAlmostOver ) {

    _powerPelletAlmostOver = powerPelletAlmostOver;

}

void Ghost::deathAnimation(SDL_Renderer* const& pRenderer) {}

void Ghost::startValues() {

    Character::startValues();
    _stepCounter = 30;

}

void Ghost::drawScorePowerPellet( SDL_Renderer* renderer, Uint16 const& score ) {

    switch( score ) {

    case POINTS_ONE_GHOST_EATEN:
        _surface->setSelection( 17, 19, 184, 0 );
        break;

    case POINTS_TWO_GHOSTS_EATEN:
        _surface->setSelection( 17, 19, 184, 0 );
        break;

    case POINTS_THREE_GHOSTS_EATEN:
        _surface->setSelection( 17, 19, 184, 0 );
        break;

    case POINTS_FOUR_GHOSTS_EATEN:
        _surface->setSelection( 17, 19, 184, 0 );
        break;

    }

    SDL_Rect selection = _surface->getSelection();
    SDL_Rect position = _surface->getPosition();

    SDL_RenderCopy( renderer,
                    _surface->getTexture(),
                    &selection,
                    &position );

}

void Ghost::returnToWarpZone() {

    startValues();

}

GhostBehavior* Ghost::getBehavior() const {

    return _behavior;

}

void Ghost::setBehavior( GhostBehavior* newBehavior ) {

    delete _behavior;
    _behavior = newBehavior;

}
