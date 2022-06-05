#pragma once

#include <cinder/audio/GainNode.h>
#include <cinder/audio/Voice.h>
#include <tetrominoes/I_tetromino.h>
#include <tetrominoes/J_tetromino.h>
#include <tetrominoes/L_tetromino.h>
#include <tetrominoes/O_tetromino.h>
#include <tetrominoes/S_tetromino.h>
#include <tetrominoes/T_tetromino.h>
#include <tetrominoes/Z_tetromino.h>

#include "cinder/gl/gl.h"
#include "tetromino.h"

namespace tetris {

/**
 * This class stores the game and updates it on each frame.
 */
class TetrisGame {
  vec2 top_left_pixel_ = vec2(kHorizontalMargin, kVerticalMargin);
  vec2 bottom_right_pixel_ = vec2(kHorizontalMargin + kContainerBreadth,
                                  kVerticalMargin + kContainerLength);

  Block board_[kBoardLength][kBoardBreadth];

  Tetromino* current_tetromino_;
  Tetromino* next_tetromino_;

  size_t frames_processed_ = 0;
  size_t frames_to_drop_ = 10;
  size_t score_ = 0;
  size_t level_ = 1;
  size_t lines_broken_ = 0;

  ci::audio::FilePlayerNodeRef tetris_sound_;
  ci::audio::GainNodeRef gain_;

  bool is_game_over_ = false;

  /**
   * Generates a random Tetromino pointer from I, J, L, O, S, T, and Z.
   * @return the randomly generated Tetromino*
   */
  Tetromino* GenerateRandomTetromino() const;

  /**
   * Plays the Tetris music.
   */
  void PlayMusic();

  /**
   * Draws the given block on the board.
   * @param block the Block to be drawn
   */
  void DrawBlock(const Block& block) const;

  /**
   * Draws the current_tetromino_ on the board.
   */
  void DisplayCurrentTetromino() const;

  /**
   * Draws the next tetromino_.
   */
  void DrawNextTetromino() const;

  /**
   * Moves the current_tetromino_ down.
   */
  void MoveTetrominoDown();

  /**
   * Checks if lines are breaking and calls BreakRow() if they are.
   */
  void BreakLines();

  /**
   * Checks if the current game is over or not.
   */
  void CheckGameOver();

  /**
   * Checks if the current_tetromino_'s non-empty blocks are touching the bottom
   * wall of the container.
   * @return true, if touching the bottom wall, else, false
   */
  bool AreBlocksTouchingBottomWall() const;

  /**
   * Checks if the whole current_tetromino_ is touching the left wall of the
   * container.
   * @return true, if touching left wall, else, false
   */
  bool IsTetrominoTouchingLeftWall() const;

  /**
   * Implements left wall kicks when the tetromino_ is touching the left wall.
   */
  void LeftWallKick();

  /**
   * Checks if the whole current_tetromino_ is touching the right wall of the
   * container.
   * @return true, if touching right wall, else, false
   */
  bool IsTetrominoTouchingRightWall() const;

  /**
   * Implements right wall kicks when the tetromino_ is touching the right wall.
   */
  void RightWallKick();

  /**
   * Checks if the blocks are overlapping after being rotated or moved.
   * @return true, if overlapping, else false.
   */
  bool AreBlocksOverlapping();

  /**
   * Checks if the current_tetromino_'s non-empty blocks are touching the left
   * wall of the container.
   * @return true, if touching left wall, else, false
   */
  bool AreBlocksTouchingLeftWall() const;

  /**
   * Checks if the current_tetromino_'s non-empty blocks are touching the right
   * wall of the container.
   * @return true, if touching right wall, else, false
   */
  bool AreBlocksTouchingRightWall() const;

  /**
   * Checks for any block collisions with blocks below.
   */
  bool AreBlocksCollidingBelow() const;

  /**
   * Stops the tetromino in its place.
   */
  void StopTetromino();

  /**
   * Breaks the given row and moves the blocks on top down.
   * @param row to be broken
   */
  void BreakRow(size_t row);

 public:
  /**
   * Constructor for creating the Tetris Game and the corresponding components.
   */
  TetrisGame();

  /**
   * Displays the board_ and the corresponding components.
   */
  void Display() const;

  /**
   * Updates the position of the tetromino (based on the rules of Tetris).
   */
  void AdvanceOneFrame();

  /**
   * Rotates the current_tetromino_ clockwise only.
   */
  void RotateTetromino();

  /**
   * Moves the current_tetromino_ left.
   */
  void MoveTetrominoLeft();

  /**
   * Moves the current_tetromino_ right.
   */
  void MoveTetrominoRight();

  /**
   * Moves down the current_tetromino_ and increases the score accordingly.
   */
  void SoftDrop();

  /**
   * Drops down the current_tetromino_ and increases the score accordingly.
   */
  void HardDrop();

  Tetromino* const GetCurrentTetromino() const;

  size_t const GetScore() const;

  bool const GetIsGameOver() const;

  void SetCurrentTetromino(Tetromino* tetromino);

  void SetIsGameOver(bool value);
};
}  // namespace tetris
