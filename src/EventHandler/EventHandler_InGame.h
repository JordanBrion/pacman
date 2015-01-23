#ifndef     EVENTHANDLER_INGAME_H
#define     EVENTHANDLER_INGAME_H

//!
//! \file EventHandler_InGame.h
//! \brief Class to handle SDL_Event when the user is playing
//! \author Jordan Brion
//! \version 0.1
//! \date 22 January 2015
//!

#include "EventHandler.h"

//!
//! \class EventHandler_InGame
//! \brief Class to handle SDL_Event when the user is playing
//!
class EventHandler_InGame : public EventHandler {

    /* METHODS */
public:
    //!
    //! \brief EventHandler_InGame constructor
    //!
    EventHandler_InGame();
    //!
    //! \brief EventHandler_InGame destructor
    //!
    ~EventHandler_InGame();
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

#endif      /* EVENTHANDLER_INGAME_H */
