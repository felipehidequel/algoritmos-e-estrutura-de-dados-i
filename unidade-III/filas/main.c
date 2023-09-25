#include "fila.c"

int main()
{
    int n = 20;
    Fila *q = cria_fila(n);

    insere_fila(q, 10);
    insere_fila(q, 5);
    insere_fila(q, 11);
    insere_fila(q, 14);

    imprime_fila(q);

    destruir_fila(&q);
    return 0;
}