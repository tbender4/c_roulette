#include "stdio.h"
#include "shotgun.h"

void flipShotgunHolder() {
    if(shotgunHolder == &player) {
        shotgunHolder = &dealer;
    }
    else {
        shotgunHolder = &player;
    }
    printf("Shotgun now controlled by %s\n", shotgunHolder->name);
}

void shoot(Player* victim) {
    Bullet *firedBullet = &bulletArray[bulletIndex];
    
    printf("%s shot %s with a %s round!/n", shotgunHolder->name, victim->name, printBulletType(*firedBullet));

}