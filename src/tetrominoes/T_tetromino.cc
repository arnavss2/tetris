#include "tetrominoes/T_tetromino.h"

namespace tetris {
TTetromino::TTetromino() {
  ChangeOrientation();
}

void TTetromino::ChangeOrientation() {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      std::string row_string =
          json_[kTTetromino].at(std::to_string(orientation_)).at(row);

      // If it is not a blank space, then it needs to be colored.
      if (row_string[col] != ' ') {
        tetromino_[row][col].SetColor(kTColor);
      } else {
        tetromino_[row][col].SetColor(kBlackColor);
      }
    }
  }
}
}  // namespace tetris
