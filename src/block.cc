#include "block.h"

namespace tetris {
Block::Block() {
}

void Block::MoveDown() {
  y_position_++;
}

void Block::MoveLeft() {
  x_position_--;
}

void Block::MoveRight() {
  x_position_++;
}

const int Block::GetXPosition() const {
  return x_position_;
}

const int Block::GetYPosition() const {
  return y_position_;
}

const ci::Color& Block::GetColor() const {
  return color_;
}

void Block::SetXPosition(int x_position) {
  x_position_ = x_position;
}

void Block::SetYPosition(int y_position) {
  y_position_ = y_position;
}

void Block::SetColor(ci::Color color) {
  color_ = color;
}
}  // namespace tetris