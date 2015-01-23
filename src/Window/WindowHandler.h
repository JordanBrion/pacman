#ifndef     WINDOW_HANDLER_H
#define     WINDOW_HANDLER_H

//!
//! \file WindowHandler.h
//! \brief Class to handle SDL_Event for each loop iteration
//! \author Jordan Brion
//! \version 0.1
//! \date 22 January 2015
//!

#include <SDL2/SDL.h>

#include <vector>

#include "../EventHandler/EventHandler.h"

//!
//! \class WindowHandler
//! \brief Class to handle SDL_Event for each loop iteration
//!
class WindowHandler {

    /* METHODS */
public:
    //!
    //! \brief WindowHandler constructor
    //!
    WindowHandler();
    //!
    //! \brief WindowHandler destructor
    //!
    ~WindowHandler();
    //!
    //! \brief Method to handle SDL_Event variable for each loop iteration
    //! \param evt : SDL_Event variable
    //! \return Integer macro for Management type (see Management.h)
    //!
    int8_t handle( const SDL_Event& evt );
    //!
    //! \brief Method to determine the next handler type after call of the SDL_Event handling in the handle method
    //!
    void nextHandler();

    /* ATTRIBUTES */
private:
    std::vector<EventHandler*> _handlers;   /*!<  All the handlers */
    EventHandler* _currentHandler;          /*!<  The current handler */
    int8_t _currentManagementType;          /*!<  The management type returned by the handle method */

};

#endif      /* WINDOW_HANDLER_H */
