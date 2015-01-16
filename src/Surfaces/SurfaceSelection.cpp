#include "SurfaceSelection.h"

SurfaceSelection::SurfaceSelection( SDL_Texture* const& texture,
                                    const SDL_Rect& selection,
                                    const SDL_Rect& position ) :
    Surface( texture, position ),
    _selection( selection ) {

}

SurfaceSelection::~SurfaceSelection() {


}

SDL_Rect SurfaceSelection::getSelection() const {

    return _selection;

}

void SurfaceSelection::setSelection( const int& w, const int& h,
                                     const int& x, const int& y ) {

    _selection.w = w;
    _selection.h = h;
    _selection.x = x;
    _selection.y = y;

}

void SurfaceSelection::setSelection( const SDL_Rect& rect ) { _selection = rect; }

void SurfaceSelection::setSelectionW( const int& w ) { _selection.w = w; }

void SurfaceSelection::setSelectionH( const int& h ) { _selection.h = h; }

void SurfaceSelection::setSelectionX( const int& x ) { _selection.x = x; }

void SurfaceSelection::setSelectionY( const int& y ) { _selection.y = y; }
