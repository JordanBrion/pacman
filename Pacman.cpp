#include "Pacman.h"

using namespace std;

Pacman::Pacman(map<string, int> src, map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : Personnage(src, dest, renderer, sprite), _superPower(false) {

}

void Pacman::move() {}
void Pacman::stopMove() {}
void Pacman::checkCollision() {}
void Pacman::deadAnimation() {}
void Pacman::teleportation() {}
void Pacman::calculateDirection(std::map<std::string, bool>) {}
