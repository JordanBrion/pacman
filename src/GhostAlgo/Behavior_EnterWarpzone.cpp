#include "Behavior_EnterWarpzone.h"
#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"

Behavior_EnterWarpzone::Behavior_EnterWarpzone( Ghost* master,
                                                PacMan* pacMan ) {

    _ghost = master;
    _pacMan = pacMan;

}

Behavior_EnterWarpzone::~Behavior_EnterWarpzone() {}

void Behavior_EnterWarpzone::run() {}

Uint8 Behavior_EnterWarpzone::getState() const { return ENTER_WARPZONE; }
