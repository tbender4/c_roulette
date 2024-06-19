#ifndef PLAYER_H
#define PLAYER_H

#include "item.h"
#define MIN_CHARGES 2
#define MAX_CHARGES 4
#define MAX_PLAYER_ITEMS 8

// typedef struct Item;

struct Player
{
    char name[30];
    int charges; // lives
    struct Player *opponent;
    Item *items[8];
    int numItems; // Keep track of live items. Dead items are
};
typedef struct Player Player;

void promptPlayerName(Player *player);
void assignCharges(Player *player, Player *dealer);
void printPlayer(Player *player);

void initPlayerItems(Player *player);
void printPlayerItems(Player *player);

#endif