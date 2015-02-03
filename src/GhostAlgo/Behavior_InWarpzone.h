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

#include <pm/Chrono.h>

#define     INWARPZONE_DURATION                     3000        //! \def The duration in the Warpzone
#define     INWARPZONE_OFFSETY_MAX                  5           //! \def The maximum offset-y towards the ghost is moving
#define     INWARPZONE_VELOCITY                     1           //! \def The velocity of the ghost in the Warpzone
#define     INWARPZONE_VELOCITY_MODERATOR_MAX       1           //! \def Moderate the velocity of the ghost

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

    /* STATIC ATTRIBUTES */
    static uint8_t instancesCounter;                        /*!< Static attribute to count the instances */

    /* ATTRIBUTES */
private:
    Chrono<Behavior_InWarpzone>* _inWarpZoneChrono;         /*!< Chrono for the duration in the Warpzone */
    uint8_t _velocityModerator;                             /*!< Attribute to moderate the velocity */

};

#endif      /* BEHAVIOR_INWARPZONE_H */
