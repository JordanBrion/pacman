#ifndef AREATOP_H
#define AREATOP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <map>
#include "Area.h"
#include "Const.h"

class AreaTop: public Area {

public:
    AreaTop();
    void drawArea( SDL_Renderer* const pRenderer, TTF_Font* const& pFont, int const& pHightScore, int const& pScoreP1, int const& pScoreP2 );
    void drawHighScore( SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, int const& pHighScore );
    void drawPlayerOneScore( SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, int const& pScore );
    void drawPlayerTwoScore( SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, int const& pScore );
    int scoreTextureWidth(int pScore);
    const char* convertIntToChar(int const& pScore);
    void initPositionText(int const& w, int const& h, int const& x, int const& y);
    void drawText(SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, const char* pText, SDL_Color pColor);

};

#endif
