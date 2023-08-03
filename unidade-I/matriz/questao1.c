#include <stdio.h>
#include <stdlib.h>

int main(void){

    int tamanho;
    printf("Informe o tamanho do vetor\n");
    scanf("%d", &tamanho);

    int * vetor = (int*) malloc(tamanho * sizeof(int));
    if(vetor==NULL){exit(1);}
    
    //Recebe elementos inseridos pelo user
    printf("Informe os valores para o seu vetor de tamanho %i\n", tamanho );
    for (int index = 0; index < tamanho; index++){
        scanf("%d", &vetor[index]);
    }
    //Imprime os elementos em ordem inversa
    for (int index = tamanho-1; index >= 0; index--){
        printf("%d\n", vetor[index]);
    }

    free(vetor);
    return 0;
}