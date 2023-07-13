// 2. Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui os
// seguintes campos: nome da pessoa, numero do documento e idade.
// a) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Pessoa e
// preencha seus campos com valores fornecidos pelo usu´ario via teclado.
// b) Escreva uma fun¸c˜ao que receba como parˆametro o endere¸co de uma estrutura do tipo Pessoa e
// imprima os valores dos seus campos.
// c) Implemente uma fun¸c˜ao para realizar uma atualiza¸c˜ao da idade de uma estrutura do tipo Pessoa.
// d) Escreva uma fun¸c˜ao que receba como parˆametro um vetor de estruturas do tipo Pessoa e imprima
// o nome da Pessoa mais velha e mais nova

#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
    char nome[30];
    int id;
    int idade;
}Pessoa;

// Função para cortar linha
void cortaLinha();
/*
Função usada pra preencher campos de estrutura do tipo Pessoa
Input: Pessoa * pessoa
*/
void preenchePessoa(Pessoa * pessoa);
/*
Função usada para imprimir camopos de estrutura do tipo Pessoa
Input: Pessoa * pessoa
*/
void imprimePessoa(Pessoa * pessoa);
/*
Função que altera o campo idade de estrutura do tipo Pessoa
*/
void alteraIdade(Pessoa * pessoa);
/*
Função que recebe como argumento um vetor do tipo Pessoa e retorna a instancia
com maior idade e menor idade
Input: Pessoa *Pessoas (tem que ser um vetor), qtd_de_pessoas (numero de indices do vetor)
*/
void maior_menor_idade(Pessoa *pessoas, int qtd_pessoas);

int main(void){
    int qtd_pessoas = 2;
    Pessoa* pessoas = (Pessoa*) malloc (qtd_pessoas*sizeof(Pessoa));
    
    for (int pessoa=0; pessoa < qtd_pessoas; pessoa++){
        preenchePessoa(&pessoas[pessoa]);
        imprimePessoa(&pessoas[pessoa]);
    }

    alteraIdade(&pessoas[0]);
    maior_menor_idade(pessoas, qtd_pessoas);

    return 0;
}


void cortaLinha(){
    for (int i = 0; i<21; i++){
        printf("=");
    }
    printf("\n");
}

void preenchePessoa(Pessoa * pessoa){  
    cortaLinha();
    printf("Digite o nome: \n");
    scanf(" %[^\n]", pessoa->nome);

    printf("Informe o numero do documento: \n");
    scanf("%d", &pessoa->id);

    printf("Informe a idade: \n");
    scanf("%d", &pessoa->idade);
}

void imprimePessoa(Pessoa * pessoa){
    cortaLinha();
    printf("\tDados\n");
    cortaLinha();    
    printf("Nome: %s\n", pessoa->nome);
    printf("Documento: %d\n", pessoa->id);
    printf("Idade: %d\n", pessoa->idade);      
    cortaLinha();  
}

void alteraIdade(Pessoa * pessoa){     
    printf("Digite a nova idade para %s: \n", pessoa->nome);
    scanf("%d", &pessoa->idade);
}

void maior_menor_idade(Pessoa *pessoas, int qtd_pessoas){
    float mais_nova = pessoas[0].idade;
    float mais_velha = pessoas[0].idade;
    int maior_indice = 0;
    int menor_indice = 0;


    for (int pessoa = 1; pessoa < qtd_pessoas; pessoa++){

        if(pessoas[pessoa].idade < mais_nova){
            mais_nova = pessoas[pessoa].idade;
            menor_indice = pessoa;
        }

        if(pessoas[pessoa].idade > mais_velha){
            mais_velha = pessoas[pessoa].idade;
            maior_indice = pessoa;
        }
    }

    cortaLinha();
    printf("\tPessoa mais nova\n");
    cortaLinha();
    printf("Nome: %s\n", pessoas[menor_indice].nome);    
    cortaLinha();

    cortaLinha();
    printf("\tPessoa mais velha\n");
    cortaLinha();
    printf("Nome: %s\n", pessoas[maior_indice].nome);    
    cortaLinha();
    
}