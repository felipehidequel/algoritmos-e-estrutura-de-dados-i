#include <stdio.h>


int main(void){

    float var = 2.5;

    // Declaração de ponteiro

    float * ponteiro;

    ponteiro = &var;

    
    // Modificar o valor da variavel atraves do ponteiro
    *ponteiro = 3.7;

    printf("Var = %.1f \nPonteiro = %p \n", var, ponteiro);

    return 0;
}