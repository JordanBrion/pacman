#ifndef     MANAGEMENT_INGAME_H
#define     MANAGEMENT_INGAME_H

//!
//! \file Management_InGame.h
//! \brief Class to manage the game when the user is playing
//! \author Jordan Brion
//! \version 0.1
//! \date 23 January 2015
//!

#include "Management.h"

//!
//! \class Management_InGame
//! \brief Class to manage the game when the user is playing
//!
class Management_InGame : public Management {

    /* METHODS */
public:
    //!
    //! \brief Management_InGame constructor
    //!
    Management_InGame();
    //!
    //! \brief Management_InGame destructor
    //!
    ~Management_InGame();
    //!
    //! \brief Method to manage the current state of the game
    //! \param w : SDL_Window
    //! \return True if the management is correct. Otherwise, false
    //!
    bool manage( Window* const w );

    /* ATTRIBUTES */
private:

};

#endif      /* MANAGEMENT_INGAME_H */
