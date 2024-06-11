#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bullet.h"
#include "player.h"
#include "item.h"
#include "shotgun.h"

// Global variables
Bullet bulletArray[MAX_BULLETS];
int bulletIndex;
Player dealer, player;
Player *shotgunHolder;
//

void initGame();
void gameLoop();
void initRound();

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
}

void initRound() {
    initPlayerItems(&player);
    initPlayerItems(&dealer);
    shotgunHolder = &player;
    bulletIndex = 0;
    generateChestItems();
}

void gameLoop()
{

    while (1)
    {
        assignCharges(&player, &dealer);
        initRound();
        printPlayer(&dealer);
        printPlayer(&player);
        shoot(&dealer);
        
        break; // User input
    }
}
