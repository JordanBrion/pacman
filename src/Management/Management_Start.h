#ifndef     MANAGEMENT_START_H
#define     MANAGEMENT_START_H

//!
//! \file Management_Start.h
//! \brief Class to manage the game when the game starts
//! \author Jordan Brion
//! \version 0.1
//! \date 23 January 2015
//!

#include "Management.h"

//!
//! \class Management_Start
//! \brief Class to manage the game when the game starts
//!
class Management_Start : public Management {

    /* METHODS */
public:
    //!
    //! \brief Management_Start constructor
    //!
    Management_Start();
    //!
    //! \brief Management_Start destructor
    //!
    ~Management_Start();
    //!
    //! \brief Method to manage the current state of the game
    //! \param w : SDL_Window
    //! \return True if the management is correct. Otherwise, false
    //!
    bool manage( Window* const w );

    /* ATTRIBUTES */
private:

};

#endif      /* MANAGEMENT_START_H */
