#ifndef FANTOME_H
#define FANTOME_H

#include <sstream>
#include "Personnage.h"

class Ghost : public Personnage {

  public:
    Ghost(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
    void loadSpriteCoord();
    void move();
    bool newRandomDirection() const;
    void stopMove();
    void checkCollision();
    void deadAnimation();
    void teleportation();
    void returnToWarpZone();
    void setVulnerable( bool vulnerable );

};

#endif
