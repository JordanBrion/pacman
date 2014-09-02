#ifndef BUBBLESCASE_H
#define BUBBLESCASE_H

//!
//! \file PacDotsCase.h
//! \brief Class for a pac-dot case. This class renders the pac-dots in terms of his type.
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <iostream>
#include "PacDot.h"

//!
//! \class PacDotsCase
//! \brief Class for a pac-dot case. This class renders the pac-dots in terms of his type.
//!
class PacDotsCase {

public:
    //!
    //!  \brief PacDotsCase constructor
    //!  \param row : The row number of the case in the grid
    //!  \param col : The column number of the case in the grid
    //!  \param type : The type of the case where the pac-dot is located
    //!  \param renderer : SDL_Renderer* of the window
    //!  \param sprite : SDL_Surface* containing the sprite of all the characters (and also the pac-dot)
    //!
    PacDotsCase( int const& row, int const& col, int const& type, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    //!
    //!  \brief PacDotsCase destructor
    //!
    ~PacDotsCase();
    //!
    //!  \brief Getter for the type of the case
    //!  \return The type of the case
    //!
    int getType() const;
    //!
    //!  \brief Setter for the type of the case
    //!  \param type : The type of the case where the pac-dot is located
    //!
    void setType( int const& type );
    //!
    //!  \brief Method to render the case (and all the pac-dots in) to the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \return The cumulated points of all the non-eaten pac-dots in the case
    //!
    int render( SDL_Renderer* const& renderer );
    //!
    //!  \brief Getter for the pac-dots in the case
    //!  \return The array containing the pac-dots in the case
    //!
    std::vector<PacDot*> getPacDots() const;
    //!
    //!  \brief Getter to have a selected pac-dot in the case
    //!  \param x : The x coordonate of the pac-dot on the screen
    //!  \param y : The y coordonate of the pac-dot on the screen
    //!  \return A selected pac-dot in the case
    //!
    PacDot* getPacDot ( int const& x, int const& y ) const;
    //!
    //!  \brief Method to reinitialize the pac-dot in the case
    //!
    void reinitPacDotsEaten();
    //!
    //!  \brief Setter when a pac-dot is eaten by the pac-man
    //!  \param x : The x coordonate of the pac-dot on the screen
    //!  \param y : The y coordonate of the pac-dot on the screen
    //!  \param eaten : True if the pac-dot is eaten. Otherwise, false.
    //!
    void setPacDotEaten( int const& x, int const& y, bool eaten );
    //!
    //!  \brief Initialize the pac-dots in line before rendering it to the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \param sprite : SDL_Surface* containing the sprite of all the characters (and also the pac-dot)
    //!
    void initPacDotsInLine( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    //!
    //!  \brief Initialize the pac-dots in angle before rendering it to the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \param sprite : SDL_Surface* containing the sprite of all the characters (and also the pac-dot)
    //!
    void initPacDotsInAngle( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    //!
    //!  \brief Initialize the pac-dots in junction (with 3 ways) before rendering it to the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \param sprite : SDL_Surface* containing the sprite of all the characters (and also the pac-dot)
    //!
    void initPacDotsWithThreeJunctions( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    //!
    //!  \brief Initialize the pac-dots in junction (with 4 ways) before rendering it to the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \param sprite : SDL_Surface* containing the sprite of all the characters (and also the pac-dot)
    //!
    void initPacDotsWithFourJunctions( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );

private:
    int _row;                       /*!< The row number of the case in the grid */
    int _col;                       /*!< The column number of the case in the grid */
    bool _empty;                    /*!< Flag to check if the case is empty */
    int _type;                      /*!< The type of the case */
    std::vector<PacDot*> _pacDots;  /*!< The array containing the pac-dots in the case */

};

#endif
