#ifndef     BEHAVIOR_SHOWSCORE_H
#define     BEHAVIOR_SHOWSCORE_H

//!
//! \file Behavior_ShowScore.h
//! \brief Class representing the ghost behavior when the power-pellet score has to be rendered
//! \author Jordan Brion
//! \version 0.1
//! \date 30 January 2015
//!

#include "GhostBehavior.h"

//!
//! \class Behavior_ShowScore
//! \brief Class representing the ghost behavior when the power-pellet score has to be rendered
//!
class Behavior_ShowScore : public GhostBehavior {

    /* METHODS */
public:
    //!
    //! \brief Behavior_ShowScore constructor
    //! \param master : A pointer on the ghost master
    //! \param pacMan : A pointer on the Pac-Man
    //!
    Behavior_ShowScore( Ghost* master,
                        PacMan* pacMan );
    //!
    //! \brief Behavior_ShowScore destructor
    //!
    ~Behavior_ShowScore();
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

#endif      /* BEHAVIOR_SHOWSCORE_H */
