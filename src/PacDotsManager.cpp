#include "PacDotsManager.h"

using namespace std;

#include "InteractiveElements/PacDot.h"

PacDotsManager::PacDotsManager( std::vector<std::vector<int> > level,
                                SDL_Texture* const& sprite ) {

    for( int i(0); i < level.size(); i++ ) {

        addRow();

        for( int j(0); j < level[i].size(); j++ ) {

            addCase( i, level[i][j], sprite );

        }

    }

}

PacDotsManager::~PacDotsManager() {


}

void PacDotsManager::addRow() {

    vector<PacDotsCase*> v;
    _pacDotsCases.push_back( v );

}

void PacDotsManager::addCase( int const& row,
                              int const& type,
                              SDL_Texture* const& sprite ) {

    PacDotsCase *pdc = ( type < PACDOTS_LAYOUT ) ?
                                        new PacDotsCase( row, ( _pacDotsCases[ row ].size() ) -1, type, sprite ) :
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

PacDot* PacDotsManager::isThereAPacDot( int const& row, int const& col,
                                        int const& x, int const& y ) {

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

bool PacDotsManager::eatPacDot( int const& row, int const& col,
                                int const& x, int const& y ) {

    int startRow = ( row-1 > -1 ) ? row-1 : row;
    int startCol = ( col-1 > -1 ) ? col-1 : col;

    int endRow = ( row+1 < _pacDotsCases.size() ) ? row+1 : row;
    int endCol = ( col+1 < _pacDotsCases[0].size() ) ? col+1 : col;

    PacDot* p(0);
    bool powerPellet( false );

    while( startRow <= endRow ) {

        p = isThereAPacDot( startRow, col, x, y );

        if( p != NULL ) {

            p->setEaten( true );
            if( p->getCaseType() == PACDOTS_POWERPELLET )
                powerPellet = true;

        }

        startRow++;

    }

    while( startCol <= endCol ) {

        p = isThereAPacDot( row, startCol, x, y );

        if( p != NULL ) {

            p->setEaten( true );
            if( p->getCaseType() == PACDOTS_POWERPELLET )
                powerPellet = true;

        }

        startCol++;

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

