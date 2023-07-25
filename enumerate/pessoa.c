/*
Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e gênero. O
gênero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa
deve ler os dados de uma pessoa e imprimir os dados da pessoa
*/
#include <stdio.h>
#include <string.h>

// constantes para genero sexual
typedef enum gen{MASCULINO, FEMININO}genero;

typedef struct pessoa
{
    char nome[20];
    int idade;
    genero gen;
}Pessoa;

int main(void){
    Pessoa p;
    char genero[11];
    

    printf("Digite um nome: \n");
    scanf(" %[^\n]", p.nome);
    printf("Digite a idade: \n");
    scanf("%d", &p.idade);
    printf("Informe o seu genero: \n0 para Masculino\n1 para Femino\n");
    scanf("%d", &p.gen);
    if(p.gen == 0){
        strcpy(genero, "masculino");
    }else{
        strcpy(genero, "feminino");
    }
   
    printf("\nDados:\nNome: %s \nIdade: %d \nGenero: %s \n", p.nome, p.idade, genero);
    

    return 0;
}
