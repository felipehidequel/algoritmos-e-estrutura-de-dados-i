#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct disciplina Disciplina;

/*Aloca dinamicamente na memoria espaço para uma estrutura Disciplina
** @param nome: nome da disciplina
** @param codigo: ID da turma
*/
Disciplina *criaDisciplina(char *nome, int codigo);

/*Busca uma disciplina por nome e retorna o seu indice
** @param codigo: Codigo da disciplina buscada
** @param nDisciplinas: quantidade de disciplinas registradas
** @param disciplinas: array de estrutura Disciplina
*/
int buscarDisciplina(int codigo, int nDisciplinas, Disciplina** disciplinas);

/* Libera o espaço alocado dinamicamente para a estrutura da disciplina
** @param disciplina: Estrutura a ser liberada
*/
void excluiDisciplina(Disciplina *disciplina);

#endif // DISCIPLINA