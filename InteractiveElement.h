#ifndef INTERACTIVEELEMENT_H
#define INTERACTIVEELEMENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include "Const.h"

class InteractiveElement {

protected:
    InteractiveElement(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
public:
    void show(SDL_Renderer* const&);
    SDL_Rect getPosition() const;

protected:
    int _x;
    int _y;
    std::map<std::string, int> _initialStateSrc; // Initial coord on the sprite
    std::map<std::string, int> _initialStateDest; // Coord on the screen at the start of the game
    SDL_Texture* _element;
    SDL_Rect _position;
    SDL_Rect _selection;
    static int zIndexCounter;
    int _zIndex;

};

#endif
