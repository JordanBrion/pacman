#include "Behavior_Hunter.h"

#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"
#include "Behavior_Hunted.h"

#include <pm/Directions.h>

Behavior_Hunter::Behavior_Hunter( Ghost* master,
                                  PacMan* pacMan ) {

    _ghost = master;
    _pacMan = pacMan;

}

Behavior_Hunter::~Behavior_Hunter() {}

void Behavior_Hunter::run() {

    // Update the ghost attributes
    _ghost->updateAll();

    // If the Pac-Man is not eatable
    // => we change the behavior of the ghost
    if( !_pacMan->isEatable() ) {

        _ghost->setBehavior( new Behavior_Hunted( _ghost, _pacMan ) );

    }

    // Move the ghost
    else if( _ghost->move() != NO_DIRECTION ) {

        // After the move, detect if there is a collision
        if( _ghost->checkCollision( _pacMan ) ) {

            _pacMan->setDead( true );

        }

        _ghost->nextSprite();

    }

}

Uint8 Behavior_Hunter::getState() const { return HUNTER; }
