#ifndef FILESMANAGER_H
#define FILESMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <map>
#include "Const.h"

class FilesManager {

public:
    FilesManager();
    ~FilesManager();
    void loadFileXML();
    void loadFileLevel();
    void initLevelTable();
    std::vector<std::vector<int> > getLevelTable() const;
    int getLevelTableCase( int i, int j ) const;
    bool loadIMG();
    SDL_Texture* getSpriteLevel() const;
    SDL_Texture* getSpriteCharacters() const;
    void initLevelSpriteCoord();
    std::vector<std::map<std::string, int> > getLevelSpriteCoord() const;
    void addCharacterCoord ( std::string key, int x, int y );
    std::map<std::string, std::map<std::string, int> > getCharactersCoord() const;
    int getCharacterCoordX( std::string key ) const;
    int getCharacterCoordY( std::string key ) const;
    void loadFont();
    TTF_Font* getFont() const;
    void free();

private:
    int _rowsNbr;
    int _colsNbr;
    int _areaGameWidth;
    int _areaGameHeight;
    int _lifesNbr;
    int _ghostsNbr;
    SDL_Texture* _spriteLevel;
    SDL_Texture* _spriteCharacters;
    std::vector<std::vector<int> > _levelTable;
    std::vector<std::map<std::string, int> > _levelSpriteCoord;
    std::map<std::string, std::map<std::string, int> > _charactersCoord;
    TTF_Font* _font;

};

#endif
