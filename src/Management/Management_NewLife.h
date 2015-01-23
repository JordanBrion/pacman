#ifndef     MANAGEMENT_NEWLIFE_H
#define     MANAGEMENT_NEWLIFE_H

//!
//! \file Management_NewLife.h
//! \brief Class to manage the game when the Pac-Man died
//! \author Jordan Brion
//! \version 0.1
//! \date 23 January 2015
//!

#include "Management.h"

//!
//! \class Management_NewLife
//! \brief Class to manage the game when the Pac-Man died
//!
class Management_NewLife : public Management {

    /* METHODS */
public:
    //!
    //! \brief Management_NewLife constructor
    //!
    Management_NewLife();
    //!
    //! \brief Management_NewLife destructor
    //!
    ~Management_NewLife();
    //!
    //! \brief Method to manage the current state of the game
    //! \param w : SDL_Window
    //! \return True if the management is correct. Otherwise, false
    //!
    bool manage( Window* const w );

    /* ATTRIBUTES */
private:

};

#endif      /* MANAGEMENT_NEWLIFE_H */
