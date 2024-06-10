#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "player.h"

// Predefined items
Item itemPool[ITEM_POOL_COUNT] = {
    {"medicine", ""},
    {"beer", ""},
    {"cigarette", ""},
    {"magnifying glass", ""},
    {"handcuffs", ""}};

// void assignRandomItemsToArray(Item *itemArray, int *numItems) {
//     *numItems = (rand() % NEW_ITEMS_RANGE_END - 1) + NEW_ITEMS_RANGE_START;
//     for (int i = 0; i < *numItems; i++) {
//         int randomIndex = rand() % ITEM_POOL_COUNT;
//         itemArray[i] = itemPool[randomIndex];
//     }
// }

// void assignRandomItemsToPlayer(Player *player)
// {
//     int numItems = (rand() % 4) + 2;

//     player->numItems = numItems;
//     for (int i = 0; i < numItems; i++)
//     {
//         int randomIndex = rand() % ITEM_POOL_COUNT;
//         player->items[i] = &itemPool[randomIndex];
//     }
// }

void printItem(Item *item)
{
    if (item == NULL)
        printf("Empty\n");
    else
        printf("s - %s\n", item->name, item->description);
}

void printItemsFromPtr(Item **itemsPtr, int numItems)
{
    for (int i = 0; i < numItems; i++)
    {
        printf("Item %d: ", i + 1);
        printItem(*itemsPtr);
        itemsPtr++;
    }
}