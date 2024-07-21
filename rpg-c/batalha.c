#include "batalha.h"

void batalha(Player *player, NPC *monstro)
{

    while (player->hp > 0 && monstro->hp > 0)
    {
        monstro->hp -= player->damage;
        player->hp -= monstro->damage;
        print_batalha(player, monstro);
        sleep(3);
    }

    if (player->hp > 0)
    {
        printf("You win!! ++%dexp\n", monstro->exp);
        player->exp += monstro->exp;
        player->hp = player->maxHp;
        if (up_level(player))
        {
            printf("Level UP!!\n");
        }

        print_player(player);
    }
    else
    {
        printf("Game Over! :(\n");
    }
}

void print_batalha(Player *p, NPC *m)
{
    printf("==================\n");
    printf("[PLAYER] HP %d/%d\n", p->hp, p->maxHp);
    printf("==================\n");

    printf("==================\n");
    printf("[MONSTER] HP %d/%d\n", m->hp, HP_MAX_MONSTER);
    printf("==================\n");
}