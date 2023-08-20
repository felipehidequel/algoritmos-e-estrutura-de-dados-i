#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz
{
    int lin;
    int col;
    float *v;
};

Matriz *matCria(int m, int n)
{
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    if (mat == NULL)
    {
        printf("Memory alocation error!");
        exit(1);
    }

    mat->lin = m;
    mat->col = n;

    mat->v = (float *)malloc((m * n) * sizeof(float));
    if (mat->v == NULL)
    {
        free(mat);
        printf("Memory alocation error!");
        exit(1);
    }

    return mat;
}

void matLibera(Matriz *mat)
{
    if (mat != NULL)
    {
        free(mat->v);
        free(mat);
    }
}

float matAcessa(Matriz *mat, int i, int j)
{
    if (mat == NULL || i < 0 || i > mat->lin || j >= mat->col)
        return 0.0;

    return mat->v[i * mat->col + j];
}
void matAtribui(Matriz *mat, int i, int j, float v)
{
    if (mat == NULL || i < 0 || i > mat->lin || j >= mat->col)
        return;

    mat->v[i * mat->col + j] = v;
}
int matLinhas(Matriz *mat)
{
    if (mat == NULL)
        return 0;

    return mat->lin;
}

int matColunas(Matriz *mat)
{
    if (mat == NULL)
        return 0;

    return mat->col;
}