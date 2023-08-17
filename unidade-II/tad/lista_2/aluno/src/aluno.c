#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char nome[101];
    float nota;
};

Aluno *alunoCria(char *nome, float nota){
    Aluno *a = (Aluno *)malloc(sizeof(Aluno));
    if (a == NULL)
    {
        printf("Erro ao alocar memoria para aluno");
        exit(1);
    }

    strcpy(a->nome, nome);
    a->nota = nota;

    return a;
}

void alunoLibera(Aluno *a){
    free(a);
}

void alunoImprime(Aluno *a){
    printf("%s\t%2.f\n", a->nome, a->nota);
}

int compararAluno(const void *a, const void *b){
    Aluno *aluno_a = *((Aluno**)a);
    Aluno *aluno_b = *((Aluno**)b);

    return strcmp(aluno_a->nome, aluno_b->nome);
}

void alunoOrdena(int n, Aluno **v){
    qsort(v, n, sizeof(Aluno*), compararAluno);
}

void alunoSalva(FILE *fp, int n, Aluno **v){
    fp = fopen("../out/alunos.txt", "w");

    for (int i = 0; i < n; i++){
        fprintf(fp,"%s\t%2.f\n", v[i]->nome, v[i]->nota);
    }

    fclose(fp);
}
