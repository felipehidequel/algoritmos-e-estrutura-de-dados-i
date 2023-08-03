/*  
    Questão 4: Crie um programa para calcular a área e o perímetro de um hexágono. O seu
    programa deve implementar uma função chamada calcula_hexagono que calcula a área e o
    perímetro de um hexágono regular de lado l. A função deve obedecer ao seguinte protótipo:
    void calcula_hexagono(float l, float *area, float *perimetro);

    File: calcula_hexagono.c
    Purpose: Calculate the area and perimeter of a hexagon

    Input: l
    Output: Area and perimeter of a hexagon

    Compile: gcc -g -Wall -o calcula_hexagono calcula_hexagono.c -lm
    Usage: ./calcula_hexagono
*/

#include <stdio.h>
#include <math.h>

/*
    Função que calcula a área e o perímetro de um hexágono regular de lado l.
    float l : lado
    float *area : área do hexagono
    float *perimetro: périmetro do hexagono
*/
void calcula_hexagono(float l, float *area, float *perimetro);

int main(void)
{

    float l;
    float area, perimetro;

    l = area = perimetro = 0.0;

    printf("Entre com l\n");
    scanf("%f", &l);

    calcula_hexagono(l, &area, &perimetro);
    printf("A área do hexagono é: %f\n", area);    
    printf("O perímetro do hexagono é: %f\n", perimetro);    

    return 0;
}

void calcula_hexagono(float l, float *area, float *perimetro)
{

    *area = (3 * pow(l, 3) * sqrt(3)) / 2; // Cálculo da area
    *perimetro = 6 * l;                    // Cálculo do périmetro    
}
