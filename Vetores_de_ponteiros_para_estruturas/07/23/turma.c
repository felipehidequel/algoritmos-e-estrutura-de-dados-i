/*
Escreva um programa em C que manipula dados dos alunos da disciplina de
Algoritmos e Estruturas de Dados I da UFERSA Pau dos Ferros. Seu programa deverá utilizar os
tipos estruturados e o vetor definidos a seguir:
*/

//Constantes
#include <stdio.h>
#include <stdlib.h>

#define MAX_VAGAS 2
#define MAX_TURMAS 2


typedef struct aluno{
    int mat;
    char nome[81];
    float notas[3];
    float media;
}Aluno;

typedef struct turma{
    char id; /*Caratere que identifica a turma, e.g. A ou B*/
    int vagas; /*Número de vagas ofertados por turma*/
    Aluno* alunos[MAX_VAGAS];
}Turma;


/*Implemente uma função que cria uma turma, fornecendo-lhe um identificador.
Essa função deve ser responsável por indicar que a turma não tem alunos
matriculados, atribuindo a constante NULL a cada um dos elementos do vetor de
ponteiros.*/
Turma* cria_turma(char id);
/*Implemente uma função que recebe os dados de um aluno e o matricula em uma
das turmas, caso haja vaga disponível. Inicialize suas notas com zero.
*/
void matricula_aluno(Turma* turma, int mat, char* nome);
/*Implemente uma função que lança as notas e calcula a média dos alunos de uma
determinada turma*/
void lanca_notas(Turma* turma);
/*Implemente uma função que imprime os dados de todos os alunos de uma turma*/
void imprime_alunos(Turma* turma);
/*Implemente uma função que imprime os dados de todas as turmas.*/
void imprime_turmas(Turma** turmas, int n);
/*Implemente uma função para procurar uma turma.*/
Turma* procura_turma(Turma** turmas, int  n, char id);

int main(void){
    Turma* turmas[MAX_TURMAS];

    for (int turma=0; turma<MAX_TURMAS; turma++){
        turmas[turma] = (Turma*) malloc (sizeof(Turma));
    }
    
    int escolha;
    scanf("%i", &escolha);
    switch (escolha)
    {
    case 1:
        turmas[0] = cria_turma(turmas[0]->id);
        break;
    
    default:
        break;
    }

    return 0;
}

Turma* cria_turma(char id){
    printf("Criando nova turma... \n");
    printf("Infome o nome da turma: \n");
    scanf(" %c", &id);

    printf("Turma %c criada com sucesso!\n", id);
    

    return NULL; 
}

void matricula_aluno(Turma* turma, int mat, char* nome){
    ch num_turma;
    printf("Informe a turma para matricula:");
    scanf("%d", &);

    return 0;
}


