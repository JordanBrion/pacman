#ifndef FANTOME_H
#define FANTOME_H

#include <sstream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include "Personnage.h"
#include "Pacman.h"

class Ghost : public Personnage {

  public:
    Ghost(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
    void loadSpriteCoord();
    void move();
    void resetValues();
    int newRandomDirection() const;
    void deadAnimation();
    void teleportation();
    void returnToWarpZone();
    void setVulnerable( bool vulnerable );

private:
    int _previousDirection;

};

#endif
