#pragma once
#include <cstddef>

#include "cinder/gl/gl.h"
#include "config.h"
namespace tetris {
class Block {
  int x_position_ = 0;
  int y_position_ = 0;
  ci::Color color_ = kBlackColor;

 public:
  /**
   * Default Constructor for Block class.
   */
  Block();

  /**
   * Moves the block down, i.e., increases y_position_ by 1.
   */
  void MoveDown();

  /**
   * Moves the block left, i.e., decreases x_position_ by 1.
   */
  void MoveLeft();

  /**
   * Move the block right, i.e., increases x_position_ by 1.
   */
  void MoveRight();

  const int GetXPosition() const;

  const int GetYPosition() const;

  const ci::Color& GetColor() const;

  void SetXPosition(int x_position);

  void SetYPosition(int y_position);

  void SetColor(ci::Color color);
};
}  // namespace tetris
