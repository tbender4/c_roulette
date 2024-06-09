#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bullet.h"

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
