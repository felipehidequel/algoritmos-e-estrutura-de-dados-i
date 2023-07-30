#include "turma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char id;
    char nome[81];
    Turma **turma = (Turma **)malloc(MAX_TURMAS * sizeof(Turma *));
    if (turma == NULL)
    {
        printf("Erro ao alocar memoria para turma");
        exit(1);
    }
    Turma *buscaTurma;
    int nTurmas; // numero de turmas já cadastradas
    int escolha, matricula;
    escolha = nTurmas = matricula = 0;

    cabecalho();
    while (escolha != 6) // No caso da opção 6 ser escolhidam o programa será encerrado.
    {
        printf("\n\n\tMenu:\n1 - Criar turma\n2 - Listar turmas\n3 - Matricular aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n\nDigite sua opcao: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            printf("Criando nova turma...");
            printf("\nDigite um id: ");
            scanf(" %c", &id);
            if (nTurmas == MAX_TURMAS)
            {
                printf("Número maximo de turmas atingido!");
            }
            else if (procura_turma(turma, nTurmas, id) != NULL)
            {
                printf("A turma já existe!");
            }
            else
            {
                turma[nTurmas] = cria_turma(id);
                nTurmas++;
                printf("Turma %c criada com sucesso!", id);
            }
            break;
        case 2:
            imprime_turmas(turma, nTurmas);
            break;
        case 3:
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            buscaTurma = procura_turma(turma, nTurmas, id);
            if (buscaTurma != NULL)
            {
                printf("Digite o nome: ");
                scanf(" %[^\n]", nome);
                printf("Digite a matricula: ");
                scanf(" %d", &matricula);
                matricula_aluno(buscaTurma, matricula, nome);
            }
            else
            {
                printf("Turma inexistente");
            }
            break;
        case 4:
            printf("Lançando notas...");
            printf("\nDigite o id da turma: ");
            scanf(" %c", &id);
            buscaTurma = procura_turma(turma, nTurmas, id);
            if (buscaTurma != NULL)
            {
                lanca_notas(buscaTurma);
            }
            else
            {
                printf("Turma inexistente!");
            }
            break;
        case 5:
            printf("Informe o id da turma: ");
            scanf(" %c", &id);
            buscaTurma = procura_turma(turma, nTurmas, id);
            if (buscaTurma != NULL)
            {
                imprime_alunos(buscaTurma);
            }
            else
            {
                printf("Turma inexistente!");
            }
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < nTurmas; i++)
    {
        free(turma[i]);
    }
    free(turma);

    return 0;
}