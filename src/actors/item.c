#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "item.h"
#include "player.h"

// Predefined items available in the game
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

// An array of items available to choose from in the chest.
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

/// @brief Assigns 2-5 items into the chest for player to take out. The item will not be described.
// Only the name will be shown.
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
    printf("New items are available.\n");
    // TODO: PrintName
}

// return if
bool reachedMaxItems(Player *player)
{
    if (player->numItems == MAX_PLAYER_ITEMS)
    {
        printf("How unfortunate...\n");
        return false
    }
    return true;
}
bool tryAddItemToPlayer(Player *player, int index, Item *newItemAddr)
{
    if (player->items[index - 1] == NULL)
    {
        player->items[index - 1] = newItemAddr;
        player->numItems++;
        return true;
    }
    printf("Item already in slot. Try again\n");
    return false;
}

// Player will draw items from chest one-by-one.
void playerDrawItemsFromChest(Player *player)
{
    Item *item = *itemChest;
    for (; item != NULL; item++)
    {
        char inputChar;
        int ch, validInput = 0;
        printf("Widthdrew %s.\n", item->name);
        if (reachedMaxItems(player))
        {
            break;
        }
        // TODO: If console input
        while (!validInput)
        {
            validInput = 0;
            printf("Select a spot to place the item (1-8): ");
            inputChar = fgetc(stdin);
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            if (inputChar < '1' || inputChar > 8)
            {
                printf("Invalid option.\n");
                continue;
            }
            if (!tryAddItemToPlayer(player, player->items[inputChar - 0], item))
            {
                continue;
            }
        }
    }
}
