#!/bin/bash

cc main.c board.c $(pkg-config --libs --cflags raylib) -o game-of-life && ./game-of-life
