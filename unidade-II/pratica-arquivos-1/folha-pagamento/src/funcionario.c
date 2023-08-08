#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>

struct funcionario
{
    char funcional[3];
    char nome[21];
    char departamento[2];
    float salario;
};

void copia_dados(FILE *fl, int n, Funcionario **pessoal)
{
    for (int i = 0; i < n; i++)
    {
        fscanf(fl, "%s\t%s\t%s\t%f", pessoal[i]->funcional, pessoal[i]->nome, pessoal[i]->departamento, &pessoal[i]->salario);
    }
}

void imprime_folha_pagamento(int n, Funcionario **pessoal, char depto)
{
    float valorTotal = 0;
    printf("FOLHA DE PAGAMENTO DEPTO %c\n", depto);
    printf("FUNCIONAL\tNOME\tDEPTO\tSALARIO\n");
    for (int i = 0; i < n; i++)
    {
        if (depto == pessoal[i]->departamento[0])
        {
            printf("%s\t\t%s\t%s\t%.2f\n", pessoal[i]->funcional, pessoal[i]->nome, pessoal[i]->departamento, pessoal[i]->salario);
            valorTotal += pessoal[i]->salario;
        }
    }
    printf("VALOR TOTAL: R$\t%.2f\n\n", valorTotal);
}

Funcionario **allocFuncionario(int n)
{
    Funcionario **pessoal = (Funcionario **)malloc(n * sizeof(*pessoal));
    if (pessoal == NULL)
    {
        printf("Erro de alocação de memoria para pessoal");
    }
    for (int i = 0; i < n; i++)
    {
        pessoal[i] = (Funcionario *)malloc(sizeof(Funcionario));
    }

    return pessoal;
}