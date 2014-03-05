#ifndef PACMAN_H
#define PACMAN_H

#include "Personnage.h"

class Pacman: public Personnage {

private:
    bool _superPower;
public:
    void init();
    void move();
    void stopMove();
    void checkCollision();
    void deadAnimation();
    void teleportation();
    void calculateDirection(std::map<std::string, bool>);

};

#endif
