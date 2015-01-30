#ifndef     BEHAVIOR_HUNTED_H
#define     BEHAVIOR_HUNTED_H

//!
//! \file Behavior_Hunted.h
//! \brief Class representing the ghost behavior when the ghost is hunted by the Pac-Man
//! \author Jordan Brion
//! \version 0.1
//! \date 30 January 2015
//!

#include "GhostBehavior.h"

//!
//! \class Behavior_Hunted
//! \brief Class representing the ghost behavior when the ghost is hunted by the Pac-Man
//!
class Behavior_Hunted : public GhostBehavior {

    /* METHODS */
public:
    //!
    //! \brief Behavior_Hunted constructor
    //! \param master : A pointer on the ghost master
    //! \param pacMan : A pointer on the Pac-Man
    //!
    Behavior_Hunted( Ghost* master,
                     PacMan* pacMan );
    //!
    //! \brief Behavior_Hunted destructor
    //!
    ~Behavior_Hunted();
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

#endif      /* BEHAVIOR_HUNTED_H */
