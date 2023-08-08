#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    char funcional[3];
    char nome[21];
    char departamento[2];
    float salario;
} Funcionario;

/*
Função que copia os dados de um arquivo de texto para um estrutura struct do tipo Funcionario
    @param 'fl': Ponteiro para o arquivo de onde os dados serão lidos
    @param 'n': Número de funcionarios
    @param 'pessoal': Ponteiro para um ponteiro de Funcionario
*/
void copia_dados(FILE *fl, int n, Funcionario **pessoal);

/*
Função que imprime os dados dos funcionarios filtrando por departamento
    @param 'n': Número de funcionarios
    @param 'pessoal': Ponteiro para um ponteiro de Funcionario
    @param 'depto': Filtro de busca por departamento 
*/
void imprime_folha_pagamento(int n, Funcionario **pessoal, char depto);

/*
Função que aloca memoria para array de Funcionarios
    @param 'n': Número de funcionarios
*/
Funcionario **allocFuncionario(int n);

int main()
{
    FILE *fl;
    fl = fopen("../funcionarios.txt", "r");
    if (fl == NULL)
    {
        printf("Não é possivel abrir o arquivo.\n");
        exit(1);
    }

    int n;
    fscanf(fl, "%d", &n);

    Funcionario **pessoal = allocFuncionario(n);
    copia_dados(fl, n, pessoal);

    imprime_folha_pagamento(n, pessoal, 'A');
    imprime_folha_pagamento(n, pessoal, 'B');
    imprime_folha_pagamento(n, pessoal, 'C');

    fclose(fl);
    free(pessoal);

    return 0;
}

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