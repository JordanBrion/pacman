#ifndef AREATOP_H
#define AREATOP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Area.h"
#include "Const.h"

class AreaTop: public Area {

public:
    AreaTop();
    void drawArea ( SDL_Renderer* const pRenderer, TTF_Font* const& pFont );
    void drawHighScore ( int const& highscore );
    void drawPlayerOneScore ( int const& score );
    void drawPlayerTwoScore ( int const& score );

};

#endif
