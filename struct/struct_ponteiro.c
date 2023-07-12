#include <stdio.h>
#include <stdlib.h>
//struct com ponteiros

#define isAlloc(v, s)                               \
    if ((v) == NULL) {                               \
        printf("Erro ao alocar memoria para " s "\n");\
        exit(1);                                       \
}

typedef struct disciplina{
    char nome[30];
    float nota;
}Disciplina;

typedef struct aluno {
    char nome [20];
    int matricula;
    Disciplina* disciplina;
}Aluno;


int main(void){

    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));
    isAlloc(aluno, "aluno");
    aluno->disciplina = (Disciplina*) malloc(sizeof(Disciplina));

    printf("Digite o nome: \n");
    scanf(" %[^\n]", aluno->nome);
    printf("Digite a matricula: \n");
    scanf("%d", &aluno->matricula);
    printf("Digite o nome da disciplina: \n");
    scanf(" %[^\n]", aluno->disciplina->nome);

    printf("Dados: \n");
    printf("\tNome: %s \n\tMatricula: %d \n\tDisciplina: %s \n", 
    aluno->nome, aluno->matricula, aluno->disciplina->nome);

    free(aluno->disciplina);
    free(aluno);

    return 0;
}