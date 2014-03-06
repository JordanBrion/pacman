#ifndef PACMAN_H
#define PACMAN_H

#include "Personnage.h"

class Pacman : public Personnage {

public:
    Pacman(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
    ~Pacman();
    void move();
    void stopMove();
    void checkCollision();
    void deadAnimation();
    void teleportation();
    void calculateDirection(std::map<std::string, bool>);

private:
    bool _superPower;

};

#endif
