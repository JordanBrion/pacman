#ifndef INTERACTIVEELEMENT_H
#define INTERACTIVEELEMENT_H

//!
//! \file InteractiveElement.h
//! \brief Abstract class to manage an interactive element (pac-man, ghost, fruit...)
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include "Const.h"

//!
//! \class InteractiveElement
//! \brief Abstract class to manage an interactive element (pac-man, ghost, fruit...)
//!
class InteractiveElement {

protected:
    //!
    //!  \brief InteractiveElement constructor
    //!  \param renderer : SDL_Renderer* of the window
    //!  \param sprite : SDL_Surface* containing the sprite of all the characters
    //!
    InteractiveElement( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    //!
    //!  \brief InteractiveElement constructor
    //!  \param dest : The position where the ghost has to be rendered on the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \param sprite : SDL_Surface* containing the sprite of all the characters
    //!
    InteractiveElement( std::map<std::string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
public:
    //!
    //!  \brief Method to render the element to the screen
    //!  \param pRenderer : SDL_Renderer* of the window
    //!
    void show(SDL_Renderer* const& pRenderer);
    //!
    //!  \brief Method to select the element on the sprite
    //!  \param w : The width
    //!  \param h : The height
    //!  \param x : The x position
    //!  \param y : The y position
    //!
    void initRect(SDL_Rect* rect, int const& w, int const& h, int const& x, int const&  y);
    //!
    //!  \brief Getter for the row of the element in the grid
    //!  \return The row of the element in the grid
    //!
    int getRow() const;
    //!
    //!  \brief Getter for the column of the element in the grid
    //!  \return The column of the element in the grid
    //!
    int getCol() const;
    //!
    //!  \brief Getter for the position of the element in the area game
    //!  \return The position of the element in the area game
    //!
    SDL_Rect getPosition() const;
    //!
    //!  \brief Getter for the selection of the element in the sprite
    //!  \return The selection of the element in the sprite
    //!
    SDL_Rect getSelection() const;

protected:
    int _row;                       /*!< The row of the element in the grid */
    int _col;                       /*!< The column of the element in the grid */
    SDL_Texture* _element;          /*!< Texture of the element */
    SDL_Rect _position;             /*!< Position of the element in the area game */
    SDL_Rect _selection;            /*!< Selection of the element in the sprite */
    int _zIndex;                    /*!< z-index of the element */
public:
    static int zIndexCounter;       /*!< Static varible to count the number of elements */

};

#endif
