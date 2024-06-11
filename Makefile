OBJECTS = main.c player.c item.c bullet.c
CFLAGS = -g
SRC = main.c bullet.c player.c item.c


all: build

build: $(SRC)
	gcc $(CFLAGS) -o debug $(SRC)

clean:
	rm -f main