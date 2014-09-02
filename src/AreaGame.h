#ifndef AREAGAME_H
#define AREAGAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <map>
#include <string>
#include "Area.h"
#include "Const.h"

class AreaGame: public Area {

public:
    AreaGame( SDL_Renderer* const& pRenderer, SDL_Surface* const& pSpriteLevel );
    void drawArea(SDL_Renderer* const& pRenderer,
                    int const& pRowsNbr, int const& pColsNbr,
                    std::vector<std::vector<int> > pLevelTable, std::vector<std::map<std::string, int> > pLevelSpriteCoord);

};

#endif
