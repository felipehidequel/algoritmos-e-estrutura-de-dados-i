#include <stdio.h>
#include <stdlib.h>
// #include "aluno.h"
#include "aluno.c"
// #include "disciplina.h"



int main()
{
    Disciplina **disciplinas = (Disciplina **)malloc(10 * sizeof(Disciplina *));
    Aluno **alunos = (Aluno **)malloc(10 * sizeof(Aluno *));
    int nDisci = 0, nAlunos = 0;
    int escolha = 0, codigo, matricula;
    char nomeA[101], nomeD[21];

    int matriculas[10];
    int codigos[10];

    while (escolha != 5)
    {
        printf("\nMenu:");
        printf("\n1 - criar disciplina\n2 - cadastrar aluno\n3 - matricular aluno em disciplina\n4 - imprimir alunos\n5 - sair\n");
        printf("\nDigite a ação desejada: ");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            if (nDisci >= 10)
            {
                printf("Limite de disciplinas registradas alcançado!\n");
                break;
            }
            printf("Digite o nome da disciplina: ");
            scanf(" %[^\n]", nomeD);
            while(1){
                printf("Digite o código da disciplina: ");
                scanf("%d", &codigo);
                if(verificaCodigo(codigos, codigo, nDisci) == -1){
                    printf("O codigo informado já está em uso! Tente novamente.\n");
                }else{
                    break;
                }
            }
            disciplinas[nDisci] = criaDisciplina(nomeD, codigo);
            codigos[nDisci] = codigo;
            nDisci++;

            printf("\nDisciplina %s criada!\n", nomeD);
            break;

        case 2:
            if (nAlunos >= 10)
            {
                printf("Número limite de alunos atingido!\n");
                break;
            }
            printf("Digite o nome do aluno: ");
            scanf(" %[^\n]", nomeA);
            while(1){
                printf("Digite o numero de matricula: ");
                scanf("%d", &matricula);
                if (matricula_valida(matriculas, matricula, nAlunos) == -1)
                {
                    printf("Matricula informada já está em uso! Tente novamente.\n");
                }
                else{
                    break;
                }            
            }
            alunos[nAlunos] = cria_aluno(nomeA, matricula);
            matriculas[nAlunos] = matricula;
            nAlunos++;            
            printf("\nAluno cadastrado!\n");
            break;

        case 3:
            printf("Digite o número de matricula do aluno: ");
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
                printf("Disciplina não encontrada!\n");
                break;
            }

            // verifica se o aluno já está matriculado nessa disciplina
            /*Nesse trecho, o vetor c[10] vai receber o codigos das disciplinas que o aluno já está
            * matriculado. Com essa informação é possivel verificar se ele já está matriculado na disciplina.
            */
            int c[10];
            for (int i; i < alunos[aluno]->num_disciplinas; i++){
                c[i] = alunos[aluno]->disciplinas[i]->codigo;                
            }
            if((verificaCodigo(c, codigo, alunos[aluno]->num_disciplinas)) == -1){
                printf("O Aluno já está matriculado nessa disciplina!\n");
                break;
            }

            matricula_disciplina(alunos[aluno], disciplinas[disciplina]);
            printf("\nAluno matriculado!\n");
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