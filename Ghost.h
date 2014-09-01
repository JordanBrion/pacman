#ifndef FANTOME_H
#define FANTOME_H

#include <sstream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include "Character.h"
#include "PacMan.h"

class Ghost : public Character {

  public:
    Ghost(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
    void loadSpriteCoord();
    void move();
    void resetValues();
    int newRandomDirection() const;
    void deathAnimation(SDL_Renderer* const&);
    void teleportation();
    void defaultValues();
    void returnToWarpZone();
    void setVulnerable( bool vulnerable );

private:
    int _previousDirection;

};

#endif
