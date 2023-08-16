#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
    
    strcpy(nome, d->nome);
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


void excluiDisciplina(Disciplina *disciplina){
    free(disciplina);
}
