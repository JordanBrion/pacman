#ifndef     CHRONO_H
#define     CHRONO_H

//!
//! \file Chrono.h
//! \brief Template class for a chronometer
//! \author Jordan Brion
//! \version 0.1
//! \date 26 January 2015
//!

#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>

#include <string>
#include <iostream>

#define     STOPPED     0       //! \def Macro for a stopped chronometer
#define     RUNNING     1       //! \def Macro for a running chronometer
#define     PAUSED      2       //! \def Macro for a paused chronometer

//!
//! \class Chrono
//! \brief Template class for a chronometer
//!
template<typename T>
class Chrono {

    /* METHODS */
public:

    //!
    //! \brief Chrono constructor
    //! \param durationInMillis : duration in ms
    //! \param name : name of the chronometer
    //! \param obj : Instance used to call the callback function
    //! \param callback : Pointer to member callback function
    //!
    Chrono( Uint32 durationInMillis,
            const std::string& name,
            T* obj,
            void (T::*callback)() ) :
        _durationInMillis( durationInMillis ),
        _state( STOPPED ),
        _thread( NULL ),
        _name( name ),
        _obj( obj ),
        _callback( callback ) {

    }

    //!
    //! \brief Chrono destructor
    //!
    ~Chrono() {}

    //!
    //! \brief Method to start the chronometer
    //!
    void start() throw( const char* ) {

        try {

            if( _state == STOPPED ) {
                _startInMillis = SDL_GetTicks();
                _thread = SDL_CreateThread( threadFunc, _name.c_str(), (void*) this );
                _state = RUNNING;
            }
            else
                throw "Chrono already running";

        }
        catch( const char* msg ) {

            std::cerr << msg << std::endl;

        }

    }

    //!
    //! \brief Method to check if the chronometer is running
    //! \return True if the chronometer is running. Otherwise, false
    //!
    bool isRunning() const {

        return _state == RUNNING;

    }

    //!
    //! \brief Method to pause the chronometer
    //!
    void pause() throw( const char* ) {

        try {

            if( _state == RUNNING ) {
                // _startInMillis become an offset
                _startInMillis = SDL_GetTicks() - _startInMillis;
                _state = PAUSED;
            }
            else
                throw "Chrono not running";

        }
        catch( const char* msg ) {

            std::cerr << msg << std::endl;

        }

    }

    //!
    //! \brief Method to check if the chronometer is paused
    //! \return True if the chronometer is paused. Otherwise, false
    //!
    bool isPaused() const {

        return _state == PAUSED;

    }

    //!
    //! \brief Method to unpause the chronometer
    //!
    void unpause() throw( const char* ) {

        try {

            if( _state == PAUSED ) {
                // Use _startInMillis offset to calculate the new start value
                _startInMillis = SDL_GetTicks() - _startInMillis;
                _state = RUNNING;
            }
            else
                throw "Chrono not paused";

        }
        catch( const char* msg ) {

            std::cerr << msg << std::endl;

        }

    }

    //!
    //! \brief Method to stop the chronometer
    //!
    void stop() throw( const char* ) {

        try {

            if( _state == RUNNING || _state == PAUSED ) {
                _startInMillis = 0;
                _state = STOPPED;
            }
            else
                throw "Chrono not started";

        }
        catch( const char* msg ) {

            std::cerr << msg << std::endl;

        }

    }

    //!
    //! \brief Method to check if the chronometer is stopped
    //! \return True if the chronometer is stopped. Otherwise, false
    //!
    bool isStopped() const {

        return _state == STOPPED;

    }

    //!
    //! \brief Method to reset the chronometer
    //!
    void reset() throw( const char* ) {

        try {

            if( _state == RUNNING || _state == PAUSED ) {
                _state = STOPPED;
                start();
            }
            else
                throw "Chrono not started";

        }
        catch( const char* msg ) {

            std::cerr << msg << std::endl;

        }
    }

    //!
    //! \brief Method to check if the chronometer is over
    //! \return True if the chronometer is over. Otherwise, false
    //!
    bool isOver() const {

        if( _state == PAUSED )
            return 0;

        return ( _state == STOPPED || SDL_GetTicks() - _startInMillis > _durationInMillis );

    }

    //!
    //! \brief Method to wait for X ms
    //! \param DurationInMillis : The duration in ms
    //!
    void wait( Uint32 durationInMillis ) throw( const char* ) {

        try {

            if( _state == RUNNING ) {
                pause();
                SDL_Delay( durationInMillis );
                unpause();
            }
            else
                throw "Chrono not running";

        }
        catch( const char* msg) {

            std::cerr << msg << std::endl;

        }

    }

    //!
    //! \brief Getter for the remaining time in ms
    //! \return The remaining time in ms
    //!
    int getRemainingTimeInMillis() const {

        int value = (int) ( ( _startInMillis + _durationInMillis ) - SDL_GetTicks() );

        if( value < 0 ) {
            return 0;
        }

        return value;


    }

    //!
    //! \brief Getter for the duration in ms
    //! \return The duration in ms
    //!
    Uint32 getDurationInMillis() const { return _durationInMillis; }

    //!
    //! \brief Setter for the duration in ms
    //! \param The duration in ms
    //!
    void setDurationInMillis( Uint32 durationInMillis ) { _durationInMillis = durationInMillis; }

    //!
    //! \brief Getter for the state of the chronometer (see macro section above)
    //! \return The current state of the chrono
    //!
    Uint8 getState() const { return _state; }

    //!
    //! \brief Template getter for the instance on which call the callback method
    //! \return The instance on which call the callback method
    //!
    T* getObj() const { return _obj; }

private:
    //!
    //! \brief Method called by the SDL_CreateThread function
    //! \param data : Third param of the SDL_CreateThread function
    //! \return The value returned to SDL_WaitThread function
    //!
    static int threadFunc( void* data ) {

        Chrono* c = (Chrono*) data;

        return c->loop();

    }

    //!
    //! \brief Loop function to wait until the chronometer is over
    //! \return The value returned to SDL_WaitThread function
    //!
    int loop() {

        SDL_Delay( 1 ); // Without the delay, call immediately the callback O_____0 ??

        while( !isOver() ) {

            SDL_Delay( 100 );

        }

        stop();

        // Call the callback
        (getObj()->*_callback)();

        return 0;

    }

private:
    Uint32 _startInMillis;          /*!< Initialization time in ms */
    Uint32 _durationInMillis;       /*!< Duration in ms */
    Uint8 _state;                   /*!< State of the chronometer (see macro section above) */
    SDL_Thread* _thread;            /*!< Thread of the chronometer */
    std::string _name;              /*!< Name of the chronometer */
    T* _obj;                        /*!< Instance used to call the callback function */
    void (T::*_callback)();         /*!< Pointer to member callback function */

};

#endif      /* CHRONO_H */
