#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "point_phase.h"
#include "come_out_phase.h"
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}
TEST_CASE("Test die rolls return a value from 1 to 6", "verfication") {
    Die dice;
    for (int i = 0; i < 10; ++i) {
        dice.roll();
        int result = dice.rolled_value();
        REQUIRE(result >= 1);
        REQUIRE(result <= 6);
    }
}
TEST_CASE("Test die rolls return a value from 2 to 12", "verfication") {
Die die1, die2;
Roll roll(die1, die2);
    for (int i = 0; i < 10; ++i) {
        roll.roll_die();
        int result = roll.roll_value();
        REQUIRE(result >= 2);
        REQUIRE(result <= 12);
    }
}
TEST_CASE("Test that ComeOutPhase get outcomes returns values RollOutcome::natural, RollOutcome::craps, and RollOutcome::point", "verfication") {
    Die die1, die2;
    ComeOutPhase comeOutPhase;
    
    Roll roll1(die1, die2);
    roll1.roll_die();
    int rollValue = roll1.roll_value();
    REQUIRE((rollValue == 7 || rollValue == 11));
    RollOutcome outcome = comeOutPhase.get_outcome(&roll1);
    REQUIRE(outcome == RollOutcome::natural);

    Roll roll2(die1, die2);
    roll2.roll_die();
    rollValue = roll2.roll_value();
    REQUIRE((rollValue == 2 || rollValue == 3 || rollValue == 12)); 
    outcome = comeOutPhase.get_outcome(&roll2);
    REQUIRE(outcome == RollOutcome::craps);

    Roll roll3(die1, die2);
    roll3.roll_die();
    rollValue = roll3.roll_value();
    REQUIRE(!(rollValue == 2 || rollValue == 3 || rollValue == 7 || rollValue == 11 || rollValue == 12));
    outcome = comeOutPhase.get_outcome(&roll3);
    REQUIRE(outcome == RollOutcome::point);
}