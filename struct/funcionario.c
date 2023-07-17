// 1. Crie um tipo estruturado para armazenar dados de um funcionário. Uma estrutura deste tipo possui
// os seguintes campos: nome, salário, identificador e cargo.
// a) Escreva uma função que receba como parâmetro o endereçoo de uma estrutura do tipo Funcionario
// e preencha seus campos com valores fornecidos pelo usuário via teclado.
// b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
// e imprima os valores dos seus campos.
// c) Implemente uma função para realizar uma alteração no salário de uma estrutura do tipo Funcionario.
// d) Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Funcionario e
// imprima o cargo e salário do Funcionario com maior salário e o cargo e salário do funcionário
// com o menor salário.
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARACTERES 20

#define isAlloc(v, s)                               \
    if ((v) == NULL) {                               \
        printf("Erro ao alocar memoria para " s "\n");\
        exit(1);                                       \
}

typedef struct funcionario{
    char nome[MAX_CARACTERES];
    float salario;
    int identificador;
    char cargo[MAX_CARACTERES];
}Funcionario;

/*Função que recebe como parametro o endereço de uma estrutura do tipo funcionario e 
preenche os seus campos com valores fornecidos pelo usuario.*/
void preencheFuncionario(Funcionario * funcionario);

/*Função que recebe como parametro o endereço de uma estrutura do tipo funcionario
e imprime os seus campos na tela.*/
void imprimeFuncionario(Funcionario * funcionario);

/*Função que realiza alteração no sálario de uma estrutura do tipo Funcionario*/
void alteraSalario(Funcionario * funcionario);

/*Função que pecorre veotr do tipo Funcionario e imprime o funcionario com menor salario e
o funcionario com maior salario, e seus respectivos salarios*/
void maior_menor_salario(Funcionario *funcionarios, int qtd_funcionarios);
// Utilities
void cortaLinha();

int main(void){    
    Funcionario * funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    isAlloc(funcionario,"funcionario");

    preencheFuncionario(funcionario);
    imprimeFuncionario(funcionario);
    alteraSalario(funcionario);
    
    int num_funcionarios = 2;
    Funcionario * funcionarios = (Funcionario*) malloc(num_funcionarios*sizeof(Funcionario));
    isAlloc(funcionarios, "funcionarios");

    for (int i = 0; i < num_funcionarios; i++){
        preencheFuncionario(&funcionarios[i]);
    }
    maior_menor_salario(funcionarios, num_funcionarios);


    free(funcionario);
    free(funcionarios);
    return 0;
}

void cortaLinha(){
    for (int i = 0; i<21; i++){
        printf("=");
    }
    printf("\n");
}

void preencheFuncionario(Funcionario * funcionario){  
    cortaLinha();
    printf("Digite o nome: \n");
    scanf(" %[^\n]", funcionario->nome);

    printf("informe o seu salario: \n");
    scanf("%f", &funcionario->salario);

    printf("Informe o identificador para o funcionario: \n");
    scanf("%d", &funcionario->identificador);

    printf("Informe o cargo do funcionario: \n");
    scanf(" %[^\n]", funcionario->cargo);
}

void imprimeFuncionario(Funcionario * funcionario){
    cortaLinha();
    printf("\tDados\n");
    cortaLinha();    
    printf("Nome: %s\n", funcionario->nome);
    printf("Salario: %2.fR$\n", funcionario->salario);
    printf("Identificador: %d\n", funcionario->identificador);      
    printf("Cargo: %s\n", funcionario->cargo);
    cortaLinha();  
}

void alteraSalario(Funcionario * funcionario){
    float novo_salario, salario_antigo;

    salario_antigo = funcionario->salario;

    printf("Digite o novo salário para o funcionario %s: \n", funcionario->nome);
    scanf("%f", &funcionario->salario);
    novo_salario = funcionario->salario;

    cortaLinha();
    if (novo_salario > salario_antigo){
        printf("O salário do funcionario subiu de %.2fR$ para %.2fR$\n", 
        salario_antigo, novo_salario);
    }
    else if(novo_salario < salario_antigo){
        printf("O salário do funcionario diminuiu de %.2fR$ para %2.fR$\n",
        salario_antigo, novo_salario);
    }
    cortaLinha();
}

// d) Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Funcionario e
// imprima o cargo e salário do Funcionario com maior salário e o cargo e salário do funcionário
// com o menor salário.

void maior_menor_salario(Funcionario *funcionarios, int qtd_funcionarios){
    float menor_salario = funcionarios[0].salario;
    float maior_salario = funcionarios[0].salario;
    int maior_indice = 0;
    int menor_indice = 0;


    for (int funcionario = 1; funcionario < qtd_funcionarios; funcionario++){

        if(funcionarios[funcionario].salario < menor_salario){
            menor_salario = funcionarios[funcionario].salario;
            menor_indice = funcionario;
        }

        if(funcionarios[funcionario].salario > maior_salario){
            maior_salario = funcionarios[funcionario].salario;
            maior_indice = funcionario;
        }
    }

    cortaLinha();
    printf("\tFuncionario com menor salario\n");
    cortaLinha();
    printf("Cargo: %s\n", funcionarios[menor_indice].cargo);
    printf("Salario: %.2f\n", funcionarios[menor_indice].salario);
    cortaLinha();

    cortaLinha();
    printf("\tFuncionario com maior salario\n");
    cortaLinha();
    printf("Cargo: %s\n", funcionarios[maior_indice].cargo);
    printf("Salario: %.2f\n", funcionarios[maior_indice].salario);
    cortaLinha();
    
}