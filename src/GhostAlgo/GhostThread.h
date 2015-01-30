#ifndef     GHOSTTHREAD_H
#define     GHOSTTHREAD_H

//!
//! \file GhostThread.h
//! \brief Thread for the ghost behavior
//! \author Jordan Brion
//! \version 0.1
//! \date 30 January 2015
//!

#include <SDL2/SDL_thread.h>

class Ghost;

//!
//! \class GhostThread
//! \brief Thread for the ghost behavior
//!
class GhostThread {

    /* METHODS */
public:
    //!
    //! \brief GhostThread constructor
    //! \param master : A pointer on the ghost master
    //! \param pacMan : A pointer on the Pac-Man
    //! \param quitGame: Pointer on quitGame attribute of the Window class
    //!
    GhostThread( Ghost* master,
                 Uint16 id,
                 bool* const& quitGame );
    //!
    //! \brief GhostThread destructor
    //!
    ~GhostThread();
    //!
    //! \brief Static method to create the thread
    //! \param data : Void pointer on the GhostThread instance
    //! \return Return value of loop method
    //!
    static int createThread( void* data );
    //!
    //! \brief Loop to call the current ghost behavior
    //! \return Return 0
    //!
    int loop();

    /* ATRIBUTES */
private:
    Ghost* _ghost;              /*!< Pointer on the ghost master */
    SDL_Thread* _thread;        /*!< Thread to manage the ghost behavior */
    SDL_mutex* _lock;           /*!< Mutex to pause the ghost thread */
    SDL_cond* _canMove;         /*!< Condition to (un)pause the ghost thread */
    bool* _quit;                /*!< Flag to quit the game */

};

#endif      /* GHOSTTHREAD_H */
