#ifndef GAME_H
#define GAME_H
#include "stdlib.h"
#include "game.h"
#include "actors/player.h"

// Gameplay functionality

// Bullet bulletArray[MAX_BULLETS];
int bulletIndex;
Player dealer, player;
Player *shotgunHolder;

void initGame()
{
    strcpy(dealer.name, "Dealer");
    strcpy(player.name, "Player");
    dealer.opponent = &player;
    player.opponent = &dealer;
}

/// @brief A round is a fresh start. players' items are emptied.
// lives assigned. new items are made.
void initRound()
{
    initPlayerItems(&player);
    initPlayerItems(&dealer);
    shotgunHolder = &player;
    bulletIndex = 0;
    assignCharges(&player, &dealer);
    generateChestItems();
    runInputDialog();
}

void gameLoop() {
        initRound();
        exit(0);
}

// void gameLoop()
// {

//     while (1)
//     {
//         assignCharges(&player, &dealer);
//         initRound();
//         printPlayer(&dealer);
//         printPlayer(&player);
//         shoot(&dealer);
        
//         break; //TODO: User input
//     }
// }

#endif