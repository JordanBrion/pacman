#ifndef PACMAN_H
#define PACMAN_H

#include "Personnage.h"

class Pacman : public Personnage {

public:
    Pacman(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
    ~Pacman();
    void loadSpriteCoord();
    bool isCenteredInTheSquareWhenKeyUp();
    void stopMove();
    void checkCollision();
    void deadAnimation();
    void teleportation();

private:
    bool _superPower;

};

#endif
