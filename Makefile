OBJECTS = main.c player.c item.c bullet.c
CFLAGS = -g
SRC = main.c bullet.c player.c


all: build

build: $(SRC)
	gcc $(CFLAGS) -o main $(SRC)

clean:
	rm -f main