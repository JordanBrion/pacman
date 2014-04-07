#ifndef AREA_H
#define AREA_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Const.h"

class Area {

protected:
    Area();
public:
    ~Area();
    void free();
protected:
    virtual void drawArea (SDL_Renderer* const& pRenderer) = 0;

protected:
    SDL_Texture* _texture;
    SDL_Rect _position;
    SDL_Rect _selection;

};

#endif
