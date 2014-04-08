#include "AreaTop.h"

AreaTop::AreaTop() {}

void AreaTop::drawArea( SDL_Renderer* const pRenderer, TTF_Font* const& pFont,
                        int const& pHightScore, int const& pScoreP1, int const& pScoreP2 ) {

    drawPlayerOneScore(pScoreP1);
    drawHighScore(pHightScore);
    drawPlayerTwoScore(pScoreP2);

}

void AreaTop::drawHighScore ( int const& highscore ) {}

void AreaTop::drawPlayerOneScore ( int const& score ) {}

void AreaTop::drawPlayerTwoScore ( int const& score ) {}
