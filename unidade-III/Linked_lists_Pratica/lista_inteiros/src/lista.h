#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct lista_inteiros Lista;

/* Retorna o número de nós que possuem o campo info com
valorees maiores que n */
int maiores(Lista *l, int n);
/* Retorna o ultimo nó de l */
Lista *ultimo(Lista *l);
/* Retorna a concatenação de l1 e l2 */
Lista *concatena(Lista *l1, Lista *l2);
/* Retira n de l */
Lista *retira_n(Lista *l, int n);
/* Insere um elemento em l */
Lista* lst_insere(Lista* l, int n);
/* Busca um elemento em l */
Lista* lst_busca(Lista* l, int n);
/* Imprime l */
void lst_imprime(Lista* l);

#endif // LISTA_H