#include "lista.h"

struct lista_inteiros
{
    int info;
    Lista *ant;
    Lista *prox;
};

int maiores(Lista *l, int n)
{
    Lista *p;
    int qtd = 0; // quantidade de nós maiores que n

    for (p = l; p != NULL; p = p->prox)
        if (p->info > n)
            qtd++;
    return qtd;
}
Lista *ultimo(Lista *l)
{
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
        if (p->prox == NULL)
            return p;
    return l;
}
Lista *concatena(Lista *l1, Lista *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    Lista *end_l1;
    Lista *l3 = l1;

    // Conectando o ultimo nó de l1 à l2
    end_l1 = ultimo(l1);
    end_l1->prox = l2;
    l2->ant = end_l1;

    return l3;
}
Lista *retira_n(Lista *l, int n)
{
    Lista *p = lst_busca(l, n);

    if (p->prox)
        p->prox->ant = p->ant;
    if (l == NULL)
        return l;
    if (p == l)
        l = p->prox;
    else
        p->ant->prox = p->prox;
}
Lista *lst_insere(Lista *l, int n)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));

    if (novo == NULL)
        exit(1);
    novo->info = n;
    novo->prox = l; //  o novo elemento se torna o nó raiz
    novo->ant = NULL;
    /* checa se a lista não está vazia */
    if (l)
        l->ant = novo;

    return novo;
}
// Lista *lst_busca(Lista *l, int n)
// {
//     Lista *p; // Ponteiro para pecorrer l

//     for (p = l; p != NULL; p = p->prox)
//         if (p->info == n)
//             return p; // busca sequencial por n
//     return NULL;      // nó não encontrado
// }
void lst_imprime(Lista *l)
{
    Lista *p;

    for (p = l; p != NULL; p = p->prox)
        printf("Info = %d\n", p->info);
}

Lista *lst_busca(Lista *l, int n)
{
    Lista *p; // Ponteiro para pecorrer l

    for (p = l; p != NULL; p = p->prox)
        if (p->info == n)
            return p; // busca sequencial por n
    return NULL;      // nó não encontrado
}