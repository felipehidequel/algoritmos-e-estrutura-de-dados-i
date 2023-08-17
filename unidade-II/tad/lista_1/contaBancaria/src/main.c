#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"


int main(){
    ContaBancaria *conta1 = criaConta();
    ContaBancaria *conta2 = criaConta();

    preencheConta(conta1);
    preencheConta(conta2);

    imprimeConta(conta1);
    imprimeConta(conta2);

    deposita(conta1, 100.50);
    deposita(conta2, 200.00);

    imprimeConta(conta1);
    imprimeConta(conta2);

    saca(conta2, 50.00);

    transfere(conta1, conta2, 100.00);
    transfere(conta1, conta2, 10000.00);


    return 0;
}

