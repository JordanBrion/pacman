#include "FilesManager.h"

using namespace std;

FilesManager::FilesManager() {

    _rowsNbr = 22;
    _colsNbr = 23;
    _lifesNbr = 3;
    _bubblesNbr = 350;
    _ghostsNbr = 4;
    _highScore = 0;
    _spriteLevel = NULL;
    _spriteCharacters = NULL;
    _font = NULL;

}

FilesManager::~FilesManager(){
}

void FilesManager::loadFileXML(){
}

void FilesManager::loadFileLevel(){
}

int FilesManager::getRowsNbr() const {

    return _rowsNbr;

}

int FilesManager::getColsNbr() const {

    return _colsNbr;

}

int FilesManager::getLifesNbr() const {

    return _lifesNbr;

}

int FilesManager::getBubblesNbr() const {

    return _bubblesNbr;

}

int FilesManager::getGhostsNbr() const {

    return _ghostsNbr;

}

int FilesManager::getHighScoreNbr() const {

    return _highScore;

}

void FilesManager::initLevelTable(char pLevel[]) {

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

vector<vector<int> > FilesManager::getLevelTable() const {

    return _levelTable;

}

int FilesManager::getLevelTableCase(int i, int j) const {

    return _levelTable[i][j];

}

bool FilesManager::loadIMG(){

    _spriteLevel = IMG_Load("../pacman/img/sprite-level.png");
    _spriteCharacters = IMG_Load("../pacman/img/sprite-anim.png");

    if( _spriteLevel == NULL || _spriteCharacters == NULL )
        return false;

    return true;

}

SDL_Surface* FilesManager::getSpriteLevel() const {

    return _spriteLevel;

}

SDL_Surface* FilesManager::getSpriteCharacters() const {

    return _spriteCharacters;

}

void FilesManager::initLevelSpriteCoord() {

    map<string, int> temp;
    int y(0);

    for (int i = 0; i < COUNT; i++) {

        // Insert the pictures coord of the sprite image in an array
        temp["y"] = y;
        _levelSpriteCoord.push_back( temp );
        y += 31;

    }

}

vector<map<string, int> > FilesManager::getLevelSpriteCoord() const {

    return _levelSpriteCoord;

}

void FilesManager::addCharacterCoord(string key, int row, int col) {

    // Coordonates of the character on the screen
    _charactersCoord[key]["row"] = row;
    _charactersCoord[key]["col"] = col;

}

map<string, map<string, int> > FilesManager::getCharactersCoord() const {

    return _charactersCoord;

}

int FilesManager::getCharacterCoordRow(string key) {

    return _charactersCoord[key]["row"];

}

int FilesManager::getCharacterCoordCol(string key) {

    return _charactersCoord[key]["col"];

}

bool FilesManager::loadFont() {

    _font = TTF_OpenFont( "fonts/slkscre.ttf", 28 );

    if( !_font ) {
        return false;
    }

    return true;

}

TTF_Font* FilesManager::getFont() const {

    return _font;

}

void FilesManager::free(){
}

