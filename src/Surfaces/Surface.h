#ifndef     SURFACE_H
#define     SURFACE_H

//!
//! \file Surface.h
//! \brief Class representing a rectangle surface on the screen
//! \author Jordan Brion
//! \version 0.1
//! \date 15 january 2015
//!

#include <SDL2/SDL.h>

//!
//! \class Surface
//! \brief Class representing a rectangle surface on the screen
//!
class Surface {

    /* METHODS */
public:
    //!
    //!  \brief Surface constructor
    //!  \param texture : texture used for the content of the surface
    //!  \param position : Position and size of the surface
    //!
    Surface( SDL_Texture* texture,
             const SDL_Rect& position );
    //!
    //!  \brief Surface destructor
    //!
    ~Surface();
    //!
    //! \brief Getter for the texture pointer
    //! \return A pointer to the texture
    //!
    SDL_Texture* getTexture() const;
    //!
    //!  \brief Getter for the surface position and size
    //!
    SDL_Rect getPosition() const;
    //!
    //! \brief Setter for the surface position and size
    //!  \param w : The width
    //!  \param h : The height
    //!  \param x : The x position
    //!  \param y : The y position
    //!
    void setPosition( const int& w, const int& h,
                      const int& x, const int& y );
    //!
    //! \brief Setter for the surface position and size
    //! \param rect : An other SDL_Rect
    //!
    void setPosition( const SDL_Rect& rect );
    //!
    //! \brief Setter for the w attr of the surface position and size
    //! \param w : The width
    //!
    void setPositionW( const int& w );
    //!
    //! \brief Setter for the h attr of the surface position and size
    //! \param h : The height
    //!
    void setPositionH( const int& h );
    //!
    //! \brief Setter for the x attr of the surface position and size
    //! \param x : The x position
    //!
    void setPositionX( const int& x );
    //!
    //! \brief Setter for the y attr of the surface position and size
    //! \param y : The y position
    //!
    void setPositionY( const int& y );

    /* STATIC */
    //!
    //!  \brief Static method to init a SDL_Rect
    //!  \param w : The width
    //!  \param h : The height
    //!  \param x : The x position
    //!  \param y : The y position
    //!
    static void initRect( SDL_Rect* rect,
                          const int& w, const int& h,
                          const int& x, const int& y );

    /* ATTRIBUTES */
private:
    SDL_Texture* _texture;      /*!< Texture used for the content of the surface */
    SDL_Rect _position;         /*!< Position and size of the surface */

};

#endif     /* SURFACE_H */
