#include <iostream>
#include <vector>
#include <ctime>
#include "shooter.h"
#include "roll.h"
#include "die.h"
#include "come_out_phase.h"
#include "point_phase.h"
int main() {
    srand(static_cast<unsigned>(time(0)));

    Die die1, die2;
    Shooter shooter;
    Roll* roll = shooter.throw_die(die1, die2);
    ComeOutPhase come_out_phase;
    while (come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps) {
        std::cout << "Rolled " << roll->roll_value() << " Roll again" << std::endl;
        delete roll;
        roll = shooter.throw_die(die1, die2);
    }
    std::cout << "Rolled " << roll->roll_value() << " Start of point phase" << std::endl;
    int point = roll->roll_value();
    std::cout << "Roll until " << point << " or 7 is rolled" << std::endl;
    delete roll;
    PointPhase point_phase(point);
    Roll* pointRoll = nullptr;
    while (point_phase.get_outcome(pointRoll) != RollOutcome::point && point_phase.get_outcome(pointRoll) != RollOutcome::seven_out) {
        if (pointRoll != nullptr) {
            std::cout << "Rolled " << pointRoll->roll_value() << std::endl;
            delete pointRoll;
        }
        pointRoll = shooter.throw_die(die1, die2); 
    }
    if (pointRoll) {
        std::cout << "Rolled " << pointRoll->roll_value() << " - End of point phase" << std::endl;
        delete pointRoll;
    }
    std::cout << shooter << std::endl;
    return 0;
}