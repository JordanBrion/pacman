#ifndef     BEHAVIOR_INWARPZONE_H
#define     BEHAVIOR_INWARPZONE_H

//!
//! \file Behavior_InWarpzone.h
//! \brief Class representing the ghost behavior when the ghost is in the Warpzone
//! \author Jordan Brion
//! \version 0.1
//! \date 30 January 2015
//!

#include "GhostBehavior.h"

//!
//! \class Behavior_InWarpzone
//! \brief Class representing the ghost behavior when the ghost is in the Warpzone
//!
class Behavior_InWarpzone : public GhostBehavior {

    /* METHODS */
public:
    //!
    //! \brief Behavior_InWarpzone constructor
    //! \param master : A pointer on the ghost master
    //! \param pacMan : A pointer on the Pac-Man
    //!
    Behavior_InWarpzone( Ghost* master,
                         PacMan* pacMan );
    //!
    //! \brief Behavior_InWarpzone destructor
    //!
    ~Behavior_InWarpzone();
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

#endif      /* BEHAVIOR_INWARPZONE_H */
