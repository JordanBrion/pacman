#include "InteractiveElement.h"

using namespace std;

/* STATIC VARIABLES */
Uint16 InteractiveElement::instancesCounter = 0;

InteractiveElement::InteractiveElement() {}

InteractiveElement::InteractiveElement( std::map<std::string, int>& dest ) :
    _row( dest["row"] ),
    _col( dest["col"] ) {

    // Inc counter for new instance ID
    instancesCounter++;
    _instanceID = instancesCounter;

}

void InteractiveElement::show( SDL_Renderer* const& renderer) {

    SDL_Rect selection = _surface->getSelection();
    SDL_Rect position = _surface->getPosition();

    SDL_RenderCopy( renderer,
                    _surface->getTexture(),
                    &selection,
                    &position );

}

int InteractiveElement::getRow() const {

    return _row;

}

int InteractiveElement::getCol() const {

    return _col;

}

SurfaceSelection* InteractiveElement::getSurface() const { return _surface; }

SDL_Rect InteractiveElement::getSelection() const { return _surface->getSelection(); }

SDL_Rect InteractiveElement::getPosition() const { return _surface->getPosition(); }

Uint16 InteractiveElement::getInstanceID() const { return _instanceID; }
