#include "turma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 2
#define MAX_TURMAS 2

struct aluno
{
    int mat;
    char nome[81];
    float notas[3];
    float media;
};

struct turma
{
    char id;   /*Caratere que identifica a turma, e.g. A ou B*/
    int vagas; /*Número de vagas ofertados por turma*/
    Aluno *alunos[MAX_VAGAS];
};

void cabecalho(void)
{
    printf("Bem vindo ao programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as \nfuncionalidades de matricula, lancamento de notas e listagem de \nalunos.");
    printf("\nAutor: Felipe Hidequel\tVersão: 1.0");
}

Turma *cria_turma(char id)
{
    Turma *turma = (Turma *)malloc(sizeof(Turma));
    turma->vagas = MAX_VAGAS;
    turma->id = id;
    for (int aluno = 0; aluno < MAX_VAGAS; aluno++)
    {
        turma->alunos[aluno] = NULL;
    }

    return turma;
}

void imprime_turmas(Turma **turmas, int nTurmas)
{

    for (int turma = 0; turma < nTurmas; turma++)
    {
        Turma *t = turmas[turma];
        printf("Turma %c - vagas disponiveis: %d\n", t->id, t->vagas);
    }
}

Turma *procura_turma(Turma **turma, int nTurmas, char id)
{
    // se o indice se manter com valor de menos 1, a turma buscada não existe
    int indice = -1;
    for (int t = 0; t < nTurmas; t++)
    {
        if (strcmp(id, turma[t]->id) == 0)
        {
            indice = t;
        }
    }
    if (indice == -1)
    {
        return NULL;
    }
    return turma[indice];
}

void matricula_aluno(Turma *turma, int mat, char *nome)
{
    if (turma->vagas == 0)
    {
        printf("Não há vagas disponiveis na turma %c.\n", turma->id);
        return;
    }

    Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));
    novoAluno->mat = mat;
    strcpy(novoAluno->nome, nome);
    for (int nota = 0; nota < 3; nota++)
    {
        novoAluno->notas[nota] = 0;
    }
    novoAluno->media = 0.0;

    for (int i = 0; i < MAX_TURMAS; i++)
    {
        if (turma->alunos[i] == NULL)
        {
            turma->alunos[i] = novoAluno;
            turma->vagas--;
            printf("Aluno matriculado com sucesso!");
            return;
        }
    }
}

void lanca_notas(Turma *turma)
{
    float sum = 0.0;
    int nota = 0;
    printf("Lançamento de notas para a turma %c:\n", turma->id);
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] != NULL)
        {
            printf("Matricula: %d \nAluno: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
            for (nota = 0; nota < 3; nota++)
            {
                printf("Digite a nota: %d ", nota + 1);
                scanf("%f", &turma->alunos[i]->notas[nota]);
            }
            for (nota = 0; nota < 3; nota++)
            {
                sum += turma->alunos[i]->notas[nota];
            }
            turma->alunos[i]->media = sum / 3;
        }
    }
    printf("Notas lançadas!\n");
}

void imprime_alunos(Turma *turma)
{
    int vagasFilleds = MAX_TURMAS - turma->vagas;
    for (int i = 0; i < vagasFilleds; i++)
    {
        printf("Nome: %s\tMatricula: %d\tMedia: %f\n", turma->alunos[i]->nome, turma->alunos[i]->mat, turma->alunos[i]->media);
    }
}


