#ifndef FRUTA_H
#define FRUTA_H

#define MAX_FRUTAS 2

/*
    Contém caractericas de uma determinada fruta.
    Campos: nome (string), cor (string), sabor (string) e quantidade (int)
*/
typedef struct fruta Fruta;

struct fruta
{
    char nome[21];
    char cor[21];
    char sabor[21];
    int quantidade;
};

/*Alocando memoria para Array structs do tipo Fruta*/
Fruta **allocFruta();

/*
    Cadastrar uma nova fruta:
    Solicitar ao usuário que insira o nome, cor, sabor e quantidade da fruta.
    Em seguida, adicionar a fruta ao array de structs.
*/
Fruta *cadastra(char *nome);
/*
    Listar todas as frutas cadastradas: Imprimir na tela todas as informações das frutas cadastradas até o momento.
*/
void listar(Fruta **frutas, int nFrutas);
/*
    Buscar fruta por nome:
    Função busca no array de structs por todas as frutas com esse nome e imprimir suas informações.
*/
Fruta *buscar(Fruta **frutas, char *nome, int nFrutas);

#endif // FRUTA_H