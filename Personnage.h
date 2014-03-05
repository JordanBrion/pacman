#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "InteractiveElement.h"

class Personnage: public InteractiveElement {

protected:
    int _vitesse;
    bool _dead;
    std::map<std::string, int> _positionForRespawn;
    std::map<std::string, bool> _directionsPossible;
    std::map<std::string, bool> _directionsPossibleAnticipated;

protected:
    virtual void move () = 0;
    virtual void stopMove () = 0;
    virtual void checkCollision () = 0;
    virtual void deadAnimation () = 0;
    virtual void teleportation () = 0;
    virtual void calculateDirection ( std::map<std::string, bool> ) = 0;

};

#endif
