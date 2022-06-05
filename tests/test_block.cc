#include <catch2/catch.hpp>

#include "block.h"
#include "config.h"

using tetris::Block;
using tetris::kBlackColor;

TEST_CASE("Empty Constructor") {
  Block block = Block();
  SECTION("X Position") {
    REQUIRE(block.GetXPosition() == 0);
  }
  SECTION("Y Position") {
    REQUIRE(block.GetYPosition() == 0);
  }
  SECTION("Block Color") {
    REQUIRE(block.GetColor() == kBlackColor);
  }
}

TEST_CASE("Move Down") {
  Block block = Block();
  block.MoveDown();
  REQUIRE(block.GetXPosition() == 0);
  REQUIRE(block.GetYPosition() == 1);
}

TEST_CASE("Move Left") {
  Block block = Block();
  block.MoveLeft();
  REQUIRE(block.GetXPosition() == -1);
  REQUIRE(block.GetYPosition() == 0);
}

TEST_CASE("Move Right") {
  Block block = Block();
  block.MoveRight();
  REQUIRE(block.GetXPosition() == 1);
  REQUIRE(block.GetYPosition() == 0);
}
