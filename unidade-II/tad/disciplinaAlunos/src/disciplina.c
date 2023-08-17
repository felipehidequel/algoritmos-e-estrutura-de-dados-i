#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"


struct disciplina
{
    char nome[21];
    int codigo;
};

Disciplina *criaDisciplina(char *nome, int codigo){
    Disciplina *d = (Disciplina*) malloc (sizeof(Disciplina));
    if (d == NULL)
    {
        printf("Erro ao alocar memoria para disciplina!\n");
        exit(1);
    }
    
    strcpy(d->nome, nome);
    d->codigo = codigo;

    return d;
}

int buscarDisciplina(int codigo, int nDisciplinas, Disciplina** disciplinas){
    for (int i = 0; i < nDisciplinas; i++){
        if (codigo == disciplinas[i]->codigo)
        {
            return i;
        }        
    }

    return -1;
}

int verificaCodigo(int *codigos, int codigo, int nDisci){
    for (int i=0; i < nDisci; i++){
        if(codigo == codigos[i])return -1;
    }
    return 1;
}

void excluiDisciplina(Disciplina *disciplina){
    free(disciplina);
}
