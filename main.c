#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bullet.h"
#include "player.h"
#include "item.h"

// Global variables
Bullet bulletArray[MAX_BULLETS];
Player dealer, player;

void initGame();
void gameLoop();

int main()
{
    srand(time(NULL));
    initGame();
    gameLoop();
    return 0;
}

void initGame()
{
    generateBulletsArray(bulletArray);

    strcpy(dealer.name, "Dealer");
    strcpy(player.name, "Player");
    dealer.opponent = &player;
    player.opponent = &dealer;
    assignCharges(&player, &dealer);
    initPlayerItems(&player);
    initPlayerItems(&dealer);
}

void gameLoop()
{

    // TODO: Make this a loop
    while (1)
    {
        printPlayer(&dealer);
        printPlayer(&player);
        generateChestItems();
        break;
    }
}
