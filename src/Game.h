#ifndef GAME_H
#define GAME_H

//!
//! \file Game.h
//! \brief Class to save all the values of the current game
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include <vector>
#include "Const.h"

//!
//! \class Game
//! \brief Class to save all the values of the current game
//!
class Game {

public:
    //!
    //!  \brief Game constructor
    //!  \param lifesNbr : The number of lifes
    //!  \param pacDotsNbr : The number of pac-dots
    //!  \param highScore : The highscore for this level
    //!
    Game( int const& lifesNbr, int const& pacDotsNbr, int const& highScore );
    //!
    //!  \brief Game destructor
    //!
    ~Game();
    //!
    //!  \brief Getter for number of pac-dots remaining
    //!  \return The number of pac-dots remaining
    //!
    int getPacDotsNbr() const;
    //!
    //!  \brief Setter to change the number of pac-dots
    //!  \param nbr : The number of pac-dots
    //!
    void setPacDotsNbr( int const& nbr );
    //!
    //!  \brief Getter for the number of lifes
    //!  \return The number of lifes remaining
    //!
    int getLifesNbr() const;
    //!
    //!  \brief Setter to increment the number of lifes
    //!
    void incLifesNbr();
    //!
    //!  \brief Setter to decrement the number of lifes
    //!
    void decLifesNbr();
    //!
    //! \brief Setter the the number of lifes
    //! \param nbr : The new number of lifes
    //!
    void setLifesNbr( int const& nbr );
    //!
    //!  \brief Getter for the array of fruit
    //!  \return The array of fruit
    //!
    std::vector<int> getAllFruitNbr() const;
    //!
    //!  \brief Getter for the number of the selected fruit
    //!  \param key : The key to select the fruit
    //!  \return The number of the selected fruit
    //!
    int getFruitNbr( int const& key ) const;
    //!
    //!  \brief Setter to change the number of the selected fruit
    //!  \param key : The key to select the fruit
    //!  \param nbr : The new number of fruit
    //!
    void setFruitNbr( int const& key, int const& nbr );
    //!
    //!  \brief Method to put the number of all fruit to 0
    //!
    void resetAllFruitNbr();
    //!
    //! \brief Getter for the power-pellet combo score
    //! \return the power-pellet combo score
    //!
    int getComboPowerPellet() const;
    //!
    //! \brief Setter for the power-pellet combo score
    //! \param score: The power-pellet combo score
    //!
    void setComboPowerPellet( int const& score );
    //!
    //!  \brief Getter for score of player 1
    //!  \return The score of player 1
    //!
    int getScoreP1() const;
    //!
    //!  \brief Setter for score of player 1
    //!  \param score : the score of player 1
    //!
    void setScoreP1( int const& score );
    //!
    //!  \brief Getter for score of player 2
    //!  \return The score of player 2
    //!
    int getScoreP2() const;
    //!
    //!  \brief Setter for score of player 2
    //!  \param score : the score of player 2
    //!
    void setScoreP2( int const& score );
    //!
    //!  \brief Getter for the highscore
    //!  \return The highscore
    //!
    int getHighScore() const;
    //!
    //!  \brief Setter for the highscore
    //!  \param highscore : the highscore of the level
    //!
    void setHighScore( int const& score );
    //!
    //!  \brief Getter to check if the game is a 2-player game
    //!  \return True if it is a single-player game. Otherwise, false
    //!
    bool isTwoPlayersGame() const;
    //!
    //!  \brief Setter to change the flag of the number of players in the game
    //!  \param solo : Flag of the number of players in the game
    //!
    void setTwoPlayersGame( bool const& solo );

private:
    int _lifesNbr;                  /*!< Number of lifes remaining */
    int _pacDotsNbr;                /*!< Number of pac-dots remaining */
    std::vector<int> _fruit;        /*!< Array storing the number of fruit picked up */
    int _comboPowerPellet;          /*!< Save the combo of Ghosts eaten after power pellet pick up */
    int _scoreP1;                   /*!< The score of player 1 */
    int _scoreP2;                   /*!< The score of player 2 */
    int _highScore;                 /*!< The highscore of the level */
    bool _twoPlayersGame;           /*!< Flag for a 2-player game */

};

#endif
