#include <stdio.h>
#include <stdlib.h>

int main(){
    // FILE* arquivo = fopen("entrada.txt", "wt");
    // if(arquivo==NULL)
    // {
    //     printf("Não foi possivel acessar o arquivo\n");
    //     exit(1);
    // }

    // if(!fclose(arquivo))
    // {
    //     printf("Arquivo fechado com sucesso!\n");
    // };

    FILE *fp;
    char str[100];
    int c;


    // lendo o arquivo e formantando como string
    fp = fopen("nome.txt", "r");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    fscanf(fp, "%s", str); // Lê uma string formatada do arquivo fp e arma:    
    printf("%s\n", str); // imprime a string lida
    fclose(fp);

    c = fgetc(fp); // Lê um caractere do arquivo
    printf("%c\n", c);
    fclose(fp);

    return 0;
}