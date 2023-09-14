#include "lista_dupla.c"

int main(){

    Lista_dupla* lista = NULL;
    lista = lst_insere(lista, 1);
    lista = lst_insere(lista, 2);
    lista = lst_insere(lista, 3);
    lista = lst_insere(lista, 4);

    printf("Elementos da lista:\n");
    lst_circ_imprime(lista);

    if (lst_busca(lista, 2) != NULL) printf ("Elemento encontrado!\n");
    else printf ("Elemento não encontrado\n");

    int item_remover = 2;
    lst_retira(lista, item_remover);

    printf("Elementos da lista após remoção de %d:\n", item_remover);
    lst_circ_imprime(lista);

    printf("Inserção ordenada\n");
    lista = lst_insere_ordenado(lista, 1);
    lista = lst_insere_ordenado(lista, 2);
    lista = lst_insere_ordenado(lista, 0);
    lst_circ_imprime(lista);

    return 0;
}