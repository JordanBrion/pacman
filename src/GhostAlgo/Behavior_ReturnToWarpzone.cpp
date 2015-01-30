#include "Behavior_ReturnToWarpzone.h"
#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"

Behavior_ReturnToWarpzone::Behavior_ReturnToWarpzone( Ghost* master,
                                                      PacMan* pacMan ) {

    _ghost = master;
    _pacMan = pacMan;

}

Behavior_ReturnToWarpzone::~Behavior_ReturnToWarpzone() {}

void Behavior_ReturnToWarpzone::run() {}

Uint8 Behavior_ReturnToWarpzone::getState() const { return RETURN_TO_WARPZONE; }
