#include "Behavior_InWarpzone.h"
#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"

Behavior_InWarpzone::Behavior_InWarpzone( Ghost* master,
                                          PacMan* pacMan ) {

    _ghost = master;
    _pacMan = pacMan;

}

Behavior_InWarpzone::~Behavior_InWarpzone() {}

void Behavior_InWarpzone::run() {}

Uint8 Behavior_InWarpzone::getState() const { return DEFAULT_WARPZONE; }
