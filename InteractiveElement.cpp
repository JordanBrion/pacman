#include "InteractiveElement.h"

using namespace std;

/* STATIC VARIABLES */
int InteractiveElement::zIndexCounter = 0;

InteractiveElement::InteractiveElement(SDL_Renderer* const& renderer, SDL_Surface* const& sprite) {

    // Initialize texture
    _element = SDL_CreateTextureFromSurface(renderer, sprite);

    // Inc counter for z-index
    zIndexCounter++;
    // z-index
    _zIndex = zIndexCounter;

}

InteractiveElement::InteractiveElement(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite) :
        _row(dest["row"]), _col(dest["col"]) {

    // Initialize texture
    _element = SDL_CreateTextureFromSurface(renderer, sprite);

    // Initialize positions on the screen
    int x = dest["col"] * 30 + AREAGAME_MARGIN;
    int y = dest["row"] * 30 + AREATOP_HEIGHT;
    initRect(&_position, 30, 30, x, y);

    // Inc counter for z-index
    zIndexCounter++;
    // z-index
    _zIndex = zIndexCounter;

}

void InteractiveElement::show(SDL_Renderer* const& pRenderer) {

    SDL_RenderCopy(pRenderer, _element, &_selection, &_position);

}

void InteractiveElement::initRect(SDL_Rect* rect, int const& w, int const& h, int const& x, int const&  y) {

    rect->w = w;
    rect->h = h;
    rect->x = x;
    rect->y = y;

}

int InteractiveElement::getRow() const {

    return _row;

}

int InteractiveElement::getCol() const {

    return _col;

}

SDL_Rect InteractiveElement::getPosition() const {

    return _position;

}

SDL_Rect InteractiveElement::getSelection() const {

    return _position;

}
