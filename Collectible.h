#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include "Const.h"
#include <InteractiveElement.h>

class Collectible : public InteractiveElement {

public:
    Collectible( int const& name, std::map<std::string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    ~Collectible();
    int getType() const;
    void setType( int const& type );
    int getNbr() const;
    void setNbr( int const& nbr );
    void initPositionAreaGame();
    void initPositionAreaBottom();
    void initRect(SDL_Rect rect, int const& w, int const& h, int const& x, int const&  y);

private:
    int _type;
    int _nbr;

};

#endif
