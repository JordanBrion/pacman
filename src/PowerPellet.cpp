#include "PowerPellet.h"

#include <pm/Points.h>

using namespace std;

PowerPellet::PowerPellet( map<string, int> dest,
                          int type,
                          int x,
                          int y,
                          SDL_Renderer* const& renderer,
                          SDL_Surface* const& sprite ) :
    PacDot( dest, type, x, y, renderer, sprite ),
    _blinkChrono( 0 ) {

    initRect(&_position, 20, 20, x, y);

}

PowerPellet::~PowerPellet() {}

bool PowerPellet::blink() {}

void PowerPellet::resetBlinkChrono() {}

int PowerPellet::show( SDL_Renderer * const &renderer ) {

    int score(0);

    if( !_eaten ) {

        InteractiveElement::show( renderer );

    }
    else {

        score = Points::POWER_PELLET;

    }

    return score;

}
