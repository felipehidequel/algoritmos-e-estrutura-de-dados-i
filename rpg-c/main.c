#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define HP_MAX_MONSTER 100
#define HP_MAX_PLAYER 100

typedef struct npc
{
    int hp;     // 0 - 100
    int damage; // 5 * level
    int level;  // 1 - 50 rand
    char name[20];
    int exp; // quanto xp ele dropa
} NPC;

typedef struct player
{
    int hp;     // 0 - 100
    int damage; // 25 * level
    int level;  // 1 - 50 rand
    int exp;    // 0 - 100
    int maxHp;  // 100
    int maxExp; // 100
    char name[20];
} Player;

/*Função para inicializar um monstro
*@param level: nivel do monstro
*@return monstro: estrura de dados NPC

*/
NPC cria_monstro(int level);

void print_monstro(NPC m);

Player cria_player(char *nome);

void print_player(Player *p);

/*
    monsto.hp - player.damage
    player.hp - monstro.damage
*/
void batalha(Player *player, NPC *monstro);

int up_level(Player *p);

void print_batalha(Player *p, NPC *m);

int main()
{
    int n_monsters = 5;
    NPC monstros[n_monsters];
    Player player;
    char name_player[20];

    printf("Entry hero name: ");
    scanf("%[^\n]", name_player);
    player = cria_player(name_player);
    print_player(&player);
    printf("\n");

    for (int i = 0; i < n_monsters; i++)
    {
        monstros[i] = cria_monstro(i + 1);
        printf("New monster!\n");
        print_monstro(monstros[i]);
        printf("===================\n");
    }

    batalha(&player, &monstros[0]);

    return 0;
}

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

void print_batalha(Player *p, NPC *m)
{
    printf("==================\n");
    printf("[PLAYER] HP %d/%d\n", p->hp, p->maxHp);
    printf("==================\n");

    printf("==================\n");
    printf("[MONSTER] HP %d/%d\n", m->hp, HP_MAX_MONSTER);
    printf("==================\n");
}