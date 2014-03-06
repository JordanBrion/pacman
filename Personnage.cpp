#include "Personnage.h"

using namespace std;

Personnage::Personnage(map<string, int> dest, SDL_Renderer* const& renderer, SDL_Surface* const& sprite)
    : InteractiveElement(dest, renderer, sprite) {


}
