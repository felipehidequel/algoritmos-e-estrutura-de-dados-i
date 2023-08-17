#ifndef ALUNO_H
#define ALUNO_H
#include "disciplina.h"


typedef struct aluno Aluno;

/*Aloca dinamicamente uma estrutura do tipo Aluno e retorna seu endereço
** @param nome: Nome para o aluno
** @param matricula: Matricula do aluno
*/
Aluno *cria_aluno(char *nome, int matricula);

/*matricula o aluno em uma disciplina, adicionando o ponteiro da
 *disciplina ao array de disciplinas do aluno.
 ** @param aluno: Aluno que será matriculado
 ** @param disciplina: Disciplina que o aluno será matriculado
 */
void matricula_disciplina(Aluno *aluno, Disciplina *disciplina);

/* Libera o espaço alocado dinamicamente para a estrutura do Aluno.
** @param aluno: Estrutura que terá o espaço liberado.
*/
void exclui_aluno(Aluno *aluno);

/*Busca um aluno e retorna o seu endereço
** @param matricula: numero de matricula do aluno buscado
** @param nAlunos: quantidade de alunos matriculados
** @patam alunos: Array de estrutura Aluno
*/
int buscaAluno(int matricula, int nAlunos, Aluno **alunos);

/*Imprime os dados de todos os alunos
**@param alunos: array de estrutura Aluno
**@param nAlunos: quantidade de alunos
*/
void imprimeA(Aluno **alunos, int nAlunos);

/*Verifica se a matricula informada já está em uso, retornando -1 se for esse o caso.
** @param matriculas: vetor de inteiros contendo todas as matriculas
** @param matricula: Matricula a ser testada
** @param nAlunos: quantidade de alunos matriculados
*/
int matricula_valida(int *matriculas, int matricula, int nAlunos);


#endif // ALUNO_H