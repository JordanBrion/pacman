#ifndef BUBBLESCASE_H
#define BUBBLESCASE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <iostream>
#include "Bubble.h"

class BubblesCase {

public:
    BubblesCase( int const& row, int const& col, int const& type, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    ~BubblesCase();
    int getType() const;
    void setType( int const& type );
    int render( SDL_Renderer* const& renderer );
    std::vector<Bubble*> getBubbles() const;
    Bubble* getBubble ( int const& x, int const& y ) const;
    void reinitBubblesEaten();
    void setBubbleEaten( int const& x, int const& y, bool eaten );
    void initBubblesInLine( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    void initBubblesInAngle( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    void initBubblesWithThreeJunctions( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    void initBubblesWithFourJunctions( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );

private:
    int _row;
    int _col;
    bool _empty;
    int _type;
    std::vector<Bubble*> _bubbles;

};

#endif
