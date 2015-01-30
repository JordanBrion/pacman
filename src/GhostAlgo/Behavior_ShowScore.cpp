#include "Behavior_ShowScore.h"

#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"
#include "Behavior_ReturnToWarpzone.h"

Behavior_ShowScore::Behavior_ShowScore( Ghost* master,
                                        PacMan* pacMan ) {

    _ghost = master;
    _pacMan = pacMan;

}

Behavior_ShowScore::~Behavior_ShowScore() {}

void Behavior_ShowScore::run() {

    // Check if the power-pellet chrono is paused
    if( _pacMan->getPowerPelletChrono()->isPaused()  ) {

        // The ghost was eaten
        // => trigger the GhostEatenScoreChrono
        _pacMan->getGhostEatenScoreChrono()->start();

        // The chrono is now running
        // => wait for the end
        SDL_WaitThread( _pacMan->getGhostEatenScoreChrono()->getThread(), 0 );

    }

    // The ghost was eaten => go to the Warpzone
    _ghost->setBehavior( new Behavior_ReturnToWarpzone( _ghost, _pacMan ) );

}

Uint8 Behavior_ShowScore::getState() const { return SHOW_SCORE; }
