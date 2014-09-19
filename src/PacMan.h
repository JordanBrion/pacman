//!
//! \file Pacman.h
//! \brief Class to manage the Pac-Man character ( moves, directions, images, ... )
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#ifndef PACMAN_H
#define PACMAN_H

#include "Character.h"
#include "PacDotsManager.h"

//!
//! \class PacMan
//! \brief The Pacman class, inherited Character class
//!
class PacMan : public Character {

public:
    //!
    //! \brief PacMan constructor
    //! \param dest : The coordonates of the character ( row and col )
    //! \param renderer : The renderer of the SDL window
    //! \param sprite : The SDL_Surface of the sprites
    //!
    PacMan( std::map<std::string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
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
    //!
    void updateAll( std::vector<std::vector<int> > levelTable );
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
    //! \return The power pellet chronometer. 0 if the chrono is not started.
    //!
    Uint32 getPowerPelletChrono() const;
    //!
    //! \brief Method to start the power pellet chronometer
    //!
    void startPowerPelletChrono();
    //!
    //! \brief Method to check if the power pellet chronometer is exceeded
    //! \return True if the power pellet chrono is resetted. Otherwise, false
    //!
    bool checkPowerPelletChrono();
    //!
    //! \brief Method to reset the power pellet chronometer
    //!
    void resetPowerPelletChrono();
    //!
    //! \brief Method to calculate the time left for the power pellet duration
    //! \return The time left
    //!
    Uint32 timeLeftPowerPellet();
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
    //! \brief Method to render the teleportation
    //!
    void teleportation();
    //!
    //! \brief Method to reset the attributes of the Pac-Man to the start ones
    //!
    void startValues();

private:
    int _deathAnimationCounter;     /*!< Counter of the death animation */
    Uint32 _powerPelletChrono;      /*!< Flag when pac-man eat a */

};

#endif
