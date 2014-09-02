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
    InteractiveElement(SDL_Renderer* const& renderer, SDL_Surface* const& sprite);
    InteractiveElement(std::map<std::string, int>, SDL_Renderer* const&, SDL_Surface* const&);
public:
    void show(SDL_Renderer* const&);
    void initRect(SDL_Rect* rect, int const& w, int const& h, int const& x, int const&  y);
    int getRow() const;
    int getCol() const;
    SDL_Rect getPosition() const;
    SDL_Rect getSelection() const;

protected:
    int _row;
    int _col;
    SDL_Texture* _element;
    SDL_Rect _position;
    SDL_Rect _selection;
    int _zIndex;
public:
    static int zIndexCounter;

};

#endif
