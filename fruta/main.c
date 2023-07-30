#include "fruta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    Fruta **frutas = allocFruta();
    Fruta *minhaFruta;
    char nome[21];
    int escolha = 0, nFrutas = 0;

    while (escolha != 3) // se o usuario digite 3, o programa é encerrado
    {
        printf("\nMenu:\n 0 - Cadastrar nova fruta\n 1 - Listar frutas\n 2 - Buscar fruta\n 3 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:
            printf("Cadastrando...\n");
            printf("Digite o nome da fruta: ");
            scanf(" %[^\n]", nome);
            if (nFrutas == MAX_FRUTAS)
            {
                printf("Número maximo de frutas cadastradas atingido!\n");
            }
            else if (buscar(frutas, nome, nFrutas) != NULL)
            {
                printf("Fruta já cadastrada!\n");
            }
            else
            {
                frutas[nFrutas] = cadastra(nome);
                nFrutas++;
                printf("%s cadastrada com sucesso!\n", nome);
            }
            break;
        case 1:
            if (nFrutas == 0)
            {
                printf("Nenhuma fruta cadastrada\n");
            }
            else
            {
                listar(frutas, nFrutas);
            }
            break;
        case 2:
            if (nFrutas == 0)
            {
                printf("Nenhuma fruta casdastrada");
                break;
            }

            printf("Digite o nome da fruta que deseja buscar: ");
            scanf(" %[^\n]", nome);
            minhaFruta = buscar(frutas, nome, nFrutas);
            if (minhaFruta == NULL)
            {
                printf("Fruta não encontrada");
            }
            else
            {
                printf("Nome: %s\nCor: %s\nSabor: %s\nQuantidade: %d\n", minhaFruta->nome, minhaFruta->cor, minhaFruta->sabor, minhaFruta->quantidade);
            }
            break;
        default:
            break;
        }
    }

    for (int indice = 0; indice < nFrutas; indice++)
    {
        free(frutas[indice]);
    }
    free(frutas);

    return 0;
}
