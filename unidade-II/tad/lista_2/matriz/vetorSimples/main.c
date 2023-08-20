#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{
    int m, n;
    Matriz *mat;
    float v;

    printf("informe o tamanho da matriz\n");
    printf("Linhas: ");
    scanf("%d", &m);
    printf("Colunas: ");
    scanf("%d", &n);

    mat = matCria(m, n);

    printf("Preenchendo matriz...\n");
    for (int i = 0; i < matLinhas(mat); i++)
    {
        for (int j = 0; j < matColunas(mat); j++)
        {
            v = rand() % 100;
            matAtribui(mat, i, j, v);
        }
        
    }
    
    


    for (int i = 0; i < matLinhas(mat); i++)
    {
        for (int j = 0; j < matColunas(mat); j++)
        {
            printf("%.2f ", matAcessa(mat, i, j));
        }
        printf("\n");
    }

    matLibera(mat);

}