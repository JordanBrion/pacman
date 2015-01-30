#include <pm/Points.h>

#include "PacDot.h"
#include "../Surfaces/Surface.h"

using namespace std;

PacDot::PacDot( std::map<std::string, int>& dest,
                const int& type,
                const SDL_Rect& selection,
                const SDL_Rect& position,
                SDL_Texture* const& sprite ) :
    InteractiveElement( dest ),
    _eaten( false ),
    _caseType( type ) {

    _surface = new SurfaceSelection( sprite, selection, position );

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

        score = POINTS_PACDOT;

    }

    return score;

}

