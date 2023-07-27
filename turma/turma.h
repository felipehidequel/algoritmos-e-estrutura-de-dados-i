#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct turma Turma;
typedef struct aluno Aluno;



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
void imprime_turmas(Turma** turmas, int nTurmas);
/*Implemente uma função para procurar uma turma.*/
Turma* procura_turma(Turma** turmas, int  nTurmas, char id);