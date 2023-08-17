#include <stdio.h>
#include <stdlib.h>
#include "aluno.c"

#define MAX_ALUNOS 5

int main(){
    FILE *fp;
    Aluno **v = (Aluno**) malloc (MAX_ALUNOS * sizeof(Aluno*));
    if (v == NULL)
    {
        printf("Erro ao alocar memoria para alunos");
        exit(1);
    }

    char nome[101];
    float nota;
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        printf("Nome: ");
        scanf(" %[^\n]", nome);
        printf("Nota: ");
        scanf("%f", &nota);
        v[i] = alunoCria(nome, nota);
    }

    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        alunoImprime(v[i]);
    }

    alunoOrdena(MAX_ALUNOS, v);

    alunoSalva(fp, MAX_ALUNOS, v);

    free(v);   

    return 0;
}