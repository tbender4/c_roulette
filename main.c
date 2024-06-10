#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bullet.h"
#include "player.h"
#include "item.h"

int main()
{
    srand(time(NULL));

    Bullet bulletArray[MAX_BULLETS];
    generateBulletsArray(bulletArray);
    
    Player dealer, player;
    strcpy(dealer.name, "Dealer");
    // promptPlayerName(&player);
    strcpy(player.name, "Player");

    assignCharges(&player, &dealer);
    dealer.opponent = &player;
    player.opponent = &dealer;

    initPlayerItems(&dealer);
    initPlayerItems(&player);

    printPlayer(&dealer);
    printPlayer(&player);

    return 0;
}