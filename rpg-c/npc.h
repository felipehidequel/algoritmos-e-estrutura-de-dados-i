#ifndef NPC_H
#define NPC_H

#define HP_MAX_MONSTER 100

typedef struct npc NPC;

/*Função para inicializar um monstro
*@param level: nivel do monstro
*@return monstro: estrura de dados NPC

*/
NPC cria_monstro(int level);

void print_monstro(NPC m);

#endif // NPH_H