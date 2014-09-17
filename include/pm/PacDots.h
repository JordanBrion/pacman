#ifndef PACDOTS_H
#define PACDOTS_H

#include <SDL2/SDL.h>

namespace PacDots {

    ///!
    //! \brief Enum for the pacdot paths
    //!
    enum pacDotsPath {

        PACDOTS_PATH = -1,
        PACDOTS_EMPTY = -2,
        PACDOTS_HOR = -3,
        PACDOTS_VER = -4,
        PACDOTS_ANGLE_TOP_LEFT = -5,
        PACDOTS_ANGLE_TOP_RIGHT = -6,
        PACDOTS_ANGLE_BOTTOM_LEFT = -7,
        PACDOTS_ANGLE_BOTTOM_RIGHT = -8,
        PACDOTS_JUNCTION_3_TOTOP = -9,
        PACDOTS_JUNCTION_3_TOBOTTOM = -10,
        PACDOTS_JUNCTION_3_TORIGHT = -11,
        PACDOTS_JUNCTION_3_TOLEFT = -12,
        PACDOTS_JUNCTION_4 = -13,
        PACDOTS_POWERPELLET = -14

    };

    static const Uint16 POWERPELLET_DURATION = 10000;   /*!< The duration of the power pellet chronometer */

}

#endif /* PACDOTS_H */
