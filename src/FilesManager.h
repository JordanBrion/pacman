#ifndef FILESMANAGER_H
#define FILESMANAGER_H

//!
//! \file FilesManager.h
//! \brief Class to manage all the media files (images, fonts...) .
//! \author Jordan Brion
//! \version 0.1
//! \date 2 september 2014
//!

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <exception>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <sstream>
#include "Const.h"

typedef struct element {
    uint8_t row;
    uint8_t col;
} Element;

typedef struct s_warpzone {

    Element entrance, exit;
    int8_t orientationEnter;
    int8_t orientationExit;
    bool vertical;

} Warpzone;

//!
//! \class FilesManager
//! \brief Class to manage all the media files (images, fonts...) .
//!
class FilesManager {

public:
    //!
    //!  \brief FilesManager constructor
    //!
    FilesManager();
    //!
    //!  \brief FilesManager destructor
    //!
    ~FilesManager();
    //!
    //!  \brief Method to load the XML file containing the data of the level
    //!
    void loadFileXML();
    //!
    //!  \brief Method to load the file containing the level
    //!
    void loadFileLevel();
    //!
    //!  \brief Getter for the number of rows
    //!  \return The number of rows
    //!
    int getRowsNbr() const;
    //!
    //!  \brief Getter for the number of columns
    //!  \return The number of columns
    //!
    int getColsNbr() const;
    //!
    //!  \brief Getter for the number of lifes
    //!  \return The number of lifes
    //!
    int getLifesNbr() const;
    //!
    //!  \brief Getter for the number of pac-dots
    //!  \return The number of pac-dots
    //!
    int getPacDotsNbr() const;
    //!
    //!  \brief Getter for the number of ghosts
    //!  \return The number of ghosts
    //!
    int getGhostsNbr() const;
    //!
    //!  \brief Getter for the highscore of the level
    //!  \return The highscore of the level
    //!
    int getHighScore() const;
    //!
    //!  \brief Method to load the array containing the level in form of caracters
    //!  \param pLevel : The level in form of string
    //!
    void initLevelTable(char pLevel[]);
    //!
    //!  \brief Getter for the array containing the level in form of caracters
    //!  \return The array containing the level in form of caracters
    //!
    std::vector<std::vector<int> > getLevelTable() const;
    //!
    //!  \brief Getter for an element of the array containing the level in form of caracters
    //!  \param i : Row
    //!  \param j : Column
    //!  \return An element of the array containing the level in form of caracters
    //!
    int getLevelTableCase( int i, int j ) const;
    //!
    //!  \brief Method to load the images with SDL2_image
    //!  \return True if no error in the loading. Otherwise, false.
    //!
    bool loadIMG();
    //!
    //! \brief Getter for the logo of the game
    //! \return The logo of the game
    //!
    SDL_Surface* getLogo() const;
    //!
    //!  \brief Getter for the sprite containing the level
    //!  \return The sprite containing the level
    //!
    SDL_Surface* getSpriteLevel() const;
    //!
    //!  \brief Getter for the sprite containing the characters
    //!  \return The sprite containing the characters
    //!
    SDL_Surface* getSpriteCharacters() const;
    //!
    //!  \brief Method to initialize the coordinates of the sprite level
    //!
    void initLevelSpriteCoord();
    //!
    //!  \brief Getter for the array containing the coordinates of the sprite level
    //!  \return The array containing the coordinates of the sprite level
    //!
    std::vector<std::map<std::string, int> > getLevelSpriteCoord() const;
    //!
    //! \brief Getter for the Warpzone infos (see struct above)
    //! \return The Warpzone infos
    //!
    Warpzone* getWarpzone();
    //!
    //! \brief Getter for the entrance coordinates of the Warpzone
    //! \return The entrance coordinates of the Warpzone
    //!
    Element* getWarpzoneEntrance();
    //!
    //! \brief Getter for the exit coordinates of the Warpzone
    //! \return The exit coordinates of the Warpzone
    //!
    Element* getWarpzoneExit();
    //!
    //!  \brief Method to add the position of a character in the grid
    //!  \param key : The key to identify the character
    //!  \param row : The row
    //!  \param col : The column
    //!
    void addCharacterCoord ( std::string key, int row, int col );
    //!
    //!  \brief Getter for the position of the characters in the grid
    //!  \return The position of the characters in the grid
    //!
    std::map<std::string, std::map<std::string, int> > getCharactersCoord() const;
    //!
    //!  \brief Getter for the row of a character in the grid
    //!  \param key : The key to identify the character
    //!  \return The row of a character in the grid
    //!
    int getCharacterCoordRow( std::string key );
    //!
    //!  \brief Getter for the column of a character in the grid
    //!  \param key : The key to identify the character
    //!  \return The column of a character in the grid
    //!
    int getCharacterCoordCol( std::string key );
    //!
    //!  \brief Method to add the position of a fruit in the grid
    //!  \param coord : Row and col of the fruit
    //!
    void addFruitLocationCoord( std::vector<int> coord );
    //!
    //! \brief Getter for the coord of all the fruit
    //! \return Vector for all the fruit locations
    //!
    std::vector<std::vector<int> > getFruitLocationCoord() const;
    //!
    //! \brief Getter for the coord of the desired fruit (specified by the index)
    //! \param index: The desired fruit
    //! \return Vector for the coord of the desired fruit (specified by the index)
    //!
    std::vector<int> getOneFruitLocationCoord( int index ) const;
    //!
    //! \brief Method to sort in a std::map the teleporation locations coordinates
    //! \param locations: The locations coordinates
    //!
    void sortTeleportationLocationsCoord( std::map<char, std::vector<std::vector<int> > > locations );
    //!
    //! \brief Getter for the teleportation locations coordinates
    //! \return The teleportation locations coordinates
    //!
    std::map<std::string, std::vector<int> > getTeleportationLocationsCoord();
    //!
    //!  \brief Method to load the font files with SDL2_ttf
    //!  \return True if no error in the loading. Otherwise, false.
    //!
    bool loadFont();
    //!
    //!  \brief Getter for the game font
    //!  \return The font of the game.
    //!
    TTF_Font* getFont() const;
    //!
    //!  \brief Method to free all the variables in memory
    //!
    void free();

private:
    int _rowsNbr;                                                           /*!< Number of rows in the level */
    int _colsNbr;                                                           /*!< Number of columns in the level */
    int _areaGameWidth;                                                     /*!< Width of the area game */
    int _areaGameHeight;                                                    /*!< Height of the area game */
    int _lifesNbr;                                                          /*!< Number of lifes */
    int _pacdotsNbr;                                                        /*!< Number of pac-dots */
    int _ghostsNbr;                                                         /*!< Number of ghosts */
    int _highScore;                                                         /*!< Highscore of the level */
    SDL_Surface* _logo;                                                     /*!< SDL_Surface containing the logo of the game */
    SDL_Surface* _spriteLevel;                                              /*!< Sprite for the level */
    SDL_Surface* _spriteCharacters;                                         /*!< Sprite for the characters */
    std::vector<std::vector<int> > _levelTable;                             /*!< Array containing the level in form of caracters */
    std::vector<std::map<std::string, int> > _levelSpriteCoord;             /*!< Array containing the coordinates of the sprite level */
    Warpzone _warpzone;                                                     /*!< Warpzone infos (see struct above) */
    std::map<std::string, std::map<std::string, int> > _charactersCoord;    /*!< Array containing the position of the characters in the level */
    std::vector<std::vector<int> > _fruitLocationCoord;                     /*!< Array containing the position of the fruit in the level */
    std::map<std::string, std::vector<int> > _teleportationLocationsCoord;  /*!< Array containing all the teleporation locations */
    TTF_Font* _font;                                                        /*!< Font of the game */

};

#endif
