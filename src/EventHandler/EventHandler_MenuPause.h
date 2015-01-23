#ifndef     EVENTHANDLER_MENUPAUSE_H
#define     EVENTHANDLER_MENUPAUSE_H

//!
//! \file EventHandler_MenuPause.h
//! \brief Class to handle SDL_Event when the user is in the pause menu
//! \author Jordan Brion
//! \version 0.1
//! \date 22 January 2015
//!

#include "EventHandler_Menu.h"

//!
//! \class EventHandler_MenuPause
//! \brief Class to handle SDL_Event when the user is in the pause menu
//!
class EventHandler_MenuPause : public EventHandler_Menu {

    /* METHODS */
public:
    //!
    //! \brief EventHandler_MenuPause
    //!
    EventHandler_MenuPause();
    //!
    //! \brief EventHandler_MenuPause
    //!
    ~EventHandler_MenuPause();
    //!
    //! \brief Method to handle SDL_Event variable for each loop iteration
    //! \param evt : SDL_Event variable
    //! \return Integer macro for Management type (see Management.h)
    //!
    int8_t handle( const SDL_Event& evt );
    //!
    //! \brief Method to determine the next handler type after call of the SDL_Event handling in the handle method
    //! \param type : Management type (see macros in Management.h file)
    //! \return The new handler type (see macros in EventHandler.h)
    //!
    int8_t nextHandlerType( const int& managementType );

    /* ATTRIBUTES */
private:

};

#endif      /* EVENTHANDLER_MENUPAUSE_H */
