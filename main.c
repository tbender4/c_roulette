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


void initGame() {
    generateBulletsArray(bulletArray);
    strcpy(dealer.name, "Dealer");
    strcpy(player.name, "Player");
    dealer.opponent = &player;
    player.opponent = &dealer;
    assignCharges(&player, &dealer);
    initPlayerItems(&player);
    initPlayerItems(&dealer);
}

void gameLoop() {


  // TODO: Make this a loop
}

int main()
{
    srand(time(NULL));
    initGame();
    printPlayer(&dealer);
    printPlayer(&player);

    return 0;
}