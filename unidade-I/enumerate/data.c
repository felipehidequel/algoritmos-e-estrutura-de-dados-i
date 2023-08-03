/*
Escreva um programa que implementa uma struct Data com os campos dia, mês e ano. O mês deve
ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARÇO, ABRIL, MAIO,
JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
deve ler a data e imprimir a data no formato dd/mm/aaaa.
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum mes{
    JANEIRO, FEVEREIRO, MARÇO, ABRIL, MAIO,
    JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO,
    DEZEMBRO
}Mes;

typedef struct data{
    int dia;
    Mes mes;
    int ano;
}Data;

void leia(Data *d){
    printf("Informe a data: \n");
    printf("dia: ");
    scanf("%d", &d->dia);

    printf("mês: ");
    int mes;
    scanf("%d", &mes);

    // Verifica se o mês está dentro do intervalo válido
    if (mes < 1 || mes > 12){
        printf("Mês inválido!\n");
        exit(1);
    }

    /*Convertendo o valor mes para o tipo enum Mes*/
    d->mes = mes - 1;

    printf("ano: ");
    scanf("%d", &d->ano);
}

void imprima(Data d){
    printf("%d/%d/%d\n", d.dia, d.mes+1, d.ano);
}

int main(void){

    Data d;
    leia(&d);
    imprima(d);
    
    return 0;
    }