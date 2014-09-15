#include "PacDotsManager.h"

#include <pm/PacDots.h>
using namespace PacDots;

using namespace std;

PacDotsManager::PacDotsManager( vector<vector<int> > level, SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    for( int i(0); i < level.size(); i++ ) {

        addRow();

        for( int j(0); j < level[i].size(); j++ ) {

            addCase( i, level[i][j], renderer, sprite );

        }

    }

}

PacDotsManager::~PacDotsManager() {


}

void PacDotsManager::addRow() {

    vector<PacDotsCase*> v;
    _pacDotsCases.push_back( v );

}

void PacDotsManager::addCase( int const& row, int const& type, SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    PacDotsCase *pdc = ( type < PACDOTS_PATH ) ?
                                        new PacDotsCase( row, ( _pacDotsCases[ row ].size() ) -1, type, renderer, sprite ) :
                                        NULL;

    _pacDotsCases[ row ].push_back( pdc );

}

int PacDotsManager::render( SDL_Renderer* const& renderer ) {

    int score(0);

    for( int i(0); i < _pacDotsCases.size(); i++ ) {

        for( int j(0); j < _pacDotsCases[i].size(); j++ ) {

            if( _pacDotsCases[i][j] != NULL ) {

                score += _pacDotsCases[i][j]->render( renderer );

            }

        }

    }

    return score;

}

PacDot* PacDotsManager::isThereAPacDot( int const& row, int const& col, int const& x, int const& y ) {

    if( _pacDotsCases[ row ][ col ] != NULL ) {

        PacDot *p = _pacDotsCases[ row ][ col ]->getPacDot( x, y );

        if( p != NULL ) {

            // If Pac-Dot was not eaten
            if( !p->isEaten() ) {

                return p;

            }

        }

    }

    return NULL;

}

bool PacDotsManager::eatPacDot( int const& row, int const& col, int const& x, int const& y ) {

    int tempRow = row - 1;
    int tempCol = col - 1;

    PacDot* p(0);
    bool powerPellet( false );

    while( tempRow <= row + 1 ) {

        p = isThereAPacDot( tempRow, col, x, y );

        if( p != NULL ) {

            p->setEaten( true );
            if( p->getCaseType() == PACDOTS_POWERPELLET )
                powerPellet = true;

        }

        tempRow++;

    }

    while( tempCol <= col + 1 ) {

        p = isThereAPacDot( row, tempCol, x, y );

        if( p != NULL ) {

            p->setEaten( true );
            if( p->getCaseType() == PACDOTS_POWERPELLET )
                powerPellet = true;

        }

        tempCol++;

    }

    return powerPellet;

}

void PacDotsManager::reinitAllPacDotsEaten() {

    for( int i(0); i < _pacDotsCases.size(); i++ ) {

        for( int j(0); j < _pacDotsCases[i].size(); j++ ) {

            if( _pacDotsCases[i][j] != NULL ) {

                _pacDotsCases[i][j]->reinitPacDotsEaten();

            }

        }

    }

}

