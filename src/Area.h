#ifndef AREA_H
#define AREA_H

//!
//! \file Area.h
//! \brief Class for the areas rendered on the screen
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Const.h"

//!
//! \class Area
//! \brief Class for the areas rendered on the screen
//!
class Area {

protected:
    //!
    //!  \brief Area constructor
    //!
    Area();
public:
    //!
    //!  \brief Area destructor
    //!
    ~Area();
    //!
    //!  \brief Method to free all the SDL values
    //!
    void free();

protected:
    SDL_Texture* _texture;      /*!< SDL_Texture* containing everything who needed to be rendered */
    SDL_Rect _position;         /*!< SDL_Rect to determine the position on the screen */
    SDL_Rect _selection;        /*!< SDL_Rect to select a part of a sprite */

};

#endif
