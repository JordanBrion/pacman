#include "Bubble.h"

using namespace std;

Bubble::Bubble( map<string, int> dest, int type, int x, int y, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : InteractiveElement( dest, renderer, sprite ), _eaten( false ), _caseType( type ) {

    initRect(&_selection, 13, 13, 3, 183);
    initRect(&_position, 8, 8, x, y);

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

int Bubble::show( SDL_Renderer* const& renderer ) {

    int score(0);

    if( !_eaten ) {

        InteractiveElement::show( renderer );

    }
    else {

        score = PAC_DOT;

    }

    return score;

}

