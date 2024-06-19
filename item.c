#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "player.h"

// Predefined items
Item itemPool[ITEM_POOL_QUANTITY] = {
    {"adrenaline", "steal and item and use it immediately."},
    {"beer", "racks the shotgun. ejects the current shell."},
    {"burner phone", "a mysterious voice gives you insight from the future."},
    {"expired medicine", "50\% chance to regain 2 charges. if not, lose 1 charge."},
    {"cigarette", "takes the edge off. regain 1 charge."},
    {"hand saw", "shotgun deals 2 damage."},
    {"handcuffs", "dealer skips the next turn."},
    {"inverter", "swaps the polarity of the current shell in the chamber."},
    {"magnifying glass", "check the current round in the chamber."}};
Item *itemChest[NEW_ITEMS_RANGE_END];

void printItem(Item *item)
{
    if (item == NULL)
        printf("Empty\n");
    else
        printf("%s - %s ", item->name, item->description);
}

void printItemsFromPtr(Item **itemsPtr, int numItems)
{
    printf("Items: ");
    for (int i = 0; i < numItems; i++)
    {
        printItem(*itemsPtr);
        if (i != numItems)
            printf("| ");
        itemsPtr++;
    }
    printf("\n");
}

/// @brief Assigns 2-5 items into the chest for player to take out
void generateChestItems()
{
    int i = 0;
    int upper = NEW_ITEMS_RANGE_END;
    int lower = NEW_ITEMS_RANGE_START;
    int quantity = (rand() % (upper - lower + 1)) + lower;

    for (int itemIndex; i < quantity; i++)
    {
        itemChest[i] = &itemPool[rand() % ITEM_POOL_QUANTITY];
    }
    // clear old
    for (; i < NEW_ITEMS_RANGE_END; i++)
    {
        itemChest[i] = NULL;
    }
    printf("New items are available:\n");
    printItemsFromPtr(itemChest, NEW_ITEMS_RANGE_END);
}