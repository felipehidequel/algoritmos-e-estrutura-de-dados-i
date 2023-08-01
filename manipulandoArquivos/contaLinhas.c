#include <stdio.h>
#include <stdlib.h>

int main(void){
    int c;
    int nLinhas = 1;
    FILE *fp;

    fp = fopen("entrada.txt", "rt");
    if(fp==NULL){
        printf("Não foi possivel abrir o arquivo txt");
        return 1;
    }

    while((c = fgetc(fp)) != EOF){
        printf("%c", &c);
        if(c == '\n')
            nLinhas++;
    }
    /* Fecha o arquivo*/
    fclose(fp);

    printf("\nNumero de linhas = %d\n", nLinhas);
    return 0;
}