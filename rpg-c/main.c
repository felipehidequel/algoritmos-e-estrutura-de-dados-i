#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "npc.c"
#include "player.c"
#include "batalha.c"

int menu_principal()
{
    int escolha;

    printf("[1] Novo Jogo\n");
    printf("[2] Sair\n");

    printf("Entre com uma escolha: ");
    scanf("%d", &escolha);
    getchar();

    return escolha;
}

// int menu_player();

int main()
{
    int n_monsters = 5;
    NPC monstros[n_monsters];
    Player player;
    char name_player[20];
    int escolha = 0;

    do
    {
        escolha = menu_principal();
        switch (escolha)
        {
        case 1:
            printf("Digite o nome do heroi: ");
            scanf("%[^\n]", name_player);
            player = cria_player(name_player);
            print_player(&player);
            printf("\n");

            break;
        case 2:
            printf("Saindo...\n");
            exit(1);
            break;

        default:
            printf("Entrada invalida!\n");
            break;
        }
    } while (escolha != 2);

    for (int i = 0; i < n_monsters; i++)
    {
        monstros[i] = cria_monstro(i + 1);
        printf("New monster!\n");
        print_monstro(monstros[i]);
        printf("===================\n");
    }

    batalha(&player, &monstros[0]);

    return 0;
}
