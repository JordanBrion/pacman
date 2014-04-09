#include "InteractiveElement.h"

using namespace std;

/* STATIC VARIABLES */
int InteractiveElement::zIndexCounter = 0;

InteractiveElement::InteractiveElement(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite) :
        _initialX(dest["x"]), _initialY(dest["y"]) {

    // Initialize texture
    _element = SDL_CreateTextureFromSurface(renderer, sprite);

    // Initialize positions on the screen
    _initialStateDest["x"] = dest["x"] * 30 + AREAGAME_MARGIN;
    _initialStateDest["y"] = dest["y"] * 30 + AREATOP_HEIGHT;
    _position.x = _initialStateDest["x"];
    _position.y = _initialStateDest["y"];
    _position.w = 30;
    _position.h = 30;

    // Inc counter for z-index
    zIndexCounter++;
    // z-index
    _zIndex = zIndexCounter;

}

void InteractiveElement::show(SDL_Renderer* const& pRenderer) {

    SDL_RenderCopy(pRenderer, _element, &_selection, &_position);

}

SDL_Rect InteractiveElement::getPosition() const {

    return _position;

}
