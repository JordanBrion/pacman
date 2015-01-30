#ifndef FRUITMANAGER_H
#define FRUITMANAGER_H

//!
//! \file FruitManager.h
//! \brief Class to manage the fruit (location, number, points...).
//! \author Jordan Brion
//! \version 0.1
//! \date 22 september 2014
//!

#include <SDL2/SDL.h>

#include "InteractiveElements/Fruit.h"

//!
//! \class FruitManager
//! \brief Class to manage the fruit (location, number, points...).
//!
class FruitManager {

public:
    //!
    //! \brief FruitManager constructor
    //!
    FruitManager();
    //!
    //! \brief FruitManager destructor
    //!
    ~FruitManager();
    //!
    //! \brief Method to initialize the instances of Fruit Class
    //! \param sprite: SDL_Texture* containing the sprite for the level */
    //! \param selections : Array for the fruit selections on the sprite
    //!
    void initFruit( SDL_Texture* const& sprite,
                    const std::vector<SDL_Rect>& selections );
    //!
    //! \brief Getter for all instances of Fruit
    //! \return Array containing the instances of Fruit
    //!
    std::vector<Fruit*> getFruit() const;
    //!
    //! \brief Getter for one instance of Fruit
    //! \param type: Type of fruit to return
    //! \return The instance of fruit specified by the type parameter
    //!
    Fruit* getOneFruit( int const& type ) const;
    //!
    //! \brief Getter for the number of fruit eaten specified by the type parameter
    //! \param type: Type of fruit to increment
    //! \return The number of fruit eaten specified by the type parameter
    //!
    int getFruitNbr( int const& type ) const;
    //!
    //! \brief Setter to increment the number of fruit eaten specified by the type parameter
    //! \param type: Type of fruit to increment
    //!
    void incFruitNbr( int const& type );
    //!
    //! \brief Setter to decrement the number of fruit eaten specified by the type parameter
    //! \param type: Type of fruit to decrement
    //!
    void decFruitNbr( int const& type );
    //!
    //! \brief Getter for the number of points earned for fruit specified by the type parameter
    //! \param type: Type of fruit
    //! \return The number of points earned for fruit specified by the type parameter
    //!
    int getFruitPoints( int const& type ) const;
    //!
    //! \brief Method to initialize the coordonates where the fruit appears in the grid
    //! \param fruitLocationGrid: Array containing the places where the fruit appear in the grid
    //!
    void initFruitLocationCoord( const std::vector<std::vector<int> >& fruitLocationsGrid );
    //!
    //! \brief Method to start the value to know details about the rendered fruit (location and chrono)
    //!
    void startCurrentFruit();
    //!
    //! \brief Method to randomize a location and a type for the future rendered fruit
    //!
    bool randomFruit();
    //!
    //! \brief Method to reset the value to know details about the rendered fruit (location and chrono)
    //!
    void resetCurrentFruit();
    //!
    //! \brief Method to start the chronometer to know since when no fruit was rendered
    //!
    void startBetweenFruitChrono();
    //!
    //! \brief Method to reset the chronometer to know since when no fruit was rendered
    //!
    void resetBetweenFruitChrono();
    //!
    //! \brief Method to check the chronometers values
    //! \return True if _currentFruitChrono is started. Otherwise, false
    //!
    bool checkFruitChronos();
    //!
    //! \brief Method to eat the rendered fruit if the pacman is at the correct location
    //! \param row: The row where the pacman is located
    //! \param col: The col where the pacman is located
    //! \return True if the fruit is eaten. Otherwise, false
    //!
    bool eatFruit( int const& row, int const& col );
    //!
    //! \brief Method to located the rendered fruit if the pacman is at the correct location
    //! \param row: The row where the pacman is located
    //! \param col: The col where the pacman is located
    //! \return True if the fruit is located. Otherwise, false
    //!
    bool isThereAFruit( int const& row, int const& col );
    //!
    //! \brief Getter for the points of eaten fruit
    //! \return The points of eaten fruit
    //!
    Uint16 getTotalFruitScore();
    //!
    //! \brief Method to render the fruit
    //! \param renderer: SDL_Renderer* of the window
    //!
    void renderFruit( SDL_Renderer* renderer );

private:
    std::vector<Fruit*> _fruits;                         /*!< Array containing instances of Fruit */
    std::vector<std::vector<int> > _fruitLocationsGrid;  /*!< Array for the fruit locations in the grid */
    std::vector<SDL_Rect> _fruiSelections;               /*!< Array for the fruit selections on the sprite */
    std::vector<SDL_Rect> _fruitPositions;               /*!< Array for the fruit positions on the screen */
    int8_t _currentFruitLocationGrid;                    /*!< Index of the current position where a fruit is rendered */
    int8_t _currentFruitType;                            /*!< Flag to know which type of fruit is rendered */
    Uint32 _currentFruitChrono;                          /*!< Chronometer to know when the fruit was rendered */
    Uint32 _betweenFruitChrono;                          /*!< Chronometer to know since when no fruit was rendered */
    Uint64 _totalFruitScore;                             /*!< The points of eaten fruit */

};

#endif /* FRUITMANAGER_H */
