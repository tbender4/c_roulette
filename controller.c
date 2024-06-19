#include <stdio.h>
#include "controller.h"
#include "player.h"

void printItemQuick(Item *item)
{
    if (item == NULL)
        printf("Empty\n");
    else
        printf("Item: %s\n", item->name);
}

void cpuWithdrawFromChest(Item **itemChest, Player *dealer)
{
}

void playerWithdrawFromChest(Item **itemChest, Player *player)
{
    printf("Opening Chest...");
    for (int i = 0; i < NEW_ITEMS_RANGE_END || *itemChest == NULL; i++)
    {
        printItemQuick(*itemChest);
        if (player->numItems == MAX_PLAYER_ITEMS)
        {
            printf("Too bad...\n");
            break;
        }
        // TODO: put in player items; playeritems++
        printPlayerItems(player);
        itemChest++;
    }
}