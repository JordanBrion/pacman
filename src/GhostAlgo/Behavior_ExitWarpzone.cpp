#include "Behavior_ExitWarpzone.h"
#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"

Behavior_ExitWarpzone::Behavior_ExitWarpzone( Ghost* master,
                                              PacMan* pacMan ) {

    _ghost = master;
    _pacMan = pacMan;

}

Behavior_ExitWarpzone::~Behavior_ExitWarpzone() {}

void Behavior_ExitWarpzone::run() {}

Uint8 Behavior_ExitWarpzone::getState() const { return EXIT_WARPZONE; }
