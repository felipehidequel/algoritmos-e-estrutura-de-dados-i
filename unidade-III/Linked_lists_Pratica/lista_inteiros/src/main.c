#include "lista.c"

int main()
{
    Lista* lista1 = NULL;
    lista1 = lst_insere(lista1, 0);
    lista1 = lst_insere(lista1, 1);
    lista1 = lst_insere(lista1, 2);

    Lista* lista2 = NULL;
    lista2 = lst_insere(lista2, 3);
    lista2 = lst_insere(lista2, 4);
    lista2 = lst_insere(lista2, 5);

    printf("Existem %d nós maiores que %d na lista 1\n", maiores(lista1, 0), 0);
    Lista *end = ultimo(lista2);
    printf("Esse é o valor do ultimo nó da linha 2: %d\n", end->info);

    Lista *lista3 = concatena(lista1, lista2);
    printf("Lista 1\n");
    lst_imprime(lista1);

    printf("Lista 2\n");
    lst_imprime(lista2);

    printf("A lista 3 é a concatenação das duas:\n");
    lst_imprime(lista3);

    lista3 = retira_n(lista3, 2);
    printf("Foi removido um elemento da lista 3:\n");
    lst_imprime(lista3);

    return 0;
}