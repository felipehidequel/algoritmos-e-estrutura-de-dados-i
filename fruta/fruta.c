/*
Você precisa criar um programa para armazenar informações sobre diferentes tipos de frutas. Crie uma struct chamada "Fruta" com os seguintes campos: nome (string), cor (string), sabor (string) e quantidade (int).
Em seguida, escreva um programa que permita ao usuário cadastrar várias frutas, armazenando-as em um vetor de structs. O programa deve ter as seguintes funcionalidades:
Cadastrar uma nova fruta: Solicitar ao usuário que insira o nome, cor, sabor e quantidade da fruta. Em seguida, adicionar a fruta ao array de structs.
Listar todas as frutas cadastradas: Imprimir na tela todas as informações das frutas cadastradas até o momento.
Buscar fruta por nome: Solicitar ao usuário que insira o nome de uma fruta. O programa deve buscar no array de structs por todas as frutas com esse nome e imprimir suas informações.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FRUTAS 2

typedef struct fruta Fruta;

/*Alocando memoria para Array structs do tipo Fruta*/
Fruta **allocFruta()
{
    Fruta **f = (Fruta **)malloc(MAX_FRUTAS * sizeof(Fruta *));
    if (f == NULL)
    {
        printf("Erro ao alocar memoria para frutas");
        exit(1);
    }
    return f;
}

/*
    Cadastrar uma nova fruta:
    Solicitar ao usuário que insira o nome, cor, sabor e quantidade da fruta.
    Em seguida, adicionar a fruta ao array de structs.
*/
Fruta *cadastra(char *nome);
/*
    Listar todas as frutas cadastradas: Imprimir na tela todas as informações das frutas cadastradas até o momento.
*/
void listar(Fruta *frutas, int nFrutas);
/*
    Buscar fruta por nome: 
    Função busca no array de structs por todas as frutas com esse nome e imprimir suas informações.
*/
Fruta* buscar(char* nome, int nFrutas);


int main(void)
{
    Fruta **frutas = allocFruta();
    char nome[21];
    int escolha=0, nFrutas = 0;

    while (escolha != 3)//se o usuario digite 3, o programa é encerrado
    {
        printf("Menu:\n 0 - Cadastrar nova fruta\n 1 - Listar frutas\n 2 - Buscar fruta\n 3 - Sair\n");
        scanf("%d" ,&escolha);

        switch (escolha)
        {
        case 0:
            printf("Cadastrando...\n");
            printf("Digite o nome da fruta: ");
            scanf(" %[^\n]", nome);
            if (nFrutas == MAX_FRUTAS)
            {
                printf("Número maximo de frutas cadastradas atingido!");
            }
            else{
                frutas[nFrutas] = cadastra(nome);
                nFrutas++;
            }
            
            break;
        
        default:
            break;
        }
    }
    

    return 0;
}

/*
    Contém caractericas de uma determinada fruta.
    Campos: nome (string), cor (string), sabor (string) e quantidade (int)
*/
struct fruta
{
    char nome[21];
    char cor[21];
    char sabor[21];
    int quantidade;
};

Fruta* cadastra(char *nome)
{
    Fruta* f = (Fruta*) malloc (sizeof(Fruta));
     if (f == NULL)
    {
        printf("Erro ao alocar memoria para frutas");
        exit(1);
    }
    strcpy(f->nome, nome);
    
    printf("Digite a cor da fruta: ");
    scanf(" %[^\n]", f->cor);
    printf("Digite a sabor da fruta: ");
    scanf(" %[^\n]", f->sabor);
    printf("Digite a quantidade: ");
    scanf("%d", &f->quantidade);

    return f;
}
