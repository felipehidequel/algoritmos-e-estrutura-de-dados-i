#ifndef PONTO_H
#define PONTO_H
/*TAD: Ponto (x, y)*/

typedef struct ponto Ponto;

/*Função que inicializa um struct do tipo Ponto
**@param x: coordenada x
**@param y: coordenada y
*/
Ponto* pto_cria ( float x , float y);

/*Função que libera a memoria alocada para um Ponto
**@param p: Tipo estruturado Ponto
*/
void pto_libera (Ponto* p);

/*Inicializa variaveis x e y com os campos de um Tipo Estruturado Ponto
**@param *p: Tipo estruturado Ponto
**@param *x: variavel que recebe a coordenada X de p
**@param *y: variavel que recebe a coordenada y de p
*/
void pto_acessa(Ponto* p, float* x, float* y);

/*Inicializa ou altera os campos de um Tipo Estruturado Ponto
**@param *p: Tipo estruturado Ponto
**@param *x: Nova coordenada X
**@param *y: Nova coordenada Y
*/
void pto_atribui(Ponto* p, float x, float y);

/*Função que calcula a distancia entre 2 pontos
**@param p1: Tipo estruturado Ponto
**@param p2 Tipo estruturado Ponto
*/
float pto_distancia(Ponto* p1, Ponto* p2);

#endif //PONTO_H