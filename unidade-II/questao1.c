#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario
{
    int id;
    char nome[21];
    float salario;
} Funcionario;

int main(void)
{
    FILE* saida;
    saida = fopen("funcionario.txt", "w");
    if (saida==NULL)
    {
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    
    Funcionario funcionario;

    printf("Informe os seguintes campos\n");
    printf("Id:");
    scanf("%d", &funcionario.id);
    printf("Nome:");
    scanf(" %[^\n]", funcionario.nome);
    printf("Salario:");
    scanf("%f", &funcionario.salario);

    fprintf(saida, "Id: %d\tNome: %s\tSalario: R$ %2.f\n", funcionario.id, funcionario.nome, funcionario.salario);

    fclose(saida);
    return 0;
}
