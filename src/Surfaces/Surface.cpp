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

void Surface::setPosition( const int& w, const int& h,
                           const int& x, const int& y ) {

    _position.w = w;
    _position.h = h;
    _position.x = x;
    _position.y = y;
}

void Surface::setPosition( const SDL_Rect& rect ) { _position = rect; }

void Surface::setPositionW( const int& w ) { _position.w = w; }

void Surface::setPositionH( const int& h ) { _position.h = h; }

void Surface::setPositionX( const int& x ) { _position.x = x; }

void Surface::setPositionY( const int& y ) { _position.y = y; }

void Surface::initRect( SDL_Rect* rect,
                        const int& w, const int& h,
                        const int& x, const int& y ) {

    rect->w = w;
    rect->h = h;
    rect->x = x;
    rect->y = y;

}
