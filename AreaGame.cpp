#include "AreaGame.h"

using namespace std;

AreaGame::AreaGame( SDL_Renderer* const& pRenderer, SDL_Surface* const& pSpriteLevel ) {

    _texture = SDL_CreateTextureFromSurface( pRenderer, pSpriteLevel);

}

void AreaGame::drawArea( SDL_Renderer* const& pRenderer,
                         int const& pRowsNbr, int const& pColsNbr,
                         vector<vector<int> > pLevelTable, vector<map<string, int> > pLevelSpriteCoord ) {

    // Reinitialize values of position on the screen
    _position.x = 0;
    _position.y = 0;
    _position.w = 30;
    _position.h = 30;

    //  Reinitialize values of selection the image on the sprite
    _selection.x = 0;
    _selection.y = 0;
    _selection.w = 30;
    _selection.h = 30;

    int element = -1;

    // Loop for the levelTable array and show each value of this table on the screen
    for(int i(0); i < pRowsNbr; i++) {

        for(int j(0); j < pColsNbr; j++) {

            element = pLevelTable[i][j];

            // If this is not a free space
            if( element > -1 ) {

                // Select new position on the sprite
                _selection.y = pLevelSpriteCoord[ element ]["y"];
                SDL_RenderCopy( pRenderer, _texture, &_selection, &_position );

            }

            // Position on the window
            _position.x += 30;

        }

        _position.x = 0;
        _position.y += 30;

    }

}
