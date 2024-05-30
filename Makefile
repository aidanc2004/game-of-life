CC = cc
PKG_CONFIG = pkg-config
RAYLIB_FLAGS = $(shell $(PKG_CONFIG) --libs --cflags raylib)

SRC = main.c board.c
OUT = game-of-life

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(SRC) $(RAYLIB_FLAGS) -o $(OUT)

clean:
	rm -f $(OUT)

.PHONY: all clean
