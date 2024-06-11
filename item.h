#ifndef ITEM_H
#define ITEM_H

#define ITEM_POOL_QUANTITY 9 // increment this when creating new items

#define NEW_ITEMS_RANGE_START 2
#define NEW_ITEMS_RANGE_END 5

typedef struct
{
    char name[17];
    char description[56];
} Item;

extern Item itemPool[ITEM_POOL_QUANTITY];
extern Item *itemChest[NEW_ITEMS_RANGE_END];

void generateChestItems();

// void generateRandomItems(Item *itemArray, int *numItems);
void printItemsFromPtr(Item **itemArray, int numItems);

#endif