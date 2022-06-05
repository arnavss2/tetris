#include "tetromino.h"

#include "config.h"

namespace tetris {

using glm::vec2;

Tetromino::Tetromino() {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      tetromino_[row][col].SetXPosition(kDefaultXPosition + col);
      tetromino_[row][col].SetYPosition(row);
    }
  }
  std::ifstream i("/Users/arnavshah/Desktop/Cinder/my-projects/final-project-arniboy4/tetris.json");
  i >> json_;
}

void Tetromino::MoveDown() {
  for (size_t row = 0; row < kMaxTetrominoSize; row++) {
    for (size_t col = 0; col < kMaxTetrominoSize; col++) {
      tetromino_[row][col].MoveDown();
    }
  }
}

void Tetromino::MoveLeft() {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      tetromino_[row][col].MoveLeft();
    }
  }
}

void Tetromino::MoveRight() {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      tetromino_[row][col].MoveRight();
    }
  }
}

void Tetromino::Rotate() {
  orientation_++;
  if (orientation_ >= 4) {
    orientation_ = 0;
  }
  ChangeOrientation();
}

const Block& Tetromino::GetBlockAt(size_t row, size_t col) const {
  if (row >= 4 || col >= 4) {
    throw std::length_error(kIncorrectLength);
  }
  return tetromino_[row][col];
}

bool Tetromino::operator==(const Tetromino& rhs) const {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      if (tetromino_[row][col].GetColor() !=
          rhs.GetBlockAt(row, col).GetColor()) {
        return false;
      }
    }
  }
  return true;
}

Tetromino::~Tetromino() {
}
}  // namespace tetris
