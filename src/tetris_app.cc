#include "tetris_app.h"

#include <cinder/audio/Context.h>

#include "config.h"

namespace tetris {

using std::string;

TetrisApp::TetrisApp() : current_game_() {
  ci::app::setWindowSize(kWindowLength, kWindowLength);

  // Reading in the JSON for high scores.
  std::ifstream i(kJsonPath);
  i >> json_;
  for (size_t index = 0; index < kHighScores; ++index) {
    high_scores_[index] = json_[kHighScoresString][index];
  }

  // Sets the initial current_game_ to over.
  current_game_.SetIsGameOver(true);
}

void TetrisApp::draw() {
  if (!current_game_.GetIsGameOver()) {
    ci::gl::draw(ci::gl::Texture2d::create(
        loadImage(ci::app::loadAsset(kBackgroundPath))));
    current_game_.Display();
  } else {
    ci::gl::draw(
        ci::gl::Texture2d::create(loadImage(ci::app::loadAsset(kTetrisPath))));
    ci::gl::drawString(kPressNString, kPressNPosition, kLabelColor, kLabelFont);
    ci::gl::drawString(kNewGameString, kNewGamePosition, kLabelColor,
                       kLabelFont);
  }
  ci::gl::drawString(kHighScoresString, kHighScorePosition, kLabelColor,
                     kLabelFont);
  for (size_t index = 0; index < kHighScores; ++index) {
    ci::gl::drawString(
        std::to_string(high_scores_[index]),
        vec2(kHighScorePosition.x,
             kHighScorePosition.y + kHighScoreDistance * (index + 1)),
        kLabelColor, kLabelFont);
  }
}

void TetrisApp::update() {
  if (!is_first_game_) {
    if (!current_game_.GetIsGameOver()) {
      current_game_.AdvanceOneFrame();
    } else if (!is_updated_) {
      PlaySoundEffect(kGameOverPath);
      UpdateHighScores();
      is_updated_ = true;
    }
  }
}

void TetrisApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_UP:
      current_game_.RotateTetromino();
      PlaySoundEffect(kRotatePath);
      break;

    case ci::app::KeyEvent::KEY_LEFT:
      current_game_.MoveTetrominoLeft();
      PlaySoundEffect(kMovePath);
      break;

    case ci::app::KeyEvent::KEY_RIGHT:
      current_game_.MoveTetrominoRight();
      PlaySoundEffect(kMovePath);
      break;

    case ci::app::KeyEvent::KEY_DOWN:
      current_game_.SoftDrop();
      PlaySoundEffect(kMovePath);
      break;

    case ci::app::KeyEvent::KEY_SPACE:
      current_game_.HardDrop();
      break;

    case ci::app::KeyEvent::KEY_n:
      NewGame();
      break;
  }
}

void TetrisApp::NewGame() {
  is_updated_ = false;
  current_game_ = TetrisGame();
  if (!is_first_game_) {
    music_->stop();
  }
  is_first_game_ = false;
}

void TetrisApp::UpdateHighScores() {
  for (size_t index = 0; index < kHighScores; ++index) {
    if (current_game_.GetScore() > high_scores_[index]) {
      // Shifts down all the lower scores and enters the new high score.
      for (size_t i = kHighScores - 1; i > index; --i) {
        high_scores_[i] = high_scores_[i - 1];
      }
      high_scores_[index] = current_game_.GetScore();

      // Updates the Json with the new high scores.
      json_[kHighScoresString] = high_scores_;
      std::ofstream o(kJsonPath);
      o << json_;

      PlayMusic(kHighscorePath);
      return;
    }
  }
  PlayMusic(kLostPath);
}

void TetrisApp::PlaySoundEffect(const string& file_path) {
  ci::audio::SourceFileRef sourceFile =
      ci::audio::load(ci::app::loadAsset(file_path));

  auto ctx = ci::audio::Context::master();
  ci::audio::FilePlayerNodeRef sound_ =
      ctx->makeNode(new ci::audio::FilePlayerNode(sourceFile));

  // create GainNode for volume control, set to max volume
  ci::audio::GainNodeRef gain_ = ctx->makeNode(new ci::audio::GainNode(1.0f));

  ci::audio::VoiceRef sound = ci::audio::Voice::create(sourceFile);

  // Connect tetris sound to audio graph
  sound_ >> gain_ >> ctx->getOutput();
  sound_->start();
}

void TetrisApp::PlayMusic(const string& file_path) {
  ci::audio::SourceFileRef sourceFile =
      ci::audio::load(ci::app::loadAsset(file_path));

  auto ctx = ci::audio::Context::master();
  music_ = ctx->makeNode(new ci::audio::FilePlayerNode(sourceFile));

  // create GainNode for volume control, set to max volume
  ci::audio::GainNodeRef gain_ = ctx->makeNode(new ci::audio::GainNode(1.0f));

  ci::audio::VoiceRef sound = ci::audio::Voice::create(sourceFile);

  // Connect tetris sound to audio graph
  music_ >> gain_ >> ctx->getOutput();

  music_->setLoopEnabled(true);
  music_->start();
}
}  // namespace tetris