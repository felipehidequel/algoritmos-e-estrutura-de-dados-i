#ifndef BATALHA_H
#define BATALHA_H

#include "player.h"
#include "npc.h"

/*
    monsto.hp - player.damage
    player.hp - monstro.damage
*/
void batalha(Player *player, NPC *monstro);

void print_batalha(Player *p, NPC *m);

#endif // BATALHA_H