/*
 * Aidan Carey
 * May 29th 2024
 * board.h
 */

#ifndef BOARD_H
#define BOARD_H

void init_board(int *board, int rows, int cols);
void print_board(int *board, int rows, int cols);
int check_neighbors(int *board, int i, int j, int rows, int cols);
int is_alive(int *board, int i, int j, int rows, int cols);
int in_bounds(int i, int j, int rows, int cols);
int update_cell(int *board, int i, int j, int rows, int cols);
void update_board(int *current, int *next, int rows, int cols);
void move_board(int *src, int *dst, int rows, int cols);
void draw_board(int *board, int screen_width, int screen_height, int rows, int cols);

#endif
