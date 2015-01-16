#include "Surface.h"

Surface::Surface( SDL_Texture* texture,
                  const SDL_Rect& position ) :
    _texture( texture ),
    _position( position ) {

}

Surface::~Surface() {

}

SDL_Texture* Surface::getTexture() const {

    return _texture;

}

SDL_Rect Surface::getPosition() const {

    return _position;

}

void Surface::initRect( SDL_Rect* rect,
                        const int& w, const int& h,
                        const int& x, const int& y ) {

    rect->w = w;
    rect->h = h;
    rect->x = x;
    rect->y = y;

}
