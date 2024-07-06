#ifndef GAME_H
#define GAME_H
#include "actors/bullet.h"
#include "actors/player.h"

// Gameplay global variables

extern Bullet bulletArray[MAX_BULLETS]; //shotgun's bullets
extern int bulletIndex;         //next bullet to be racked
extern Player dealer, player;   //current player
extern Player *shotgunHolder;   //current holder of the shotgun gets to go.

void initGame();
void initRound();
void gameLoop();


#endif