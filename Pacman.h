#ifndef PACMAN_H
#define PACMAN_H

#include "Character.h"

class Pacman : public Character {

public:
    Pacman(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
    ~Pacman();
    void loadSpriteCoord();
    void moveVertically(bool);
    void moveHorizontally(bool);
    bool isCenteredInTheSquareWhenKeyUp();
    void deadAnimation(SDL_Renderer* const&);
    int getDeadAnimationCounter() const;
    void teleportation();
    void defaultValues();

private:
    int _deadAnimationCounter;
    bool _superPower;

};

#endif
