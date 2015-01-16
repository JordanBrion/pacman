#ifndef     SURFACE_SELECTION_H
#define     SURFACE_SELECTION_H

//!
//! \file SurfaceSelection.h
//! \brief Class (inherited from Surface class) with selection on the texture
//! \author Jordan Brion
//! \version 0.1
//! \date 15 january 2015
//!

#include <SDL2/SDL.h>

#include "Surface.h"

//!
//! \class SurfaceSelection
//! \brief Class (inherited from Surface class) with selection on the texture
//!
class SurfaceSelection : public Surface {

    /* METHODS */
public:
    //!
    //!  \brief SurfaceSelection constructor
    //!  \param texture : texture used for the content of the surface
    //!  \param selection : Selection of a texture part
    //!  \param position : Position and size of the surface
    //!
    SurfaceSelection( SDL_Texture* const& texture,
                      const SDL_Rect& selection,
                      const SDL_Rect& position );
    //!
    //!  \brief SurfaceSelection destructor
    //!
    ~SurfaceSelection();
    //!
    //!  \brief Getter for the surface position and size
    //!
    SDL_Rect getSelection() const;

    /* ATTRIBUTES */
private:
    SDL_Rect _selection;         /*!< Position and size of the surface */

};

#endif     /* SURFACE_SELECTION_H */
