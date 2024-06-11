#ifndef BULLET_H
#define BULLET_H

#define LIVE 1
#define BLANK 0
#define EMPTY -1
#define MIN_BULLETS 2
#define MAX_BULLETS 8

typedef struct
{
    int type;   /* live or blank */
    int damage; /* default to 1; become 2 if sawed off */
} Bullet;

void printBulletArray(Bullet *bulletArray);
void generateBulletsArray(Bullet *bulletArray);

#endif // BULLET_H
