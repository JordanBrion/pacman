#include "Pacman.h"

using namespace std;

Pacman::Pacman(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : Personnage(dest, renderer, sprite), _superPower(false) {

    // Select image on the screen
    _initialStateSrc["x"] = 45;
    _initialStateSrc["y"] = 3;
    _selection.x = 45;
    _selection.y = 3;
    _selection.w = 16;
    _selection.h = 20;

    // Render on the screen
    show(renderer);

}

void Pacman::stopMove() {}
void Pacman::checkCollision() {}
void Pacman::deadAnimation() {}
void Pacman::teleportation() {}
