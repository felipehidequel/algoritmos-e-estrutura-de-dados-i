#ifndef PLAYER_H
#define PLAYER_H

#define HP_MAX_PLAYER 100

typedef struct player Player;

Player cria_player(char *nome);

void print_player(Player *p);

int up_level(Player *p);

#endif // PLAYER_H