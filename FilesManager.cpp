#include "FilesManager.h"

using namespace std;

FilesManager::FilesManager(){
}

FilesManager::~FilesManager(){
}

void FilesManager::loadFileXML(){
}

void FilesManager::loadFileLevel(){
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

            addCharacterCoord("Pacman", j, i);
            _levelTable[i].push_back( -1 ); // Free space

        }
        // Ghost => #
        else if( *rows == '#' ) {

            ghostCounter++;
            // Convert ghostCounter to string
            stringstream ss;
            ss << "Ghost" << ghostCounter;
            addCharacterCoord(ss.str(), j, i);
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

void FilesManager::addCharacterCoord(string key, int x, int y) {

    // Coordonates of the character on the screen
    _charactersCoord[key]["x"] = x;
    _charactersCoord[key]["y"] = y;

}

map<string, map<string, int> > FilesManager::getCharactersCoord() const {

    return _charactersCoord;

}

int FilesManager::getCharacterCoordX(string key) {

    return _charactersCoord[key]["x"];

}

int FilesManager::getCharacterCoordY(string key) {

    return _charactersCoord[key]["y"];

}

void FilesManager::loadFont(){
}

TTF_Font* FilesManager::getFont() const {
}

void FilesManager::free(){
}

