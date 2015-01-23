#ifndef     MANAGEMENT_QUITAPP_H
#define     MANAGEMENT_QUITAPP_H

//!
//! \file Management_QuitApp.h
//! \brief Class to manage the game when the user quits the application
//! \author Jordan Brion
//! \version 0.1
//! \date 23 January 2015
//!

#include "Management.h"

//!
//! \class Management_QuitApp
//! \brief Class to manage the game when the user quits the application
//!
class Management_QuitApp : public Management {

    /* METHODS */
public:
    //!
    //! \brief Management_QuitApp constructor
    //!
    Management_QuitApp();
    //!
    //! \brief Management_QuitApp destructor
    //!
    ~Management_QuitApp();
    //!
    //! \brief Method to manage the current state of the game
    //! \param w : SDL_Window
    //! \return True if the management is correct. Otherwise, false
    //!
    bool manage( Window* const w );

    /* ATTRIBUTES */
private:

};

#endif      /* MANAGEMENT_QUITAPP_H */
