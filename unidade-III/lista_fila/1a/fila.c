#include "fila.h"

Fila *cria_fila(int MAX_SIZE)
{
    Fila *Q = (Fila *)calloc(1, sizeof(Fila));

    Q->val = (int *)calloc(MAX_SIZE, sizeof(int));
    Q->MAX_SIZE = MAX_SIZE;
    Q->qtde = 0;
    Q->ini = Q->fim = 0;

    return Q;
}
void destruir_fila(Fila **Q)
{
    Fila *Qaux = *Q;
    free(Qaux->val);
    free(Qaux);
    *Q = NULL;
}

int fila_vazia(Fila *Q)
{
    return (Q->qtde == 0);
}

int fila_cheia(Fila *Q)
{
    return (Q->qtde == Q->MAX_SIZE);
}

int insere_fila(Fila *Q, int elem)
{
    if (fila_cheia(Q))
    {
        printf("Warning: Fila esta cheia\n");
        return 0; // falha na inserção
    }
    else
    {
        Q->val[Q->fim] = elem;
        Q->fim = (Q->fim + 1) % Q->MAX_SIZE;
        Q->qtde++;
        return 1; // sucesso na inserção
    }
}

int remover_fila(Fila *Q)
{
    if (fila_vazia(Q))
    {
        printf("Warning: Fila esta vazia\n");
        return 0; // falha na remocao
    }
    else
    {
        Q->ini = (Q->ini + 1) % Q->MAX_SIZE;
        Q->qtde--;
        return 1; // sucesso na remocao
    }
}

int consultar_fila(Fila *Q, int *elem)
{
    if (fila_vazia(Q))
    {
        printf("Warning: Fila esta vazia\n");
        return 0; // falha ao consultar fila
    }
    else
    {
        *elem = Q->val[Q->ini];
        return 1; // sucesso ao consultar fila
    }
}

void imprime_fila(Fila *Q){
    if(fila_vazia(Q)){
        printf("Warning: A fila está vazia!\n");
        return;
    }
    for(int i = 0; i<Q->qtde; i++)
        printf("%d\n",Q->val[i]);
}