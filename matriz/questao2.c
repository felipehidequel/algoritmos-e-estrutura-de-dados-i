#include <stdio.h>
#include <stdlib.h>

int main(void){
    int **matriz, **matrizT;
    int linhas, colunas;

    printf("Informe o numero de linhas e colunas:\n");
    scanf("%d", &linhas);
    scanf("%d", &colunas);

    // alocando memoria para matriz
    matriz = (int**) malloc (linhas * sizeof(int));
    if (matriz==NULL){exit(1);}
    for (int cont=0; cont<linhas; cont++){
        matriz[cont] = (int *) malloc(colunas*sizeof(int));
    }
    // preenchendo a matriz
    for (int linha=0; linha < linhas; linha++)
    {
        for (int coluna = 0; coluna < colunas; coluna++)
        {
            scanf("%d", &matriz[linha][coluna]);
        }        
    }
    // alocando memoria para matrizT
    matrizT = (int**) malloc (linhas * sizeof(int**));
    if (matrizT==NULL){exit(1);}
    for (int cont=0; cont<linhas; cont++){
        matrizT[cont] = (int *) malloc(colunas*sizeof(int));
    }
    // preenchendo a matrizT
    for (int linha=0; linha < linhas; linha++)
    {
        for (int coluna = 0; coluna < colunas; coluna++)
        {
            matrizT[linha][coluna] = matriz[coluna][linha];
        }        
    }

    // imprimindo as matrizes
    for (int linha=0; linha < linhas; linha++)
    {
        for (int coluna = 0; coluna < colunas; coluna++)
        {
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");        
    }

    printf("\n");

    for (int linha=0; linha < linhas; linha++)
    {
        for (int coluna = 0; coluna < colunas; coluna++)
        {
            printf("%d ", matrizT[linha][coluna]);
        }
        printf("\n");        
    }
    // liberando espaço para as matrizes
    for (int linha=0; linha < linhas; linha++)
    {
        free (matriz[linha]);
        free (matrizT[linha]);
    }

    free(matriz);
    free(matrizT);
    
    return 0;
}