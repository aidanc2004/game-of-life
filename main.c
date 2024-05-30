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

// Port favourite perl subrountines as C macros
#define say(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#define unless(cond) if (!(cond))

int main(int argc, char *argv[]) {
  // Check for rows and columns input
  unless (argc == 3) {
    say("usage: %s Rows Columns", argv[0]);
    return 1;
  }
  
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
  SetTargetFPS(30);

  int paused = 0;
  int step = 0;
  
  while (!WindowShouldClose()) {
    int screen_width = GetScreenWidth();
    int screen_height = GetScreenHeight();

    // Only step if not paused
    if (!paused) step++;
    
    // Draw to the screen
    BeginDrawing();

    ClearBackground(BLACK);
    draw_board(current, screen_width, screen_height);

    // Show text if paused
    if (paused) DrawText("Paused", 10, screen_height - 30, 20, GRAY);
    
    EndDrawing();
    
    // Press space to pause
    if (IsKeyPressed(KEY_SPACE)) paused = !paused;

    // Click to place/remove a cell
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      int mouse_x = GetMouseX();
      int mouse_y = GetMouseY();

      // Clicked cell position
      int cell_i = mouse_x / (screen_width / ROWS);
      int cell_j = mouse_y / (screen_height / COLS);

      // Invert clicked cell
      current[cell_i][cell_j] = !current[cell_i][cell_j];
    }

    // Update the board if not paused
    if (!paused && step % 2) {
      update_board(current, next);
      move_board(next, current);
    }

    
  }
  
  CloseWindow();
  
  return 0;
}
