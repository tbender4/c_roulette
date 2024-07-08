#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "item.h"
#include "player.h"

//// Placeholder functions for each item
void useAdrenaline()
{
    printf("Using adrenaline.\n");
}

void useBeer()
{
    printf("Using beer.\n");
}

void useBurnerPhone()
{
    printf("Using burner phone.\n");
}

void useExpiredMedicine()
{
    printf("Using expired medicine.\n");
}

void useCigarette()
{
    printf("Using cigarette.\n");
}

void useHandSaw()
{
    printf("Using hand saw.\n");
}

void useHandcuffs()
{
    printf("Using handcuffs.\n");
}

void useInverter()
{
    printf("Using inverter.\n");
}

void useMagnifyingGlass()
{
    printf("Using magnifying glass.\n");
}
////

// Predefined items available in the game
const Item itemPool[ITEM_POOL_QUANTITY] = {
    {"adrenaline", "steal and item and use it immediately.", useAdrenaline},
    {"beer", "racks the shotgun. ejects the current shell.", useBeer},
    {"burner phone", "a mysterious voice gives you insight from the future.", useBurnerPhone},
    {"expired medicine", "50\% chance to regain 2 charges. if not, lose 1 charge.", useExpiredMedicine},
    {"cigarette", "takes the edge off. regain 1 charge.", useCigarette},
    {"hand saw", "shotgun deals 2 damage.", useHandSaw},
    {"handcuffs", "dealer skips the next turn.", useHandcuffs},
    {"inverter", "swaps the polarity of the current shell in the chamber.", useInverter},
    {"magnifying glass", "check the current round in the chamber.", useMagnifyingGlass}};

// Random items will be sent to this chest for the user to widthdraw from
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
bool itemBoardIsFull(Player *player)
{
    if (player->numItems == MAX_PLAYER_ITEMS)
    {
        printf("How unfortunate...\n");
        return false;
    }
    return true;
}
bool tryAddItemToPlayer(Player *player, int selection, Item *newItemAddr)
{
    if (player->items[selection - 1] == NULL)
    {
        player->items[selection - 1] = newItemAddr;
        player->numItems++;
        return true;
    }
    printf("Item already in slot. Try again\n");
    return false;
}

void cpuDrawItemsFromChest(Player *player) {
    // TODO
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
        if (itemBoardIsFull(player))
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
            if (inputChar < '1' || inputChar > '8')
            {
                printf("Invalid option.\n");
                continue;
            }
            if (!tryAddItemToPlayer(player, player->items[inputChar - '0'], item))
            {
                continue;
            }
        }
    }
}
