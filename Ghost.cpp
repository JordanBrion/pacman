#include "Ghost.h"

using namespace std;

Ghost::Ghost(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : Personnage(dest, renderer, sprite) {

    // Modulo to determinate the color of the ghost
    // 4 different colors
    // _zIndex % 4 => result = from 0 to 3
    int color = _zIndex % 4;

    enum colors {
        RED, PINK, BLUE, ORANGE
    };

    switch(color) {
    case RED:
        _selection.x = 5;
        _selection.y = 84;
        break;
    case PINK:
        _selection.x = 5;
        _selection.y = 104;
        break;
    case BLUE:
        _selection.x = 5;
        _selection.y = 124;
        break;
    case ORANGE:
        _selection.x = 5;
        _selection.y = 144;
        break;

    }

    _selection.w = 17;
    _selection.h = 19;

    show(renderer);

}

void Ghost::loadSpriteCoord() {}

void Ghost::move() {

    // If the ghost is centered in the square
    if( isCenteredInTheSquare() ) {

        // New direction
        newRandomDirection();

    }

}

bool Ghost::newRandomDirection() const {



}

void Ghost::stopMove() {}
void Ghost::checkCollision() {}
void Ghost::deadAnimation() {}
void Ghost::teleportation() {}

void Ghost::returnToWarpZone() {
}

void Ghost::setVulnerable( bool vulnerable ) {
}

