#pragma once

#include "../cmake-build-debug/_deps/json-src/single_include/nlohmann/json.hpp"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "tetris_game.h"

namespace tetris {
using std::string;

/**
 * An app for visualizing the game of tetris.
 */
class TetrisApp : public ci::app::App {
  size_t high_scores_[kHighScores];

  TetrisGame current_game_;

  bool is_updated_ = false;
  bool is_first_game_ = true;

  ci::audio::FilePlayerNodeRef music_;

  nlohmann::json json_;

  /**
   * Generates a new game when the key N is pressed.
   */
  void NewGame();

  /**
   * Updates the high_scores_.
   */
  void UpdateHighScores();

 public:
  /**
   * Sets the window size and loads the high scores from JSON file.
   */
  TetrisApp();

  /**
   * Clears the screen and draws the components onto the screen.
   */
  void draw() override;

  /**
   * Updates the current_game_ and corresponding score, level, and lines.
   */
  void update() override;

  /**
   * Executes current_game_ functions based on the key pressed.
   * @param event the key event that triggered the function
   */
  void keyDown(ci::app::KeyEvent event) override;

  /**
   * Plays the sound effect when the user or computer does an action.
   * @param file_path to the file with the sound effect
   */
  static void PlaySoundEffect(const string& file_path);

  /**
   * Plays the high-score or lost music after the current_game_ is over.
   * @param file_path to the file with the music to play on loop
   */
  void PlayMusic(const string& file_path);
};

}  // namespace tetris
