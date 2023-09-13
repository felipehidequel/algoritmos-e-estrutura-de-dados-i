#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char ** frutas = (char**) malloc (4*sizeof(char*));
    int cont;
    for (cont = 0; cont < 4; cont++)
    {
        frutas[cont] = (char*) malloc (10 * sizeof(char));
        char nome[10];
        scanf(" %s", nome);
        strcpy(frutas[cont], nome);
    }
     
    for (cont = 0; cont < 4; cont++)
    {
        printf("%s\n", frutas[cont]);
    }

    return 0;
}