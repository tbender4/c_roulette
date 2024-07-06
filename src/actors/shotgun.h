#ifndef SHOTGUN_H
#define SHOTGUN_H

#include "player.h"
#include "bullet.h"

extern Bullet bulletArray[MAX_BULLETS];
extern int bulletIndex;
extern Player dealer, player;
extern Player *shotgunHolder;

/// @brief Flips the shotgun to the other player
void flipShotgunHolder();

/// @brief Shoots shotgun and ends turn.
/// @param victim 
void shoot(Player *victim);

#endif
