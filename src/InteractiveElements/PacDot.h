#ifndef     PACDOT_H
#define     PACDOT_H

//!
//! \file PacDot.h
//! \brief Class of a pac-dot. A pac-dot is a small circle eaten by the pac-man to finish the game.
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include "InteractiveElement.h"

//!
//! \defgroup PacDots layouts in the grid element
//! @{
//!
#define     PACDOTS_LAYOUT                  -1
#define     PACDOTS_EMPTY                   -2
#define     PACDOTS_HOR                     -3
#define     PACDOTS_VER                     -4
#define     PACDOTS_ANGLE_TOP_LEFT          -5
#define     PACDOTS_ANGLE_TOP_RIGHT         -6
#define     PACDOTS_ANGLE_BOTTOM_LEFT       -7
#define     PACDOTS_ANGLE_BOTTOM_RIGHT      -8
#define     PACDOTS_JUNCTION_3_TOTOP        -9
#define     PACDOTS_JUNCTION_3_TOBOTTOM     -10
#define     PACDOTS_JUNCTION_3_TORIGHT      -11
#define     PACDOTS_JUNCTION_3_TOLEFT       -12
#define     PACDOTS_JUNCTION_4              -13
#define     PACDOTS_POWERPELLET             -14
//!@}

//!
//! \class PacDot
//! \brief Class of a pac-dot. A pac-dot is a small circle eaten by the pac-man to finish the game.
//!
class PacDot: public InteractiveElement {

public:
    //!
    //!  \brief PacDot constructor
    //!  \param dest : The location where the pac-dot has to be rendered to the screen
    //!  \param type : The type of the case where the pac-dot is located
    //!  \param selection : Selection on the sprite
    //!  \param position : Position on the screen
    //!  \param sprite : SDL_Texture* containing the sprite of all the characters (and also the pac-dot)
    //!
    PacDot( std::map<std::string, int>& dest,
            const int& type,
            const SDL_Rect& selection,
            const SDL_Rect& position,
            SDL_Texture* const& sprite );
    //!
    //!  \brief PacDot destructor
    //!
    ~PacDot();
    //!
    //!  \brief Getter to check if the pac-dot is eaten
    //!  \return True if the pac-dot is eaten. Otherwise, false.
    //!
    bool isEaten() const;
    //!
    //!  \brief Setter to change the value when the pac-dot is eaten or not
    //!  \param state : True if the pac-dot is eaten. Otherwise, false.
    //!
    void setEaten( int const& state );
    //!
    //!  \brief Getter for the type of the case where the pac-dot is located
    //!  \return The type of the case where the pac-dot is located
    //!
    int getCaseType() const;
    //!
    //!  \brief Setter for the type of the case where the pac-dot is located
    //!  \param type : The type of the case where the pac-dot is located
    //!
    void setCaseType( int const& type );
    //!
    //!  \brief Method to render the pac-dot to the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \return The points of the pac-dot if the pac-dot has not been eaten
    //!
    virtual int show( SDL_Renderer* const& renderer );

protected:
    bool _eaten;         /*!< Flag to check if the pac-dot is eaten */
    int _caseType;       /*!< Type of the case where the pac-dot is located (cf. enum pacDotsPath) */

};

#endif      /* PACDOT_H */
