//
#include<iostream>
#include<cstdlib> 
#include<ctime>
#include "die.h"
#ifndef ROLL_H
#define ROLL_H

class Roll
{
public:
Roll(Die& d1, Die& d2);
void roll_die();
int roll_value() const;

private:
Die& die1;
Die& die2;
bool rolled {false};
int value;

};


#endif