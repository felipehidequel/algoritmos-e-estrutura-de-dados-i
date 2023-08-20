#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct matriz Matriz;

/*Cria uma matriz de dimensão m por n*/
Matriz* matCria(int m, int n);
/*Libera a memoria alocada por matriz*/
void matLibera(Matriz* mat);
/*Acessa o elemento da linha i e da coluna j da matriz*/
float matAcessa(Matriz* mat, int i, int j);
/*Atribui o elemento da linha i e da coluna j da matriz*/
void matAtribui(Matriz* mat, int i, int j, float v);
/*Retorna o número de linhas da matriz*/
int matLinhas(Matriz* mat);
/*Retonar o número de colunas da matriz*/
int matColunas(Matriz* mat);


#endif //MATRIZ_H