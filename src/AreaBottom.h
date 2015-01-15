#ifndef AREABOTTOM_H
#define AREABOTTOM_H

//!
//! \file AreaBottom.h
//! \brief Class for the bottom area. The bottom area contains the number of lifes and the fruit picked up.
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include "Area.h"
#include "InteractiveElements/Fruit.h"
#include "Const.h"

//!
//! \class AreaBottom
//! \brief Class for the bottom area. The bottom area contains the number of lifes and the fruit picked up.
//!
class AreaBottom: public Area {

public:
    //!
    //!  \brief AreaBottom constructor
    //!
    AreaBottom();
    //!
    //!  \brief Method to render the number of lifes to the screen
    //!  \param pRenderer : SDL_Renderer* of the window
    //!  \param pSpriteCharacters : SDL_Surface* containing the sprite of all the characters
    //!  \param pFont : TTF_Font* to render text
    //!  \param pLifesNbr : The number of lifes
    //!
    void drawLifesPanel( SDL_Renderer* const& pRenderer, SDL_Surface* const& pSpriteCharacters, TTF_Font* const& pFont, int const& pLifesNbr );
    //!
    //!  \brief Method to render the number of fruit picked up to the screen
    //!  \param pRenderer : SDL_Renderer* of the window
    //!  \param pSpriteCharacters : SDL_Surface* containing the sprite of all the characters
    //!  \param pFont : TTF_Font* to render text
    //!  \param pFruit : Vector containing all the fruit picked up
    //!
    void drawFruitPanel( SDL_Renderer* const& pRenderer, SDL_Surface* const& pSpriteCharacters, TTF_Font* const& pFont, std::vector<Fruit*> pFruit );

};

#endif
