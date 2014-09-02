#ifndef AREAGAME_H
#define AREAGAME_H

//!
//! \file AreaGame.h
//! \brief Class for the game area. The game area contains the level and the characters.
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <map>
#include <string>
#include "Area.h"
#include "Const.h"

//!
//! \class AreaGame
//! \brief Class for the game area. The game area contains the level and the characters.
//!
class AreaGame: public Area {

public:
    //!
    //!  \brief AreaGame constructor
    //!  \param pRenderer : SDL_Renderer* of the window
    //!  \param pSpriteLevel : SDL_Surface* containing the sprite of the level parts
    //!
    AreaGame( SDL_Renderer* const& pRenderer, SDL_Surface* const& pSpriteLevel );
    //!
    //!  \brief Method to render the game area
    //!  \param pRenderer : SDL_Renderer* of the window
    //!  \param pRowsNbr : The number of rows in the level
    //!  \param pColsNbr : The number of columns in the level
    //!  \param pLevelTable : Array containing the level in the form of caracters
    //!  \param pLevelSpriteCoord : Array containing the coordinates of the level sprite
    //!
    void drawArea(SDL_Renderer* const& pRenderer,
                  int const& pRowsNbr, int const& pColsNbr,
                  std::vector<std::vector<int> > pLevelTable, std::vector<std::map<std::string, int> > pLevelSpriteCoord);

};

#endif
