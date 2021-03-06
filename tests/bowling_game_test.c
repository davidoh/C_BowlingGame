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
  assert( bowling_game_score() == 0);
}

static void test_all_ones() {
  bowling_game_init();
  roll_many(20, 1);
  assert( bowling_game_score() == 20);
}

static void test_one_spare() {
  bowling_game_init();
  bowling_game_roll(5);
  bowling_game_roll(5);
  bowling_game_roll(3);
  roll_many(17, 0);
  assert( bowling_game_score() == 16);
}

static void test_multiple_spares() {
  bowling_game_init();
  bowling_game_roll(5);
  bowling_game_roll(5); //first frame = 13
  bowling_game_roll(3);
  bowling_game_roll(7); //second frame = 18
  bowling_game_roll(8);
  roll_many(15, 0);
  assert( bowling_game_score() == 39);
}

static void test_one_strike() {
  bowling_game_init();
  bowling_game_roll(10); //first frame = 19
  bowling_game_roll(2);
  bowling_game_roll(7);
  roll_many(17, 0);
  assert( bowling_game_score() == 28);
}

static void test_multiple_strikes() {
  bowling_game_init();
  bowling_game_roll(10); //first frame = 23
  bowling_game_roll(10); //second frame = 13
  bowling_game_roll(3);
  roll_many(15, 0);
  assert( bowling_game_score() == 39);
}

static void test_spare_after_gutter_ball() {
  bowling_game_init();
  bowling_game_roll(0);
  bowling_game_roll(10); //first frame = 11
  roll_many(18, 1);
  assert( bowling_game_score() == 29);
}

static void test_strike_in_last_frame() {
  bowling_game_init();
  roll_many(18, 0);
  bowling_game_roll(10);
  bowling_game_roll(7);
  bowling_game_roll(3);
  assert( bowling_game_score() == 20);
}

static void test_perfect_game() {
  bowling_game_init();
  roll_many(12, 10);
  assert( bowling_game_score() == 300);
}

int main() {
  test_gutter_game();
  test_all_ones();
  test_one_spare();
  test_multiple_spares();
  test_one_strike();
  test_multiple_strikes();
  test_spare_after_gutter_ball();
  test_strike_in_last_frame();
  test_perfect_game();
}
