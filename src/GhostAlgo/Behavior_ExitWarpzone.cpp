#include "Behavior_ExitWarpzone.h"

#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"
#include "Behavior_Hunter.h"
#include "Behavior_Hunted.h"

#include <pm/Directions.h>

Behavior_ExitWarpzone::Behavior_ExitWarpzone( Ghost* master,
                                              PacMan* pacMan ) {

    _ghost = master;
    _pacMan = pacMan;

    // Calculate the direction towards the ghost has to move to reach the exit of the Warpzone
    Warpzone* warpzone = _ghost->getFm()->getWarpzone();
    Element* exit = _ghost->getFm()->getWarpzoneExit();

    int8_t* direction = new int8_t();
    int8_t* forbid = new int8_t();

    if( warpzone->vertical ) {

        if( _ghost->getRow() < exit->row ) {
            *direction = DOWN;
            *forbid = UP;
        }
        else {
            *direction = UP;
            *forbid = DOWN;
        }

    }
    else {

        if( _ghost->getCol() < exit->col ) {
            *direction = RIGHT;
            *forbid = LEFT;
        }
        else {
            *direction = LEFT;
            *forbid = RIGHT;
        }

    }

    _ghost->setGoTo( *direction );
    _ghost->setStep( *direction );
    _ghost->setForbiddenDirection( *forbid );
    delete direction;
    delete forbid;
    _ghost->setVelocity( EXIT_WARPZONE_VELOCITY );
    _ghost->defineVelocity();

}

Behavior_ExitWarpzone::~Behavior_ExitWarpzone() {}

void Behavior_ExitWarpzone::run() {

    if( _pacMan->getPowerPelletChrono()->isRunning() ) {
        _ghost->setEatable( true );
    }
    else {
        _ghost->setEatable( false );
    }

    // Check if Warpzone is vertical
    // If vertical      => _ghost and exit are in the same col => nothing to do
    //                  => but not in the same row => check that !
    // If not vertical  => _ghost and exit are in the same row => nothing to do
    //                  => but not in the same col => check that !
    bool cond = ( _ghost->getFm()->getWarpzone()->vertical ) ?
                ( _ghost->getRow() != _ghost->getFm()->getWarpzoneExit()->row ) :
                ( _ghost->getCol() != _ghost->getFm()->getWarpzoneExit()->col );

    // We move the ghost until he is in the exit grid element
    if( cond ) {

        _ghost->move();
        _ghost->nextSprite();
        _ghost->updateAll();

    }

    // If the ghost is in the exit grid element
    // => The ghost exit the Warpzone => he goes to the entrance grid element
    else if( _ghost->getStepCounter() + EXIT_WARPZONE_VELOCITY < 60 ) {

        switch( _ghost->getFm()->getWarpzone()->orientationExit ) {

        case UP:
            _ghost->getSurface()->setPositionY( _ghost->getPosition().y - EXIT_WARPZONE_VELOCITY );
            _ghost->setGoTo( UP );
            _ghost->setStep( UP );
            break;
        case DOWN:
            _ghost->getSurface()->setPositionY( _ghost->getPosition().y + EXIT_WARPZONE_VELOCITY );
            _ghost->setGoTo( DOWN );
            _ghost->setStep( DOWN );
            break;
        case RIGHT:
            _ghost->getSurface()->setPositionX( _ghost->getPosition().x + EXIT_WARPZONE_VELOCITY );
            _ghost->setGoTo( RIGHT );
            _ghost->setStep( RIGHT );
            break;
        case LEFT:
            _ghost->getSurface()->setPositionX( _ghost->getPosition().x - EXIT_WARPZONE_VELOCITY );
            _ghost->setGoTo( LEFT );
            _ghost->setStep( LEFT );
            break;

        }

        _ghost->setStepCounter( _ghost->getStepCounter() + EXIT_WARPZONE_VELOCITY );
        _ghost->nextSprite();

    }

    // If the ghost is in the entrance grid element
    // => we change his behavior
    else {

        _ghost->setStepCounter( 30 );
        _ghost->setBack( true );
        _ghost->setRow( _ghost->getFm()->getWarpzone()->entrance.row );
        _ghost->setCol( _ghost->getFm()->getWarpzone()->entrance.col );

        if( _pacMan->getPowerPelletChrono()->isRunning() ) {
            _ghost->setBehavior( new Behavior_Hunted( _ghost, _pacMan ) );
        }
        else {
            _ghost->setBehavior( new Behavior_Hunter( _ghost, _pacMan ) );
        }

    }

}

Uint8 Behavior_ExitWarpzone::getState() const { return EXIT_WARPZONE; }
