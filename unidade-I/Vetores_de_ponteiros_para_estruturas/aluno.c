//Estrutura aluno
#include <stdio.h>
#include <stdlib.h>

//constantes
#define MAX 10

/*Estutura do tipo aluno*/
typedef struct aluno{
    int mat; // número de matricula
    char nome[81]; // nome
    char end[121]; // endereço
    char tel[21]; // telefone
}Aluno;

/*Função que inicializa vetor do tipo Aluno com o valor NULL*/
void incializa(int n, Aluno** tab);
/*Função que aloca espaço pra cada indice de um vetor do tipo Aluno
e preenche os seus campos com informações do usuario.*/
void preenche (int n, Aluno** tab, int i);
/*Função que retira dados de aluno de um vetor do tipo Aluno*/
void retira (int n, Aluno ** tab, int i);
/*Função que imprime os campos de um Aluno*/
void imprime(int n, Aluno ** tab, int i);
/*Função que imprime os campos de cada indice de um vetor do tipo Aluno*/
void imprime_tudo(int n, Aluno** tab);

int main(void){
    Aluno* tab[MAX];
    // inicializa vetor
    incializa(MAX, tab);
    // preenchendo campos de vetor no indice 0, 1 e 2
    preenche(MAX, tab, 0);
    preenche(MAX, tab, 1);
    preenche(MAX, tab, 2);
    // imprime os vetores preenchidos para o usuario
    imprime_tudo(MAX, tab);
    // liberando campos preenchidos
    retira(MAX, tab, 0);
    retira(MAX, tab, 1);
    retira(MAX, tab, 2);

    return 0;
}

void incializa(int n, Aluno** tab){
    for (int i = 0; i<n; i++){
        tab[i] = NULL;
    }
}

void preenche (int n, Aluno** tab, int i){
    if (i<0 || i>= n){
        printf("Indice fora do limite do vetor.\n");
        exit(1); //Aborta o programa
    }

    if (tab[i] == NULL){
        tab[i] = (Aluno*) malloc (sizeof(Aluno));
    }

    printf("Entre com a matricula: ");
    scanf("%d", &tab[i]->mat);
    printf("Entre com o nome: ");
    scanf(" %80[^\n]", tab[i]->nome);
    printf("Entre com o endereço: ");
    scanf(" %120[^\n]", tab[i]->end);
    printf("Entre com o telefone: ");
    scanf(" %20[^\n]", tab[i]->tel);
}

void retira (int n, Aluno ** tab, int i){
    if (i<0 || i>= n){
        printf("Indice fora do limite do vetor.\n");
        exit(1); // aborta o programa
    }

    if (tab[i] != NULL){
        free(tab[i]);
        tab[i] = NULL; // indica que na posição nao existe mais dado
    }
}

void imprime(int n, Aluno ** tab, int i){
    if (i < 0 || i >= n){
        printf("indice fora do limite do vetor.\n");
        exit(1); // aborta o programa
    }

    if (tab[i] != NULL){
        printf("Matricula: %d\n", tab[i]->mat);
        printf("Nome: %s\n", tab[i]->nome);
        printf("Endereço: %s\n", tab[i]->end);
        printf("Telefone: %s\n", tab[i]->tel);
    }
}

void imprime_tudo(int n, Aluno** tab){
    int i;
    for (i=0; i<MAX; i++){
        imprime(MAX,tab,i);
    }
}