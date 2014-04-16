#include "bowling_game.h"

enum { max_rolls = 21, max_frames = 10 };
static int rolls[max_rolls];
static int current_roll;

void bowling_game_init() {
  for(int i=0; i< max_rolls; i++) {
    rolls[i] = 0;
  }
  current_roll = 0;
}

void bowling_game_roll(int pins) {
  rolls[current_roll++] = pins;
}

int bowling_game_score() {
  int score = 0;
  int i = 0;
  for(int frame=0; frame < max_frames; frame++) {
    int frame_score = rolls[i] + rolls[i+1];
    score += frame_score;
    if(frame_score == 10) {
      int next_roll = rolls[i+2];
      score += next_roll;
    }
    i += 2;
  }
  return score;
}
