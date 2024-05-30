/*
 * Aidan Carey
 * May 29th 2024
 * main.c
 */

#include "stdio.h"
#include "stdlib.h"
#include "raylib.h"

#include "board.h"

// Initial screen size
#define WIDTH 800
#define HEIGHT 800

// Perl inspired subroutines
#define say(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#define unless(cond) if (!(cond))

int main(int argc, char *argv[]) {
  // Check for rows and columns input
  unless (argc == 3) {
    say("usage: %s ROWS COLUMNS", argv[0]);
    return 1;
  }

  // Get rows and cols from input
  int rows = atoi(argv[1]);
  int cols = atoi(argv[2]);
  
  int *current = malloc(rows * cols * sizeof(current));
  int *next = malloc(rows * cols * sizeof(next));

  // Initialize boards with 0s
  init_board(current, rows, cols);
  init_board(next, rows, cols);

  // Create a glider
  current[5 * cols + 5] = 1;
  current[4 * cols + 4] = 1;
  current[5 * cols + 6] = 1;
  current[4 * cols + 6] = 1;
  current[3 * cols + 6] = 1;

  // Create window
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
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
    draw_board(current, screen_width, screen_height, rows, cols);

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
      int cell_i = mouse_x / (screen_width / rows);
      int cell_j = mouse_y / (screen_height / cols);

      // Invert clicked cell
      current[cell_i * cols + cell_j] = !current[cell_i * cols + cell_j];
    }

    // Update the board if not paused
    if (!paused && step % 2) {
      update_board(current, next, rows, cols);
      move_board(next, current, rows, cols);
    }
  }

  // Clean up
  free(current);
  free(next);
  
  CloseWindow();
  
  return 0;
}
