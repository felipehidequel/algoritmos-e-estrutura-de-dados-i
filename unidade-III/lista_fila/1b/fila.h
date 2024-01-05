#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <lista.h>

typedef struct _fila
{
    Lista *ini, *fim;
} Fila;

Fila *cria_fila();
void destruir_fila(Fila **Q);
int fila_vazia(Fila *Q);

int fila_cheia(Fila *Q);
int insere_fila(Fila *Q, char *str);
int remover_fila(Fila *Q);
int consultar_fila(Fila *Q, char *str);
// void imprime_fila(Fila *Q);

#endif // FILA_H