#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

struct matriz
{
    int lin;
    int col;
    float **v;
};

Matriz *matCria(int m, int n)
{
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    if (mat == NULL)
    {
        exit(1);
    }

    mat->lin = m;
    mat->col = n;

    mat->v = (float **)malloc((m) * sizeof(float *));
    if (mat->v == NULL)
    {
        free(mat);
        exit(1);
    }

    for (int i = 0; i < m; i++)
    {
        mat->v[i] = (float *)malloc(n * sizeof(float));
        if (mat->v[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(mat->v[i]);
            free(mat->v);
            free(mat);
        }
    }

    return mat;
}

void matLibera(Matriz *mat)
{
    if (mat != NULL)
    {
        for (int i = 0; i < mat->lin; i++)
            free(mat->v[i]);
        free(mat->v);
        free(mat);
    }
}

float matAcessa(Matriz *mat, int i, int j)
{
    if (mat == NULL || i < 0 || i > mat->lin || j >= mat->col)
        return 0.0;

    return mat->v[i][j];
}

void matAtribui(Matriz *mat, int i, int j, float v)
{
    if (mat == NULL || i < 0 || i > mat->lin || j >= mat->col)
        return;

    mat->v[i][j] = v;
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