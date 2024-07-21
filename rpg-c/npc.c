#include "npc.h"

struct npc
{
    int hp;     // 0 - 100
    int damage; // 5 * level
    int level;  // 1 - 50 rand
    char name[20];
    int exp; // quanto xp ele dropa
};

NPC cria_monstro(int level)
{
    NPC monstro;
    monstro.level = level;
    monstro.hp = HP_MAX_MONSTER;
    monstro.damage = level * 5;
    monstro.exp = 7 * level;
    snprintf(monstro.name, sizeof(monstro.name), "Monster #%d", level);

    return monstro;
}

void print_monstro(NPC m)
{
    printf("Nome: %s\n", m.name);
    printf("Nivel: %d\n", m.level);
    printf("Hp: %d\n", m.hp);
    printf("Dano: %d\n", m.damage);
}