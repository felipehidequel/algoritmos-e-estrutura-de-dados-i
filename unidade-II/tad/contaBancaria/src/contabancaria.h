#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

typedef struct contabancaria ContaBancaria;

/*Aloca na memoria um tipo estruturado do tipo ContaBancaria*/
ContaBancaria* criaConta();

/*Atualiza o saldo de uma conta
** @param *conta: endereço de uma estrutura do tipo ContaBancaria
** @param novoSaldo: Valor atualizado do saldo
*/
void deposita(ContaBancaria *conta, double novoSaldo);

/*Realiza o saque de uma conta, verifica se é possivel realizar o saque
** @param *conta: endereço de uma estrutura do tipo ContaBancaria
** @param saque: valor que atualiza o saldo
*/
void saca(ContaBancaria *conta, double saque);

/* Transfere um valor de uma conta para a outra e verifica se o saldo é suficiente para a ação
** @param *conta1: endereço de conta bancaria de onde será realizada a transferencia
** @param *conta2: endereço de conta bancaria que recebe a transferencia
** @param transferir: saldo passado
*/
void transfere(ContaBancaria *conta1, ContaBancaria *conta2,  double transferir);

/*Função usada para preencher campos de uma estutura do tipo ContaBancaria
** @param *usuario: conta que vai ter os dados preenchidos
*/
void preencheConta(ContaBancaria * usuario);

/*Função usada para imprimir os dados de uma estutura do tipo ContaBancaria
** @param *usuario: endereço de conta bancaria
*/
void imprimeConta(ContaBancaria * usuario);

#endif // CONTABANCARIA_H