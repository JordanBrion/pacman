#ifndef     MANAGEMENT_PAUSE_H
#define     MANAGEMENT_PAUSE_H

//!
//! \file Management_Pause.h
//! \brief Class to manage the game when a pause is required
//! \author Jordan Brion
//! \version 0.1
//! \date 23 January 2015
//!

#include "Management.h"

//!
//! \class Management_Pause
//! \brief Class to manage the game when a pause is required
//!
class Management_Pause : public Management {

    /* METHODS */
public:
    //!
    //! \brief Management_Pause constructor
    //!
    Management_Pause();
    //!
    //! \brief Management_Pause destructor
    //!
    ~Management_Pause();
    //!
    //! \brief Method to manage the current state of the game
    //! \param w : SDL_Window
    //! \return True if the management is correct. Otherwise, false
    //!
    bool manage( Window* const w );

    /* ATTRIBUTES */
private:

};

#endif      /* MANAGEMENT_PAUSE_H */
