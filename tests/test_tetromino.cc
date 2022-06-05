#include <catch2/catch.hpp>

#include "tetromino.h"
#include "config.h"
#include "tetrominoes/I_tetromino.h"
#include "tetrominoes/J_tetromino.h"
#include "tetrominoes/L_tetromino.h"
#include "tetrominoes/O_tetromino.h"
#include "tetrominoes/S_tetromino.h"
#include "tetrominoes/T_tetromino.h"
#include "tetrominoes/Z_tetromino.h"

using tetris::Tetromino;
using glm::vec2;
using tetris::kBlackColor;

TEST_CASE("Test ITetromino") {
  Tetromino* I_tetromino = new tetris::ITetromino();
  SECTION("Default Constructor") {
    REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
    REQUIRE(I_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
    REQUIRE(I_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
    REQUIRE(I_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
    REQUIRE(I_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
  }

  SECTION("MoveDown() method") {
    I_tetromino->MoveDown();
    REQUIRE(I_tetromino->GetBlockAt(0, 0).GetYPosition() == 1);
  }

  SECTION("Rotate() method") {
    I_tetromino->Rotate();
    SECTION("First Rotation") {
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    I_tetromino->Rotate();
    SECTION("Second Rotation") {
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    I_tetromino->Rotate();
    SECTION("Third Rotation") {
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    I_tetromino->Rotate();
    SECTION("Fourth Rotation") {
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE(I_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(I_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
  }

  SECTION("MoveTetrominoLeft() method") {
    I_tetromino->MoveLeft();
    REQUIRE(I_tetromino->GetBlockAt(0, 0).GetXPosition() == 2);
  }

  SECTION("MoveTetrominoRight() method") {
    I_tetromino->MoveRight();
    REQUIRE(I_tetromino->GetBlockAt(0, 0).GetXPosition() == 4);
  }
}

TEST_CASE("Test JTetromino") {
  Tetromino* J_tetromino = new tetris::JTetromino();
  SECTION("Default Constructor") {
    REQUIRE(J_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
    REQUIRE(J_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
    REQUIRE(J_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
    REQUIRE(J_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
  }

  SECTION("MoveDown() method") {
    J_tetromino->MoveDown();
    REQUIRE(J_tetromino->GetBlockAt(0, 0).GetYPosition() == 1);
  }

  SECTION("Rotate() method") {
    J_tetromino->Rotate();
    SECTION("First Rotation") {
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    J_tetromino->Rotate();
    SECTION("Second Rotation") {
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    J_tetromino->Rotate();
    SECTION("Third Rotation") {
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    J_tetromino->Rotate();
    SECTION("Fourth Rotation") {
      REQUIRE(J_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(J_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(J_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
  }

  SECTION("MoveTetrominoLeft() method") {
    J_tetromino->MoveLeft();
    REQUIRE(J_tetromino->GetBlockAt(0, 0).GetXPosition() == 2);
  }

  SECTION("MoveTetrominoRight() method") {
    J_tetromino->MoveRight();
    REQUIRE(J_tetromino->GetBlockAt(0, 0).GetXPosition() == 4);
  }
}

TEST_CASE("Test LTetromino") {
  Tetromino* L_tetromino = new tetris::LTetromino();
  SECTION("Default Constructor") {
    REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
    REQUIRE(L_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
    REQUIRE(L_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
    REQUIRE(L_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
    REQUIRE(L_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(L_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
  }

  SECTION("MoveDown() method") {
    L_tetromino->MoveDown();
    REQUIRE(L_tetromino->GetBlockAt(0, 0).GetYPosition() == 1);
  }

  SECTION("Rotate() method") {
    L_tetromino->Rotate();
    SECTION("First Rotation") {
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    L_tetromino->Rotate();
    SECTION("Second Rotation") {
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    L_tetromino->Rotate();
    SECTION("Third Rotation") {
      REQUIRE(L_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    L_tetromino->Rotate();
    SECTION("Fourth Rotation") {
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(L_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(L_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
  }

  SECTION("MoveTetrominoLeft() method") {
    L_tetromino->MoveLeft();
    REQUIRE(L_tetromino->GetBlockAt(0, 0).GetXPosition() == 2);
  }

  SECTION("MoveTetrominoRight() method") {
    L_tetromino->MoveRight();
    REQUIRE(L_tetromino->GetBlockAt(0, 0).GetXPosition() == 4);
  }
}

TEST_CASE("Test OTetromino") {
  Tetromino* O_tetromino = new tetris::OTetromino();
  SECTION("Default Constructor") {
    REQUIRE_FALSE(O_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
    REQUIRE(O_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
    REQUIRE(O_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(O_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(O_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
    REQUIRE(O_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
    REQUIRE(O_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(O_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
  }

  SECTION("MoveDown() method") {
    O_tetromino->MoveDown();
    REQUIRE(O_tetromino->GetBlockAt(0, 0).GetYPosition() == 1);
  }

  SECTION("Rotate() method") {
    O_tetromino->Rotate();
    SECTION("First Rotation") {
      REQUIRE_FALSE(O_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    O_tetromino->Rotate();
    SECTION("Second Rotation") {
      REQUIRE_FALSE(O_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    O_tetromino->Rotate();
    SECTION("Third Rotation") {
      REQUIRE_FALSE(O_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    O_tetromino->Rotate();
    SECTION("Fourth Rotation") {
      REQUIRE_FALSE(O_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(O_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(O_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
  }

  SECTION("MoveTetrominoLeft() method") {
    O_tetromino->MoveLeft();
    REQUIRE(O_tetromino->GetBlockAt(0, 0).GetXPosition() == 2);
  }

  SECTION("MoveTetrominoRight() method") {
    O_tetromino->MoveRight();
    REQUIRE(O_tetromino->GetBlockAt(0, 0).GetXPosition() == 4);
  }
}

TEST_CASE("Test STetromino") {
  Tetromino* S_tetromino = new tetris::STetromino();
  SECTION("Default Constructor") {
    REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
    REQUIRE(S_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
    REQUIRE(S_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
    REQUIRE(S_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
    REQUIRE(S_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(S_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(S_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
  }

  SECTION("MoveDown() method") {
    S_tetromino->MoveDown();
    REQUIRE(S_tetromino->GetBlockAt(0, 0).GetYPosition() == 1);
  }

  SECTION("Rotate() method") {
    S_tetromino->Rotate();
    SECTION("First Rotation") {
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    S_tetromino->Rotate();
    SECTION("Second Rotation") {
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    S_tetromino->Rotate();
    SECTION("Third Rotation") {
      REQUIRE(S_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    S_tetromino->Rotate();
    SECTION("Fourth Rotation") {
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(S_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(S_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
  }

  SECTION("MoveTetrominoLeft() method") {
    S_tetromino->MoveLeft();
    REQUIRE(S_tetromino->GetBlockAt(0, 0).GetXPosition() == 2);
  }

  SECTION("MoveTetrominoRight() method") {
    S_tetromino->MoveRight();
    REQUIRE(S_tetromino->GetBlockAt(0, 0).GetXPosition() == 4);
  }
}

TEST_CASE("Test TTetromino") {
  Tetromino* T_tetromino = new tetris::TTetromino();
  SECTION("Default Constructor") {
    REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
    REQUIRE(T_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
    REQUIRE(T_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
    REQUIRE(T_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
    REQUIRE(T_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(T_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
  }

  SECTION("MoveDown() method") {
    T_tetromino->MoveDown();
    REQUIRE(T_tetromino->GetBlockAt(0, 0).GetYPosition() == 1);
  }

  SECTION("Rotate() method") {
    T_tetromino->Rotate();
    SECTION("First Rotation") {
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    T_tetromino->Rotate();
    SECTION("Second Rotation") {
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    T_tetromino->Rotate();
    SECTION("Third Rotation") {
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    T_tetromino->Rotate();
    SECTION("Fourth Rotation") {
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(T_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(T_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
  }

  SECTION("MoveTetrominoLeft() method") {
    T_tetromino->MoveLeft();
    REQUIRE(T_tetromino->GetBlockAt(0, 0).GetXPosition() == 2);
  }

  SECTION("MoveTetrominoRight() method") {
    T_tetromino->MoveRight();
    REQUIRE(T_tetromino->GetBlockAt(0, 0).GetXPosition() == 4);
  }
}

TEST_CASE("Test ZTetromino") {
  Tetromino* Z_tetromino = new tetris::ZTetromino();
  SECTION("Default Constructor") {
    REQUIRE(Z_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
    REQUIRE(Z_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
    REQUIRE(Z_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
    REQUIRE(Z_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
    REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
  }

  SECTION("MoveDown() method") {
    Z_tetromino->MoveDown();
    REQUIRE(Z_tetromino->GetBlockAt(0, 0).GetYPosition() == 1);
  }

  SECTION("Rotate() method") {
    Z_tetromino->Rotate();
    SECTION("First Rotation") {
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    Z_tetromino->Rotate();
    SECTION("Second Rotation") {
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    Z_tetromino->Rotate();
    SECTION("Third Rotation") {
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
    Z_tetromino->Rotate();
    SECTION("Fourth Rotation") {
      REQUIRE(Z_tetromino->GetBlockAt(0, 0).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(0, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(0, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
      REQUIRE(Z_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(2, 3).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 0).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 1).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
      REQUIRE_FALSE(Z_tetromino->GetBlockAt(3, 3).GetColor() != kBlackColor);
    }
  }

  SECTION("MoveTetrominoLeft() method") {
    Z_tetromino->MoveLeft();
    REQUIRE(Z_tetromino->GetBlockAt(0, 0).GetXPosition() == 2);
  }

  SECTION("MoveTetrominoRight() method") {
    Z_tetromino->MoveRight();
    REQUIRE(Z_tetromino->GetBlockAt(0, 0).GetXPosition() == 4);
  }
}