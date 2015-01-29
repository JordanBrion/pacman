#ifndef     WINDOW_INITIALIZER_H
#define     WINDOW_INITIALIZER_H

//!
//! \file WindowInitializer.h
//! \brief Class to initialize the ressources and the libs of the project.
//! \author Jordan Brion
//! \version 0.1
//! \date 15 January 2015
//!

#include "../FilesManager.h"
#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"

#include <SDL2/SDL.h>

#include <iostream>

class Window;

//!
//! \class WindowInitializer
//! \brief Class to initialize the ressources and the libs of the project.
//!
class WindowInitializer {

    /* METHODS */
public:
    //!
    //! \brief WindowInitializer constructor
    //!
    WindowInitializer();
    //!
    //! \brief WindowInitializer destructor
    //!
    ~WindowInitializer();
    //!
    //! \brief Method to initialize SDL2 and the required SDL2 libraries
    //! \param window : Window
    //! \param width : Width of the window
    //! \param height : Height of the window
    //! \param renderer : SDL_Renderer of the window
    //! \param windowSurface : SDL_Surface of the window
    //! \return
    //!
    bool initSDL( SDL_Window* &window,
                  int const& width,
                  int const& height,
                  SDL_Renderer* &renderer,
                  SDL_Surface* &windowSurface ) throw ( const std::exception& );
    //!
    //! \brief Method to initialize the media files (images, fonts...)
    //! \param fm : Instance of files manager
    //! \return
    //!
    bool initRessources( FilesManager* fm ) throw( const char* );









    //!
    //! \brief initCharacters
    //! \param fm : Instance of file manager
    //! \param renderer : SDL_Renderer of the window
    //! \param pacMan : Instance of Pac-Man
    //! \param ghosts : Vector array of ghost intances
    //!
    void initCharacters( Window* w,
                         PacMan* &pacMan,
                         std::vector<Ghost*>& ghosts);






    /* ATTRIBUTES */
private:


};

#endif     /* WINDOW_INITIALIZER_H */

