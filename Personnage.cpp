#include "Personnage.h"

using namespace std;

Personnage::Personnage(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : InteractiveElement(dest, renderer, sprite) {

}

void Personnage::moveVertically(bool up) {

    // If move to the top
    if(up) {

        _position.y -= 1;

    }
    // Else move the the bottom
    else {

        _position.y += 1;

    }

}

void Personnage::moveHorizontally(bool left) {

    // If move to the left
    if(left) {

        _position.x -= 1;

    }
    // Else move to the right
    else {

        _position.x += 1;

    }

}

void Personnage::calculateDirection(int x, int y, vector<vector<int> > levelTable) {

    // Check if the next positions are runnable by pacman
    _directionsPossible["up"] = ( levelTable[y-1][x] < 0 ) ? true : false;
    _directionsPossible["bottom"] = ( levelTable[y+1][x] < 0 ) ? true : false;
    _directionsPossible["right"] = ( levelTable[y][x+1] < 0 ) ? true : false;
    _directionsPossible["left"] = ( levelTable[y][x-1] < 0 ) ? true : false;

}
