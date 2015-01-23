#ifndef     EVENTHANDLER_MENUOPTIONS_H
#define     EVENTHANDLER_MENUOPTIONS_H

//!
//! \file EventHandler_MenuOptions.h
//! \brief Class to handle SDL_Event when the user is in the options menu
//! \author Jordan Brion
//! \version 0.1
//! \date 22 January 2015
//!

#include "EventHandler_Menu.h"

//!
//! \class EventHandler_MenuOptions
//! \brief Class to handle SDL_Event when the user is in the options menu
//!
class EventHandler_MenuOptions : public EventHandler_Menu {

    /* METHODS */
public:
    //!
    //! \brief EventHandler_MenuOptions constructor
    //!
    EventHandler_MenuOptions();
    //!
    //! \brief EventHandler_MenuOptions destructor
    //!
    ~EventHandler_MenuOptions();
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

#endif      /* EVENTHANDLER_MENUOPTIONS_H */
