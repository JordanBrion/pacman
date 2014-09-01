#include "AreaBottom.h"

using namespace std;

AreaBottom::AreaBottom() {}

void AreaBottom::drawLifesPanel( SDL_Renderer* const& pRenderer, SDL_Surface* const& pSpriteCharacters, TTF_Font* const& pFont, int const& pLifesNbr ) {

    // Show lifes number image
    _texture = SDL_CreateTextureFromSurface(pRenderer, pSpriteCharacters);

    _selection.w = 35;
    _selection.h = 38;
    _selection.x = 283;
    _selection.y = 43;

    _position.w = 30;
    _position.h = 30;
    _position.x = AREAGAME_MARGIN + 10;
    _position.y = AREAGAME_HEIGHT;

    SDL_RenderCopy( pRenderer, _texture, &_selection, &_position );

    // Show lifes number
    string s = to_string(pLifesNbr);
    char const *c = s.c_str();
    SDL_Surface* textSurface = TTF_RenderText_Solid( pFont, c, SDL_WHITE );
    _texture = SDL_CreateTextureFromSurface(pRenderer, textSurface);
    _position.x += 40;

    SDL_RenderCopy( pRenderer, _texture, NULL, &_position );

    SDL_FreeSurface( textSurface );

}

void AreaBottom::drawFruitPanel( SDL_Renderer* const& pRenderer, SDL_Surface* const& pSpriteCharacters, TTF_Font* const& pFont, vector<Fruit*> pFruit ) {

    _texture = SDL_CreateTextureFromSurface(pRenderer, pSpriteCharacters);

    SDL_Surface* textSurface = NULL;

    for( int i(0); i < pFruit.size(); i++ ) {

        // Show fruit image
        pFruit[i]->initPositionAreaBottom();
        _selection = pFruit[i]->getSelection();
        _position = pFruit[i]->getPosition();
        pFruit[i]->show( pRenderer );

        // Show fruit number
        string s = to_string( pFruit[i]->getNbr() );
        char const *c = s.c_str();
        textSurface = TTF_RenderText_Solid( pFont, c, SDL_WHITE );
        _texture = SDL_CreateTextureFromSurface(pRenderer, textSurface);
        _position.x = pFruit[i]->getPosition().x + 30;

        SDL_RenderCopy( pRenderer, _texture, NULL, &_position );

    }

    SDL_FreeSurface( textSurface );

}


