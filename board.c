/*
 * Aidan Carey
 * May 29th 2024
 * board.c
 */

#include "stdio.h"
#include "board.h"
#include "raylib.h"

// Fill a board with 0s
void init_board(int *board) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i * COLS + j] = 0;
    }
  }
}

// Print out the board with an 'x' for an alive cell and ' ' for a dead one
void print_board(int *board) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      putchar(board[i * COLS + j] ? 'x' : '.');
    }
    putchar('\n');
  }
}

// Check if a cell is in the bounds of the board
int in_bounds(int i, int j) {
  return i < ROWS && i >= 0 && j < COLS && j >= 0;
}

// Check if a cell is alive and is on the board
int is_alive(int *board, int i, int j) {
  return board[i * COLS + j] && in_bounds(i, j);
}

// Get the number of neighbors of a cell
int check_neighbors(int *board, int i, int j) {
  int n = 0;
    
  int neighbors[8][2] = {
    {i-1, j-1}, {i-1, j}, {i-1, j+1}, // * * *
    {i  , j-1},           {i  , j+1}, // * x *
    {i+1, j-1}, {i+1, j}, {i+1, j+1}  // * * *
  };
    
  for (int i = 0; i < 8; ++i)
    n += is_alive(board, neighbors[i][0], neighbors[i][1]);
    
  return n;
}

// Check if cell should be alive or dead next generation
int update_cell(int *board, int i, int j) {
  int neighbors = check_neighbors(board, i, j);

  if (is_alive(board, i, j)) {
    return neighbors == 2 || neighbors == 3;
  } else {
    return neighbors == 3;
  }
}

// Update all of the cells in current and put the updated cells in next
void update_board(int *current, int *next) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      next[i * COLS + j] = update_cell(current, i, j);
    }
  }
}

// Move all of the cells from one board to another
void move_board(int *src, int *dst) {
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
      dst[i * COLS + j] = src[i * COLS + j];
    }
  }
}

// Draw the board on the screen
void draw_board(int *board, int screen_width, int screen_height) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (!board[i * COLS + j]) continue;
      
      DrawRectangle(i * (screen_width/ROWS), j * (screen_height/COLS), screen_width/ROWS, screen_height/COLS, WHITE);
    }
  }
}
