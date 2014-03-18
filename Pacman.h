#ifndef PACMAN_H
#define PACMAN_H

#include "Personnage.h"

class Pacman : public Personnage {

public:
    Pacman(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
    ~Pacman();
    void loadSpriteCoord();
    void moveVertically(bool);
    void moveHorizontally(bool);
    bool isCenteredInTheSquareWhenKeyUp();
    void stopMove();
    void deadAnimation();
    void teleportation();

private:
    bool _superPower;

};

#endif
