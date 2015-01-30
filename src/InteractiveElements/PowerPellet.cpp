#include "PowerPellet.h"

using namespace std;

#include "../Surfaces/Surface.h"

#include <pm/Points.h>

/*
 * STATIC ATTRIBUTES
 *
 * Static attributes because all the power-pellets has to use
 * the same chronometers to blink at the same time
 *
 */
Chrono<PowerPellet>* PowerPellet::blinkChrono = new Chrono<PowerPellet>( POWERPELLET_BLINK_DURATION,
                                                                         "Chrono for blink duration" );
Chrono<PowerPellet>* PowerPellet::betweenBlinkChrono = new Chrono<PowerPellet>( POWERPELLET_BLINK_BETWEEN_DURATION,
                                                                                "Chrono for duration between 2 blinks" );

PowerPellet::PowerPellet( std::map<std::string, int>& dest,
                          const int& type,
                          const SDL_Rect& selection,
                          const SDL_Rect& position,
                          SDL_Texture* const& sprite ) :
    PacDot( dest,
            type,
            selection, position,
            sprite ) {

}

PowerPellet::~PowerPellet() {}

bool PowerPellet::blink() {

    // No chrono are running ?
    // => start the blinkChrono
    if( PowerPellet::blinkChrono->isStopped()
            && PowerPellet::betweenBlinkChrono->isStopped() ) {

        PowerPellet::blinkChrono->start();

    }

    // If the blinkChrono is running and the remaining time is less than 100 ms
    // => start the other chrono
    else if( PowerPellet::blinkChrono->isRunning()
             && PowerPellet::blinkChrono->getRemainingTimeInMillis() < 10
             && !PowerPellet::betweenBlinkChrono->isRunning() ) {

        PowerPellet::betweenBlinkChrono->start();

    }

    if( PowerPellet::blinkChrono->isRunning() )
        return true;
    else
        return false;

}

int PowerPellet::show( SDL_Renderer* const& renderer ) {

    int score(0);

    if( !_eaten ) {

        // If the power-pellet has to blink, don't render it
        if( PowerPellet::blink() ) {
            InteractiveElement::show( renderer );
        }

    }
    else {

        score = POINTS_POWERPELLET;

    }

    return score;

}
