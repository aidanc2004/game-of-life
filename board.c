/*
 * Aidan Carey
 * May 29th 2024
 * board.c
 */

#include "stdio.h"
#include "board.h"
#include "raylib.h"

// Fill a board with 0s
void init_board(int *board, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      board[i * cols + j] = 0;
    }
  }
}

// Print out the board with an 'x' for an alive cell and ' ' for a dead one
void print_board(int *board, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      putchar(board[i * cols + j] ? 'x' : '.');
    }
    putchar('\n');
  }
}

// Check if a cell is in the bounds of the board
int in_bounds(int i, int j, int rows, int cols) {
  return i < rows && i >= 0 && j < cols && j >= 0;
}

// Check if a cell is alive and is on the board
int is_alive(int *board, int i, int j, int rows, int cols) {
  return board[i * cols + j] && in_bounds(i, j, rows, cols);
}

// Get the number of neighbors of a cell
int check_neighbors(int *board, int i, int j, int rows, int cols) {
  int n = 0;
    
  int neighbors[8][2] = {
    {i-1, j-1}, {i-1, j}, {i-1, j+1}, // * * *
    {i  , j-1},           {i  , j+1}, // * x *
    {i+1, j-1}, {i+1, j}, {i+1, j+1}  // * * *
  };
    
  for (int i = 0; i < 8; ++i)
    n += is_alive(board, neighbors[i][0], neighbors[i][1], rows, cols);
    
  return n;
}

// Check if cell should be alive or dead next generation
int update_cell(int *board, int i, int j, int rows, int cols) {
  int neighbors = check_neighbors(board, i, j, rows, cols);

  if (is_alive(board, i, j, rows, cols)) {
    return neighbors == 2 || neighbors == 3;
  } else {
    return neighbors == 3;
  }
}

// Update all of the cells in current and put the updated cells in next
void update_board(int *current, int *next, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      next[i * cols + j] = update_cell(current, i, j, rows, cols);
    }
  }
}

// Move all of the cells from one board to another
void move_board(int *src, int *dst, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      dst[i * cols + j] = src[i * cols + j];
    }
  }
}

// Draw the board on the screen
void draw_board(int *board, int screen_width, int screen_height, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (!board[i * cols + j]) continue;
      
      DrawRectangle(i * (screen_width/rows), j * (screen_height/cols), screen_width/rows, screen_height/cols, WHITE);
    }
  }
}
