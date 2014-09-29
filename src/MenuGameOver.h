#ifndef MENUGAMEOVER_H
#define MENUGAMEOVER_H

//!
//! \file MenuGameOver.h
//! \brief Class to render the game over menu of the game
//! \author Jordan Brion
//! \version 0.1
//! \date 29 september 2014
//!

#include "Menu.h"

///!
//! \brief Enum for the values of the game over menu
//!
enum menuGameOver_values {

    MENUGAMEOVER_YES = 1,       /*!< Value is the answer is yes */
    MENUGAMEOVER_NO,            /*!< Value is the answer is no */

    MENUGAMEOVER_NBR            /*!< Number of menu values */

};

//!
//! \class MenuGameOver
//! \brief Class to render the game over menu of the game
//!
class MenuGameOver : public Menu {

public:
    //!
    //! \brief MenuGameOver constructor
    //! \param title : The title of the menu
    //! \param elements : The choices in the menu
    //!
    MenuGameOver( std::string title, std::vector<std::string> elements );
    //!
    //! \brief MenuGameOver destructor
    //!
    ~MenuGameOver();
    //!
    //! \brief Method to handle a key pressed by the player
    //! \param key : The key pressed by the player
    //! \return 0 if no element selected. Otherwise, the element selected ( by pressing enter or space bar ).
    //!
    Uint8 handleEvent( SDL_Event& e );
    //!
    //! \brief Method to render the pause menu of the game
    //! \param renderer : SDL_Renderer of the window
    //! \param width : The width of the window
    //! \param height : The width of the window
    //! \param font : The font of the game
    //! \param logo : The SDL_Surface logo of the game
    //!
    void render( SDL_Renderer* renderer, int const& width, int const& height, TTF_Font* font, SDL_Surface* logo );

};

#endif /* MENUGAMEOVER_H */
