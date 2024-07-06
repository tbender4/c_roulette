#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "player.h"

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

void initPlayerItems(Player *player)
{
    player->numItems = 0;
    for (int i = 0; i < MAX_PLAYER_ITEMS; i++)
        player->items[i] = NULL;
}

void assignCharges(Player *player, Player *dealer)
{
    int charges = (rand() % (MAX_CHARGES - 1)) + MIN_CHARGES;
    player->charges = charges;
    dealer->charges = charges;
}

void printPlayersCharges(Player *dealer, Player *player)
{
    printf("%s lives: %d | ", dealer->name, dealer->charges);
    printf("%s lives: %d\n", player->name, player->charges);
}

void printPlayerItems(Player *player)
{
    printf("Items for %s:\n", player->name);
    printItemsFromPtr(player->items, MAX_PLAYER_ITEMS);
}