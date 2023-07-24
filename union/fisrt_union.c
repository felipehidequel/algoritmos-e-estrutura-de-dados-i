#include <stdio.h>

union documentos{
    int cpf;
    int RG;
    int CNH;
};

typedef union tipo{
    int inteiro;
    float real;
}Tipo;

typedef union documentos Docs;

int main(void){
    Docs documento;
    Tipo t;

    // printf("Digite o CPF: ");
    // scanf("%d", &documento.cpf);
    // printf("\nDigite o RG: ");
    // scanf("%d", &documento.RG);
    // printf("\nDigite o CNH: ");
    // scanf("%d", &documento.CNH);

    // printf("\n Documento: %d\n", documento.cpf);
    // printf("\n Documento: %d\n", documento.RG);
    // printf("\n Documento: %d\n", documento.CNH);

    // t.inteiro = 10;
    // t.real = 5.0;
    // printf("%d\n", t.inteiro);
    // printf("%f\n", t.real);


    return 0;
}
