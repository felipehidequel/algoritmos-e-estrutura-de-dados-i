#include "calc.h"

struct calc
{
    char f[21]; /* Formato para impressão */
    Pilha *p;   /* pilha de operandos */
};

Calc *calc_cria(char *f)
{
    Calc *c = (Calc *)malloc(sizeof(Calc));
    if (c == NULL)
    {
        printf("Erro ao alocar memoria para calculadora!\n");
        exit(1);
    }

    strcpy(c->f, f);
    c->p = pilha_cria();
    return c;
}
void calc_operando(Calc *c, float v)
{
    pilha_push(c->p, v);
    printf(c->f, v);
}
void calc_operador(Calc *c, char op)
{
    float v1, v2, v;
    /* desempilha operandos */
    if (pilha_vazia(c->p))
        v2 = 0.0;
    else
        v2 = pilha_pop(c->p);
    if (pilha_vazia(c->p))
        v1 = 0.0;
    else
        v1 = pilha_pop(c->p);

    switch (op)
    {
    case '+':
        v = v1 + v2;
        break;
    case '-':
        v = v1 - v2;
        break;
    case '*':
        v = v1 * v2;
        break;
    case '/':
        v = v1 / v2;
        break;
    }
    pilha_push(c->p, v); // empilha resultado
    printf(c->f, v);     // imprime todo da pilha
}
void calc_libera(Calc *c)
{
    pilha_libera(c->p);
    free(c);
}
