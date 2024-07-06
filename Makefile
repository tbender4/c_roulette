OBJECTS = src/main.c src/player.c src/item.c src/bullet.c
DEBUG_FLAGS = -g
SRC = src/main.c src/bullet.c src/player.c src/item.c src/shotgun.c
DEBUG_DIR=build/debug


all: build

build: $(SRC)
	gcc $(DEBUG_FLAGS) -o $(DEBUG_DIR)/debug $(SRC)

clean:
	rm -f main

sdl2: sdl2.c
	gcc ${DEBUG_FLAGS} -o $(DEBUG_DIR)/sdl_test sdl2.c -g `sdl2-config --cflags --libs` -lSDL2_ttf 