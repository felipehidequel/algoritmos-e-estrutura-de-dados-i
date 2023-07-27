#include "turma.h"

#define MAX_VAGAS 2
#define MAX_TURMAS 2

struct aluno
{
    int mat;
    char nome[81];
    float notas[3];
    float media;
};

struct turma
{
    char id;   /*Caratere que identifica a turma, e.g. A ou B*/
    int vagas; /*Número de vagas ofertados por turma*/
    Aluno *alunos[MAX_VAGAS];
};

void freeTurma(Turma **turma, int nTurmas)
{
    for (int i = 0; i < nTurmas; i++)
    {
        free(turma[i]);
    }
    free(turma);
}

void cabecalho(void)
{
    printf("Bem vindo ao programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as \nfuncionalidades de matricula, lancamento de notas e listagem de \nalunos.");
    printf("\nAutor: Felipe Hidequel\tVersão: 1.0");
}

Turma *cria_turma(char id)
{
    Turma *turma = (Turma *)malloc(sizeof(Turma));
    turma->vagas = MAX_VAGAS;
    turma->id = id;
    for (int aluno = 0; aluno < MAX_VAGAS; aluno++)
    {
        turma->alunos[aluno] = NULL;
    }

    return turma;
}

void imprime_turmas(Turma **turmas, int nTurmas)
{

    for (int turma = 0; turma < nTurmas; turma++)
    {
        Turma *t = turmas[turma];
        printf("Turma %c - vagas disponiveis: %d\n", t->id, t->vagas);
    }
}

Turma *procura_turma(Turma **turma, int nTurmas, char id)
{
    // se o indice se manter com valor de menos 1, a turma buscada não existe
    int indice = -1;
    for (int t = 0; t < nTurmas; t++)
    {
        if (turma[t]->id == id)
        {
            indice = t;
        }
    }
    if (indice == -1)
    {
        return NULL;
    }
    return turma[indice];
}

void matricula_aluno(Turma *turma, int mat, char *nome)
{
    if (turma->vagas == 0)
    {
        printf("Não há vagas disponiveis na turma %c.\n", turma->id);
        return;
    }

    Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));
    novoAluno->mat = mat;
    strcpy(novoAluno->nome, nome);
    for (int nota = 0; nota < 3; nota++)
    {
        novoAluno->notas[nota] = 0;
    }
    novoAluno->media = 0.0;

    for (int i = 0; i < MAX_TURMAS; i++)
    {
        if (turma->alunos[i] == NULL)
        {
            turma->alunos[i] = novoAluno;
            turma->vagas--;
            printf("Aluno matriculado com sucesso!");
            return;
        }
    }
}

void lanca_notas(Turma* turma){
    for (int nota=0; nota < 3; nota++){
        printf("Nota %d - %f\t", nota, turma->alunos->nota[nota]);
    }
}


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
            if(buscaTurma != NULL){
                lanca_notas(buscaTurma);
            }else{
                printf("Turma inexistente!");
            }
            break;
        default:
            break;
        }
    }

    freeTurma(turma, nTurmas);

    return 0;
}
