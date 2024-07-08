#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "actors/player.h"

// Gameplay functionality

// Bullet bulletArray[MAX_BULLETS];
int bulletIndex;
Player dealer, player;
Player *shotgunHolder;

void initGame()
{
    strcpy(dealer.name, "Dealer");
    strcpy(player.name, "Player");
    dealer.opponent = &player;
    player.opponent = &dealer;
}

/// @brief A round is a fresh start. players' items are emptied.
// lives assigned. new items are made.
void initRound()
{
    initPlayerItems(&player);
    initPlayerItems(&dealer);
    shotgunHolder = &player;
    bulletIndex = 0;
    assignCharges(&player, &dealer);
    generateChestItems();
    cpuDrawItemsFromChest(&dealer);
    playerDrawItemsFromChest(&player);
}

void beginTurn()
{
    runInputDialogLoop(); // TODO
}

void runInputDialogLoop()
{
    while (true)
    {
        // TODO all this
        //
        break;
    }
}

void flipShotgunHolder()
{
    if (shotgunHolder == &player)
    {
        shotgunHolder = &dealer;
    }
    else
    {
        shotgunHolder = &player;
    }
    printf("Shotgun now controlled by %s\n", shotgunHolder->name);
}

void pickUpShotgun()
{
    char inputChar;
    int ch;

    while (true)
    {
        printf("Shoot dealer (1) or yourself (2): ");
        inputChar = fgetc(stdin);

        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        if (inputChar != '1' || inputChar != '2')
        {
            printf("Invalid option.\n");
            continue;
        }
        if (fireShotgun(inputChar - '0' - 1))
        {
            flipShotgunHolder();
        }
        break;
    }
}

// returns true if your turn is over
bool fireShotgun(bool shotYourself)
{
    Bullet *firedBullet = &bulletArray[bulletIndex++];
    Player *victim = shotYourself ? &shotgunHolder : shotgunHolder->opponent;
    printf("%s shot %s with a %s round!\n", shotgunHolder->name, victim->name, printBulletType(*firedBullet));
    bool tookDamage = updatePlayerHealth(victim, firedBullet);
    if (victim == shotgunHolder && !tookDamage)
    {
        return true;
    }
    return false;
}

// returns true if you took damage
bool updatePlayerHealth(Player *player, Bullet *firedBullet)
{
    if (firedBullet->type == LIVE)
    {
        player->charges--;
        // if sawed off
        //   player->charged--
        return true;
    }
    return false;
}

void gameLoop()
{
    initRound();
    exit(0);
}

// void gameLoop()
// {

//     while (1)
//     {
//         assignCharges(&player, &dealer);
//         initRound();
//         printPlayer(&dealer);
//         printPlayer(&player);
//         shoot(&dealer);

//         break; //TODO: User input
//     }
// }