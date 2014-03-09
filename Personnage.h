#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "InteractiveElement.h"

class Personnage: public InteractiveElement {

protected:
    Personnage(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
public:
    void moveVertically(bool);
    void moveHorizontally(bool);
    void calculateDirection(std::vector<std::vector<int> >);
    bool isCenteredInTheSquareWhenKeyDown();
    bool isCenteredInTheSquareWhenKeyUp();
    void setStepCounter(int, int);
    void calculateOffset(bool);
    void updatePositionInTheGrid();
    void resetValues();
    virtual void stopMove () = 0;
    virtual void checkCollision () = 0;
    virtual void deadAnimation () = 0;
    virtual void teleportation () = 0;

protected:
    int _x;
    int _y;
    int _stepCounter;
    int _offset;
    int _offsetV;
    int _offsetH;
    int _goTo;
    bool _back;
    std::map<std::string, bool> _directionsPossible;
    int _vitesse;
    bool _dead;
    int _spriteFlag;
    std::vector<std::map<std::string, int> > _spriteCoord;
    std::map<std::string, int> _positionForRespawn;

};

#endif
