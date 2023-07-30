/*
Você precisa criar um programa para armazenar informações sobre diferentes tipos de frutas. Crie uma struct chamada "Fruta" com os seguintes campos: nome (string), cor (string), sabor (string) e quantidade (int).
Em seguida, escreva um programa que permita ao usuário cadastrar várias frutas, armazenando-as em um vetor de structs. O programa deve ter as seguintes funcionalidades:
Cadastrar uma nova fruta: Solicitar ao usuário que insira o nome, cor, sabor e quantidade da fruta. Em seguida, adicionar a fruta ao array de structs.
Listar todas as frutas cadastradas: Imprimir na tela todas as informações das frutas cadastradas até o momento.
Buscar fruta por nome: Solicitar ao usuário que insira o nome de uma fruta. O programa deve buscar no array de structs por todas as frutas com esse nome e imprimir suas informações.
*/
#include "fruta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Fruta *cadastra(char *nome)
{
    Fruta *f = (Fruta *)malloc(sizeof(Fruta));
    if (f == NULL)
    {
        printf("Erro ao alocar memoria para f");
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

void listar(Fruta **frutas, int nFrutas)
{
    for (int fruta = 0; fruta < nFrutas; fruta++)
    {
        Fruta *f = frutas[fruta];
        printf("Nome: %s\nCor: %s\nSabor: %s\nQuantidade: %d\n\n", f->nome, f->cor, f->sabor, f->quantidade);
    }
}

Fruta *buscar(Fruta **frutas, char *nome, int nFrutas)
{
    for (int fruta = 0; fruta < nFrutas; fruta++)
    {
        if (strcmp(nome, frutas[fruta]->nome) == 0)
        {
            return frutas[fruta];
        }
    }

    return NULL;
}
