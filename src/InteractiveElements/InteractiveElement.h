#ifndef INTERACTIVEELEMENT_H
#define INTERACTIVEELEMENT_H

//!
//! \file InteractiveElement.h
//! \brief Abstract class to manage an interactive element (pac-man, ghost, fruit...)
//! \author Jordan Brion
//! \version 0.1
//! \date 15 January 2015
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

#include "../Const.h"
#include "../Surfaces/SurfaceSelection.h"

//!
//! \class InteractiveElement
//! \brief Abstract class to manage an interactive element (pac-man, ghost, fruit...)
//!
class InteractiveElement {

    /* METHODS */
protected:
    //!
    //! \brief InteractiveElement default constructor
    //!
    InteractiveElement();
    //!
    //!  \brief InteractiveElement constructor
    //!  \param dest : The position where the ghost has to be rendered on the screen
    //!
    InteractiveElement( std::map<std::string, int>& dest );
public:
    //!
    //!  \brief Method to render the element to the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!
    void show( SDL_Renderer* const& renderer);
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
    //! \brief Getter for the SurfaceSelection instance
    //! \return The SurfaceSelection instance
    //!
    SurfaceSelection* getSurface() const;
    //!
    //! \brief Getter for the selection of the element
    //! \return Selection of the _surface attribute
    //!
    SDL_Rect getSelection() const;
    //!
    //! \brief Getter for the position of the element
    //! \return Position of the _surface attribute
    //!
    SDL_Rect getPosition() const;
    //!
    //! \brief Getter for the _instanceID attribute
    //! \return The _instanceID attribute
    //!
    Uint16 getInstanceID() const;

    /* STATIC ATTRIBUTES */
public:
    static Uint16 instancesCounter;     /*!< Static varible to count the number of elements */

    /* ATTRIBUTES */
protected:
    int _row;                           /*!< The row of the element in the grid */
    int _col;                           /*!< The column of the element in the grid */
    SurfaceSelection* _surface;         /*!< SurfaceSelection instance for :
                                                - selection on the sprite
                                                - position on the screen
                                                */
    Uint16 _instanceID;                 /*!< ID of the element */

};

#endif
