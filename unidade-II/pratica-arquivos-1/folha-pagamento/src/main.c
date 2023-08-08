#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fl;
    fl = fopen("../funcionarios.txt", "r");
    if (fl == NULL)
    {
        printf("Não é possivel abrir o arquivo.\n");
        exit(1);
    }

    int n;
    fscanf(fl, "%d", &n);

    Funcionario **pessoal = allocFuncionario(n);
    copia_dados(fl, n, pessoal);

    imprime_folha_pagamento(n, pessoal, 'A');
    imprime_folha_pagamento(n, pessoal, 'B');
    imprime_folha_pagamento(n, pessoal, 'C');

    fclose(fl);
    free(pessoal);

    return 0;
}

