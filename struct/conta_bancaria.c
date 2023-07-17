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
    float saldo;
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

    for (int usuario = 0; usuario<qtdContas; usuario++){
        printf("\t\tUsuario %d\n", usuario+1);
        preencheConta(&usuarios[usuario]);
    }

    for (int usuario = 0; usuario<qtdContas; usuario++){
        printf("\t\tUsuario %d\n", usuario+1);
        imprimeConta(&usuarios[usuario]);
    }

    return 0;
}

void preencheConta(ContaBancaria * usuario){
    printf("Informe os seguintes dados de usuario: \n");
    printf("nome: ");
    scanf(" %[^\n]", usuario->nome);
    printf("\n");

    printf("Número da conta: ");
    scanf("%d", &usuario->num_conta);
    printf("\n");

    printf("Saldo: ");
    scanf("%f", &usuario->saldo);
    printf("\n");
}
void imprimeConta(ContaBancaria * usuario){
    printf("Dados de usuario: \n");
    printf("nome: %s\n", usuario->nome);
    printf("Número da conta: %d\n", usuario->num_conta);
    printf("Saldo: %.2fR$\n", usuario->saldo);
}
