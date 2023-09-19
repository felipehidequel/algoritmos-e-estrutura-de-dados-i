#ifndef CALC_H
#define CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.c"

typedef struct calc Calc;

Calc* calc_cria(char* f);
void calc_operando(Calc* c, float v);
void calc_operador(Calc* c, char op);
void calc_libera(Calc* c);

#endif // CALC_H 