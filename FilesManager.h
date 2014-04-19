#ifndef FILESMANAGER_H
#define FILESMANAGER_H

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

class FilesManager {

public:
    FilesManager();
    ~FilesManager();
    void loadFileXML();
    void loadFileLevel();
    int getRowsNbr() const;
    int getColsNbr() const;
    int getLifesNbr() const;
    int getGhostsNbr() const;
    void initLevelTable(char pLevel[]);
    std::vector<std::vector<int> > getLevelTable() const;
    int getLevelTableCase( int i, int j ) const;
    bool loadIMG();
    SDL_Surface* getSpriteLevel() const;
    SDL_Surface* getSpriteCharacters() const;
    void initLevelSpriteCoord();
    std::vector<std::map<std::string, int> > getLevelSpriteCoord() const;
    void addCharacterCoord ( std::string key, int row, int col );
    std::map<std::string, std::map<std::string, int> > getCharactersCoord() const;
    int getCharacterCoordRow( std::string key );
    int getCharacterCoordCol( std::string key );
    bool loadFont();
    TTF_Font* getFont() const;
    void free();

private:
    int _rowsNbr;
    int _colsNbr;
    int _areaGameWidth;
    int _areaGameHeight;
    int _lifesNbr;
    int _ghostsNbr;
    SDL_Surface* _spriteLevel;
    SDL_Surface* _spriteCharacters;
    std::vector<std::vector<int> > _levelTable;
    std::vector<std::map<std::string, int> > _levelSpriteCoord;
    std::map<std::string, std::map<std::string, int> > _charactersCoord;
    TTF_Font* _font;

};

#endif
