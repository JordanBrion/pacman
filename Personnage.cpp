#include "Personnage.h"

using namespace std;

Personnage::Personnage(map<string, int> src, map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : InteractiveElement(src, dest, renderer, sprite) {


}
