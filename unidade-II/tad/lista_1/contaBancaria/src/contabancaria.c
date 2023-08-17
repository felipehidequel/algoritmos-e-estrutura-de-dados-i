#include "contabancaria.h"
#include <stdio.h>
#include <stdlib.h>

struct contabancaria{
    char titular[21];
    int numero;
    double saldo;
};

ContaBancaria* criaConta(){
    ContaBancaria* conta = (ContaBancaria*) malloc (sizeof(ContaBancaria));
    if (conta == NULL)
    {
        printf("Erro ao alocar memoria para conta!\n");
        exit(1);
    }
    
    return conta;
}


void deposita(ContaBancaria *conta, double novoSaldo){
    conta->saldo += novoSaldo;
    printf("Operação de deposito realizada com sucesso!\n");
}

void saca(ContaBancaria *conta, double saque){
    double saldoAtual = conta->saldo;
    if ((saldoAtual - saque) < 0){
        printf("Saldo indisponivel!\n");
        return;
    }else{
        conta->saldo = saldoAtual - saque;
        printf("Saque realizado!\n");
    }
}

void transfere(ContaBancaria *conta1, ContaBancaria *conta2,  double transferir){
    double saldoConta1 = conta1->saldo;
    double saldoConta2 = conta2->saldo;

    if (saldoConta1 - transferir < 0){
        printf("Saldo indisponivel para realizar operação de transferencia!\n");
        return;
    }
    else{
        saldoConta1 -= transferir;
        saldoConta2 += transferir;

        conta1->saldo = saldoConta1;
        conta2->saldo = saldoConta2;

        printf("Operação realizada com sucesso!\n");
    }

}

void preencheConta(ContaBancaria * usuario){
    printf("Informe os seguintes dados de usuario: \n");
    printf("nome: ");
    scanf(" %[^\n]", usuario->titular);
    printf("\n");

    printf("Número da conta: ");
    scanf("%d", &usuario->numero);
    printf("\n");

    printf("Saldo: ");
    scanf("%lf", &usuario->saldo);
    printf("\n");
}

void imprimeConta(ContaBancaria * usuario){
    printf("\nDados de usuario: \n");
    printf("nome: %s\n", usuario->titular);
    printf("Número da conta: %d\n", usuario->numero);
    printf("Saldo: %.2fR$\n\n", usuario->saldo);
}