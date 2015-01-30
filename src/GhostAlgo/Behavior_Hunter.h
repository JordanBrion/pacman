#ifndef     BEHAVIOR_HUNTER_H
#define     BEHAVIOR_HUNTER_H

//!
//! \file Behavior_Hunter.h
//! \brief Class representing the ghost behavior when the ghost is hunting the Pac-Man
//! \author Jordan Brion
//! \version 0.1
//! \date 30 January 2015
//!

#include "GhostBehavior.h"

//!
//! \class Behavior_Hunter
//! \brief Class representing the ghost behavior when the ghost is hunting the Pac-Man
//!
class Behavior_Hunter : public GhostBehavior {

    /* METHODS */
public:
    //!
    //! \brief Behavior_Hunter constructor
    //! \param master : A pointer on the ghost master
    //! \param pacMan : A pointer on the Pac-Man
    //!
    Behavior_Hunter( Ghost* master,
                     PacMan* pacMan );
    //!
    //! \brief Behavior_Hunter destructor
    //!
    ~Behavior_Hunter();
    //!
    //! \brief Method to run the behavior
    //!
    void run();
    //!
    //! \brief Getter for the state of the ghost behavior (see the macro above)
    //! \return The current state of the ghost
    //!
    Uint8 getState() const;

    /* ATTRIBUTES */
private:

};

#endif      /* BEHAVIOR_HUNTER_H */
