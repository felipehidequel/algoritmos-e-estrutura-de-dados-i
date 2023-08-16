#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "disciplina.h"

int main()
{
    Disciplina **disciplinas = (Disciplina **)malloc(10 * sizeof(Disciplina *));
    Aluno **alunos = (Aluno **)malloc(10 * sizeof(Aluno *));
    int nDisci = 0, nAlunos = 0;
    int escolha = 0, codigo, matricula;
    char nomeA[101], nomeD[21];
    Aluno *meuAluno;

    while (escolha != 5)
    {
        printf("\n1 - criar disciplina\n2 - cadastrar aluno\n3 - matricular aluno em disciplina\n4 - imprimir alunos\n5 - sair\n");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            if (nDisci >= 10)
            {
                printf("Limite de disciplinas registradas alcançado!");
                break;
            }
            printf("Digite o nome da disciplina: \n");
            scanf(" %[^\n]", nomeD);
            printf("Digite o código da disciplina: \n");
            scanf("%d", &codigo);
            disciplinas[nDisci] = criaDisciplina(nomeD, codigo);
            nDisci++;

            printf("Disciplina %s criada!\n", nomeD);
            break;

        case 2:
            if (nAlunos >= 10)
            {
                printf("Número limite de alunos atingido!\n");
                break;
            }
            printf("Digite o nome do aluno: \n");
            scanf(" %[^\n]", nomeA);
            printf("Digite o numero de matricula: \n");
            scanf("%d", &matricula);
            alunos[nAlunos] = cria_aluno(nomeA, matricula);
            nAlunos++;
            printf("Aluno cadastrado!\n");
            break;

        case 3:
            printf("Digite o número de matricula do aluno: \n");
            scanf("%d", &matricula);
            int aluno = buscaAluno(matricula, nAlunos, alunos);
            if (aluno == -1)
            {
                printf("Aluno não encontrado!\n");
                break;
            }

            printf("Digite o codigo da disciplina: ");
            scanf("%d", &codigo);
            int disciplina = buscarDisciplina(codigo, nDisci, disciplinas);
            if (disciplina == -1)
            {
                printf("Disciplina não encontrada\n");
                break;
            }

            matricula_disciplina(alunos[aluno], disciplinas[disciplina]);
            printf("Aluno matriculado!\n");
            break;

        case 4:
            imprimeA(alunos, nAlunos);
        default:
            break;
        }
    }

    for (int i = 0; i < nAlunos; i++)
    {
        exclui_aluno(alunos[i]);
    }
    free(alunos);

    for (int i = 0; i < nDisci; i++)
    {
        excluiDisciplina(disciplinas[i]);
    }
    free(disciplinas);

    return 0;
}