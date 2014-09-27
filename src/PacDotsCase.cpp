#include "PacDotsCase.h"
#include "PowerPellet.h"

#include <pm/PacDots.h>
using namespace PacDots;

using namespace std;

PacDotsCase::PacDotsCase( int const& row, int const& col, int const& type, SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) :
    _row( row ), _col( col ), _type( type ) {

    _empty = false;

    switch( type ) {

    case PACDOTS_EMPTY:
        _empty = true;
        break;
    case PACDOTS_HOR:
    case PACDOTS_VER:
        initPacDotsInLine( renderer, sprite );
        break;
    case PACDOTS_ANGLE_TOP_LEFT:
    case PACDOTS_ANGLE_TOP_RIGHT:
    case PACDOTS_ANGLE_BOTTOM_LEFT:
    case PACDOTS_ANGLE_BOTTOM_RIGHT:
        initPacDotsInAngle( renderer, sprite );
        break;
    case PACDOTS_JUNCTION_3_TOTOP:
    case PACDOTS_JUNCTION_3_TOBOTTOM:
    case PACDOTS_JUNCTION_3_TORIGHT:
    case PACDOTS_JUNCTION_3_TOLEFT:
        initPacDotsWithThreeJunctions( renderer, sprite );
        break;
    case PACDOTS_JUNCTION_4:
        initPacDotsWithFourJunctions( renderer, sprite );
        break;
    case PACDOTS_POWERPELLET:
        initPacDotPowerPellet( renderer, sprite );
        break;

    }

}

PacDotsCase::~PacDotsCase() {



}

int PacDotsCase::getType() const {

    return _type;

}

void PacDotsCase::setType( int const& type ) {

    _type = type;

}

int PacDotsCase::render(SDL_Renderer* const& renderer) {

    int score = 0;

    if( _type != PACDOTS_EMPTY ) {

        for( int i(0); i < _pacDots.size(); i++ ) {

            score += _pacDots[i]->show( renderer );

        }

    }

    return score;

}

vector<PacDot*> PacDotsCase::getPacDots() const {

    return _pacDots;

}

PacDot* PacDotsCase::getPacDot( int const& x, int const& y ) const {

    if( _type != PACDOTS_EMPTY ) {

        for( int i(0); i < _pacDots.size(); i++ ) {

            if( _type != PACDOTS_POWERPELLET && x == _pacDots[i]->getPosition().x
                    && y == _pacDots[i]->getPosition().y )  {

                return _pacDots[i];

            }
            else if( _type == PACDOTS_POWERPELLET && x-5 == _pacDots[i]->getPosition().x
                        && y-5 == _pacDots[i]->getPosition().y )  {

                return _pacDots[i];

            }

        }

    }

    return NULL;

}

void PacDotsCase::reinitPacDotsEaten() {

    for( int i(0); i < _pacDots.size(); i++ ) {

        _pacDots[i]->setEaten( false );

    }

}

void PacDotsCase::setPacDotEaten( int const& x, int const& y, bool eaten ) {

    PacDot *p = getPacDot(x, y);

    if( p != NULL ) {

        p->setEaten(eaten);

    }

}

void PacDotsCase::initPacDotsInLine( SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    map<string, int> dest;
    dest["row"] = _row;
    dest["col"] = _col;

    int x = 0;
    int y = 0;

    if( _type == PACDOTS_HOR ) {

        // Bubble in the center of the case
        x = _col*30 + AREAGAME_MARGIN + 30 + 8;
        y = _row*30 + AREATOP_HEIGHT + 10;
        _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );

        // Bubble on the right corner of the case
        x = _col*30 + AREAGAME_MARGIN + 30 + 22;
        _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );

    }
    else if( _type == PACDOTS_VER ) {

        x = _col*30 + AREAGAME_MARGIN + 30 + 10;
        y = _row*30 + AREATOP_HEIGHT + 1;
        _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );

        y = _row*30 + AREATOP_HEIGHT + 17;
        _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );

    }

}

void PacDotsCase::initPacDotsInAngle( SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    map<string, int> dest;
    dest["row"] = _row;
    dest["col"] = _col;

    int x = _col*30 + AREAGAME_MARGIN + 30 + 10;
    int y = _row*30 + AREATOP_HEIGHT + 10;

    switch( _type ) {

    case PACDOTS_ANGLE_TOP_LEFT:
    case PACDOTS_ANGLE_BOTTOM_LEFT:
        _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );
        x = _col*30 + AREAGAME_MARGIN + 30 + 23;
        y = _row*30 + AREATOP_HEIGHT + 10;
        _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );
        break;

    case PACDOTS_ANGLE_TOP_RIGHT:
    case PACDOTS_ANGLE_BOTTOM_RIGHT:
        _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );
        break;

    }

}

void PacDotsCase::initPacDotsWithThreeJunctions( SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    map<string, int> dest;
    dest["row"] = _row;
    dest["col"] = _col;

    int x = _col*30 + AREAGAME_MARGIN + 30 + 10;
    int y = _row*30 + AREATOP_HEIGHT + 10;

    switch( _type ) {

    case PACDOTS_JUNCTION_3_TOTOP:
    case PACDOTS_JUNCTION_3_TOBOTTOM:
    case PACDOTS_JUNCTION_3_TORIGHT:
        _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );
        x = _col*30 + AREAGAME_MARGIN + 30 + 23;
        _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );
        break;

    case PACDOTS_JUNCTION_3_TOLEFT:
        _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );
        break;

    }

}

void PacDotsCase::initPacDotsWithFourJunctions( SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    map<string, int> dest;
    dest["row"] = _row;
    dest["col"] = _col;

    int x = _col*30 + AREAGAME_MARGIN + 30 + 10;
    int y = _row*30 + AREATOP_HEIGHT + 10;
    _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );

    x = _col*30 + AREAGAME_MARGIN + 30 + 23;
    _pacDots.push_back( new PacDot( dest, _type, x, y, renderer, sprite ) );


}

void PacDotsCase::initPacDotPowerPellet( SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    map<string, int> dest;
    dest["row"] = _row;
    dest["col"] = _col;

    int x = _col*30 + AREAGAME_MARGIN + 30 + 5;
    int y = _row*30 + AREATOP_HEIGHT + 30/2 - 10;

    _pacDots.push_back( new PowerPellet( dest, _type, x, y, renderer, sprite ) );

}
