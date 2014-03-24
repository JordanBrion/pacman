#ifndef CHARACTER_H
#define CHARACTER_H

#include "InteractiveElement.h"

class Character: public InteractiveElement {

protected:
    Character(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
    virtual void loadSpriteCoord() = 0;
    bool moveVertically(bool);
    bool moveHorizontally(bool);
    virtual void deadAnimation(SDL_Renderer* const&) = 0;
    virtual void teleportation() = 0;
    void defaultValues();
public:
    void calculateDirection(std::vector<std::vector<int> >);
    bool isCenteredInTheSquare();
    void setStepCounter(int, int);
    void calculateOffset(bool);
    void updatePositionInTheGrid();
    void resetValues();
    void nextSprite(int);
    bool checkCollision( InteractiveElement* const& ) const;
    bool isDead() const;
    void setDead();

protected:
    int _x;
    int _y;
    int _stepCounter;
    int _offset;
    int _offsetV;
    int _offsetH;
    int _goTo;
    bool _back;
    std::vector<bool> _directionsPossible;
    int _spriteFlag;
    std::vector<std::vector<std::vector<int> > > _spriteCoord;
    int _velocity;
    bool _dead;
    std::map<std::string, int> _positionForRespawn;

};

#endif
