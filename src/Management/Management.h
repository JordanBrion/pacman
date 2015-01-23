#ifndef     MANAGEMENT_H
#define     MANAGEMENT_H

//!
//! \file Management.h
//! \brief Parent and abstract class to manage the current state of the game
//! \author Jordan Brion
//! \version 0.1
//! \date 23 January 2015
//!

#define     NO_MANAGEMENT           -1
#define     MANAGEMENT_INGAME       0
#define     MANAGEMENT_NEWLIFE      1
#define     MANAGEMENT_RESETTER     2
#define     MANAGEMENT_START        3
#define     MANAGEMENT_PAUSE        4
#define     MANAGEMENT_QUITGAME     5
#define     MANAGEMENT_QUITAPP      6

#include <iostream>

#include "../Window/Window.h"

class Window;

//!
//! \class Management
//! \brief Parent and abstract class to manage the current state of the game
//!
class Management {

    /* METHODS */
protected:
    //!
    //! \brief Management constructor
    //!
    Management();
    //!
    //! \brief Management destructor
    //!
    ~Management();
public:
    //!
    //! \brief Virtual method to manage the current state of the game
    //! \param w : SDL_Window
    //! \return True if the management is correct. Otherwise, false
    //!
    virtual bool manage( Window* const w ) = 0;

    /* ATTRIBUTES */
private:

};

#endif      /* MANAGEMENT_H */
