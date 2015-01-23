#ifndef     EVENTHANDLER_H
#define     EVENTHANDLER_H

//!
//! \file EventHandler.h
//! \brief Parent and abstract class for each type of EventHandler
//! \author Jordan Brion
//! \version 0.1
//! \date 22 January 2015
//!

#define     NO_EVENTHANDLER              -1
#define     EVENTHANDLER_MENUSTART        0
#define     EVENTHANDLER_INGAME           1
#define     EVENTHANDLER_MENUOPTIONS      2
#define     EVENTHANDLER_MENUPAUSE        3
#define     EVENTHANDLER_MENUGAMEOVER     4

#define     NO_MANAGEMENT           -1
#define     MANAGEMENT_INGAME       0
#define     MANAGEMENT_NEWLIFE      1
#define     MANAGEMENT_RESETTER     2
#define     MANAGEMENT_START        3
#define     MANAGEMENT_PAUSE        4
#define     MANAGEMENT_QUITGAME     5
#define     MANAGEMENT_QUITAPP      6

#include <SDL2/SDL.h>

#include <iostream>

//!
//! \class EventHandler
//! \brief Abstract class for each type of EventHandler
//!
class EventHandler {

    /* METHODS */
protected:
    //!
    //! \brief EventHandler constructor
    //!
    EventHandler();
public:
    //!
    //! \brief EventHandler destructor
    //!
    ~EventHandler();
    //!
    //! \brief Virtual method to handle SDL_Event variable for each loop iteration
    //! \param evt : SDL_Event variable
    //! \return Integer macro for Management type (see Management.h)
    //!
    virtual int8_t handle( const SDL_Event& evt ) = 0;
    //!
    //! \brief Virtual method to determine the next handler type after call of the SDL_Event handling in the handle method
    //! \param type : Management type (see macros in Management.h file)
    //! \return The new handler type (see macros above)
    //!
    virtual int8_t nextHandlerType( const int& type ) = 0;

    /* ATTRIBUTES */
protected:

};

#endif      /* EVENTHANDLER_H */
