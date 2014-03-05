#ifndef AREAGAME_H
#define AREAGAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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

class AreaGame
{
public:
    AreaGame(int, int);
    ~AreaGame();
    bool imgLoad();
    void initLevelTable(char[]);
    std::vector<std::vector<int> > getLevelTable();
    int getLevelTableCase(int, int);
    void initLevelSpriteCoord();
    std::vector<std::map<std::string, int> > getLevelSpriteCoord();
    void addCharacterCoord(std::string, int, int);
    std::map<std::string, std::map<std::string, int> > getCharactersCoord();
    void initArea(char[], SDL_Renderer*);

private:
    int _rowsNbr;
    int _colsNbr;
    SDL_Surface *_spriteLevel;
    SDL_Surface *_spriteAnim;
    std::vector<std::vector<int> > _levelTable;
    std::vector<std::map<std::string, int> > _levelSpriteCoord;
    std::map<std::string, std::map<std::string, int> > _charactersCoord;

};

#endif // AREAGAME_H
