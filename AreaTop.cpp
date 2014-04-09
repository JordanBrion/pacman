#include "AreaTop.h"

using namespace std;

AreaTop::AreaTop() {}

void AreaTop::drawArea( SDL_Renderer* const pRenderer, TTF_Font* const& pFont,
                        int const& pHightScore, int const& pScoreP1, int const& pScoreP2 ) {

    drawHighScore(pRenderer, pFont, pHightScore);
    drawPlayerOneScore(pRenderer, pFont, pScoreP1);
    drawPlayerTwoScore(pRenderer, pFont, pScoreP2);

}

void AreaTop::drawHighScore( SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, int const& pHighScore ) {

    // Render text "High Score"
    drawText(pRenderer, pFont, "High Score", SDL_WHITE);

    initPositionText(
                150,
                60,
                375,
                20);

    SDL_RenderCopy( pRenderer, _texture, NULL, &_position );

    // Render the High Score number
    drawText(pRenderer, pFont, convertIntToChar(pHighScore), SDL_WHITE);

    initPositionText(
                20 + scoreTextureWidth(pHighScore),
                20,
                900 / 2 + 60 - scoreTextureWidth(pHighScore),
                _position.y + _position.h - 10);

    SDL_RenderCopy( pRenderer, _texture, NULL, &_position );

}

void AreaTop::drawPlayerOneScore( SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, int const& pScore ) {

    // Render text "1UP"
    drawText(pRenderer, pFont, "1UP", SDL_WHITE);

    initPositionText(
                60,
                40,
                170,
                25);

    SDL_RenderCopy( pRenderer, _texture, NULL, &_position );

    // Render the Player 1 Score number
    drawText(pRenderer, pFont, convertIntToChar(pScore), SDL_WHITE);

    initPositionText(
                20 + scoreTextureWidth(pScore),
                20,
                _position.x + 40 - scoreTextureWidth(pScore),
                _position.y + _position.h - 8);

    SDL_RenderCopy( pRenderer, _texture, NULL, &_position );

}

void AreaTop::drawPlayerTwoScore( SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, int const& pScore ) {

    // Render text "2UP"
    drawText(pRenderer, pFont, "2UP", SDL_WHITE);

    initPositionText(
                60,
                40,
                650,
                25);

    SDL_RenderCopy( pRenderer, _texture, NULL, &_position );

    // Render the Player 2 Score number
    drawText(pRenderer, pFont, convertIntToChar(pScore), SDL_WHITE);

    initPositionText(
                20 + scoreTextureWidth(pScore),
                20,
                _position.x + 40 - scoreTextureWidth(pScore),
                _position.y + _position.h - 8);

    SDL_RenderCopy( pRenderer, _texture, NULL, &_position );

}

int AreaTop::scoreTextureWidth(int pScore) {

    int width = 0;

    while( pScore > 9 ) {

        pScore /= 10;
        width += 20;

    }

    return width;

}

const char* AreaTop::convertIntToChar(int const& pScore) {

    string s = to_string(pScore);
    char const *c = s.c_str();

    return c;

}

void AreaTop::initPositionText(int const& w, int const& h, int const& x, int const& y) {

    _position.w = w;
    _position.h = h;
    _position.x = x;
    _position.y = y;

}

void AreaTop::drawText(SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, const char* pText, SDL_Color pColor) {

    SDL_Surface* textSurface = TTF_RenderText_Solid( pFont, pText, pColor );
    _texture = SDL_CreateTextureFromSurface( pRenderer, textSurface );
    SDL_FreeSurface(textSurface);

}
