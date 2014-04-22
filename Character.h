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
    void updatePositionInTheGrid();
    void resetValues();
    void nextSprite(int);
    bool checkCollision( InteractiveElement* const& ) const;
    bool isDead() const;
    void setDead();

protected:
    int _initialRow;
    int _initialCol;
    std::map<std::string, int> _initialStateSrc; // Initial coord on the sprite
    std::map<std::string, int> _initialStateDest; // Coord on the screen at the start of the game
    int _stepCounter;
    int _goTo;
    bool _back;
    std::vector<bool> _directionsPossible;
    int _spriteFlag;
    std::vector<std::vector<std::vector<int> > > _spriteCoord;
    int _velocity;
    int _velocityX;
    int _velocityY;
    bool _dead;
    std::map<std::string, int> _positionForRespawn;

};

#endif
