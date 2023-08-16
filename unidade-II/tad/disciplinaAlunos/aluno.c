#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno
{
    char nome[100];
    int matricula;
    Disciplina* disciplinas[10];
    int num_disciplinas;
};


Aluno* cria_aluno(char *nome, int matricula){
    Aluno *a = (Aluno*) malloc (sizeof(Aluno));
    if (a == NULL)
    {
        printf("Erro ao alocar memoria para Aluno");
        exit(1);
    }
    
    strcpy(nome, a->nome);
    a->matricula = matricula;
    a->num_disciplinas = 0;

    return a;
}

void matricula_disciplina(Aluno* aluno, Disciplina* disciplina){
    if (aluno->num_disciplinas >= 10)
    {
        printf("O aluno atingiu o número limite de disciplinas matriculadas!\n");
        return;
    }

    int indice = aluno->num_disciplinas;

    aluno->disciplinas[indice] = disciplina;
    aluno->num_disciplinas++;
}

int buscaAluno(int matricula, int nAlunos, Aluno **alunos){

    for (int i = 0; i < nAlunos; i++){
        if (matricula == alunos[i]->matricula)
        {
            return i;
        }        
    }

    return -1;
}

void imprimeA(Aluno **alunos, int nAlunos){
    int nDisci;
    for (int aluno = 0; aluno < nAlunos; aluno++){
        nDisci = alunos[aluno]->num_disciplinas;
        printf("Nome: %s\n", alunos[aluno]->nome);
        printf("Matricula: %d\n", alunos[aluno]->matricula);
        printf("Disciplinas Matriculado: %d\n", nDisci);
        printf("Disciplinas: \n");
        for (int i = 0; i < nDisci; i++)
        {
            printf("%s\t", alunos[aluno]->disciplinas[i]->nome);
            printf("%d\n", alunos[aluno]->disciplinas[i]->codigo);
        }
        
    }
}


void exclui_aluno(Aluno* aluno){
    free(aluno);
}
