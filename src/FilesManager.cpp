#include "FilesManager.h"

#include <pm/Level.h>
using namespace Level;

using namespace std;

FilesManager::FilesManager() {

    _rowsNbr = 22;
    _colsNbr = 23;
    _lifesNbr = 3;
    _pacdotsNbr = 350;
    _ghostsNbr = 4;
    _highScore = 0;
    _logo = NULL;
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

int FilesManager::getPacDotsNbr() const {

    return _pacdotsNbr;

}

int FilesManager::getGhostsNbr() const {

    return _ghostsNbr;

}

int FilesManager::getHighScore() const {

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

    // Temp array to store the teleporation locations
    map<char, vector<vector<int> > > tempTeleportationLocations;

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
            _levelTable[i].push_back( EMPTY_CASE ); // Free space

        }

        // Fruit => =
        else if( *rows == '=' ) {

            // Add fruit location
            addFruitLocationCoord( { i, j } );
            _levelTable[i].push_back( EMPTY_CASE ); // Free space

        }

        // Alphabetic caracters => teleportation to another part of the level
        else if( isalpha( *rows ) ) {

            // Calculate if the letter is the source or destination

            // If the key is not found => this letter is the source
            if ( tempTeleportationLocations.find( *rows ) == tempTeleportationLocations.end() ) {

                vector<vector<int> > temp;
                temp.push_back( { i, j } );
                tempTeleportationLocations.insert( pair<char, vector<vector<int> > >( *rows, temp ) );

            }

            // If the key is found, this letter is the destination
            else {

                tempTeleportationLocations[ *rows ].push_back( { i, j } );

            }

            _levelTable[i].push_back( EMPTY_CASE ); // Free space

        }

        // Others cases
        else {

            temp = atoi(rows);
            _levelTable[i].push_back( temp );
        }

        j++;

        rows = strtok_r( NULL, ";", &context );

    }

    // Now all the teleportation locations are stored in an array
    // => Sort the values
    if( tempTeleportationLocations.size() > 0 ) {
        sortTeleportationLocationsCoord( tempTeleportationLocations );
    }

}

vector<vector<int> > FilesManager::getLevelTable() const {

    return _levelTable;

}

int FilesManager::getLevelTableCase(int i, int j) const {

    return _levelTable[i][j];

}

bool FilesManager::loadIMG(){

    _logo = IMG_Load("../media/img/logo.bmp");
    SDL_SetColorKey( _logo, SDL_TRUE, SDL_MapRGB( _logo->format, 255, 255, 255) );
    _spriteLevel = IMG_Load("../media/img/sprite-level.png");
    _spriteCharacters = IMG_Load("../media/img/sprite-anim.png");

    if( _logo == NULL || _spriteLevel == NULL || _spriteCharacters == NULL )
        return false;

    return true;

}

SDL_Surface* FilesManager::getLogo() const {

    return _logo;

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

    for (int i = 0; i < LEVELPROPERTIES_COUNT; i++) {

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

void FilesManager::addFruitLocationCoord( vector<int> coord ) {

    // Coordonates of the fruit on the screen
    // Fruit can pop at multiple places. So, save all this places
    _fruitLocationCoord.push_back( coord );

}

vector<vector<int> > FilesManager::getFruitLocationCoord() const {

    return _fruitLocationCoord;

}

vector<int> FilesManager::getOneFruitLocationCoord( int index ) const {

    return _fruitLocationCoord[ index ];

}

void FilesManager::sortTeleportationLocationsCoord( map<char, vector<vector<int> > > locations ) {

    /*
     *
     * Param locations content => how the array is organized ?
     * Example:
     * locations["letter"] => where "letter" is an alphabetic letter
     * locations["letter"][0] => source
     * locations["letter"][1] => destination
     * locations["letter"][X][0] and locations["letter"][X][1] => row and col coordinates
     *
     */

    /*
     *
     * Now we have to sort this locations array
     * _teleportationLocationsCoord["x_y"] => "x_y" is a string with x = current row position
     *                                                          and y = current col position
     * _teleportationLocationsCoord["x_y"][0]
     * _teleportationLocationsCoord["x_y"][1]
     * => the destination ( indexes: 0=row; 1=col ) where the character has to be teleported
     *
     */

    for( map<char, vector<vector<int> > >::iterator it = locations.begin(); it != locations.end(); ++it ) {

        // Array containing source and destination
        vector<vector<int> > array = it->second;

        // If we are at the source => go to the destination
        string key = to_string( array[0][0] ) + "_" + to_string( array[0][1] );
        _teleportationLocationsCoord[ key ] = { array[1][0], array[1][1] };

        // If we are at the destination => go to the source
        key = to_string( array[1][0] ) + "_" + to_string( array[1][1] );
        _teleportationLocationsCoord[ key ] = { array[0][0], array[0][1] };

    }

}

map<string, vector<int> > FilesManager::getTeleportationLocationsCoord() {

    return _teleportationLocationsCoord;

}

bool FilesManager::loadFont() {

    _font = TTF_OpenFont( "../media/fonts/slkscre.ttf", 28 );

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

