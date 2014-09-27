#include "PowerPellet.h"

using namespace std;

PowerPellet::PowerPellet( map<string, int> dest,
                          int type,
                          int x,
                          int y,
                          SDL_Renderer* const& renderer,
                          SDL_Surface* const& sprite ) :
    PacDot( dest, type, x, y, renderer, sprite ),
    _blinkChrono( 0 ) {



}

PowerPellet::~PowerPellet() {}

bool PowerPellet::blink() {}

void PowerPellet::resetBlinkChrono() {}

void show( SDL_Renderer * const &renderer ) {}
