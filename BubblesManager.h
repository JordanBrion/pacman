#ifndef BUBBLESMANAGER_H
#define BUBBLESMANAGER_H

#include <vector>
#include "BubblesCase.h"

class BubblesManager {

public:
    BubblesManager( std::vector<std::vector<int> > level, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    ~BubblesManager();
    void addRow();
    void addCase( int const& row, int const& type, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    void render( std::vector<std::vector<int> > level, SDL_Renderer* const& renderer );
    Bubble* isThereABubble( int const& row, int const& col, int const& x, int const& y );
    void eatBubble( int const& row, int const& col, int const& x, int const& y );

private:
    std::vector<std::vector<BubblesCase*> > _bubblesCases;

};

#endif
