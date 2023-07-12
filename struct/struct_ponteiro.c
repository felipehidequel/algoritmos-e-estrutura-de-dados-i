#include <stdio.h>
#include <stdlib.h>
//struct com ponteiros
typedef struct aluno {
    char nome [20];
    int matricula;
}Aluno;

int main(void){

    Aluno * aluno = (Aluno*) malloc(sizeof(Aluno));

    printf("Digite o nome: \n");
    scanf("%[^\n]", aluno->nome);
    printf("Digite a matricula: \n");
    scanf("%d", &aluno->matricula);

    return 0;
}