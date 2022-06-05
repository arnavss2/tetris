#include "tetrominoes/J_tetromino.h"

using glm::vec2;

namespace tetris {
JTetromino::JTetromino() {
  ChangeOrientation();
}
void JTetromino::ChangeOrientation() {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      std::string row_string =
          json_[kJTetromino].at(std::to_string(orientation_)).at(row);

      // If it is not a blank space, then it needs to be colored.
      if (row_string[col] != ' ') {
        tetromino_[row][col].SetColor(kJColor);
      } else {
        tetromino_[row][col].SetColor(kBlackColor);
      }
    }
  }
}
}  // namespace tetris
