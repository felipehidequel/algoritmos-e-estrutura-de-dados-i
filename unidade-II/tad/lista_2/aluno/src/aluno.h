#ifndef ALUNO_H
#define ALUNO_H
#include <stdio.h>

typedef struct aluno Aluno;

/* aloca dinamicamente uma estrutura Aluno, configurando seu
** nome e nota com valores passados como parâmetros.
*/
Aluno *alunoCria(char *nome, float nota);

/*libera o espaço em memória para a estrutura do tipo Aluno*/
void alunoLibera(Aluno *a);

/*imprime na saída padrão os dados de um aluno*/
void alunoImprime(Aluno *a);

/*ordena em ordem alfabética um vetor de ponteiros para
**estruturas do tipo Aluno
** @param n: tamanho do array
** @param v: array de Aluno
*/
void alunoOrdena(int n, Aluno **v);

/*salva em um arquivo texto os dados de um vetor de ponteiros
**para estruturas do tipo Aluno;
** @param fp: arquivo de texto
** @param n: tamanho do array
** @param v: array de Aluno
*/
void alunoSalva(FILE *fp, int n, Aluno **v);

/*compara dois elementos (ponteiros para estruturas Aluno) 
**e retorna um valor que indica a relação entre esses elementos
*/
int compararAluno(const void *a, const void *b);

#endif // ALUNO_H