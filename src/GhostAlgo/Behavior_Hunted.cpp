#include "Behavior_Hunted.h"

#include "../InteractiveElements/PacMan.h"
#include "../InteractiveElements/Ghost.h"
#include "Behavior_Hunter.h"
#include "Behavior_ReturnToWarpzone.h"
#include "Behavior_ShowScore.h"

#include <pm/Arithmetic.h>
#include <pm/PacDots.h>

Behavior_Hunted::Behavior_Hunted( Ghost* master,
                                  PacMan* pacMan ) {

    _ghost = master;
    _pacMan = pacMan;

}

Behavior_Hunted::~Behavior_Hunted() {}

void Behavior_Hunted::run() {}

Uint8 Behavior_Hunted::getState() const { return HUNTED; }
