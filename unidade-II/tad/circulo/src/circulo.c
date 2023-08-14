#include <stdlib.h>
#include <stdio.h>
#include "circulo.h"

#define PI 3.14159

struct circulo{
    Ponto *p;
    float r;
};

Circulo *circ_cria(float x, float y, float r){
    Circulo *c = (Circulo *)malloc(sizeof(Circulo));
    if (c == NULL)
    {
        printf("Erro ao alocar memoria para 'c'\n");
        exit(1);
    }
    c->p = pto_cria(x, y);
    c->r = r;

    return c;
}

void circ_libera(Circulo *c){
    free(c);
}

float circ_area(Circulo *c){
    return PI * (c->r) * (c->r);
}

int circ_interior(Circulo *c, Ponto *p){
    float d = pto_distancia(c->p, p);
    return (d < c->r);
}
