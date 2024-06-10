#ifndef ITEM_H
#define ITEM_H

#define ITEM_POOL_COUNT 5 // increment this when creating new items

#define NEW_ITEMS_RANGE_START 2
#define NEW_ITEMS_RANGE_END 5

typedef struct
{
    char name[30];
    char description[200];
} Item;

extern Item itemPool[ITEM_POOL_COUNT];
extern Item nullItem;

// void generateRandomItems(Item *itemArray, int *numItems);
void printItemsFromPlayer(Item *itemArray, int numItems);
// void initPlayerItems(Item **playerItems);

#endif