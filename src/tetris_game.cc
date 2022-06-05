#include "tetris_game.h"

#include <cinder/audio/Context.h>
#include <cinder/audio/Voice.h>
#include <tetris_app.h>

#include <random>

#include "config.h"

namespace tetris {

using glm::vec2;

TetrisGame::TetrisGame() {
  current_tetromino_ = GenerateRandomTetromino();
  next_tetromino_ = GenerateRandomTetromino();
  while (*next_tetromino_ == *current_tetromino_) {
    next_tetromino_ = GenerateRandomTetromino();
  }
  // initializes the board_ variable
  for (size_t row = 0; row < kBoardLength; ++row) {
    for (size_t col = 0; col < kBoardBreadth; ++col) {
      board_[row][col].SetXPosition(col);
      board_[row][col].SetYPosition(row);
    }
  }
  PlayMusic();
}

void TetrisGame::Display() const {
  // displays the board container
  ci::gl::color(ci::Color(kBoardBorder));
  ci::gl::drawStrokedRect(ci::Rectf(top_left_pixel_, bottom_right_pixel_),
                          kBoardBorderWidth);

  // displays the board
  for (size_t row = 0; row < kBoardLength; ++row) {
    for (size_t col = 0; col < kBoardBreadth; ++col) {
      DrawBlock(board_[row][col]);
    }
  }
  DisplayCurrentTetromino();

  std::string score = kScoreString + std::to_string(score_);
  ci::gl::drawString(score, kScore, kLabelColor, kLabelFont);

  std::string level = kLevelString + std::to_string(level_);
  ci::gl::drawString(level, kLevel, kLabelColor, kLabelFont);

  std::string lines = kLinesString + std::to_string(lines_broken_);
  ci::gl::drawString(lines, kLines, kLabelColor, kLabelFont);

  ci::gl::drawString(kNextTetrominoString, kNextTetromino, kLabelColor,
                     kLabelFont);
  DrawNextTetromino();
}

void TetrisGame::AdvanceOneFrame() {
  frames_processed_++;
  if (frames_processed_ == frames_to_drop_) {
    MoveTetrominoDown();
    frames_processed_ = 0;
  }
  BreakLines();
  CheckGameOver();
}

void TetrisGame::RotateTetromino() {
  if (!AreBlocksTouchingBottomWall()) {
    if (IsTetrominoTouchingLeftWall()) {
      LeftWallKick();
    } else if (IsTetrominoTouchingRightWall()) {
      RightWallKick();
    } else {
      current_tetromino_->Rotate();
    }
  }
  if (AreBlocksOverlapping()) {
    current_tetromino_->Rotate();
    current_tetromino_->Rotate();
    current_tetromino_->Rotate();
  }
}

void TetrisGame::MoveTetrominoLeft() {
  if (!AreBlocksTouchingLeftWall() && !AreBlocksTouchingBottomWall()) {
    current_tetromino_->MoveLeft();
    if (AreBlocksOverlapping()) {
      current_tetromino_->MoveRight();
    }
  }
}

void TetrisGame::MoveTetrominoRight() {
  if (!AreBlocksTouchingRightWall() && !AreBlocksTouchingBottomWall()) {
    current_tetromino_->MoveRight();
    if (AreBlocksOverlapping()) {
      current_tetromino_->MoveLeft();
    }
  }
}

void TetrisGame::SoftDrop() {
  if (!AreBlocksTouchingBottomWall() && !AreBlocksCollidingBelow()) {
    MoveTetrominoDown();
    score_++;
  }
}

void TetrisGame::HardDrop() {
  while (!AreBlocksTouchingBottomWall() && !AreBlocksCollidingBelow()) {
    MoveTetrominoDown();
    score_ += 2;
  }
}

Tetromino* const TetrisGame::GetCurrentTetromino() const {
  return current_tetromino_;
}

size_t const TetrisGame::GetScore() const {
  return score_;
}

bool const TetrisGame::GetIsGameOver() const {
  return is_game_over_;
}

void TetrisGame::SetCurrentTetromino(Tetromino* tetromino) {
  current_tetromino_ = tetromino;
}

void TetrisGame::SetIsGameOver(bool value) {
  is_game_over_ = value;
  if (is_game_over_ == true) {
    tetris_sound_->stop();
  }
}

Tetromino* TetrisGame::GenerateRandomTetromino() const {
  //  std::default_random_engine generator;
  std::random_device rand_device;
  std::mt19937 generator(rand_device());
  std::uniform_int_distribution<size_t> distribution(0, kTetrominoes);
  size_t tetromino = distribution(generator);
  Tetromino* new_tetromino;
  switch (tetromino) {
    case kI:
      new_tetromino = new ITetromino();
      break;
    case kJ:
      new_tetromino = new JTetromino();
      break;
    case kL:
      new_tetromino = new LTetromino();
      break;
    case kO:
      new_tetromino = new OTetromino();
      break;
    case kS:
      new_tetromino = new STetromino();
      break;
    case kT:
      new_tetromino = new TTetromino();
      break;
    case kZ:
      new_tetromino = new ZTetromino();
  }
  return new_tetromino;
}

void TetrisGame::PlayMusic() {
  ci::audio::SourceFileRef sourceFile =
      ci::audio::load(ci::app::loadAsset(kTetrisMusic));

  auto ctx = ci::audio::Context::master();
  tetris_sound_ = ctx->makeNode(new ci::audio::FilePlayerNode(sourceFile));

  // create GainNode for volume control, set to max volume
  gain_ = ctx->makeNode(new ci::audio::GainNode(1.0f));

  ci::audio::VoiceRef sound = ci::audio::Voice::create(sourceFile);

  // Connect tetris sound to audio graph
  tetris_sound_ >> gain_ >> ctx->getOutput();

  tetris_sound_->setLoopEnabled(true);
  tetris_sound_->start();
}

void TetrisGame::DrawBlock(const Block& block) const {
  // Initializes the top-left pixel and bottom-right pixel
  vec2 top_left_block_pixel(
      top_left_pixel_.x + block.GetXPosition() * kPixelRatio,
      top_left_pixel_.y + block.GetYPosition() * kPixelRatio);
  vec2 bottom_right_block_pixel(top_left_block_pixel.x + kPixelRatio,
                                top_left_block_pixel.y + kPixelRatio);

  // Draws the actual block
  ci::gl::color(block.GetColor());
  ci::gl::drawSolidRect(
      ci::Rectf(top_left_block_pixel, bottom_right_block_pixel));

  // Draws the border of the block
  ci::gl::color(kBoardLines);
  ci::gl::drawStrokedRect(
      ci::Rectf(top_left_block_pixel, bottom_right_block_pixel),
      kBoardLineWidth);
}

void TetrisGame::DisplayCurrentTetromino() const {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      const Block& block_to_draw = current_tetromino_->GetBlockAt(row, col);
      if (block_to_draw.GetColor() != kBlackColor) {
        DrawBlock(block_to_draw);
      }
    }
  }
}

void TetrisGame::DrawNextTetromino() const {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      const Block& block = next_tetromino_->GetBlockAt(row, col);
      // Initializes the top-left pixel and bottom-right pixel
      vec2 top_left_block_pixel(
          kNextTetromino.x + block.GetXPosition() * kPixelRatio -
              kNextTetrominoXDistance,
          kNextTetromino.y + block.GetYPosition() * kPixelRatio +
              kNextTetrominoYDistance);
      vec2 bottom_right_block_pixel(top_left_block_pixel.x + kPixelRatio,
                                    top_left_block_pixel.y + kPixelRatio);

      // Draws the actual block
      ci::gl::color(block.GetColor());
      ci::gl::drawSolidRect(
          ci::Rectf(top_left_block_pixel, bottom_right_block_pixel));

      // Draws the border of the block
      ci::gl::color(kBoardLines);
      ci::gl::drawStrokedRect(
          ci::Rectf(top_left_block_pixel, bottom_right_block_pixel),
          kBoardLineWidth);
    }
  }
}

void TetrisGame::MoveTetrominoDown() {
  if (!AreBlocksTouchingBottomWall() && !AreBlocksCollidingBelow()) {
    current_tetromino_->MoveDown();
  } else {
    StopTetromino();
  }
}

void TetrisGame::BreakLines() {
  size_t lines_broken = 0;
  for (size_t row = 0; row < kBoardLength; ++row) {
    bool full_line = true;
    for (size_t col = 0; col < kBoardBreadth; ++col) {
      if (board_[row][col].GetColor() == kBlackColor) {
        full_line = false;
        break;
      }
    }
    if (full_line) {
      BreakRow(row);
      lines_broken++;
    }
  }
  if (lines_broken > 0) {
    score_ += lines_broken * kPointValue;
    TetrisApp::PlaySoundEffect(kBreakPath);
  }
}

void TetrisGame::CheckGameOver() {
  for (size_t col = 0; col < kBoardBreadth; ++col) {
    if (board_[1][col].GetColor() != kBlackColor) {
      SetIsGameOver(true);
      return;
    }
  }
}

bool TetrisGame::AreBlocksTouchingBottomWall() const {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      const Block& current_block = current_tetromino_->GetBlockAt(row, col);
      if (current_block.GetColor() != kBlackColor &&
          current_block.GetYPosition() >= kBoardLength - 1) {
        return true;
      }
    }
  }
  return false;
}

bool TetrisGame::IsTetrominoTouchingLeftWall() const {
  return current_tetromino_->GetBlockAt(0, 0).GetXPosition() < 0;
}

void TetrisGame::LeftWallKick() {
  size_t moved_steps = 0;
  while (IsTetrominoTouchingLeftWall()) {
    current_tetromino_->MoveRight();
    moved_steps++;
  }
  current_tetromino_->Rotate();
  while (moved_steps > 0 && !AreBlocksTouchingLeftWall()) {
    current_tetromino_->MoveLeft();
    moved_steps--;
  }
}

bool TetrisGame::IsTetrominoTouchingRightWall() const {
  return current_tetromino_->GetBlockAt(0, kMaxTetrominoSize - 1)
             .GetXPosition() >= kBoardBreadth;
}

void TetrisGame::RightWallKick() {
  size_t moved_steps = 0;
  while (IsTetrominoTouchingRightWall()) {
    current_tetromino_->MoveLeft();
    moved_steps++;
  }
  current_tetromino_->Rotate();
  while (moved_steps > 0 && !AreBlocksTouchingRightWall()) {
    current_tetromino_->MoveRight();
    moved_steps--;
  }
}

bool TetrisGame::AreBlocksOverlapping() {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      const Block& current_tetromino_block =
          current_tetromino_->GetBlockAt(row, col);
      const Block& current_board_block =
          board_[current_tetromino_block.GetYPosition()]
                [current_tetromino_block.GetXPosition()];
      if (current_tetromino_block.GetColor() != kBlackColor &&
          current_board_block.GetColor() != kBlackColor) {
        return true;
      }
    }
  }
  return false;
}

bool TetrisGame::AreBlocksTouchingLeftWall() const {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      const Block& current_block = current_tetromino_->GetBlockAt(row, col);
      if (current_block.GetColor() != kBlackColor &&
          current_block.GetXPosition() <= 0) {
        return true;
      }
    }
  }
  return false;
}

bool TetrisGame::AreBlocksTouchingRightWall() const {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      const Block& current_block = current_tetromino_->GetBlockAt(row, col);
      if (current_block.GetColor() != kBlackColor &&
          current_block.GetXPosition() >= kBoardBreadth - 1) {
        return true;
      }
    }
  }
  return false;
}

bool TetrisGame::AreBlocksCollidingBelow() const {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      const Block& current_block = current_tetromino_->GetBlockAt(row, col);
      if (current_block.GetColor() != kBlackColor) {
        const Block& block_beneath = board_[current_block.GetYPosition() + 1]
                                           [current_block.GetXPosition()];
        if (block_beneath.GetColor() != kBlackColor) {
          return true;
        }
      }
    }
  }
  return false;
}

void TetrisGame::StopTetromino() {
  for (size_t row = 0; row < kMaxTetrominoSize; ++row) {
    for (size_t col = 0; col < kMaxTetrominoSize; ++col) {
      const Block& current_block = current_tetromino_->GetBlockAt(row, col);
      if (current_block.GetColor() != kBlackColor) {
        board_[current_block.GetYPosition()][current_block.GetXPosition()]
            .SetColor(current_block.GetColor());
      }
    }
  }
  current_tetromino_ = next_tetromino_;
  next_tetromino_ = GenerateRandomTetromino();
  while (*next_tetromino_ == *current_tetromino_) {
    next_tetromino_ = GenerateRandomTetromino();
  }
  TetrisApp::PlaySoundEffect(kTouchPath);
}

void TetrisGame::BreakRow(size_t row) {
  while (row > 0) {
    for (size_t col = 0; col < kBoardBreadth; ++col) {
      board_[row][col].SetColor(board_[row - 1][col].GetColor());
    }
    --row;
  }
  for (size_t col = 0; col < kBoardBreadth; ++col) {
    board_[row][col].SetColor(kBlackColor);
  }
  lines_broken_++;
  if (lines_broken_ % kLinesToLevelUp == 0) {
    level_++;
    if (frames_to_drop_ > 0)
      frames_to_drop_--;
  }
}
}  // namespace tetris
