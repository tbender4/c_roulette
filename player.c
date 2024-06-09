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
    int charges = (rand() % (MAX_LIVES - 1)) + 2;
    player->charges = charges;
    dealer->charges = charges;
}