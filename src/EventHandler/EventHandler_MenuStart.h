#ifndef     EVENTHANDLER_MENUSTART_H
#define     EVENTHANDLER_MENUSTART_H

//!
//! \file EventHandler_MenuStart.h
//! \brief Class to handle SDL_Event when the user is in the start menu
//! \author Jordan Brion
//! \version 0.1
//! \date 22 January 2015
//!

#define     START       0
#define     OPTIONS     1
#define     QUIT        2

#include "EventHandler_Menu.h"

//!
//! \class EventHandler_MenuStart
//! \brief Class to handle SDL_Event when the user is in the start menu
//!
class EventHandler_MenuStart : public EventHandler_Menu {

    /* METHODS */
public:
    //!
    //! \brief EventHandler_MenuStart constructor
    //!
    EventHandler_MenuStart();
    //!
    //! \brief EventHandler_MenuStart destructor
    //!
    ~EventHandler_MenuStart();
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

#endif      /* EVENTHANDLER_MENUSTART_H */
