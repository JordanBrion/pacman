#include "BubblesCase.h"

using namespace std;

BubblesCase::BubblesCase( int const& row, int const& col, int const& type, SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) :
    _row( row ), _col( col ), _type( type ) {

    _empty = false;

    switch( type ) {

    case BUBBLES_EMPTY:
        _empty = true;
        break;
    case BUBBLES_HOR:
        initBubblesInLine( renderer, sprite );
        break;
    case BUBBLES_VER:
        initBubblesInLine( renderer, sprite );
        break;
    case BUBBLES_ANGLE_TOP_LEFT:
    case BUBBLES_ANGLE_TOP_RIGHT:
    case BUBBLES_ANGLE_BOTTOM_LEFT:
    case BUBBLES_ANGLE_BOTTOM_RIGHT:
        initBubblesInAngle( renderer, sprite );
        break;
    case BUBBLES_JUNCTION_3_TOTOP:
    case BUBBLES_JUNCTION_3_TOBOTTOM:
    case BUBBLES_JUNCTION_3_TORIGHT:
    case BUBBLES_JUNCTION_3_TOLEFT:
        initBubblesWithThreeJunctions( renderer, sprite );
        break;
    case BUBBLES_JUNCTION_4:
        break;

    }

}

BubblesCase::~BubblesCase() {



}

int BubblesCase::getType() const {

    return _type;

}

void BubblesCase::setType( int const& type ) {

    _type = type;

}

void BubblesCase::render(SDL_Renderer* const& renderer) {

    for( int i(0); i < _bubbles.size(); i++ ) {

        _bubbles[i]->show( renderer );

    }

}

vector<Bubble*> BubblesCase::getBubbles() const {

    return _bubbles;

}

Bubble* BubblesCase::getBubble( int const& x, int const& y ) const {

    if( _type != BUBBLES_EMPTY ) {

        for( int i(0); i < _bubbles.size(); i++ ) {

            if( x == _bubbles[i]->getPosition().x && y == _bubbles[i]->getPosition().y ) {

                return _bubbles[i];

            }

        }

    }

    return NULL;

}

void BubblesCase::reinitBubblesEaten() {

    for( int i(0); i < _bubbles.size(); i++ ) {

        _bubbles[i]->setEaten( false );

    }

}

void BubblesCase::setBubbleEaten( int const& x, int const& y, bool eaten ) {

    Bubble *b = getBubble(x, y);

    if( b != NULL ) {

        b->setEaten(eaten);

    }

}

void BubblesCase::initBubblesInLine( SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    map<string, int> dest;
    dest["row"] = _row;
    dest["col"] = _col;

    if( _type == BUBBLES_HOR ) {

        _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );
        _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );

    }
    else if( _type == BUBBLES_VER ) {

        _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );
        _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );

    }

}

void BubblesCase::initBubblesInAngle( SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    map<string, int> dest;
    dest["row"] = _row;
    dest["col"] = _col;

    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );
    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );
    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );

}

void BubblesCase::initBubblesWithThreeJunctions( SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    map<string, int> dest;
    dest["row"] = _row;
    dest["col"] = _col;

    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );
    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );
    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );
    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );


}

void BubblesCase::initBubblesWithFourJunctions( SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    map<string, int> dest;
    dest["row"] = _row;
    dest["col"] = _col;

    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );
    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );
    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );
    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );
    _bubbles.push_back( new Bubble( dest, _type, _col*30, _row*30, renderer, sprite ) );


}
