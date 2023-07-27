#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
TEST_CASE("Verify Die Roll Values", "verfication") {
    Die dice;
    for (int i = 0; i < 10; ++i) {
        dice.roll();
        int result = dice.rolled_value();
        REQUIRE(result >= 1);
        REQUIRE(result <= 6);
    }
}
TEST_CASE("Die Roll Returns Value from 2 to 12", "verfication") {
Die die1, die2;
Roll roll(die1, die2);
    for (int i = 0; i < 10; ++i) {
        roll.roll_die();
        int result = roll.roll_value();
        REQUIRE(result >= 2);
        REQUIRE(result <= 12);
    }
}