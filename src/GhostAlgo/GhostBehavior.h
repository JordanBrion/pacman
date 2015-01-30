#ifndef     GHOSTBEHAVIOR_H
#define     GHOSTBEHAVIOR_H

//!
//! \file GhostBehavior.h
//! \brief Abstract Class representing a ghost behavior.
//! \author Jordan Brion
//! \version 0.1
//! \date 30 January 2015
//!

#include <SDL2/SDL.h>

#define     HUNTER                  0       /*!< The ghost is hunting the Pac-Man */
#define     HUNTED                  1       /*!< The ghost is hunted by the Pac-Man */
#define     SHOW_SCORE              2       /*!< The ghost is showing the power-pellet score */
#define     RETURN_TO_WARPZONE      3       /*!< The ghost is returning to the Warpzone */
#define     DEFAULT_WARPZONE        4       /*!< The ghost is in the Warpzone */
#define     ENTER_WARPZONE          5       /*!< The ghost is entering in the Warpzone */
#define     EXIT_WARPZONE           6       /*!< The ghost is exiting the Warpzone */

class PacMan;
class Ghost;

//!
//! \class GhostBehavior
//! \brief Abstract Class representing a ghost behavior.
//!
class GhostBehavior {

    /* METHODS */
public:
    //!
    //! \brief Virtual method to run the behavior
    //!
    virtual void run() = 0;
    //!
    //! \brief Virtual getter for the state of the ghost behavior (see the macro above)
    //! \return The current state of the ghost
    //!
    virtual Uint8 getState() const = 0;

    /* ATTRIBUTES */
protected:
    Ghost* _ghost;          /*!< Pointer on the ghost master */
    PacMan* _pacMan;        /*!< Pointer on the Pac-Man */

};

#endif      /* GHOSTBEHAVIOR_H */
