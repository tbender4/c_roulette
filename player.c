#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "item.h"

void promptPlayerName(Player *player)
{
    printf("Enter Name: ");
    fgets(player->name, sizeof(player->name), stdin);
    size_t len = strlen(player->name);
    if (len > 0 && player->name[len - 1] == '\n')
    {
        player->name[len - 1] = '\0';
    }
}

void assignCharges(Player *player, Player *dealer)
{
    int charges = (rand() % (MAX_CHARGES - 1)) + MIN_CHARGES;
    player->charges = charges;
    dealer->charges = charges;
}

void printPlayer(Player *player) {
    printf("Dealer Name: %s, Lives: %d\n", player->name, player->charges);
    printItemsFromPlayer(player->items, player->numItems);
}

/// @brief 

/// @param playerItems 
void initPlayerItems(Player *player) {
    
    player->numItems = 0;
    for (int i = 0; i < MAX_PLAYER_ITEMS; i++)
        player->items[i] = &nullItem;
}