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

void FilesManager::initLevelTable(){
}

vector<vector<int> > FilesManager::getLevelTable() const {
}

int FilesManager::getLevelTableCase( int i, int j ) const {
}

bool FilesManager::loadIMG(){
}

SDL_Texture* FilesManager::getSpriteLevel() const {
}

SDL_Texture* FilesManager::getSpriteCharacters() const {
}

void FilesManager::initLevelSpriteCoord(){
}

vector<map<string, int> > FilesManager::getLevelSpriteCoord() const {
}

void FilesManager::addCharacterCoord ( string key, int x, int y ){
}

map<string, map<string, int> > FilesManager::getCharactersCoord() const {
}

int FilesManager::getCharacterCoordX ( string key ) const {
}

int FilesManager::getCharacterCoordY ( string key ) const {
}

void FilesManager::loadFont(){
}

TTF_Font* FilesManager::getFont() const {
}

void FilesManager::free(){
}

