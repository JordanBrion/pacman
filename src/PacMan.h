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
    //! \brief Method to move the Pac-Man
    //! \param levelTable : The structure of the level
    //!
    void move( std::vector<std::vector<int> > levelTable );
    //!
    //! \brief Method to move the Pac-Man vertically
    //! \param up : The direction. True = UP ; False = DOWN
    //!
    void moveVertically( bool up );
    //!
    //! \brief Method to move the Pac-Man horizontally
    //! \param left : The direction. True = LEFT ; False = RIGHT
    //!
    void moveHorizontally( bool left );
    //!
    //! \brief Method to check the collision with the Pac-Dots
    //! \param pdm : The Pac-Dots Manager which contains all the bubbles
    //!
    void checkCollisionWithPacDots( PacDotsManager* pdm );
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
    //! \brief Method to reset the attributes of the Pac-Man
    //!
    void defaultValues();

private:
    int _directionKey;              /*!< ???? */
    int _deathAnimationCounter;     /*!< Counter of the death animation */
    bool _powerPellet;              /*!< Flag when pac-man eat a */
    bool _stopKeyUp;                /*!< ???? */

};

#endif
