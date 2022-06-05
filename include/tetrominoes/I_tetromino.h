#pragma once

#include <tetromino.h>

#include "cinder/gl/gl.h"

namespace tetris {

/**
 * The class which contains all the information about the I tetromino and the
 * corresponding methods.
 */
class ITetromino : public tetris::Tetromino {
  /**
   * Sets the orientation to the current orientation_.
   */
  void ChangeOrientation() override;

 public:
  /**
   * Default Constructor for initialising the I tetromino_.
   */
  ITetromino();
};
}  // namespace tetris
