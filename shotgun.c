#include "stdio.h"
#include "shotgun.h"

void flipShotgunHolder() {
    if(shotgunHolder == &player) {
        shotgunHolder = &dealer;
    }
    else {
        shotgunHolder = &player;
    }
}

void shoot(Player* victim) {
    Bullet *firedBullet = &bulletArray[bulletIndex];
    
    printf("%s shot %s with a %s round!", shotgunHolder->name, victim->name, printBulletType(*firedBullet));

}