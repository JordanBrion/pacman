#ifndef INTERACTIVEELEMENT_H
#define INTERACTIVEELEMENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include "Const.h"

class InteractiveElement {

protected:
    SDL_Surface* _element;
    SDL_Rect _position;
    int _zIndex;

protected:
    virtual void init () = 0;

};

#endif
