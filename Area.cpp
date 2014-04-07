#include "Area.h"

Area::Area() {

    // Initialize value
    _texture = NULL;

}

Area::~Area() {

    free();

}

void Area::free() {

    SDL_DestroyTexture(_texture);
    _texture = 0;

}

