#ifndef CHARACTER_H
#define CHARACTER_H

//!
//! \file Character.h
//! \brief Class representing a character. It can be a pacman or a ghost.
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include "InteractiveElement.h"

//!
//! \class Character
//! \brief Class representing a character. It can be a pacman or a ghost.
//!
class Character: public InteractiveElement {

protected:
    //!
    //!  \brief Character constructor
    //!  \param dest : The position where the character has to be rendered on the screen
    //!  \param renderer : SDL_Renderer* of the window
    //!  \param sprite : SDL_Surface* containing the sprite of all the characters
    //!
    Character( std::map<std::string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
    //!
    //!  \brief Virtual method to load the sprite coordonates of the character
    //!
    virtual void loadSpriteCoord() = 0;
    //!
    //!  \brief Method to move vertically
    //!  \param up : Move upwards
    //!  \return True if the character has moved. Otherwise, false
    //!
    bool moveVertically( bool up );
    //!
    //!  \brief Method to move horizontally
    //!  \param left : Move left
    //!  \return True if the character has moved. Otherwise, false
    //!
    bool moveHorizontally( bool left );
    //!
    //!  \brief Virtual method to load the death animation of the character
    //!  \param pRenderer : SDL_Renderer* of the window
    //!
    virtual void deathAnimation( SDL_Renderer* const& pRenderer ) = 0;
    //!
    //!  \brief Reset the values of the character to the start ones
    //!
    void startValues();
    //!
    //! \brief Virtual method to update the data ( position of the character in the grid, possible directions, etc.  )
    //! \param levelTable: Array containing the level in form of caracters
    //! \param teleportationLocationsCoord: The cases which are able to teleport the character
    //!
    virtual void updateAll( std::vector<std::vector<int> > levelTable, std::map<std::string, std::vector<int> > teleportationLocationsCoord ) = 0;

public:
    //!
    //!  \brief Method to calculate the next possible directions for the characters
    //!  \param levelTable : Array containing the level in the form of caracters
    //!
    void calculateDirection( std::vector<std::vector<int> > levelTable );
    //!
    //!  \brief Method to check if the character is centered in the square (checkout needed for correct moves)
    //!  \return True if the character is in the center of the square. Otherwise, false
    //!
    bool isCenteredInTheSquare();
    //!
    //!  \brief Method to increment/decrement the steps counter
    //!  \param direction1 : The direction to the character is moving
    //!  \param direction2 : The opposite direction to the character is moving
    //!
    void setStepCounter( int direction1, int direction2 );
    //!
    //! \brief Method to check if the character is in a case which is able to teleport him
    //! \param teleportationLocationsCoord: The cases which are able to teleport the character
    //! \return The coordinates in a vector. Otherwise, false
    //!
    std::vector<int> checkTeleportation( std::map<std::string, std::vector<int> > teleportationLocationsCoord );
    //!
    //!  \brief Method to update the position where the character is in the grid
    //!
    void updatePositionInTheGrid();
    //!
    //!  \brief Method to reset the move variables of the character
    //!
    void resetValues();
    //!
    //!  \brief Method to move the character
    //!  \return -1 if the character is not moving. Otherwise, a direction value (cfr. "pm/Directions.h")
    //!
    int move();
    //!
    //!  \brief Method to know if the player presses the key to move vertically.
    //!  \return True if the player presses the key to move vertically. Otherwise, false
    //!
    bool isStepVertical() const;
    //!
    //!  \brief Method to know if the player presses the key to move horizontally.
    //!  \return True if the player presses the key to move horizontally. Otherwise, false
    //!
    bool isStepHorizontal() const;
    //!
    //!  \brief Method to know if the player presses the key to move upwards.
    //!  \return True if the player presses the key to move upwards. Otherwise, false
    //!
    bool isStepUp() const;
    //!
    //!  \brief Method to know if the player presses the key to move downwards.
    //!  \return True if the player presses the key to move downwards. Otherwise, false
    //!
    bool isStepDown() const;
    //!
    //!  \brief Method to know if the player presses the key to move left.
    //!  \return True if the player presses the key to move left. Otherwise, false
    //!
    bool isStepLeft() const;
    //!
    //!  \brief Method to know if the player presses the key to move right.
    //!  \return True if the player presses the key to move right. Otherwise, false
    //!
    bool isStepRight() const;
    //!
    //!  \brief Method to load the next sprite for the character animation
    //!  \param direction : The direction towards the character is going
    //!
    void nextSprite();
    //!
    //!  \brief Method to check the collisions with the other characters
    //!  \param element : The other character
    //!  \return True if a collision is detected. Otherwise, false
    //!
    bool checkCollision( InteractiveElement* const& element ) const;
    //!
    //!  \brief Getter to know if the character is dead
    //!  \return True if the character is dead. Otherwise, false
    //!
    bool isDead() const;
    //!
    //!  \brief Setter to bring alive the character or kill him
    //!
    void setDead();
    //!
    //!  \brief Getter to know if the character is eatable
    //!  \return True if the character is eatable. Otherwise, false
    //!
    bool isEatable() const;
    //!
    //!  \brief Setter to put the character as eatable
    //!
    void setEatable();
    //!
    //!  \brief Setter to put the character as eatable
    //!  \param True if the character is eatable. Otherwise, false
    //!
    void setEatable( bool eatable );
    //!
    //!  \brief Method to teleport the character to an other part of the level
    //!  \param to: Teleportation coordinates
    //!  \param levelTable: The array containing the level in form of caracters
    //!
    void teleport( std::vector<int> to, std::vector<std::vector<int> > levelTable );

protected:
    int _initialRow;                                            /*!< Initial row position of character at the start of the life  */
    int _initialCol;                                            /*!< Initial column position of character at the start of the life */
    std::map<std::string, int> _initialStateSrc;                /*!< Initial coord on the sprite */
    std::map<std::string, int> _initialStateDest;               /*!< Coord on the screen at the start of the game */
    int _step;                                                  /*!< The direction towards the character just moved */
    int _stepCounter;                                           /*!< Counter for the steps of the character */
    int _goTo;                                                  /*!< Global direction of the character */
    int _goToBackUp;                                            /*!< Backup of the global direction of the character */
    bool _back;                                                 /*!< Flag to check if the character retrace his steps */
    std::vector<bool> _directionsPossible;                      /*!< Calculate the possible directions where the character can go */
    Uint8 _spriteFlag;                                          /*!< Flag to know which sprite to select */
    std::vector<std::vector<std::vector<int> > > _spriteCoord;  /*!< Coordinates of the sprite */
    int _velocity;                                              /*!< The velocity of the character */
    int _velocityX;                                             /*!< The velocity X of the character */
    int _velocityY;                                             /*!< The velocity Y of the character */
    bool _dead;                                                 /*!< Flag to know if a character is dead or not */
    bool _eatable;                                              /*!< Flag to know if a character is eatable */
    std::map<std::string, int> _positionForRespawn;             /*!< The respawn position of the character  */

};

#endif
