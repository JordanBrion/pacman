#include "Bubble.h"

using namespace std;

Bubble::Bubble( map<string, int> dest, int type, int x, int y, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : InteractiveElement( dest, renderer, sprite ), _eaten( false ), _caseType( type ) {

    _selection.w = 13;
    _selection.h = 13;
    _selection.x = 3;
    _selection.y = 183;

    _position.w = 20;
    _position.h = 20;
    _position.x = x;
    _position.y = y;

}

Bubble::~Bubble() {
}

bool Bubble::isEaten() const {

    return _eaten;

}

void Bubble::setEaten( int const& state ) {

    _eaten = state;

}

int Bubble::getCaseType() const {

    return _caseType;

}

void Bubble::setCaseType( int const& type ){

    _caseType = type;

}

