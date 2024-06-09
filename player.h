#ifndef PLAYER_H
#define PLAYER_H

#define MAX_LIVES 4

struct Player
{
    char name[30];
    int charges; // lives
    struct Player *opponent;
};
typedef struct Player Player;

void promptPlayerName(Player *player);
void assignCharges(Player *player, Player *dealer);

#endif