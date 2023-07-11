#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PESSOAS 100
#define MAX_TAMANHO_NOMES 100

#define isAlloc(v, s)                               \
    if ((v) == NULL) {                               \
        printf("Erro ao alocar memoria para " s "\n");\
        exit(1);                                       \
    }

char** allocateNomes(int num_pessoas){
    return (char**) malloc (num_pessoas * sizeof(char*));
}

int* allocateIdades(int num_pessoas){
    return (int*) malloc (num_pessoas * sizeof(int));
}

// char* allocateNome(const char* nome){
//      return strdup(nome);
// }

void freeNomes(char** nomes, int num_pessoas){
    for (int pessoa = 0; pessoa < num_pessoas; pessoa++){
        free(nomes[pessoa]);
    }
    free(nomes);
}

void freeIdades(int* idades){
    free(idades);
}

void printNomes(char** nomes, int num_pessoas){
    for (int pessoa = 0; pessoa < num_pessoas; pessoa++){
        printf("%s\n", nomes[pessoa]);
    }
}

int main(void){
    int num_pessoas;
    char** nomes;
    int* idades;

    
    printf("Informe o número de pessoas que deseja armazenar (até %d): ", MAX_PESSOAS);
    scanf("%d", &num_pessoas);

    if (num_pessoas <= 0 || num_pessoas > MAX_PESSOAS){
        printf("Número invalido de pessoas.\n");
        exit(1);
    }

    nomes = allocateNomes(num_pessoas);
    isAlloc(nomes,"nomes");

    idades = allocateIdades(num_pessoas);
    isAlloc(idades,"idades");

    // Adquirindo o nome completo e idade de cada pessoa  
    for (int pessoa = 0; pessoa < num_pessoas; pessoa++){
        char nome[MAX_TAMANHO_NOMES];

        printf("Digite o nome completo da pessoa %d: ", pessoa + 1);
        // fgets(nome, MAX_TAMANHO_NOMES, stdin);
        scanf("%s", nome);
    

        // Alocando memória para o nome e armazenando na matriz
        nomes[pessoa] = strdup(nome);
        if (nomes == NULL){
            printf("Memory allocation erro!");
            freeNomes(nomes, num_pessoas);
            freeIdades(idades);
            exit(1);
        }

        printf("Digite a idade da pessoa %d:", pessoa + 1);
        scanf("%d", &idades[pessoa]);
    }
    // Imprimindo os nomes armazenados
    printNomes(nomes, num_pessoas);

    freeNomes(nomes, num_pessoas);
    freeIdades(idades);

    return 0;
}


