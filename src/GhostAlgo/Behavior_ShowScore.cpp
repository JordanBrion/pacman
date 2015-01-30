#include "Behavior_ShowScore.h"

#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"
#include "Behavior_ReturnToWarpzone.h"

Behavior_ShowScore::Behavior_ShowScore( Ghost* master,
                                        PacMan* pacMan ) {

    _ghost = master;
    _pacMan = pacMan;

}

Behavior_ShowScore::~Behavior_ShowScore() {}

void Behavior_ShowScore::run() {}

Uint8 Behavior_ShowScore::getState() const { return SHOW_SCORE; }
