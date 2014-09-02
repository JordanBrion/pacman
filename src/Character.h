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
    Character( std::map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
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
    //!  \brief Virtual method to teleport the character in an other part of the level
    //!
    virtual void teleportation() = 0;
    //!
    //!  \brief Reset the values of the character to the default ones
    //!
    void defaultValues();
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
    //!  \brief Method to update the position where the character is in the grid
    //!
    void updatePositionInTheGrid();
    //!
    //!  \brief Method to reset the move variables of the character
    //!
    void resetValues();
    //!
    //!  \brief Method to load the next sprite for the character animation
    //!  \param direction : The direction towards the character is going
    //!
    void nextSprite( int direction );
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

protected:
    int _initialRow;                                            /*!< Initial row position of character at the start of the life  */
    int _initialCol;                                            /*!< Initial column position of character at the start of the life */
    std::map<std::string, int> _initialStateSrc;                /*!< Initial coord on the sprite */
    std::map<std::string, int> _initialStateDest;               /*!< Coord on the screen at the start of the game */
    int _stepCounter;                                           /*!< Counter for the steps of the character */
    int _goTo;                                                  /*!< Direction of the character */
    bool _back;                                                 /*!< Flag to check if the character retrace his steps */
    std::vector<bool> _directionsPossible;                      /*!< Calculate the possible directions where the character can go */
    int _spriteFlag;                                            /*!< Flag to know which flag to select */
    std::vector<std::vector<std::vector<int> > > _spriteCoord;  /*!< Coordinates of the sprite */
    int _velocity;                                              /*!< The velocity of the character */
    int _velocityX;                                             /*!< The velocity X of the character */
    int _velocityY;                                             /*!< The velocity Y of the character */
    bool _dead;                                                 /*!< Flag to know if a character is dead or not */
    std::map<std::string, int> _positionForRespawn;             /*!< The respawn position of the character  */

};

#endif
