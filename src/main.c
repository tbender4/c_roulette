#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "game.h"


int main()
{
    srand(time(NULL));
    initGame();
    gameLoop();
    return 0;
}