#ifndef AREABOTTOM_H
#define AREABOTTOM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include "Area.h"
#include "Collectible.h"
#include "Const.h"

class AreaBottom: public Area {

public:
    AreaBottom();
    void drawLifesPanel( SDL_Renderer* const& pRenderer, SDL_Surface* const& pSpriteCharacters, TTF_Font* const& pFont, int const& pLifesNbr );
    void drawCollectiblesPanel( SDL_Renderer* const& pRenderer, SDL_Surface* const& pSpriteCharacters, TTF_Font* const& pFont, std::vector<Collectible*> pCollectibles );

};

#endif
