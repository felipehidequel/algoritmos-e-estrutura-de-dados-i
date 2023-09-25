#include "pilha.h"

#define N 3

struct pilha
{
    int n; // quantidade de elementos
    float *vet;
};

Pilha *pilha_cria(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL)
        exit(1);
     // tamanho vetor;
    p->n = 0; 

    p->vet = (float *)malloc(sizeof(float)*N);
    if (p->vet == NULL)
    {
        free(p);
        exit(1);
    }
    return p;
}
void pilha_push(Pilha *p, float v)
{
    if (p->n == N)
    {
        p->vet = (float*) realloc (p->vet, sizeof(float)*(N*2));
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
    free(p->vet);
    free(p);
}
void imprime(Pilha *p)
{
    for (int i = p->n - 1; i >= 0; i--)
        printf("info: %f\n", p->vet[i]);
}