//
#include "point_phase.h"
//public
PointPhase::PointPhase(int p) : point(p) {}

RollOutcome PointPhase::get_outcome(Roll* roll) {
    int value = roll->roll_value();
    if (value == point) {
        return RollOutcome::point;
    } else if (value == 7) {
        return RollOutcome::seven_out;
    } else {
        return RollOutcome::nopoint;
    }
}
//private