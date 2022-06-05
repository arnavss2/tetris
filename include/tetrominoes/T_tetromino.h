#pragma once

#include <tetromino.h>

#include "cinder/gl/gl.h"

namespace tetris {

/**
 * The class which contains all the information about the T tetromino and the
 * corresponding methods.
 */
class TTetromino : public tetris::Tetromino {
  /**
   * Sets the orientation to the current orientation_.
   */
  void ChangeOrientation() override;

 public:
  /**
   * Default Constructor for initializing the T tetromino_.
   */
  TTetromino();
};
}  // namespace tetris
