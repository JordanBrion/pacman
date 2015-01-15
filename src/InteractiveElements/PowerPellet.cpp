#include "PowerPellet.h"

#include <pm/Points.h>

using namespace std;

/*
 * STATIC ATTRIBUTES
 *
 * Static attributes because all the power-pellets has to use
 * the same chronometers to blink at the same time
 *
 */
Uint32 PowerPellet::blinkChrono = 0;
Uint32 PowerPellet::betweenBlinkChrono = 0;

PowerPellet::PowerPellet( map<string, int> dest,
                          int type,
                          int x,
                          int y,
                          SDL_Renderer* const& renderer,
                          SDL_Surface* const& sprite ) :
    PacDot( dest, type, x, y, renderer, sprite ) {

    initRect(&_position, 20, 20, x, y);

}

PowerPellet::~PowerPellet() {}

bool PowerPellet::blink() {

    // Blink
    if( SDL_GetTicks() - blinkChrono <= POWERPOWER_BLINK_DURATION ) {

        return true;

    }

    // Don't blink
    else if( SDL_GetTicks() - betweenBlinkChrono <= POWERPOWER_BLINK_BETWEEN_DURATION ) {

        return false;

    }

}

void PowerPellet::checkBlink() {

    // Check if the blinkChrono is not over the duration
    if( betweenBlinkChrono == 0
            && SDL_GetTicks() - blinkChrono > POWERPOWER_BLINK_DURATION ) {

        betweenBlinkChrono = SDL_GetTicks();
        blinkChrono = 0;

    }

    // Check if the betweenBlinkChrono is not over the duration
    else if( blinkChrono == 0
             && SDL_GetTicks() - betweenBlinkChrono > POWERPOWER_BLINK_BETWEEN_DURATION ) {

        blinkChrono = SDL_GetTicks();
        betweenBlinkChrono = 0;

    }

}

int PowerPellet::show( SDL_Renderer * const &renderer ) {

    int score(0);

    if( !_eaten ) {

        PowerPellet::checkBlink();

        // If the power-pellet has to blink, don't render it
        if( PowerPellet::blink() ) {
            InteractiveElement::show( renderer );
        }

    }
    else {

        score = Points::POWER_PELLET;

    }

    return score;

}
