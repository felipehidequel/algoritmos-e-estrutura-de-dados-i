#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fruta
{
    char nome[20];
    float preco;

} Fruta;


int main()
{
    FILE* fl = fopen("frutas.txt", "a"); // Abre o arquivo com "a" para inserir as novas frutas ao final do arquivo
    if (fl == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    Fruta fruta;
    
    char continuar[2];
    do
    {
        printf("Digite o nome da fruta: ");
        scanf(" %[^\n]", fruta.nome);
        printf("Digite o preço da fruta: ");
        scanf("%f", &fruta.preco);


        fprintf(fl, "%s\tR$ %2.f\n", fruta.nome, fruta.preco);

        printf("Deseja continuar? (S/n) ");
        scanf(" %c", continuar);

    } while (continuar[0] == 'S' || continuar[0] == 's');
    
    

    fclose(fl);

    return 0;
}
