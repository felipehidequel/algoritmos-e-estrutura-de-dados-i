#include "pilha.c"

int main()
{
    Pilha *p = pilha_cria();

    pilha_push(p, 5);
    pilha_push(p, 10);
    pilha_push(p, 15);
    pilha_push(p, 20);

    // imprime(p);

    float x = pilha_pop(p);

    putchar('\n');
    imprime(p);
    pilha_libera(p);

    return 0;
}