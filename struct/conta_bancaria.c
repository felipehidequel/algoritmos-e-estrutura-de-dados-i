#include <stdio.h>
#include <stdlib.h>
// Função que cadastra contas bancarias

#define isAlloc(v, s)                               \
    if ((v) == NULL) {                               \
        printf("Erro ao alocar memoria para " s "\n");\
        exit(1);                                       \
}

/*constantes*/
#define MAX_CARACTERES 30

typedef struct contaBancaria{
    char nome[MAX_CARACTERES];
    int num_conta;
    float saldo = 0.0;
}ContaBancaria;

/*Função usada para preencher campos de uma estutura do tipo 
ContaBancaria*/
void preencheConta(ContaBancaria * usuario);
/*Função usada para imprimir os dados de uma estutura do tipo ContaBancaria*/
void imprimeConta(ContaBancaria * usuario);

int main(void){
    int qtdContas = 1;
    printf("Digite o numero de contas a serem cadastradas: \n");
    scanf("%d", &qtdContas);

    ContaBancaria * usuarios = (ContaBancaria*) malloc (qtdContas * sizeof(ContaBancaria));

    for (int usuario = 0; usuario<usuarios; usuario++){
        printf("\t\tUsuario %d\n", usuario+1);
        preencheConta(usuarios[usuario]);
    }

    return 0;
}

void preencheConta(ContaBancaria * usuario){
    printf("Informe os seguintes dados de usuario: \n");
    printf("\tnome: ");
    scanf(" %[^\n]", usuario->nome);
    printf("\n");

    printf("\tNúmero da conta: ");
    scanf("%d", &usuario->num_conta);
    printf("\n");

    printf("\tSaldo: ");
    scanf("%f", &usuario->saldo);
    printf("\n");
}
void imprimeConta(ContaBancaria * usuario){
    printf("Dados de usuario: \n");
    printf("\tnome: %s\n", usuario->nome);
    printf("\tNúmero da conta: %d\n", usuario->num_conta);
    printf("\tSaldo: %.2f\n", usuario->saldo);
}


void sacar(ContaBancaria * usuario){
    return 0;
}