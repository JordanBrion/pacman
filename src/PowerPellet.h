#ifndef POWERPELLET_H
#define POWERPELLET_H

//!
//! \file PowerPellet.h
//! \brief Class of a power-pellet. A power-pellet is a pac-dot given to pacman the ability to eat ghosts.
//! \author Jordan Brion
//! \version 0.1
//! \date 27 september 2014
//!

#include "PacDot.h"

//!
//! \class PowerPellet.
//! \brief Class of a power-pellet. A power-pellet is a pac-dot given to pacman the ability to eat ghosts.
//!
class PowerPellet : public PacDot {

    /* METHODS */
public:
    //!
    //!  \brief PowerPellet constructor
    //!  \param dest : The location where the pac-dot has to be rendered to the screen
    //!  \param type : The type of the case where the pac-dot is located
    //!  \param x : The x coordonate of the pac-dot on the screen
    //!  \param y : The y coordonate of the pac-dot on the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \param sprite : SDL_Surface* containing the sprite of all the characters (and also the pac-dot)
    //!
    PowerPellet( std::map<std::string, int> dest, int type, int x, int y, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    //!
    //!  \brief PowerPellet destructor
    //!
    ~PowerPellet();
private:
    //!
    //! \brief Method to blink to power-pellet to the screen
    //! \return True if the power-pellet has to blink. Otherwise, false
    //!
    bool blink();
    //!
    //! \brief Method to reset the blink chronometer
    //!
    void resetBlinkChrono();
public:
    //!
    //!  \brief Method to render the power-pellet to the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \return The points of the power-pellet if the power-pellet has not been eaten
    //!
    int show( SDL_Renderer * const &renderer );


    /* ATTRIBUTES */
private:
    static const Uint16 POWERPOWER_BLINK_DURATION = 1000;           /*!< Static attribute for the blink duration */
    Uint32 _blinkChrono;                                            /*!< Blink chronometer */

};

#endif /* POWERPELLET_H */
