#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct frutas
{
    char nome[10];
    double preco;
    struct frutas *proxima;
}Frutas;

Frutas* insere(Frutas * fruta, char * nome, double preco){
    Frutas *nova_fruta = (Frutas*) malloc (sizeof(Frutas));
    strcpy(nova_fruta->nome, nome);
    nova_fruta->proxima = fruta;
    nova_fruta->preco = preco;

    return nova_fruta;
}

int main(){
 
    Frutas *lista = NULL;

    lista = insere(lista, "maca", 0.50);
    lista = insere(lista, "abacate", 2.00);
    lista = insere(lista, "uva", 4.00);

    for (Frutas *p = lista; p != NULL ; p = p->proxima){
        printf("%s\tR$ %.2f\n", p->nome, p->preco);
    }

    free(lista);
    return 0;
}