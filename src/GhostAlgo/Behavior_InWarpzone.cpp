#include "Behavior_InWarpzone.h"

#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"
#include "../InteractiveElements/PowerPellet.h"
#include "../GhostAlgo/Behavior_ExitWarpzone.h"

#include <pm/Directions.h>
#include <pm/Arithmetic.h>

/* STATIC ATTRIBUTES INITIALIZATION */
uint8_t Behavior_InWarpzone::instancesCounter = 0;

Behavior_InWarpzone::Behavior_InWarpzone( Ghost* master,
                                          PacMan* pacMan ) :
    _velocityModerator( 0 ) {

    _ghost = master;
    _ghost->setStepCounter( 0 );
    _pacMan = pacMan;

    // With the value of the static attribute instancesCounter
    // => set the goTo direction
    if( Behavior_InWarpzone::instancesCounter % 2 == 0 )
        _ghost->setGoTo( UP );
    else
        _ghost->setGoTo( DOWN );

    // Increment the instances counter
    Behavior_InWarpzone::instancesCounter += 1;

    // Initialize the chrono for the duration in the Warpzone
    _inWarpZoneChrono = new Chrono<Behavior_InWarpzone>( INWARPZONE_DURATION,
                                                         "Chrono for duration in the Warpzone" );
    _inWarpZoneChrono->start();

}

Behavior_InWarpzone::~Behavior_InWarpzone() {}

void Behavior_InWarpzone::run() {

    // If the chrono is running
    if( _inWarpZoneChrono->isRunning() ) {

        // If the power-pellet chrono is running
        // => Set the ghost attributes
        if( _pacMan->getPowerPelletChrono()->isRunning() ) {

            _ghost->setEatable( true );

            if( Arithmetic::valueInPercent(
                        _pacMan->getPowerPelletChrono()->getRemainingTimeInMillis(),
                        POWERPELLET_DURATION )
                    <= 50 )
                _ghost->setPowerPelletAlmostOver( true );
            else
                _ghost->setPowerPelletAlmostOver( false );

        }

        // If the ghost is going to UP
        if( _ghost->getGoTo() == UP ) {

            if( _ghost->getStepCounter() - INWARPZONE_VELOCITY < -INWARPZONE_OFFSETY_MAX ) {

                _ghost->setGoTo( DOWN );
                _ghost->setStep( DOWN );

            }
            else {

                _ghost->setStepCounter( _ghost->getStepCounter() - INWARPZONE_VELOCITY );
                _ghost->getSurface()->setPositionY(
                            _ghost->getSurface()->getPosition().y - INWARPZONE_VELOCITY );

            }

            _ghost->nextSprite();

        }

        // Else if the ghost is going to DOWN
        else if( _ghost->getGoTo() == DOWN ) {

            if( _ghost->getStepCounter() + INWARPZONE_VELOCITY > INWARPZONE_OFFSETY_MAX ) {

                _ghost->setGoTo( UP );
                _ghost->setStep( UP );

            }
            else {

                _ghost->setStepCounter( _ghost->getStepCounter() + INWARPZONE_VELOCITY );
                _ghost->getSurface()->setPositionY(
                            _ghost->getSurface()->getPosition().y + INWARPZONE_VELOCITY );

            }

            _ghost->nextSprite();

        }

    }
    // If the chrono is over
    // => center the ghost in the grid element
    else if( _ghost->getStepCounter() != 0 ) {

        if( _ghost->getStepCounter() > 0 ) {

            _ghost->setStepCounter( _ghost->getStepCounter() - INWARPZONE_VELOCITY );
            _ghost->getSurface()->setPositionY( _ghost->getSurface()->getPosition().y - INWARPZONE_VELOCITY );

        }
        else {

            _ghost->setStepCounter( _ghost->getStepCounter() + INWARPZONE_VELOCITY );
            _ghost->getSurface()->setPositionY( _ghost->getSurface()->getPosition().y + INWARPZONE_VELOCITY );

        }

    }
    // If the chrono is over
    // AND if the ghost is centered in the grid element
    // => We change the behavior => the ghost has to exit the Warpzone
    else {

        // Wait a moment
        // => The ghosts don't quit the Warpzone at the same time
        SDL_Delay( ( (_ghost->getInstanceID()-1) % 4 ) * 1000 );
        _ghost->setBehavior( new Behavior_ExitWarpzone( _ghost, _pacMan ) );

    }

    SDL_Delay( 50 );

}

Uint8 Behavior_InWarpzone::getState() const { return DEFAULT_WARPZONE; }
