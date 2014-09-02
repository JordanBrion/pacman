#include "PacDot.h"

using namespace std;

PacDot::PacDot( map<string, int> dest, int type, int x, int y, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : InteractiveElement( dest, renderer, sprite ), _eaten( false ), _caseType( type ) {

    initRect(&_selection, 13, 13, 3, 183);
    initRect(&_position, 8, 8, x, y);

}

PacDot::~PacDot() {
}

bool PacDot::isEaten() const {

    return _eaten;

}

void PacDot::setEaten( int const& state ) {

    _eaten = state;

}

int PacDot::getCaseType() const {

    return _caseType;

}

void PacDot::setCaseType( int const& type ){

    _caseType = type;

}

int PacDot::show( SDL_Renderer* const& renderer ) {

    int score(0);

    if( !_eaten ) {

        InteractiveElement::show( renderer );

    }
    else {

        score = PAC_DOT;

    }

    return score;

}

