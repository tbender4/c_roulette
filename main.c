#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LIVE 1
#define BLANK 0
#define EMPTY -1
#define MAX_BULLETS 8
#define MAX_LIVES 4

struct Bullet
{
    int type; /* live or blank */
};

struct Player
{
    char name[30];
    int charges; // lives
    struct Player *opponent;
};

struct Item
{
    char name[15];
    char description[200];
    // functionality goes here
};

// Bullet //

void shuffle(struct Bullet *array, int quantity)
{
    for (int i = quantity - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        struct Bullet temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    printf("Shuffled!\n");
}

char *printBulletType(struct Bullet bullet)
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

void printBulletArray(struct Bullet *bulletArray)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (bulletArray[i].type == EMPTY)
            break;
        printf("%s ", printBulletType(bulletArray[i]));
    }
    printf("\n");
}

void generateBulletsArray(struct Bullet *bulletArray)
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
void promptPlayerName(struct Player *player)
{
    printf("Enter Name: ");
    fgets(player->name, sizeof(player->name), stdin);
    size_t len = strlen(player->name);
    if (len > 0 && player->name[len - 1] == '\n')
    {
        player->name[len - 1] = '\0';
    }
}

void assignCharges(struct Player *player, struct Player *dealer)
{
    int charges = (rand() % (MAX_LIVES - 1)) + 2;
    player->charges = charges;
    dealer->charges = charges;
}

int main()
{
    srand(time(NULL));

    struct Bullet bulletArray[8];
    struct Player dealer;
    strcpy(dealer.name, "Dealer");
    struct Player player;
    promptPlayerName(&player);
    assignCharges(&player, &dealer);
    dealer.opponent = &player;
    player.opponent = &dealer;

    generateBulletsArray(bulletArray);

    printf("Dealer Name: %s, Lives: %d\n", dealer.name, dealer.charges);
    printf("Player Name: %s, Lives: %d\n", player.name, player.charges);
    printf("Dealer's opponent: %s\n", dealer.opponent->name);
    return 0;
}