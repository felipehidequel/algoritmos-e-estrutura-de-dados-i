#include "lista_dupla.h"

struct lista_dupla{
    int info;
    struct lista_dupla* ant;
    struct lista_dupla* prox;
    
};

/* inserção no inicio */
Lista_dupla* lst_insere(Lista_dupla* l, int v){
    Lista_dupla* novo = (Lista_dupla*) malloc (sizeof(Lista_dupla));
    if (novo == NULL) exit(1);
    novo->info = v;
    novo->prox = l;
    novo->ant = NULL;
    /* Verifica se lista não está vazia */
    if (l != NULL)
        l->ant = novo;
    
    return novo;    
}

Lista_dupla* lst_insere_ordenado(Lista_dupla *l, int v){
    //inserção de elementos ordenados na lista duplamente encadeada
    Lista_dupla* novo = (Lista_dupla*) malloc(sizeof(Lista_dupla));
    novo->info = v;
    Lista_dupla* ant = NULL;
    Lista_dupla* p = l;
    while(p!=NULL && p->info < v){
        ant = p;
        p = p->prox;
    }
    if(ant==NULL){
        novo->prox = l;
        novo->ant = NULL;
        l->ant = novo;
        return novo;
    }
    else{
        novo->prox = ant->prox;
        novo->ant = ant;
        ant->prox = novo;
        if(p!=NULL)
            p->ant = novo;
        return l;
    }

}

Lista_dupla* lst_busca(Lista_dupla* l, int v){
    Lista_dupla* p;
    for (p=l; p != NULL; p = p->prox)
    {
        if (p->info == v)
            return p;
    }
    return NULL;
    
}

Lista_dupla* lst_retira(Lista_dupla* l, int v){
    Lista_dupla* p = lst_busca(l, v);

  if(p->prox!=NULL)
        p->prox->ant=p->ant;
    if(l==NULL)
        return l;
    if(p==l)
        l=p->prox;
    else
        p->ant->prox = p->prox;
    return l;
}

void lst_circ_imprime(Lista_dupla* l){
    Lista_dupla* p;
    for (p=l; p!=NULL; p=p->prox)
        printf("Info = %d \n", p->info);    
}