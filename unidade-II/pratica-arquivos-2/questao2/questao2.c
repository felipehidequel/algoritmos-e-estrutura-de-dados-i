#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    char nome[21];
    float notas[3];
} Aluno;

int main(void)
{
    int nAlunos;
    printf("Informe a quantidade de alunos: ");
    scanf("%d", &nAlunos);

    Aluno alunos[nAlunos];

    printf("Informe os dados para cada aluno: \n");
    for (int aluno = 0; aluno < nAlunos; aluno++)
    {
        printf("Aluno %d\n", aluno + 1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[aluno].nome);

        for (int nota = 0; nota < 3; nota++)
        {
            while (1)
            {
                printf("Nota %d: ", nota + 1);
                scanf("%f", &alunos[aluno].notas[nota]);
                if (!(alunos[aluno].notas[nota] >= 0 && alunos[aluno].notas[nota] <= 10))
                {
                    printf("As notas devem estar no intervalo de 0 a 10!\n");
                }
                else
                {
                    break;
                }
            }
        }
    }

    FILE *saida = fopen("notas_alunos.txt", "w");
    if (saida == NULL)
    {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }

    fprintf(saida, "Nome:\t\tNotas\n");
    for (int i = 0; i < nAlunos; i++)
    {
        fprintf(saida, "%s\t%2.f\t%2.f\t%2.f\n", alunos[i].nome, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2]);
    }

    fclose(saida);

    printf("Informações gravadas em notas_alunos.txt\n");

    return 0;
}