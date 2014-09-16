#ifndef FANTOME_H
#define FANTOME_H

//!
//! \file Ghost.h
//! \brief Class to manage a ghost character
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include <sstream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include "Character.h"
#include "PacMan.h"

//!
//! \class Ghost
//! \brief Class to manage a ghost character
//!
class Ghost : public Character {

  public:
    //!
    //!  \brief Ghost constructor
    //!  \param dest : The position where the ghost has to be rendered on the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \param sprite : SDL_Surface* containing the sprite of all the characters
    //!
    Ghost( std::map<std::string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    //!
    //!  \brief Method to load the sprite coordonates of the ghost
    //!
    void loadSpriteCoord();
    //!
    //!  \brief Method to load the sprite coordonates of the ghost when he is eatable
    //!
    void loadSpriteCoordEatable();
    //!
    //!  \brief Method to move the ghost
    //!
    void move();
    //!
    //!  \brief Method to load the next sprite for the ghost animation
    //!  \param direction : The direction towards the ghost is going
    //!
    void nextSprite( int direction );
    //!
    //!  \brief Method to reset the move variables of the character
    //!
    void resetValues();
    //!
    //!  \brief Method to calculate a randomized direction
    //!  \return The randomized direction
    //!
    int newRandomDirection() const;
    //!
    //!  \brief Method to load the death animation of the ghost
    //!  \param pRenderer : SDL_Renderer* of the window
    //!
    void deathAnimation( SDL_Renderer* const& );
    //!
    //!  \brief Method to teleport the ghost in an other part of the level
    //!
    void teleportation();
    //!
    //!  \brief Reset the values of the ghost to the default ones
    //!
    void defaultValues();
    //!
    //!  \brief Method to return the ghost to the warp zone after his death
    //!
    void returnToWarpZone();

private:
    int _previousDirection;                                     /*!< Flag to save the previous direction of the ghost. Because the ghosts are stupid and don't know where they come from. :)  */
    std::vector<std::vector<int> > _spriteCoordEatable;        /*!< Vector for the sprite coordonates when the ghost is eatable by the pacman */

};

#endif
