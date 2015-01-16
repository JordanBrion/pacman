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
    //!
    //! \brief Setter for the surface Selection and size
    //!  \param w : The width
    //!  \param h : The height
    //!  \param x : The x Selection
    //!  \param y : The y Selection
    //!
    void setSelection( const int& w, const int& h,
                       const int& x, const int& y );
    //!
    //! \brief Setter for the surface selection and size
    //! \param rect : An other SDL_Rect
    //!
    void setSelection( const SDL_Rect& rect );
    //!
    //! \brief Setter for the w attr of the surface selection and size
    //! \param w : The width
    //!
    void setSelectionW( const int& w );
    //!
    //! \brief Setter for the h attr of the surface selection and size
    //! \param h : The height
    //!
    void setSelectionH( const int& h );
    //!
    //! \brief Setter for the x attr of the surface selection and size
    //! \param x : The x Selection
    //!
    void setSelectionX( const int& x );
    //!
    //! \brief Setter for the y attr of the surface selection and size
    //! \param y : The y Selection
    //!
    void setSelectionY( const int& y );

    /* ATTRIBUTES */
protected:
    SDL_Rect _selection;         /*!< Position and size of the surface */

};

#endif     /* SURFACE_SELECTION_H */
