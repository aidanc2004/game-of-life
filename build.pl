#!/usr/bin/perl

# Compile program
system "cc main.c board.c \$(pkg-config --libs --cflags raylib) -o game-of-life";

# Run program with arguments
my $args = join " ", @ARGV;
system "./game-of-life $args";
