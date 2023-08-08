#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[21];
    float notas[3];
} Aluno;

int main(void)
{
    int n;
    int aluno;
    printf("Informe a quantidade de alunos:");
    scanf("%d", &n);

    Aluno **alunos = (Aluno **)malloc(n * sizeof(Aluno *));
    if (alunos == NULL)
    {
        printf("Erro ao alocar memoria!");
        exit(1);
    }
    for (aluno = 0; aluno < n; aluno++)
    {
        alunos[aluno] = (Aluno *)malloc(sizeof(aluno));
    }

    printf("Informe os dados para cada aluno: \n");
    for (aluno = 0; aluno < n; aluno++)
    {
        printf("Aluno %d\n", aluno + 1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[aluno]->nome);
        printf("Nota 1: ");
        scanf("%f", &alunos[aluno]->notas[0]);
        printf("Nota 2: ");
        scanf("%f", &alunos[aluno]->notas[1]);
        printf("Nota 3: ");
        scanf("%f", &alunos[aluno]->notas[2]);
    }

    FILE *saida = fopen("notas_alunos.txt", "w");
    if (saida == NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    int i;
    for (i = 0; i < n; i++)
    {
        fprintf(saida, "Nome:\t\tNotas\n");
        fprintf(saida,"%s\t%2.f\t%2.f\t%2.f\n", alunos[i]->nome, alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2]);
    }
    

    fclose(saida);
    free(alunos);
    return 0;
}