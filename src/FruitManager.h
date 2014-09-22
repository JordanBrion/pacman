#ifndef FRUITMANAGER_H
#define FRUITMANAGER_H

//!
//! \file FruitManager.h
//! \brief Class to manage the fruit (location, number, points...).
//! \author Jordan Brion
//! \version 0.1
//! \date 22 september 2014
//!

#include "Fruit.h"

#include <SDL2/SDL.h>

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
    //! \param renderer: SDL_Renderer* of the window
    //! \param sprite: SDL_Surface* containing the sprite for the level */
    //!
    void initFruit( SDL_Renderer* const& renderer, SDL_Surface* const& sprite );
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
    Fruit* getOneFruit( int type ) const;
    //!
    //! \brief Getter for the number of fruit eaten specified by the type parameter
    //! \param type: Type of fruit to increment
    //! \return The number of fruit eaten specified by the type parameter
    //!
    int getFruitNbr( int type ) const {
    //!
    //! \brief Setter to increment the number of fruit eaten specified by the type parameter
    //! \param type: Type of fruit to increment
    //!
    void incFruitNbr( int type );
    //!
    //! \brief Setter to decrement the number of fruit eaten specified by the type parameter
    //! \param type: Type of fruit to decrement
    //!
    void decFruitNbr( int type );
    //!
    //! \brief Getter for the number of points earned for fruit specified by the type parameter
    //! \param type: Type of fruit
    //! \return The number of points earned for fruit specified by the type parameter
    //!
    int getFruitPoints( int type ) const;
private:
    std::vector<Fruit*> _fruit;                         /*!< Array containing instances of Fruit */

};

#endif /* FRUITMANAGER_H */
