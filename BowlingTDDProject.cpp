#include "catch/catch.hpp"
#include "BowlingGame.h"

class SimpleCalculator {
public:
    int add(int a, int b) {
        return a + b;
    }
};

TEST_CASE("SimpleCalculator_add_test") {
    SimpleCalculator testObj;

    REQUIRE( testObj.add(2, 2) == 4);
    REQUIRE( testObj.add(2, 4) == 6);
}

TEST_CASE("OneRoundWith0PinsShouldScore0") {
    BowlingGame game;
    
    game.roll(0);
    game.roll(0);

    REQUIRE( game.getScore() == 0);
}

TEST_CASE("RollsWithoutStrikeAndSpareShouldScoreSumOfRolls") {
    BowlingGame game;
    
    game.roll(2);
    REQUIRE( game.getScore() == 2);
    game.roll(3);
    REQUIRE( game.getScore() == 5);
    game.roll(6);
    REQUIRE( game.getScore() == 11);
    game.roll(1);
    REQUIRE( game.getScore() == 12);
}

TEST_CASE("RollsWithSpare") {
    BowlingGame game;
    
    game.roll(5);
    REQUIRE( game.getScore() == 5);
    game.roll(5);
    REQUIRE( game.getScore() == 10);

    game.roll(4);
    REQUIRE( game.getScore() == 18);

    game.roll(6);
    REQUIRE( game.getScore() == 24);

    game.roll(1);
    REQUIRE( game.getScore() == 26);
}

TEST_CASE("RollsWithStrikes") {
    BowlingGame game;
    
    game.roll(10);
    REQUIRE( game.getScore() == 10);

    game.roll(5);
    REQUIRE( game.getScore() == 20);

    game.roll(3);
    REQUIRE( game.getScore() == 26);

    game.roll(10);
    REQUIRE( game.getScore() == 36);

    game.roll(10);
    REQUIRE( game.getScore() == 56);

    game.roll(1);
    REQUIRE( game.getScore() == 59);

    game.roll(1);
    REQUIRE( game.getScore() == 61);
}

TEST_CASE("RollsWithSparesAndStrikes")
{
    BowlingGame game;
    
    game.roll(10);
    REQUIRE( game.getScore() == 10);

    game.roll(5);
    REQUIRE( game.getScore() == 20);

    game.roll(5);
    REQUIRE( game.getScore() == 30);

    game.roll(10);
    REQUIRE( game.getScore() == 50);

    game.roll(10);
    REQUIRE( game.getScore() == 70);

    game.roll(5);
    REQUIRE( game.getScore() == 85);

    game.roll(5);
    REQUIRE( game.getScore() == 95);

    game.roll(1);
    REQUIRE( game.getScore() == 97);
}

TEST_CASE("PerfectGameShouldScore300")
{
    BowlingGame game;
    
    for (auto i = 0; i < 12; i++)
        game.roll(10);

    REQUIRE( game.getScore() == 300);
}