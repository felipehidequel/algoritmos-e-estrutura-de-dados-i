#ifndef CIRCULO_H
#define CIRCULO_H
/*TAD: Circulo*/

/*Dependencia de módulos*/
#include "ponto.h"

typedef struct circulo Circulo;

/*Cria Circulo e inicializa seus campos
**@param x: coordenada x
**@param y: coordenada y
**@param r: raio
*/
Circulo* circ_cria(float x, float y, float r);

/*Função que libera tipo estruturado Circulo
**@param c: Tipo estruturado Circulo
*/
void circ_libera(Circulo* c);

/*Função que calcula area de um Circulo
**@param c: Tipo estruturado Circulo
*/
float circ_area (Circulo* c);

/*Função que verifica se um ponto existe dentro de um Circulo
**@param c: Tipo estruturado Circulo
**@param c: Tipo estruturado Ponto
*/
int circ_interior (Circulo* c, Ponto* p);

#endif //CIRCULO_H