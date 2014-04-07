#ifndef AREABOTTOM_H
#define AREABOTTOM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Area.h"
#include "Const.h"

class AreaBottom: public Area {

public:
    AreaBottom ( SDL_Renderer* const& pRenderer, SDL_Surface* const& pSpriteCharacters );
    void drawArea ( SDL_Renderer* const& pRenderer, SDL_Surface* const& pSpriteCharacters );
    void drawLifesPanel ( int const& lifesNbr );
    void drawFruitsPanel ( std::vector<int> fruits );

};

#endif
