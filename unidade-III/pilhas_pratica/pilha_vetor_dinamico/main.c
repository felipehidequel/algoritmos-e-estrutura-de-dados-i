#include "pilha.c"

int main()
{
    Pilha *p = pilha_cria();
    float v = 5;
    pilha_push(p, v);
    v = 10;
    pilha_push(p, v);
    v = 15;
    pilha_push(p, v);
    v = 20;
    pilha_push(p, v);

    imprime(p);

    float x = pilha_pop(p);

    putchar('\n');
    imprime(p);
    pilha_libera(p);

    return 0;
}