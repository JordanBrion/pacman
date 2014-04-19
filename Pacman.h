#ifndef PACMAN_H
#define PACMAN_H

#include "Character.h"
#include "BubblesManager.h"

class Pacman : public Character {

public:
    Pacman(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
    ~Pacman();
    void loadSpriteCoord();
    void handleEvent(SDL_Event const&, std::vector<std::vector<int> >);
    void moveVertically(bool);
    void moveHorizontally(bool);
    bool isCenteredInTheSquareWhenKeyUp();
    void checkCollisionWithBubbles( BubblesManager* bm );
    void deadAnimation(SDL_Renderer* const&);
    int getDeadAnimationCounter() const;
    void teleportation();
    void defaultValues();

private:
    int _deadAnimationCounter;
    bool _superPower;
    bool _stopKeyUp;

};

#endif
