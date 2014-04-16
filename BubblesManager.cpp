#include "BubblesManager.h"

using namespace std;

BubblesManager::BubblesManager( vector<vector<int> > level, SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    for( int i(0); i < level.size(); i++ ) {

        addRow();

        for( int j(0); j < level[i].size(); j++ ) {

            addCase( i, level[i][j], renderer, sprite );

        }

    }

}

BubblesManager::~BubblesManager() {


}

void BubblesManager::addRow() {

    vector<BubblesCase*> v;
    _bubblesCases.push_back( v );

}

void BubblesManager::addCase( int const& row, int const& type, SDL_Renderer* const& renderer, SDL_Surface* const& sprite ) {

    BubblesCase *b = ( type < BUBBLES_PATH ) ?
                                        new BubblesCase( row, ( _bubblesCases[ row ].size() ) -1, type, renderer, sprite ) :
                                        NULL;

    _bubblesCases[ row ].push_back( b );

}

void BubblesManager::render( SDL_Renderer* const& renderer ) {

    for( int i(0); i < _bubblesCases.size(); i++ ) {

        for( int j(0); j < _bubblesCases[i].size(); j++ ) {

            if( _bubblesCases[i][j] != NULL ) {

                _bubblesCases[i][j]->render( renderer );

            }

        }

    }

}

Bubble* BubblesManager::isThereABubble( int const& row, int const& col, int const& x, int const& y ) {

    if( _bubblesCases[ row ][ col ] != NULL ) {

        Bubble *b = _bubblesCases[ row ][ col ]->getBubble( x, y );

        if( b != NULL ) {

            // If bubble was not eaten
            if( !b->isEaten() ) {

                return b;

            }

        }

    }

    return NULL;

}

void BubblesManager::eatBubble( int const& row, int const& col, int const& x, int const& y ) {

    Bubble* b = isThereABubble( row, col, x, y );
    b->setEaten( true );

}

