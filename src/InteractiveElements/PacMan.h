//!
//! \file Pacman.h
//! \brief Class to manage the Pac-Man character ( moves, directions, images, ... )
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#ifndef PACMAN_H
#define PACMAN_H

#include <pm/Chrono.h>

#include "Character.h"
#include "../PacDotsManager.h"
#include "../FruitManager.h"

//!
//! \class PacMan
//! \brief The Pacman class, inherited Character class
//!
class PacMan : public Character {

public:
    //!
    //! \brief PacMan constructor
    //! \param dest : The coordonates of the character ( row and col )
    //! \param sprite : The SDL_Texture of the sprites
    //! \param selection : Selection on the sprite
    //! \param position : Position on the screen
    //!
    PacMan( std::map<std::string, int>& dest,
            SDL_Texture* const& texture,
            const SDL_Rect& selection,
            const SDL_Rect& position );
    //!
    //! \brief PacMan destructor
    //!
    ~PacMan();
    //!
    //! \brief Method to load the coordonates of the sprites
    //!
    void loadSpriteCoord();
    //!
    //! \brief Method to handle the inputs of the user
    //! \param e : SDL_Event&
    //!
    void handleEvent( SDL_Event& e );
    //!
    //! \brief Method to update the data ( position of the pacman in the grid, possible directions, etc.  )
    //! \param levelTable: Array containing the level in form of caracters
    //! \param teleportationLocationsCoord: The cases which are able to teleport the pacman
    //!
    void updateAll( std::vector<std::vector<int> > levelTable, std::map<std::string, std::vector<int> > teleportationLocationsCoord );
    //!
    //!  \brief Method to load the next sprite for the pacman animation
    //!  \param direction : The direction towards the pacman is going
    //!
    void nextSprite();
    //!
    //! \brief Method to check the collision with the Pac-Dots
    //! \param pdm : The Pac-Dots Manager which contains all the bubbles
    //!
    void checkCollisionWithPacDots( PacDotsManager* pdm );
    //!
    //! \brief Getter for the power pellet chronometer
    //! \return The power pellet chronometer
    //!
    Chrono<PacMan>* getPowerPelletChrono() const;
    //!
    //! \brief Getter for the chrono when a ghost is eaten
    //! \return The chronometer
    //!
    Chrono<Chrono<PacMan> >* getGhostEatenScoreChrono() const;
    //!
    //! \brief Method to check the collision with the fruit
    //! \param pdm : The fruit manager which contains all the fruit
    //! \return True if a collision is detected. Otherwise, false
    //!
    bool checkCollisionWithFruit( FruitManager* frm );
    //!
    //! \brief Method to render the Pac-Man death animation
    //! \param pRenderer : SDL_Renderer* of the window
    //!
    void deathAnimation( SDL_Renderer* const& pRenderer);
    //!
    //! \brief Getter for the state of the death animation
    //! \return The state of the death animation
    //!
    int getDeathAnimationCounter() const;
    //!
    //! \brief Method to reset the attributes of the Pac-Man to the start ones
    //!
    void startValues();

private:
    int _deathAnimationCounter;                         /*!< Counter of the death animation */
    Chrono<PacMan>* _powerPelletChrono;                 /*!< Chrono for a power-pellet eaten */
    Chrono<Chrono<PacMan> >* _ghostEatenScoreChrono;    /*!< Chrono for the wait when a ghost is eaten. (When the score is shown) */

};

#endif
