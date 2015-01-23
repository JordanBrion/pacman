#ifndef     MANAGEMENT_RESETTER_H
#define     MANAGEMENT_RESETTER_H

//!
//! \file Management_Resetter.h
//! \brief Class to manage the game when a reset is required
//! \author Jordan Brion
//! \version 0.1
//! \date 23 January 2015
//!

#include "Management.h"

//!
//! \class Management_Resetter
//! \brief Class to manage the game when a reset is required
//!
class Management_Resetter : public Management {

    /* METHODS */
public:
    //!
    //! \brief Management_Resetter constructor
    //!
    Management_Resetter();
    //!
    //! \brief Management_Resetter destructor
    //!
    ~Management_Resetter();
    //!
    //! \brief Method to manage the current state of the game
    //! \param w : SDL_Window
    //! \return True if the management is correct. Otherwise, false
    //!
    bool manage( Window* const w );

    /* ATTRIBUTES */
private:

};

#endif      /* MANAGEMENT_RESETTER_H */
