#ifndef     MANAGEMENT_QUITGAME_H
#define     MANAGEMENT_QUITGAME_H

//!
//! \file Management_QuitGame.h
//! \brief Class to manage the game when the user quits the game
//! \author Jordan Brion
//! \version 0.1
//! \date 23 January 2015
//!

#include "Management.h"

//!
//! \class Management_QuitGame
//! \brief Class to manage the game when the user quits the game
//!
class Management_QuitGame : public Management {

    /* METHODS */
public:
    //!
    //! \brief Management_QuitGame constructor
    //!
    Management_QuitGame();
    //!
    //! \brief Management_QuitGame destructor
    //!
    ~Management_QuitGame();
    //!
    //! \brief Method to manage the current state of the game
    //! \param w : SDL_Window
    //! \return True if the management is correct. Otherwise, false
    //!
    bool manage( Window* const w );

    /* ATTRIBUTES */
private:

};

#endif      /* MANAGEMENT_QUITGAME_H */
