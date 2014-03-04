#include "AreaGame.h"

using namespace std;

AreaGame::AreaGame(int rows, int cols) : _rowsNbr(rows), _colsNbr(cols) {}

AreaGame::~AreaGame() {}

bool AreaGame::imgLoad() {

    _spriteLevel = IMG_Load("../pacman/img/sprite-level.png");
    _spriteAnim = IMG_Load("../pacman/img/sprite-anim.png");

    if( _spriteLevel == NULL || _spriteAnim == NULL )
        return false;

    return true;

}

void AreaGame::initLevelTable(char pLevel[]) {

    char* context = NULL;

    // Split in rows
    char* rows = strtok_r( pLevel, ";", &context );

    int i(0);
    int j(0);

    // Before start, add of a subarray which will contain the data level of a row
    vector<int> subarray;
    int temp;
    _levelTable.push_back(subarray);

    // In the loop while there is something to split
    while (rows != NULL) {

        // Each iteration, check if the cols number is not exceeded
        // If yes, we reinitialize the values to zero and we add a new subarray
        if(j > _colsNbr - 1) {
            j = 0;
            i++;
            _levelTable.push_back(subarray);

        }

        temp = atoi(rows);
        _levelTable[i].push_back( temp );

        j++;

        rows = strtok_r( NULL, ";", &context );


    }


}

std::vector<std::vector<int> > AreaGame::getLevelTable() {

    return _levelTable;

}

int AreaGame::getLevelTableCase(int i, int j) {

    return _levelTable[i][j];

}

void AreaGame::initLevelSpriteCoord() {

    map<string, int> temp;
    int y(0);

    for (int i = 0; i < COUNT; i++) {

        // Insert the pictures coord of the sprite image in an array
        temp["y"] = y;
        _levelSpriteCoord.push_back( temp );
        y += 31;

    }

}

vector<map<string, int> > AreaGame::getLevelSpriteCoord() {

    return _levelSpriteCoord;

}

void AreaGame::initArea( char pLevel[], SDL_Renderer* pRenderer ) {

    initLevelTable(pLevel);
    initLevelSpriteCoord();

    SDL_Texture *text = SDL_CreateTextureFromSurface( pRenderer, _spriteLevel);

    SDL_Rect position;
    position.x = 0;
    position.y = 0;
    position.w = 30;
    position.h = 30;
    SDL_Rect selection;
    selection.x = 0;
    selection.y = 0;
    selection.w = 30;
    selection.h = 30;

    int element = -1;

    for(int i(0); i < _rowsNbr; i++) {

        position.x = 0;
        position.y += 30;

        for(int j(0); j < _colsNbr; j++) {

            element = _levelTable[i][j];

            // If this is not a free space
            if( element > -1 ) {

                // Select new position on the sprite
                selection.y = _levelSpriteCoord[ element ]["y"];

            }

            // Position on the window
            position.x += 30;

            if( element > -1 ) {
                SDL_RenderCopy( pRenderer, text, &selection, &position );
            }

        }

    }

}
