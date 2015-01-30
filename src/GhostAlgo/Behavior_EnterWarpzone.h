#ifndef     BEHAVIOR_ENTERWARPZONE_H
#define     BEHAVIOR_ENTERWARPZONE_H

//!
//! \file Behavior_EnterWarpzone.h
//! \brief Class representing the ghost behavior when the ghost is entering in the Warpzone
//! \author Jordan Brion
//! \version 0.1
//! \date 30 January 2015
//!

#include "GhostBehavior.h"

//!
//! \class Behavior_EnterWarpzone
//! \brief Class representing the ghost behavior when the ghost is entering in the Warpzone
//!
class Behavior_EnterWarpzone : public GhostBehavior {

    /* METHODS */
public:
    //!
    //! \brief Behavior_EnterWarpzone constructor
    //! \param master : A pointer on the ghost master
    //! \param pacMan : A pointer on the Pac-Man
    //!
    Behavior_EnterWarpzone( Ghost* master,
                            PacMan* pacMan );
    //!
    //! \brief Behavior_EnterWarpzone destructor
    //!
    ~Behavior_EnterWarpzone();
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

#endif      /* BEHAVIOR_ENTERWARPZONE_H */
