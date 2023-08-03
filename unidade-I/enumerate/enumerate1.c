#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0 

/*
Enumeração (Enum):

enum bool{
    false;
    true;
};

*/

enum boolean{false,true};

int main(void){
    enum boolean val;
    printf("Digite 0 ou 1: ");
    scanf("%d", &val);

    if (val == true){
        printf("Verdadeiro\n");
    }else{
        printf("Falso\n");
    }
}