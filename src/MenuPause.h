#ifndef MENUPAUSE_H
#define MENUPAUSE_H

//!
//! \file MenuPause.h
//! \brief Class to render the pause menu of the game
//! \author Jordan Brion
//! \version 0.1
//! \date 7 september 2014
//!

#include "Menu.h"

///!
//! \brief Enum for the pause menu values
//!
enum menuPause_values {

    MENUPAUSE_RESUME = 1,        /*!< Value to resume the game */
    MENUPAUSE_RESTART,           /*!< Value to restart the game */
    MENUPAUSE_OPTIONS,           /*!< Value to render the options menu */
    MENUPAUSE_QUIT,              /*!< Value to quit the game */

    MENUPAUSE_NBR                /*!< Number of pause menu values */

};

//!
//! \class MenuPause
//! \brief Class to render the pause menu of the game
//!
class MenuPause : public Menu {

public:
    //!
    //! \brief MenuPause constructor
    //! \param title : The title of the menu
    //! \param elements : The choices in the menu
    //!
    MenuPause( std::string title, std::vector<std::string> elements );
    //!
    //! \brief MenuPause destructor
    //!
    ~MenuPause();
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

#endif /* MENUPAUSE_H */
