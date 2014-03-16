#ifndef FANTOME_H
#define FANTOME_H

#include <sstream>
#include "Personnage.h"

class Ghost : public Personnage {

  public:
    Ghost(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
    void loadSpriteCoord();
    void move();
    void moveVertically(bool);
    void moveHorizontally(bool);
    void stopMove();
    void checkCollision();
    void deadAnimation();
    void teleportation();
    void calculateDirection(std::map<std::string, bool>);
    void returnToWarpZone();
    void setVulnerable( bool vulnerable );

};

#endif
