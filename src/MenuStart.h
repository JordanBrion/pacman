#ifndef MENUSTART_H
#define MENUSTART_H

//!
//! \file MenuStart.h
//! \brief Class to render the start menu of the game
//! \author Jordan Brion
//! \version 0.1
//! \date 4 september 2014
//!

#include "Menu.h"

/*! Enum for the menu start values */
enum MENUSTART_VALUES {
    MENUSTART_START,     /*!< Value for start menu */
    MENUSTART_OPTIONS,   /*!< Value for options menu */
    MENUSTART_QUIT,      /*!< Value for quit menu */

    MENUSTART_NBR        /*!< Number of menu values */

};

//!
//! \class MenuStart
//! \brief Class to render the start menu of the game
//!
class MenuStart : public Menu {

public:
    //!
    //! \brief MenuStart constructor
    //! \param title : The title of the menu
    //! \param elements : The choices in the menu
    //!
    MenuStart( std::string title, std::vector<std::string> elements );
    //!
    //! \brief MenuStart destructor
    //!
    ~MenuStart();
    //!
    //! \brief Method to handle a key pressed by the player
    //! \param key : The key pressed by the player
    //!
    void handleEvent( SDL_Event& e );
    //!
    //! \brief Method to render the start menu of the game
    //! \param renderer : SDL_Renderer of the window
    //! \param width : The width of the window
    //! \param height : The width of the window
    //! \param font : The font of the game
    //! \param logo : The SDL_Surface logo of the game
    //!
    void render( SDL_Renderer* renderer, int const& width, int const& height, TTF_Font* font, SDL_Surface* logo );

};

#endif /* MENUSTART_H */
