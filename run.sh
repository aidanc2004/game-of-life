#!/bin/bash

cc main.c $(pkg-config --libs --cflags raylib) -o game-of-life && ./game-of-life
