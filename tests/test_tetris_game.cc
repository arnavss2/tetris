#include <catch2/catch.hpp>

#include "config.h"
#include "tetris_game.h"
#include "tetrominoes/I_tetromino.h"

using glm::vec2;
using tetris::ITetromino;
using tetris::kBlackColor;
using tetris::TetrisGame;
using tetris::Tetromino;
using tetris::kBoardLength;

TEST_CASE("TetrisGame() Constructor") {
  TetrisGame game = TetrisGame();
  Tetromino* current_tetromino = new ITetromino();
  game.SetCurrentTetromino(current_tetromino);
  REQUIRE(current_tetromino->GetBlockAt(0, 0).GetColor() == kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(0, 1).GetColor() == kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(0, 2).GetColor() == kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(0, 3).GetColor() == kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(1, 0).GetColor() != kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(1, 1).GetColor() != kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(1, 3).GetColor() != kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(2, 0).GetColor() == kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(2, 1).GetColor() == kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(2, 2).GetColor() == kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(2, 3).GetColor() == kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(3, 0).GetColor() == kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(3, 1).GetColor() == kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(3, 2).GetColor() == kBlackColor);
  REQUIRE(current_tetromino->GetBlockAt(3, 3).GetColor() == kBlackColor);
}

TEST_CASE("AdvanceOneFrame() method") {
  TetrisGame game = TetrisGame();
  Tetromino* current_tetromino = new ITetromino();
  game.SetCurrentTetromino(current_tetromino);
  SECTION("Tetromino not touching the bottom wall") {
    for (size_t frame = 0; frame < 10; ++frame) {
      game.AdvanceOneFrame();
    }
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetXPosition() == 3);
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetYPosition() == 1);
  }

  SECTION("Tetromino touching bottom wall") {
    for (size_t row = 0; row < 20; ++row) {
      for (size_t frame = 0; frame < 10; ++frame) {
        game.AdvanceOneFrame();
      }
    }
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetXPosition() == 3);
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetYPosition() == 18);
  }
}

TEST_CASE("RotateTetromino() method") {
  TetrisGame game = TetrisGame();
  Tetromino* current_tetromino = new ITetromino();
  game.SetCurrentTetromino(current_tetromino);
  SECTION("Tetromino not touching any wall") {
    game.RotateTetromino();
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(0, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(0, 3).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 3).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 3).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 3).GetColor() == kBlackColor);
  }

  SECTION("Tetromino touching left wall") {
    for (size_t row = 0; row < 6; ++row) {
      game.MoveTetrominoLeft();
    }
    game.RotateTetromino();
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(0, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(0, 3).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 3).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 3).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 3).GetColor() == kBlackColor);
  }

  SECTION("Tetromino touching right wall") {
    for (size_t col = 4; col < 8; ++col) {
      game.MoveTetrominoRight();
    }
    game.RotateTetromino();
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(0, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(0, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(0, 3).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(1, 3).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(2, 3).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 0).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 1).GetColor() == kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 2).GetColor() != kBlackColor);
    REQUIRE(current_tetromino->GetBlockAt(3, 3).GetColor() == kBlackColor);
  }
}

TEST_CASE("MoveTetrominoLeft() method") {
  TetrisGame game = TetrisGame();
  Tetromino* current_tetromino = new ITetromino();
  game.SetCurrentTetromino(current_tetromino);
  SECTION("Tetromino not touching the left wall") {
    game.MoveTetrominoLeft();
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetXPosition() == 2);
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetYPosition() == 0);
  }

  SECTION("Tetromino touching left wall") {
    for (size_t row = 0; row < 4; ++row) {
      game.MoveTetrominoLeft();
    }
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetXPosition() == 0);
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetYPosition() == 0);
  }

  SECTION("Tetromino moving right after touching left") {
    for (size_t row = 0; row < 4; ++row) {
      game.MoveTetrominoLeft();
    }
    game.MoveTetrominoRight();
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetXPosition() == 1);
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetYPosition() == 0);
  }
}

TEST_CASE("MoveTetrominoRight() method") {
  TetrisGame game = TetrisGame();
  Tetromino* current_tetromino = new ITetromino();
  game.SetCurrentTetromino(current_tetromino);
  SECTION("Tetromino not touching the right wall") {
    game.MoveTetrominoRight();
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetXPosition() == 4);
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetYPosition() == 0);
  }

  SECTION("Tetromino touching right wall") {
    for (size_t row = 0; row < 4; ++row) {
      game.MoveTetrominoRight();
    }
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetXPosition() == 6);
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetYPosition() == 0);

    SECTION("Tetromino moving left after touching right") {
      for (size_t row = 0; row < 4; ++row) {
        game.MoveTetrominoRight();
      }
      game.MoveTetrominoLeft();
      REQUIRE(current_tetromino->GetBlockAt(0, 0).GetXPosition() == 5);
      REQUIRE(current_tetromino->GetBlockAt(0, 0).GetYPosition() == 0);
    }
  }
}

TEST_CASE("Soft Drop") {
  TetrisGame game = TetrisGame();
  Tetromino* current_tetromino = new ITetromino();
  game.SetCurrentTetromino(current_tetromino);

  SECTION("Single Soft Drop") {
    game.SoftDrop();
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetXPosition() == 3);
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetYPosition() == 1);
    REQUIRE(game.GetScore() == 1);
  }

  SECTION("Multiple Soft Drops") {
    for (size_t drop = 0; drop < kBoardLength; ++drop) {
      game.SoftDrop();
    }
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetXPosition() == 3);
    REQUIRE(current_tetromino->GetBlockAt(0, 0).GetYPosition() == 18);
    REQUIRE(game.GetScore() == 18);
  }
}

TEST_CASE("Hard Drop") {
  TetrisGame game = TetrisGame();
  Tetromino* current_tetromino = new ITetromino();
  game.SetCurrentTetromino(current_tetromino);
  game.HardDrop();
  REQUIRE(current_tetromino->GetBlockAt(0, 0).GetXPosition() == 3);
  REQUIRE(current_tetromino->GetBlockAt(0, 0).GetYPosition() == 18);
  REQUIRE(game.GetScore() == 36);
}