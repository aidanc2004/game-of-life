/*
 * Aidan Carey
 * May 29th 2024
 * main.c
 */

#include "stdio.h"
#include "raylib.h"

#include "board.h"

// Initial screen size
#define WIDTH 800
#define HEIGHT 800

// Print with newline
#define say(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)

int main() {
  // TODO: Take input for rows and cols
  int current[ROWS][COLS];
  int next[ROWS][COLS];

  // Initialize boards with 0s
  init_board(current);
  init_board(next);

  // Create a glider
  current[5][5] = 1;
  current[4][4] = 1;
  current[5][6] = 1;
  current[4][6] = 1;
  current[3][6] = 1;
  
  InitWindow(WIDTH, HEIGHT, "Game of Life");
  SetTargetFPS(5);
  
  while (!WindowShouldClose()) {
    int screen_width = GetScreenWidth();
    int screen_height = GetScreenHeight();
    
    BeginDrawing();

    ClearBackground(BLACK);
    
    draw_board(current, screen_width, screen_height);
    
    EndDrawing();

    // Update the board
    update_board(current, next);
    move_board(next, current);

    // Wait for user input
    //getchar();
  }
  
  CloseWindow();
  
  return 0;
}
