#ifndef BUBBLESMANAGER_H
#define BUBBLESMANAGER_H

//!
//! \file PacDotsManager.h
//! \brief Class to manage all the pac-dots cases and the pac-dots.
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include <vector>
#include "PacDotsCase.h"

//!
//! \class PacDotsManager
//! \brief Class to manage all the pac-dots cases and the pac-dots.
//!
class PacDotsManager {

public:
    //!
    //!  \brief PacDotsManager constructor
    //!  \param level : Array containing the level in the form of numbers
    //!  \param sprite : SDL_Texture* containing the sprite of all the characters (and also the pac-dot)
    //!
    PacDotsManager( std::vector<std::vector<int> > level,
                    SDL_Texture* const& sprite );
    //!
    //!  \brief PacDotsManager destructor
    //!
    ~PacDotsManager();
    //!
    //!  \brief Method to add a new row in _pacDotsCases (it is an empty vector)
    //!
    void addRow();
    //!
    //!  \brief Method to add a new case in _pacDotsCases
    //!  \param row : The row in _pacDotsCases
    //!  \param type : The type of the case
    //!  \param sprite : SDL_Texture* containing the sprite of all the characters (and also the pac-dot)
    //!
    void addCase( int const& row,
                  int const& type,
                  SDL_Texture* const& sprite );
    //!
    //!  \brief Method to render all the pac-dots to the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \return The cumulated points of all the non-eaten pac-dots in all the cases
    //!
    int render( SDL_Renderer* const& renderer );
    //!
    //!  \brief Method to check if there is a pac-dot at the position of pac-man
    //!  \param row : The row in _pacDotsCases
    //!  \param col : The column in _pacDotsCases
    //!  \param x : The x position on the screen
    //!  \param y : The y position on the screen
    //!  \return The pac-dot at the position of the pac-man
    //!
    PacDot* isThereAPacDot( int const& row, int const& col,
                            int const& x, int const& y );
    //!
    //!  \brief Method to eat a pac-dot
    //!  \param row : The row in _pacDotsCases
    //!  \param col : The column in _pacDotsCases
    //!  \param x : The x position on the screen
    //!  \param y : The y position on the screen
    //!  \return True if the pacman ate a power pellet. Otherwise, false.
    //!
    bool eatPacDot( int const& row, int const& col,
                    int const& x, int const& y );
    //!
    //! \brief Method to reinitialize all the pac-dots
    //!
    void reinitAllPacDotsEaten();

private:
    std::vector<std::vector<PacDotsCase*> > _pacDotsCases;      /*!< Array containing all the pac-dots cases */

};

#endif
