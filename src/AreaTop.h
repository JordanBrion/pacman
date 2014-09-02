#ifndef AREATOP_H
#define AREATOP_H

//!
//! \file AreaTop.h
//! \brief Class for the top area. The top area contains the scores and the highscore.
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <map>
#include "Area.h"
#include "Const.h"

//!
//! \class AreaTop
//! \brief Class for the top area. The top area contains the scores and the highscore.
//!
class AreaTop: public Area {

public:

    //!
    //!  \brief AreaTop constructor
    //!
    AreaTop();
    //!
    //!  \brief Method to render the complete area
    //!  \param pRenderer : SDL_Renderer* of the window
    //!  \param pFont : TTF_Font* to render text
    //!  \param pHighScore : The best score of all time
    //!  \param pScore1 : The score of the player 1
    //!  \param pScore2 : The score of the player 2
    //!
    void drawArea( SDL_Renderer* const pRenderer, TTF_Font* const& pFont, int const& pHightScore, int const& pScoreP1, int const& pScoreP2 );
    //!
    //!  \brief Method to render the highscore
    //!  \param pRenderer : SDL_Renderer* of the window
    //!  \param pFont : TTF_Font* to render text
    //!  \param pHighScore : The score to render
    //!
    void drawHighScore( SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, int const& pHighScore );
    //!
    //!  \brief Method to render the score of the player 1
    //!  \param pRenderer : SDL_Renderer* of the window
    //!  \param pFont : TTF_Font* to render text
    //!  \param pScore : The score to render
    //!
    void drawPlayerOneScore( SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, int const& pScore );
    //!
    //!  \brief Method to render the score of the player 2
    //!  \param pRenderer : SDL_Renderer* of the window
    //!  \param pFont : TTF_Font* to render text
    //!  \param pScore : The score to render
    //!
    void drawPlayerTwoScore( SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, int const& pScore );
    //!
    //!  \brief Method to calculate the width of the texture
    //!  \param pScore : The score needed to calculate the width of the texture.
    //!
    int scoreTextureWidth(int pScore);
    //!
    //!  \brief Method to convert int to char
    //!  \param pScore : The score to be converted
    //!  \return The integer converted in char
    //!
    const char* convertIntToChar(int const& pScore);
    //!
    //!  \brief Method to initialize the position where the text has to be rendered
    //!  \param w : The width
    //!  \param h : The height
    //!  \param x : The x position
    //!  \param y : The y position
    //!
    void initPositionText(int const& w, int const& h, int const& x, int const& y);
    //!
    //!  \brief Method to draw the text in a texture
    //!  \param pRenderer : SDL_Renderer* of the window
    //!  \param pFont : TTF_Font* to render text
    //!  \param pText : The text to render
    //!  \param pColor : The SDL_Color of the text
    //!
    void drawText(SDL_Renderer* const& pRenderer, TTF_Font* const& pFont, const char* pText, SDL_Color pColor);

};

#endif
