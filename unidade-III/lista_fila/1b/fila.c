#include "fila.h"

Fila *cria_fila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}
void destruir_fila(Fila **Q)
{
    if (!fila_vazia(Q))
    {
        Fila *Qaux = *Q;
        lst_libera(Qaux->ini);
        free(Qaux);
        Q = NULL;
    }
}
int fila_vazia(Fila *Q)
{
    return (Q->ini == NULL);
}

int insere_fila(Fila *Q, char *str)
{
    Lista *aux = lst_cria();
    aux = lst_insere(aux, str);
    if (fila_vazia(Q))
    {
        Q->fim = Q->ini = aux;
    }
    else
    {
        Q->fim->prox = aux;
        Q->fim = aux;
    }
    return 1;
}
char* remover_fila(Fila *Q)
{
    if (fila_vazia(Q))
    {
        printf("Warning: Fila está vazia\n");
        return 0;
    }
    else
    {
        Lista *aux = Q->ini;
        Q->ini = Q->ini->prox;
        char* info = aux->info;
        free(aux);
        return info;
    }
}
int consultar_fila(Fila *Q, char *str)
{
    if (fila_vazia(Q))
    {
        printf("Warning: Fila está vazia\n");
        return 0;
    }
    else
    {
        strcpy(str,Q->ini->info);
        return 1;
    }
}
// void imprime_fila(Fila *Q);