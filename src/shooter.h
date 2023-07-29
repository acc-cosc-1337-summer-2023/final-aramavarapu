//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "roll.h"

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter 
{
public:
Roll* throw_die(Die& die1, Die& die2);
~Shooter();
friend std::ostream& operator<<(std::ostream& os, const Shooter& shooter);

private:
std::vector<Roll*> rolls;
};

#endif