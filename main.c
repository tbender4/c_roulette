#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LIVE 1
#define BLANK 0
#define EMPTY -1
#define MAX_BULLETS 8
#define MAX_LIVES 4

typedef struct
{
    int type; /* live or blank */
} Bullet;

typedef struct
{
    char name[30];
    int charges;
} Player;

// Bullet //

void shuffle(Bullet *array, int quantity)
{
    for (int i = quantity - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Bullet temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    printf("Shuffled!\n");
}

char *printBulletType(Bullet bullet)
{
    switch (bullet.type)
    {
    case LIVE:
        return "live";
    case BLANK:
        return "blank";
    case EMPTY:
        return "empty";
    default:
        return "undefined";
    }
}

void printBulletArray(Bullet *bulletArray)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (bulletArray[i].type == EMPTY)
            break;
        printf("%s ", printBulletType(bulletArray[i]));
    }
    printf("\n");
}

void generateBulletsArray(Bullet *bulletArray)
{
    int i;
    int quantity = (rand() % (MAX_BULLETS - 1)) + 2;
    printf("Number of bullets to make: %d\n", quantity);
    int liveQuantity = quantity / 2;

    if (rand() % 2)
    {
        liveQuantity = quantity - liveQuantity;
    }
    printf("%d live, %d blank\n", liveQuantity, quantity - liveQuantity);

    for (i = 0; i < quantity; i++)
    {
        if (i < liveQuantity)
            bulletArray[i].type = LIVE;
        else
            bulletArray[i].type = BLANK;
    }
    for (; i < MAX_BULLETS; i++)
    {
        bulletArray[i].type = EMPTY;
    }
    shuffle(bulletArray, quantity);
    printBulletArray(bulletArray);
}

// Player //
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

int main()
{
    srand(time(NULL));

    Bullet bulletArray[8];
    Player dealer;
    strcpy(dealer.name, "Dealer");
    Player player;
    promptPlayerName(&player);
    assignCharges(&player, &dealer);

    generateBulletsArray(bulletArray);

    printf("Dealer Name: %s, Lives: %d\n", dealer.name, dealer.charges);
    printf("Player Name: %s, Lives: %d\n", player.name, player.charges);
    return 0;
}