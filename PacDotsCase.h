#ifndef BUBBLESCASE_H
#define BUBBLESCASE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <iostream>
#include "PacDot.h"

class PacDotsCase {

public:
    PacDotsCase( int const& row, int const& col, int const& type, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    ~PacDotsCase();
    int getType() const;
    void setType( int const& type );
    int render( SDL_Renderer* const& renderer );
    std::vector<PacDot*> getPacDots() const;
    PacDot* getPacDot ( int const& x, int const& y ) const;
    void reinitPacDotsEaten();
    void setPacDotEaten( int const& x, int const& y, bool eaten );
    void initPacDotsInLine( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    void initPacDotsInAngle( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    void initPacDotsWithThreeJunctions( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    void initPacDotsWithFourJunctions( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );

private:
    int _row;
    int _col;
    bool _empty;
    int _type;
    std::vector<PacDot*> _pacDots;

};

#endif
