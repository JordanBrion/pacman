#ifndef BUBBLESMANAGER_H
#define BUBBLESMANAGER_H

#include <vector>
#include "PacDotsCase.h"

class PacDotsManager {

public:
    PacDotsManager( std::vector<std::vector<int> > level, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    ~PacDotsManager();
    void addRow();
    void addCase( int const& row, int const& type, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    int render( SDL_Renderer* const& renderer );
    PacDot* isThereAPacDot( int const& row, int const& col, int const& x, int const& y );
    void eatPacDot( int const& row, int const& col, int const& x, int const& y );

private:
    std::vector<std::vector<PacDotsCase*> > _pacDotsCases;

};

#endif
