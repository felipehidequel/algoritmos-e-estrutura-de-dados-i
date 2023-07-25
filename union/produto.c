/*
Escreva um programa que implementa uma struct Produto com os campos nome, preco e tipo. O
tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 20

typedef union tipo{
    char alimento;
    char bebida;
    char eletronico;
}Tipo;

typedef struct produto{
    char nome[MAX_CHARS];
    float preco;
    Tipo tipo;

}Produto;

// função que ler os dados de um produto
void leia(Produto * produto){
    char* tipo = (char*) malloc (sizeof(char));
    char n[MAX_CHARS];
    printf("Digite o nome do produto: \n");
    scanf(" %[^\n]", n);
    strcpy(produto->nome, n);
    printf("Digite o preço do produto: \n");
    scanf("%f", &produto->preco);
    printf("Digite o tipo do produto [Alimento (A), Bebida(B) ou Eletronico (E)]: \n");
    scanf(" %c", tipo);

    
    if(strcmp(tipo, "A") == 0){
        strcpy(&produto->tipo.alimento, tipo);
    }else if (strcmp(tipo, "B") == 0){
        strcpy(&produto->tipo.bebida, tipo);
    }else if(strcmp(tipo, "E") == 0){
        strcpy(&produto->tipo.eletronico, tipo);
    }else{
        printf("Entrada invalida!\n");
        exit(1);
    }
}

// função que imprime os dados de um produto
void imprima(Produto * produto){
    printf("\tDados\n");
    printf("Nome: %s \n", produto->nome);
    printf("Preço: %f \n", produto->preco);
    printf("Tipo: %c \n", produto->tipo);
}

int main(void){
    Produto produto;

    leia(&produto);
    imprima(&produto);

    return 0;
}


