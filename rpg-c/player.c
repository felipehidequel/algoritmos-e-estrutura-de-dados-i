#include "player.h"

struct player
{
    int hp;     // 0 - 100
    int damage; // 25 * level
    int level;  // 1 - 50 rand
    int exp;    // 0 - 100
    int maxHp;  // 100
    int maxExp; // 100
    char name[20];
};

Player cria_player(char *nome)
{
    Player p;
    p.maxHp = HP_MAX_PLAYER;
    p.hp = p.maxHp;
    p.exp = 0;
    p.level = 1;
    p.damage = 25 * p.level;
    p.maxExp = 100 * p.level;
    strcpy(p.name, nome);
    return p;
}

void print_player(Player *p)
{
    printf("================================\n");
    printf("Nome: %s\n", p->name);
    printf("Nivel: %d\n", p->level);
    printf("Hp: %d / %d  \n", p->hp, p->maxHp);
    printf("XP: %d / %d\n", p->exp, p->maxExp);
    printf("DANO: %d\n", p->damage);
    printf("================================\n");
}

int up_level(Player *p)
{
    if (p->exp >= p->maxExp)
    {
        p->level += 1;
        p->damage *= p->level;
        p->maxHp += 25;
        p->hp = p->maxHp;
        p->exp = 0;
        return 1;
    }
    return 0;
}