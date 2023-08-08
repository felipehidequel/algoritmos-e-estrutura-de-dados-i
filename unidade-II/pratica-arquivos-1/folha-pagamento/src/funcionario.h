#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <stdio.h>

typedef struct funcionario Funcionario;

/*
Função que copia os dados de um arquivo de texto para um estrutura struct do tipo Funcionario
    @param fl: Ponteiro para o arquivo de onde os dados serão lidos
    @param n: Número de funcionarios
    @param pessoal: Ponteiro para um ponteiro de Funcionario
*/
void copia_dados(FILE *fl, int n, Funcionario **pessoal);

/*
Função que imprime os dados dos funcionarios filtrando por departamento
    @param n: Número de funcionarios
    @param pessoal: Ponteiro para um ponteiro de Funcionario
    @param depto: Filtro de busca por departamento 
*/
void imprime_folha_pagamento(int n, Funcionario **pessoal, char depto);

/*
Função que aloca memoria para array de Funcionarios
    @param n: Número de funcionarios
*/
Funcionario **allocFuncionario(int n);


#endif // FUNCIONARIO_H