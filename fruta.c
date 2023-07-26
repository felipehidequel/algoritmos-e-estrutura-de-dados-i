// Você precisa criar um programa para armazenar informações sobre diferentes tipos de frutas.
// Crie uma struct chamada "Fruta" com os seguintes campos: nome (string), cor (string), sabor (string) e quantidade (int).
// Em seguida, escreva um programa que permita ao usuário cadastrar várias frutas, armazenando-as em um vetor de structs.
//  O programa deve ter as seguintes funcionalidades:
//  • Cadastrar uma nova fruta: Solicitar ao usuário que insira o nome, cor, sabor e quantidade da fruta.
// Em seguida, adicionar a fruta ao array de structs.
// • Listar todas as frutas cadastradas: Imprimir na tela todas as informações das frutas cadastradas até o momento.
//  • Buscar fruta por nome: Solicitar ao usuário que insira o nome de uma fruta. O programa deve buscar no array de 
// structs por todas as frutas com esse nome e imprimir suas informações.

#include <stdio.h>
#include <stdlib.h>

#define MAX_FRUTAS 2

typedef struct fruta{
    char nome[20];
    char cor[20];
    char sabor[20];
    int quantidade;
}Fruta;

void cadastra(Fruta *frutas){
    printf("Informe os seguintes dados: \n");
    printf("NOME: \n");
    scanf(" %[^\n]", frutas->nome);
    printf("COR: \n");
    scanf(" %[^\n]", frutas->cor);
    printf("SABOR: \n");
    scanf(" %[^\n]", frutas->sabor);
    printf("QUANTIDADE: \n");
    scanf("%d", &frutas->quantidade);

}

void listar(Fruta *frutas){
    printf("NOME: %s\n", frutas->nome);
    printf("COR: %s\n", frutas->cor);
    printf("SABOR: %s\n", frutas->sabor);
    printf("QUANTIDADE: %d\n", frutas->quantidade);
    
}

Fruta buscar(char* nome, Fruta *frutas){
    for(int i=0; i<MAX_FRUTAS; i++){
        if(nome==frutas->nome){return frutas[i];}
    }
    return (NULL);    
}

int main(void){
    int cont = 0, frutasCadastradas=0;
    char buscarNome[20];
    Fruta *frutas = (Fruta*) malloc (MAX_FRUTAS * sizeof(Fruta));
    if(frutas==NULL){exit(1);}
    Fruta *minhaFruta = (Fruta*) malloc (sizeof(Fruta));
    if(minhaFruta==NULL){exit(1);}
    cadastra(&frutas[0]);    
    listar(&frutas[0]);
    int escolha;

    while (escolha != 3)
    {
        printf("0 - Cadastrar uma nova fruta\n1 - Listar todas as frutas\n 2 - Buscar uma fruta\n3 - Sair");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:
            if (cont >= MAX_FRUTAS){
                printf("quantidade maxima de cadastro atiginda");
                break;
            }
            cadastra(&frutas[cont]);
            break;

        case 1:
            for (int i = 0; i < MAX_FRUTAS; i++)
            {
                listar(&frutas[i]);
            }            
            break;
        case 3:
            printf("Informe o nome da fruta: ");
            scanf(" %[^\n]", buscarNome);
            minhaFruta = buscar(buscarNome, frutas);
            if(minhaFruta==NULL){
                printf("Fruta não encontrada!");
            }else{
                listar(&minhaFruta);
            }
            break;    
        default:
            break;
        }        
    }
    
    

    free(frutas);
    free(minhaFruta);
    return 0;
}