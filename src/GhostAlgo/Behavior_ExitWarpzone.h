#ifndef     BEHAVIOR_EXITWARPZONE_H
#define     BEHAVIOR_EXITWARPZONE_H

//!
//! \file Behavior_ExitWarpzone.h
//! \brief Class representing the ghost behavior when the ghost is exiting in the Warpzone
//! \author Jordan Brion
//! \version 0.1
//! \date 30 January 2015
//!

#include "GhostBehavior.h"

#define     EXIT_WARPZONE_VELOCITY      1

//!
//! \class Behavior_ExitWarpzone
//! \brief Class representing the ghost behavior when the ghost is exiting in the Warpzone
//!
class Behavior_ExitWarpzone : public GhostBehavior {

    /* METHODS */
public:
    //!
    //! \brief Behavior_ExitWarpzone constructor
    //! \param master : A pointer on the ghost master
    //! \param pacMan : A pointer on the Pac-Man
    //!
    Behavior_ExitWarpzone( Ghost* master,
                           PacMan* pacMan );
    //!
    //! \brief Behavior_ExitWarpzone destructor
    //!
    ~Behavior_ExitWarpzone();
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

#endif      /* BEHAVIOR_EXITWARPZONE_H */
