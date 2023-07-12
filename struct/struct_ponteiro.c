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
    aluno->disciplina = (Disciplina*) malloc(2*sizeof(Disciplina));

    printf("Digite o nome: \n");
    scanf(" %[^\n]", aluno->nome);
    printf("Digite a matricula: \n");
    scanf("%d", &aluno->matricula);

    printf("Digite o nome das disciplinas: \n");
    for (int i = 0; i < 2; i++){
        scanf(" %[^\n]", aluno->disciplina[i].nome);
    }
    
    

    printf("Dados: \n");
    printf("\tNome: %s \n\tMatricula: %d \n\tDisciplinas:\n \t%s \n\t%s \n", 
    aluno->nome, aluno->matricula, aluno->disciplina[0].nome, aluno->disciplina[1].nome);

    free(aluno->disciplina);
    free(aluno);

    return 0;
}