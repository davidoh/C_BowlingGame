#include "bowling_game.h"
#include <stdbool.h>

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
  if(pins == 10) {
    current_roll++;
  }
}

static bool is_spare(int frame_index) {
  return rolls[frame_index] + rolls[frame_index+1] == 10;
}

static bool is_strike(int frame_index) {
  return rolls[frame_index] == 10;
}

static int strike_score(int frame_index) {
  int next_frame_index = frame_index + 2;
  if( is_strike(next_frame_index) ) {
    return 20 + rolls[frame_index+4];
  }
  else {
    return 10 + rolls[frame_index+2] + rolls[frame_index + 3];
  }
}

static int spare_score(int frame_index) {
  return 10 + rolls[frame_index + 2];
}

static int frame_score(int frame_index) {
  return rolls[frame_index] + rolls[frame_index+1];
}

int bowling_game_score() {
  int score = 0;
  int frame_index = 0;
  for(int frame=0; frame < max_frames; frame++) {
    if( is_strike(frame_index) ) {
      score += strike_score(frame_index);
    }
    else if( is_spare(frame_index) ) {
      score += spare_score(frame_index);
    }
    else {
      score += frame_score(frame_index);
    }
    frame_index += 2;
  }
  return score;
}
