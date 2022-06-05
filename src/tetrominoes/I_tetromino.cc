#include "tetrominoes/I_tetromino.h"

#include <tetris_app.h>

namespace tetris {
ITetromino::ITetromino() {
  ChangeOrientation();
}

void ITetromino::ChangeOrientation() {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      std::string row_string =
          json_[kITetromino].at(std::to_string(orientation_)).at(row);

      // If it is not a blank space, then it needs to be colored.
      if (row_string[col] != ' ') {
        tetromino_[row][col].SetColor(kIColor);
      } else {
        tetromino_[row][col].SetColor(kBlackColor);
      }
    }
  }
}
}  // namespace tetris