//
#include "shooter.h"
#include "roll.h"
//public
Roll* Shooter::throw_die(Die& die1, Die& die2) {
    Roll* roll = new Roll(die1, die2);
    roll->roll_die();
    rolls.push_back(roll);
    return roll;
}
std::ostream& operator<<(std::ostream& os, const Shooter& shooter) {
    os << "Shooter rolls: " << std::endl;
    for (const Roll* roll : shooter.rolls) {
        os << "Rolled " << roll->roll_value() << std::endl;
    }
    return os;
}
Shooter::~Shooter() {
    for (Roll* roll : rolls) {
        delete roll;
    }
    rolls.clear();
}
//private