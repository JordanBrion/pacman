#include <sstream>

#include "../InteractiveElements/Ghost.h"
#include "GhostThread.h"

GhostThread::GhostThread( Ghost* master,
                          Uint16 id,
                          bool* const& quitGame ) :
    _ghost( master ),
    _quit( quitGame ) {

    std::stringstream ss;
    ss << "Ghost Thread (Instance ID:" << id << ")";
    _thread = SDL_CreateThread( createThread,
                                &(ss.str()[0]),
                                (void*) this );

}

GhostThread::~GhostThread() {

    SDL_DestroyMutex( _lock );
    SDL_DestroyCond( _canMove );

}

int GhostThread::createThread( void* data ) {

    GhostThread* g = (GhostThread*) data;
    return g->loop();

}

int GhostThread::loop() {

    while( !*_quit ) {

        _ghost->getBehavior()->run();
        SDL_Delay( 20 );

    }

    return 0;

}

