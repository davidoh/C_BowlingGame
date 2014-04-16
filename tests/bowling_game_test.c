#include "../src/bowling_game.h"
#include <assert.h>
#include <stdbool.h>

static void roll_many(int rolls, int pins) {
  for (int i=0; i<rolls; i++) {
    bowling_game_roll(pins);
  }
}

static void test_gutter_game() {
  bowling_game_init();
  roll_many(20, 0);
  assert( bowling_game_score() == 0 && "test_gutter_game()" );
}

static void test_all_ones() {
  bowling_game_init();
  roll_many(20, 1);
  assert( bowling_game_score() == 20 && "test_gutter_game()" );
}

int main() {
  test_gutter_game();
  test_all_ones();
}
