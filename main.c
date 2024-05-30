/*
 * Aidan Carey
 * May 29th 2024
 * main.c
 */

#include "stdio.h"
#include "raylib.h"

#include "board.h"

#define WIDTH 800
#define HEIGHT 600

// Print with newline
#define say(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)

int main() {
  int current[ROWS][COLS];
  int next[ROWS][COLS];
  
  init_board(current);
  init_board(next);

  // Create a glider
  current[5][5] = 1;
  current[4][4] = 1;
  current[5][6] = 1;
  current[4][6] = 1;
  current[3][6] = 1;
  
  InitWindow(WIDTH, HEIGHT, "Game of Life");

  while (!WindowShouldClose()) {
    // Draw
    BeginDrawing();
    EndDrawing();

    // Update
    print_board(current);

    update_board(current, next);

    move_board(next, current);

    getchar();
  }
  
  CloseWindow();
  
  return 0;
}
