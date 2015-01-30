#ifndef     BEHAVIOR_RETURNTOWARPZONE_H
#define     BEHAVIOR_RETURNTOWARPZONE_H

//!
//! \file Behavior_ReturnToWarpzone.h
//! \brief Class representing the ghost behavior when the ghost has to return to the Warpzone
//! \author Jordan Brion
//! \version 0.1
//! \date 30 January 2015
//!

#include "GhostBehavior.h"

//!
//! \class Behavior_ReturnToWarpzone
//! \brief Class representing the ghost behavior when the ghost has to return to the Warpzone
//!
class Behavior_ReturnToWarpzone : public GhostBehavior {

    /* METHODS */
public:
    //!
    //! \brief Behavior_ReturnToWarpzone constructor
    //! \param master : A pointer on the ghost master
    //! \param pacMan : A pointer on the Pac-Man
    //!
    Behavior_ReturnToWarpzone( Ghost* master,
                               PacMan* pacMan );
    //!
    //! \brief Behavior_ReturnToWarpzone destructor
    //!
    ~Behavior_ReturnToWarpzone();
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

#endif      /* BEHAVIOR_RETURNTOWARPZONE_H */
