#include "pilha.h"

#define N 50 // numero maximo de elementos

struct pilha
{
    int n; // quantidade de elementos
    float vet[N];
};

Pilha *pilha_cria(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL)
        exit(1);
    p->n = 0; // inicializa com zero elementos
    return p;
}
void pilha_push(Pilha *p, float v)
{
    if (p->n == N)
    {
        printf("Capacidade da pilha estorou.\n");
        exit(1);
    }

    p->vet[p->n] = v;
    p->n++;
}
float pilha_pop(Pilha *p)
{
    float v;
    if (pilha_vazia(p))
    {
        printf("Pilha vazia.\n");
        exit(1);
    }
    v = p->vet[p->n - 1];
    p->n--;
    return v;
}
int pilha_vazia(Pilha *p)
{
    return (p->n == 0);
}
void pilha_libera(Pilha *p)
{
    free(p);
}
void imprime(Pilha *p){
    for (int i=p->n-1; i>=0; i--)
        printf("info: %f\n",p->vet[i]);
}