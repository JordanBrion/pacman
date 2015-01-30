#include "Behavior_Hunter.h"

#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"
#include "Behavior_Hunted.h"

Behavior_Hunter::Behavior_Hunter( Ghost* master,
                                  PacMan* pacMan ) {

    _ghost = master;
    _pacMan = pacMan;

}

Behavior_Hunter::~Behavior_Hunter() {}

void Behavior_Hunter::run() {}

Uint8 Behavior_Hunter::getState() const { return HUNTER; }
