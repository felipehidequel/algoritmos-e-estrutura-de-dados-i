#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _fila
{
    int ini, fim;
    int qtde;     // num de elementos da fila
    int MAX_SIZE; // tamanho maximo da fila
    int *val;     // vetor dos valores
} Fila;

Fila *cria_fila(int MAX_SIZE);
void destruir_fila(Fila **Q);
int fila_vazia(Fila *Q);

int fila_cheia(Fila *Q);
int insere_fila(Fila *Q, int elem);
int remover_fila(Fila *Q);
int consultar_fila(Fila *Q, int *elem);
void imprime_fila(Fila *Q);

#endif // FILA_H