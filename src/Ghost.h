#ifndef FANTOME_H
#define FANTOME_H

//!
//! \file Ghost.h
//! \brief Class to manage a ghost character
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include <sstream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include "Character.h"
#include "PacMan.h"

//!
//! \brief Enum for the ghost colors
//!
enum colors {

    RED,
    PINK,
    BLUE,
    ORANGE

};

//!
//! \class Ghost
//! \brief Class to manage a ghost character
//!
class Ghost : public Character {

  public:
    //!
    //!  \brief Ghost constructor
    //!  \param dest : The position where the ghost has to be rendered on the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \param sprite : SDL_Surface* containing the sprite of all the characters
    //!
    Ghost( std::map<std::string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    //!
    //!  \brief Method to load the sprite coordonates of the ghost
    //!
    void loadSpriteCoord();
    //!
    //!  \brief Method to load the sprite coordonates of the ghost when he is eatable
    //!
    void loadSpriteCoordEatable();
    //!
    //! \brief Method to update the data ( position of the ghost in the grid, possible directions, etc.  )
    //! \param levelTable: Array containing the level in form of caracters
    //! \param teleportationLocationsCoord: The cases which are able to teleport the ghost
    //!
    void updateAll( std::vector<std::vector<int> > levelTable, std::map<std::string, std::vector<int> > teleportationLocationsCoord );
    //!
    //!  \brief Method to load the next sprite for the ghost animation
    //!  \param direction : The direction towards the ghost is going
    //!
    void nextSprite();
    //!
    //!  \brief Method to reset the move variables of the character
    //!
    void resetValues();
    //!
    //!  \brief Method to calculate a randomized direction
    //!  \return The randomized direction
    //!
    int newRandomDirection() const;
    //!
    //! \brief Method to define the velocity of the ghost
    //!
    void defineVelocity();
    //!
    //!  \brief Method to check the collisions with the pacman
    //!  \param pacman : The pacman
    //!  \return True if a collision is detected. Otherwise, false
    //!
    bool checkCollision( PacMan* const& pacman ) const;
    //!
    //! \brief Method to eat the pacman
    //! \param pacman: An instance of pacman
    //! \return True if the pacman is eaten. Otherwise, false.
    //!
    bool eat( PacMan* pacman );
    //!
    //! \brief Method to change the ghost attributes depending the power-pellet chronometer
    //! \param pacman: An instance of pacman
    //!
    void handlePowerPellet( PacMan* pacman );
    //!
    //! \brief Setter if the power pellet duration is 50% over
    //! \param powerPelletAlmostOver: True if the power pellet duration is 50% over. Otherwise, false
    //!
    void setPowerPelletAlmostOver( bool powerPelletAlmostOver );
    //!
    //! \brief Method to start the power pellet score chronometer
    //!
    void startPowerPelletScoreChrono();
    //!
    //! \brief Method to reset the power pellet score chronometer
    //!
    void resetPowerPelletScoreChrono();
    //!
    //! \brief Method to know if the power pellet score chronometer is over
    //!
    bool isPowerPelletScoreChronoOver();
    //!
    //!  \brief Method to load the death animation of the ghost
    //!  \param pRenderer : SDL_Renderer* of the window
    //!
    void deathAnimation( SDL_Renderer* const& );
    //!
    //!  \brief Reset the values of the ghost to the start ones
    //!
    void startValues();
    //!
    //! \brief Method to select the score of a eaten ghost on the sprite
    //! \param renderer: SDL_Renderer* of the window
    //! \param score: The current score
    //!
    void drawScorePowerPellet( SDL_Renderer* renderer, Uint16 const& score );
    //!
    //!  \brief Method to return the ghost to the warp zone after his death
    //!
    void returnToWarpZone();

    /* STATIC VARIABLES */
    static int8_t eatenBrother;                             /*!< Flag to know if a ghost was eaten */
    static const Uint32 POWERPELLET_SCORE_DURATION = 2000;  /*!< Duration of the chronometer to render the power-pellet score chrono */

private:
    Uint32 _powerPelletScoreChrono;                             /*!< Chronometer to render the power-pellet score chrono */
    int _forbiddenDirection;                                    /*!< Flag to forbid the previous direction of the ghost. Because the ghosts are stupid and don't know where they come from. :)  */
    std::vector<std::vector<int> > _spriteCoordEatable;         /*!< Vector for the sprite coordonates when the ghost is eatable by the pacman */
    bool _powerPelletAlmostOver;                                /*!< Flag to know if the power pellet duration is 50% over */

};

#endif
