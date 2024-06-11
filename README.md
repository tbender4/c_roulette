# Retro Roulette

A C implementation of Buckshot Roulette. With the intention of porting the game to retro devices.

## Game Plan

Develop the core gameplay functionality. Once the gameplay is established, port the game to the Sony Playstation. After it's ported to the playstation we attempt to get graphics and everything else running.


## Game Plan SDL

Let's get this running in SDL2... at least so I'm not stuck in a terminal.

```bash
brew install sdl2
gcc -o sdl_test sdl2.c -g `sdl2-config --cflags --libs`   
```