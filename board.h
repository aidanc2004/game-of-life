/*
 * Aidan Carey
 * May 29th 2024
 * board.h
 */

#ifndef BOARD_H
#define BOARD_H

#define ROWS 50
#define COLS 50

void init_board(int *board);
void print_board(int *board);
int check_neighbors(int *board, int i, int j);
int is_alive(int *board, int i, int j);
int in_bounds(int i, int j);
int update_cell(int *board, int i, int j);
void update_board(int *current, int *next);
void move_board(int *src, int *dst);
void draw_board(int *board, int screen_width, int screen_height);

#endif
