#include "AreaGame.h"

using namespace std;

AreaGame::AreaGame(int const& rows, int const& cols) : _rowsNbr(rows), _colsNbr(cols) {}

AreaGame::~AreaGame() {}

bool AreaGame::imgLoad() {

    _spriteLevel = IMG_Load("../pacman/img/sprite-level.png");
    _spriteAnim = IMG_Load("../pacman/img/sprite-anim.png");

    if( _spriteLevel == NULL || _spriteAnim == NULL )
        return false;

    return true;

}

SDL_Surface* AreaGame::getSpriteLevel() const {

    return _spriteLevel;

}

SDL_Surface* AreaGame::getSpriteAnim() const {

    return _spriteAnim;

}

void AreaGame::initLevelTable(char pLevel[]) {

    char* context = NULL;

    // Split in rows
    char* rows = strtok_r( pLevel, ";", &context );

    int i(0);
    int j(0);
    int ghostCounter(0);

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

        // If the case contains Pacman or a ghost > we add -1 (free space) in _levelTable
        // Pacman => @
        if( *rows == '@' ) {

            addCharacterCoord("Pacman", i, j);
            _levelTable[i].push_back( -1 ); // Free space

        }
        // Ghost => #
        else if( *rows == '#' ) {

            ghostCounter++;
            // Convert ghostCounter to string
            stringstream ss;
            ss << "Ghost" << ghostCounter;
            addCharacterCoord(ss.str(), i, j);
            _levelTable[i].push_back( -1 ); // Free space

        }
        // Others cases
        else {

            temp = atoi(rows);
            _levelTable[i].push_back( temp );
        }

        j++;

        rows = strtok_r( NULL, ";", &context );


    }


}

vector<vector<int> > AreaGame::getLevelTable() const {

    return _levelTable;

}

int AreaGame::getLevelTableCase(int i, int j) const {

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

vector<map<string, int> > AreaGame::getLevelSpriteCoord() const {

    return _levelSpriteCoord;

}

void AreaGame::addCharacterCoord(string key, int x, int y) {

    // Coordonates of the character on the screen
    _charactersCoord[key]["x"] = x;
    _charactersCoord[key]["y"] = y;

}

map<string, map<string, int> > AreaGame::getCharactersCoord() const {

    return _charactersCoord;

}

int AreaGame::getCharacterCoordX(string key) {

    return _charactersCoord[key]["x"];

}

int AreaGame::getCharacterCoordY(string key) {

    return _charactersCoord[key]["y"];

}

void AreaGame::initArea( char pLevel[], SDL_Renderer* const& pRenderer ) {

    initLevelTable(pLevel);
    initLevelSpriteCoord();

    SDL_Texture *text = SDL_CreateTextureFromSurface( pRenderer, _spriteLevel);

    // Position on the screen
    SDL_Rect position;
    position.x = 0;
    position.y = 0;
    position.w = 30;
    position.h = 30;
    // Selection the image on the sprite
    SDL_Rect selection;
    selection.x = 0;
    selection.y = 0;
    selection.w = 30;
    selection.h = 30;

    int element = -1;

    // Loop for the levelTable array and show each value of this table on the screen
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
