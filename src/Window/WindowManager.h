#ifndef     WINDOW_MANAGER_H
#define     WINDOW_MANAGER_H

//!
//! \file WindowInitializer.h
//! \brief Class to initialize the ressources and the libs of the project.
//! \author Jordan Brion
//! \version 0.1
//! \date 15 January 2015
//!

#include <SDL2/SDL.h>

#include "../Management/Management.h"

class Window;
class Management;

//!
//! \class WindowInitializer
//! \brief Class to initialize the ressources and the libs of the project.
//!
class WindowManager {

    /* METHODS */
public:
    //!
    //! \brief WindowInitializer constructor
    //!
    WindowManager();
    //!
    //! \brief WindowInitializer constructor
    //!
    ~WindowManager();
    //!
    //! \brief WindowInitializer constructor
    //!
    bool manage( Window* const window, const int8_t& type );

    /* ATTRIBUTES */
private:
    std::vector<Management*> _managements;      /*!<  Instance of FilesManager */

};

#endif      /* WINDOW_MANAGER_H */
