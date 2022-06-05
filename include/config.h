#pragma once
#include "cinder/gl/gl.h"
namespace tetris {

const static size_t kWindowLength = 800;
const static size_t kVerticalMargin = 100;
const static size_t kHorizontalMargin = 250;
const static size_t kContainerBreadth = 300;
const static size_t kContainerLength = 600;
const static size_t kMaxTetrominoSize = 4;
const static size_t kPixelRatio = 30;
const static size_t kBoardLength = 20;
const static size_t kBoardBreadth = 10;
const static size_t kBoardBorderWidth = 5;
const static size_t kBoardLineWidth = 1;
const static size_t kPointValue = 100;
const static size_t kLinesToLevelUp = 5;
const static size_t kHighScores = 5;
const static size_t kHighScoreDistance = 25;
const static size_t kTetrominoes = 6;
const static size_t kI = 0;
const static size_t kJ = 1;
const static size_t kL = 2;
const static size_t kO = 3;
const static size_t kS = 4;
const static size_t kT = 5;
const static size_t kZ = 6;
const static size_t kNextTetrominoXDistance = 75;
const static size_t kNextTetrominoYDistance = 50;

const static int kDefaultXPosition = 3;

// Position Vectors
const static glm::vec2 kScore(50, 100);
const static glm::vec2 kLevel(50, 200);
const static glm::vec2 kLines(50, 300);
const static glm::vec2 kNextTetromino(600, 100);
const static glm::vec2 kPressNPosition(100, 375);
const static glm::vec2 kNewGamePosition(100, 400);
const static glm::vec2 kHighScorePosition(600, 375);

const static std::string kIncorrectLength = "The row or column is incorrect!";
const static std::string kScoreString = "Score : ";
const static std::string kLevelString = "Level : ";
const static std::string kLinesString = "Lines : ";
const static std::string kHighScoresString = "High Scores: ";
const static std::string kPressNString = "Press N to start";
const static std::string kNewGameString = "a new game.";
const static std::string kNextTetrominoString = "Next Tetromino : ";
const static std::string kITetromino = "I_tetromino_";
const static std::string kJTetromino = "J_tetromino_";
const static std::string kLTetromino = "L_tetromino_";
const static std::string kOTetromino = "O_tetromino_";
const static std::string kSTetromino = "S_tetromino_";
const static std::string kTTetromino = "T_tetromino_";
const static std::string kZTetromino = "Z_tetromino_";

// Paths
const static std::string kJsonPath =
    "/Users/arnavshah/Desktop/Cinder/my-projects/final-project-arniboy4/"
    "tetris.json";
const static std::string kBackgroundPath = "background.png";
const static std::string kTetrisPath = "Tetris.png";
const static std::string kGameOverPath = "game_over.mp3";
const static std::string kRotatePath = "rotate.mp3";
const static std::string kMovePath = "move_tetromino.mp3";
const static std::string kHighscorePath = "highscore.mp3";
const static std::string kLostPath = "lost.mp3";
const static std::string kBreakPath = "break_line.mp3";
const static std::string kTouchPath = "touch_bottom.mp3";
const static std::string kTetrisMusic = "Tetris.ogg";

// Colors
const static ci::Color kBoardLines = "gray";
const static ci::Color kBoardBorder = "white";
const static ci::Color kBlackColor = "black";
const static ci::Color kIColor = "cyan";
const static ci::Color kJColor = "blue";
const static ci::Color kLColor = "orange";
const static ci::Color kOColor = "yellow";
const static ci::Color kSColor = "green";
const static ci::Color kTColor = "purple";
const static ci::Color kZColor = "red";
const static ci::Color kLabelColor = "gold";

const static ci::Font kLabelFont = ci::Font("Futura", 20);
}  // namespace tetris
