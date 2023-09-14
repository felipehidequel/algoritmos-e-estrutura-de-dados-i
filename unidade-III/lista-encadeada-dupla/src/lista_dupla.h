#ifndef LISTA_DUPLA_H
#define LISTA_DUPLA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct lista_dupla Lista_dupla;

Lista_dupla* lst_insere(Lista_dupla* l, int v);

Lista_dupla* lst_busca(Lista_dupla* l, int v);

Lista_dupla* lst_retira(Lista_dupla* l, int v);

void lst_circ_imprime(Lista_dupla* l);

#endif //LISTA_DUPLA_H