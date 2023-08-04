#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

/*Exception: erro ao abrir arquivo*/
void isOpen(FILE *arquivo, const char *nome)
{
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo %s\n", nome);
        exit(1);
    }
}

/*retorna o menor elemento de um vetor de inteiros*/
int min(int *vetor)
{
    int minVetor = vetor[0];
    for (int indice = 0; indice < TAMANHO; indice++)
    {
        if (vetor[indice] < minVetor)
        {
            minVetor = vetor[indice];
        }
    }

    return minVetor;
}

/*retorna o maior elemento de um vetor de inteiros*/
int max(int *vetor)
{
    int maxVetor = vetor[0];
    for (int indice = 0; indice < TAMANHO; indice++)
    {
        if (vetor[indice] > maxVetor)
        {
            maxVetor = vetor[indice];
        }
    }

    return maxVetor;
}

int main(void)
{
    FILE *entrada, *saida;
    float media = 0.0;
    int vetor[TAMANHO];
    int minVetor = 0, maxVetor = 0;
    char linha[100];

    entrada = fopen("entrada_q2.txt", "r");
    isOpen(entrada, "entrada_q2.txt");
    saida = fopen("saida_q2.txt", "w");
    isOpen(saida, "saida_q2.txt");

    int contador = 0;
    while ((fgets(linha, 100, entrada)) != NULL)
    {
        sscanf(linha, "%d", &vetor[contador]);

        media += (float)vetor[contador];
        contador++;
    }

    minVetor = min(vetor);
    maxVetor = max(vetor);

    fprintf(saida, "Menor elemento: %d\nMaior elemento: %d\nMedia dos elementos: %.1f", minVetor, maxVetor, (media / (float)TAMANHO));

    fclose(entrada);
    fclose(saida);

    return 0;
}