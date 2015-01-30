#include "Behavior_Hunted.h"

#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"
#include "Behavior_Hunter.h"
#include "Behavior_ReturnToWarpzone.h"
#include "Behavior_ShowScore.h"

#include <pm/Arithmetic.h>
#include <pm/PacDots.h>

Behavior_Hunted::Behavior_Hunted( Ghost* master,
                                  PacMan* pacMan ) {

    _ghost = master;
    _pacMan = pacMan;

}

Behavior_Hunted::~Behavior_Hunted() {}

void Behavior_Hunted::run() {

    // If the power-pellet chrono is not over
    if( !_pacMan->getPowerPelletChrono()->isOver() ) {

        _ghost->setEatable( true );

        // Update the ghost attributes
        _ghost->updateAll();

        // If the Pac-Man ate a ghost, the power-pellet combo score is shown for 2 seconds
        // => If this chrono is running, don't move the ghost
        if( !_pacMan->getGhostEatenScoreChrono()->isRunning()
                && _ghost->move() != -1 ) {

            // If the power pellet duration is equal or less than 50%
            if( Arithmetic::valueInPercent(
                        _pacMan->getPowerPelletChrono()->getRemainingTimeInMillis(),
                        PacDots::POWERPELLET_DURATION )
                    <= 50 )
                _ghost->setPowerPelletAlmostOver( true );

            // Set the value to false in case _pacMan pick up another power-pellet before the chronometer is finished
            else
                _ghost->setPowerPelletAlmostOver( false );

            // After the move, detect if there is a collision
            if( _ghost->checkCollision( _pacMan ) ) {

                _ghost->setDead( true );

                // Pause the power-pellet chrono
                _pacMan->getPowerPelletChrono()->pause();

                // The ghost was eaten => power-pellet score has to be rendered
                _ghost->setBehavior( new Behavior_ShowScore( _ghost, _pacMan ) );

            }

            _ghost->nextSprite();

        }
        else {

            // The GhostEatenScoreChrono is running
            // => wait for the end
            SDL_Delay( _pacMan->getGhostEatenScoreChrono()->getRemainingTimeInMillis() );

        }

    }

    // The power pellet duration is over
    else {

        _ghost->setEatable( false );
        _ghost->setPowerPelletAlmostOver( false );
        _ghost->setBehavior( new Behavior_Hunter( _ghost, _pacMan ) );

    }

}

Uint8 Behavior_Hunted::getState() const { return HUNTED; }
