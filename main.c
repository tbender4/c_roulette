#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bullet.h"
#include "player.h"

int main()
{
    srand(time(NULL));

    Bullet bulletArray[MAX_BULLETS];
    Player dealer;
    strcpy(dealer.name, "Dealer");
    Player player;
    // promptPlayerName(&player);
    strcpy(player.name, "Player");

    assignCharges(&player, &dealer);
    dealer.opponent = &player;
    player.opponent = &dealer;

    generateBulletsArray(bulletArray);

    printf("Dealer Name: %s, Lives: %d\n", dealer.name, dealer.charges);
    printf("Player Name: %s, Lives: %d\n", player.name, player.charges);
    return 0;
}