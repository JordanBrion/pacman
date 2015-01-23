#ifndef     EVENTHANDLER_MENU_H
#define     EVENTHANDLER_MENU_H

//!
//! \file EventHandler_Menu.h
//! \brief Parent and abstract class to handle SDL_Event when the user is in a menu
//! \author Jordan Brion
//! \version 0.1
//! \date 22 January 2015
//!

#include <SDL2/SDL.h>

#include <iostream>

#include "EventHandler.h"
#include "../Management/Management.h"

//!
//! \class EventHandler_Menu
//! \brief Parent and abstract class to handle SDL_Event when the user is in a menu
//!
class EventHandler_Menu : public EventHandler {

    /* METHODS */
protected:
    //!
    //! \brief EventHandler_Menu constructor
    //!
    EventHandler_Menu();
public:
    //!
    //! \brief EventHandler_Menu destructor
    //!
    ~EventHandler_Menu();
    //!
    //! \brief Method to handle SDL_Event variable for each loop iteration
    //! \param evt : SDL_Event variable
    //! \return Integer macro for Management type (see Management.h)
    //!
    int8_t handle( const SDL_Event& evt );

    /* ATTRIBUTES */
protected:
    Uint8 _selectedID;          /*!< Menu element selected */

};

#endif      /* EVENTHANDLER_MENU_H */
