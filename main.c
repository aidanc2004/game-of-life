/*
 * Aidan Carey
 * May 29th 2024
 * main.c
 */

#include "stdio.h"
#include "raylib.h"

int main() {
  InitWindow(800, 600, "Game of Life");

  while (!WindowShouldClose()) {
    BeginDrawing();
    EndDrawing();
  }
  
  CloseWindow();
  
  return 0;
}
