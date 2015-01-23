#include "WindowManager.h"

WindowManager::WindowManager() {}

WindowManager::~WindowManager() {}

bool WindowManager::manage( Window* const window, const int8_t& type ) {

    return _managements[type]->manage( window );

}
