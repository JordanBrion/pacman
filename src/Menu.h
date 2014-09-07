#ifndef MENU_H
#define MENU_H

//!
//! \file Menu.h
//! \brief Abstract class to render a menu
//! \author Jordan Brion
//! \version 0.1
//! \date 4 september 2014
//!

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <iostream>
#include <vector>

//!
//! \class Menu
//! \brief Abstract class to render a menu
//!
class Menu {

protected:
    //!
    //! \brief Menu constructor
    //! \param title : The title of the menu
    //! \param elements : The choices in the menu
    //!
    Menu( std::string title, std::vector<std::string> elements );
    //!
    //! \brief Menu destructor
    //!
    ~Menu();
    //!
    //! \brief Virtual method to handle a key pressed by the player
    //! \param key : The key pressed by the player
    //! \return 0 if no element selected. Otherwise, the element selected ( by pressing enter or space bar ).
    //!
    virtual Uint8 handleEvent( SDL_Event& e ) = 0;
    //!
    //! \brief Virtual method to render the menu
    //! \param renderer : SDL_Renderer of the window
    //! \param width : The width of the window
    //! \param height : The height of the window
    //! \param font : The font of the game
    //! \param logo : The SDL_Surface logo of the game
    //!
    virtual void render( SDL_Renderer* renderer, int const& width, int const& height, TTF_Font* font, SDL_Surface* logo ) = 0;

protected:
    std::string _title;                         /*!< The title of the menu  */
    std::vector<std::string> _elements;         /*!< The choices in the menu */
    Uint8 _elementID;                           /*!< Flag to store the selected menu element */

};


#endif /* MENU_H */
