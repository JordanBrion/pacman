#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "InteractiveElement.h"

class Personnage: public InteractiveElement {

protected:
    Personnage(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
public:
    void moveVertically(bool);
    void moveHorizontally(bool);
    virtual void stopMove () = 0;
    virtual void checkCollision () = 0;
    virtual void deadAnimation () = 0;
    virtual void teleportation () = 0;
    virtual void calculateDirection ( std::map<std::string, bool> ) = 0;

protected:
    int _vitesse;
    bool _dead;
    int _spriteFlag;
    std::vector<std::map<std::string, int> > _spriteCoord;
    std::map<std::string, int> _positionForRespawn;
    std::map<std::string, bool> _directionsPossible;
    std::map<std::string, bool> _directionsPossibleAnticipated;

};

#endif
