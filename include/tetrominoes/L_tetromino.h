#pragma once

#include <tetromino.h>

#include "cinder/gl/gl.h"

namespace tetris {

/**
 * The class which contains all the information about the L tetromino and the
 * corresponding methods.
 */
class LTetromino : public tetris::Tetromino {
  /**
   * Sets the orientation to the current orientation_.
   */
  void ChangeOrientation() override;

 public:
  /**
   * Default Constructor for initializing the L tetromino_.
   */
  LTetromino();
};
}  // namespace tetris
