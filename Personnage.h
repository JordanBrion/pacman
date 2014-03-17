#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "InteractiveElement.h"

class Personnage: public InteractiveElement {

protected:
    Personnage(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
    virtual void loadSpriteCoord() = 0;
    bool moveVertically(bool);
    bool moveHorizontally(bool);
    virtual void stopMove() = 0;
    virtual void checkCollision() = 0;
    virtual void deadAnimation() = 0;
    virtual void teleportation() = 0;
public:
    void calculateDirection(std::vector<std::vector<int> >);
    bool isCenteredInTheSquare();
    void setStepCounter(int, int);
    void calculateOffset(bool);
    void updatePositionInTheGrid();
    void resetValues();
    void nextSprite(int);
    bool isDead() const;

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
    int _spriteFlag;
    std::vector<std::vector<std::vector<int> > > _spriteCoord;
    int _vitesse;
    bool _dead;
    std::map<std::string, int> _positionForRespawn;

};

#endif
