#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include "Const.h"
#include <InteractiveElement.h>

class Fruit : public InteractiveElement {

public:
    Fruit( int const& name, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    ~Fruit();
    int getType() const;
    void setType( int const& type );
    int getNbr() const;
    void setNbr( int const& nbr );
    int getPoints() const;
    void initPositionAreaGame();
    void initPositionAreaBottom();

private:
    int _type;
    int _nbr;
    int _points;

};

#endif
