#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Window/Window.h"
#include <iostream>

using namespace std;

int main( int argc, char* args[] ) {

    Window *window = new Window();
    //window->drawSplashScreen();
    window->loop();

    return 0;

}
