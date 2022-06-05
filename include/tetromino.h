#pragma once

#include "../cmake-build-debug/_deps/json-src/single_include/nlohmann/json.hpp"
#include "block.h"
#include "cinder/gl/gl.h"
#include "config.h"

namespace tetris {

using glm::vec2;
using nlohmann::json;

/**
 * The class which contains all the information about the tetrominoes and the
 * corresponding methods.
 */
class Tetromino {

  /**
   * Sets the orientation to the current orientation_.
   */
  virtual void ChangeOrientation() = 0;

 protected:
  Block tetromino_[kMaxTetrominoSize][kMaxTetrominoSize];

  size_t orientation_ = 0;

  json json_;

  ci::Color color_;

 public:
  /**
   * Default constructor for a tetromino_.
   */
  Tetromino();

  /**
   * Moves the tetromino_ down.
   */
  void MoveDown();

  /**
   * Moves the tetromino_ left.
   */
  void MoveLeft();

  /**
   * Moves the tetromino_ right.
   */
  void MoveRight();

  /**
   * Rotates the tetromino clockwise.
   */
  void Rotate();

  /**
   * Returns a reference to the Block at the given row and column.
   * @param row at which the Block is
   * @param col at which the Block is
   * @return a reference to the Block at the given row and column
   */
  const Block& GetBlockAt(size_t row, size_t col) const;

  /**
   * Operator == for checking equality between two tetrominoes.
   * @param rhs the teromino to be compared with
   * @return true, if they are equal tetrominoes, else, false
   */
  bool operator==(const Tetromino& rhs) const;

  /**
   * Destructor for Tetromino class.
   */
  ~Tetromino();
};
}  // namespace tetris
