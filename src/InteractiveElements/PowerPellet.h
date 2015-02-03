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

#include <pm/Chrono.h>

#define     POWERPELLET_DURATION                5000   //! \def The duration of the power pellet chronometer
#define     POWERPELLET_BLINK_DURATION          1000   //! \def The blink duration
#define     POWERPELLET_BLINK_BETWEEN_DURATION  1000   //! \def The duration between blink
#define     POWERPELLET_MULTIPLICATOR           2      //! \def Power-pellet multiplicator

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
    //!  \param selection : Selection on the sprite
    //!  \param position : Position on the screen
    //!  \param sprite : SDL_Texture* containing the sprite of all the characters (and also the pac-dot)
    //!
    PowerPellet( std::map<std::string, int>& dest,
                 const int& type,
                 const SDL_Rect& selection,
                 const SDL_Rect& position,
                 SDL_Texture* const& sprite );
    //!
    //!  \brief PowerPellet destructor
    //!
    ~PowerPellet();
    //!
    //!  \brief Method to render the power-pellet to the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \return The points of the power-pellet if the power-pellet has not been eaten
    //!
    virtual int show( SDL_Renderer* const& renderer );
    //!
    //! \brief Static method to blink to power-pellet to the screen
    //! \return True if the power-pellet has to blink. Otherwise, false
    //!
    static bool blink();

    /* STATIC ATTRIBUTES */
public:
    static Chrono<PowerPellet>* blinkChrono;            /*!< Chrono for blink duration */
    static Chrono<PowerPellet>* betweenBlinkChrono;     /*!< Chrono for duration between 2 blinks */

    /* ATTRIBUTES */
private:

};

#endif /* POWERPELLET_H */
