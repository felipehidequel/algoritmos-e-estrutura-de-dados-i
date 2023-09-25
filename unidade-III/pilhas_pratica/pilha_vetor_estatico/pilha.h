#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
/*Cria uma pilha vazia*/
Pilha* pilha_cria(void);
/*Empurra v para o topo da pilha p*/
void pilha_push(Pilha* p, float v);
/*Remove o elemento do topo da pilha p*/
float pilha_pop(Pilha *p);
/*Verifica se a pilha está vazia*/
int pilha_vazia(Pilha *p);
/*Libera memoria alocada para pilha p*/
void pilha_libera(Pilha* p);

#endif // PILHA_H