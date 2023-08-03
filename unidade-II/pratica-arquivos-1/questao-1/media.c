/*
    Escreva um programa em C que leia de um arquivo as notas dos alunos de uma turma e escreva em
    outro arquivo o nome e a média de cada aluno, bem como a sua situação (aprovado (Média >=7))
    ou reprovado). Tanto no arquivo de entrada quanto no de saída, considere que os dados em cada
    linha estão separados por um caractere de tabulação '\t'. Para a execução do programa com o
    arquivo de entrada "entrada_q3.txt", deverá ser criado o arquivo de saída "saída_q3.txt",
    como ilustrado a seguir.
*/
#include <stdio.h>
#include <stdlib.h>

/*Exception: erro ao abrir arquivo*/
void isOpen(FILE *arquivo, const char *nome)
{
    if (arquivo == NULL)
    {
        printf("Erro ao abrir %s\n", nome);
        exit(1);
    }
}

int main(void)
{
    // declaração de variaveis
    float nota[] = {0, 0, 0};
    float media = 0.0;
    char linha[100], nome[100];
    FILE *entrada, *saida;

    // abrindo arquivos
    entrada = fopen("entrada_q3.txt", "r");
    isOpen(entrada, "entrada");
    saida = fopen("saida_q3.txt", "wt");
    isOpen(saida, "saida");

    // lendo a entrada e obtendo os dados necessarios para calcular a media de cada aluno
    while ((fgets(linha, 100, entrada)) != NULL)
    {

        sscanf(linha, "%[^\t]%f\t%f\t%f", nome, &nota[0], &nota[1], &nota[2]);
        media = (nota[0] + nota[1] + nota[2]) / 3;

        fprintf(saida, "%s\t%.1f\t%s\n", nome, media, (media >= 7.0) ? "aprovado" : "reprovado");
    }

    // fechando os arquivos
    fclose(entrada);
    fclose(saida);

    return 0;
}
