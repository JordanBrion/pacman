#include "SurfaceSelection.h"

SurfaceSelection::SurfaceSelection( SDL_Texture* texture,
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
