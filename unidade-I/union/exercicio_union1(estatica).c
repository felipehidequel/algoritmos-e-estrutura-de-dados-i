#include <stdio.h>

/*Estruturas de união representando o indice academico*/
typedef union indice_a{
    float IG, IRA, IRT;
}IA;

/*Estutura do tipo aluno*/
typedef struct aluno{
    int mat; // número de matricula
    char nome[20]; // nome
    char curso[20]; // endereço
    IA indiceA; // indice academico
}Aluno;

int main(void){
    Aluno a;
    int op;
    float ia;
    printf("Preencha os dados do aluno: \n");
    printf("Nome: \n");
    scanf(" %[^\n]", a.nome);
    printf("Matricula: \n");
    scanf(" %d", &a.mat);
    printf("Curso: \n");
    scanf(" %[^\n]", a.curso);
    printf("Digite: \n 0 - IG \n 1 - IRA \n 2 - IRT \n");
    scanf("%d", &op);
    switch (op){
        case 0:
            printf("Indice Academico (IG): \n");    
            scanf("%f", &a.indiceA.IG);
            ia = a.indiceA.IG;
            break;
        case 1:
            printf("Indice Academico (IRA): \n");    
            scanf("%f", &a.indiceA.IRA);
            ia = a.indiceA.IRA;
            break;
        case 2:
            printf("Indice Academico (IRT): \n");    
            scanf("%f", &a.indiceA.IRT);
            ia = a.indiceA.IRT;
            break;
    }
   
    printf("Nome: %s\tMatricula: %d\tCurso: %s\tIA: %2.f\n", a.nome, a.mat, a.curso, ia);

    return 0;
}