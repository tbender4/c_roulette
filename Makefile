OBJECTS = main.c player.c item.c bullet.c
CFLAGS = -g
SDLCFLAGS = -D_THREAD_SAFE
SRC = main.c bullet.c player.c item.c shotgun.c


all: build

build: $(SRC)
	gcc $(CFLAGS) -o debug $(SRC)

clean:
	rm -f main

sdl2: sdl2.c
	gcc -o sdl_test sdl2.c -g `sdl2-config --cflags --libs`