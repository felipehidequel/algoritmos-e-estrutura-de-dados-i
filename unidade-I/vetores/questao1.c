/*
Questão 1) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um
novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o
produto (gostou/não gostou). Escreva um programa em C que:
a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados,
um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta
para a segunda pergunta.
b) determine a porcentagem de pessoas do sexo feminino que responderam que
gostaram do produto.
c) determine a porcentagem de pessoas do sexo masculino que responderam que não
gostaram do produto.
*/

#include <stdio.h>
#include <stdlib.h>

/*
Função que inicializa vetores do tipo char.
Input: tamanho do vetor
*/
char* inicializa_vetor_char(int tamanho);
/*
Função que contabilza o numero de mulheres que participaram da pesquisa e sua opinião 
sobre o produto.
*/
void contador_mulheres(char * sexo, char * opiniao, int * qtd_mulheres, int * mulheres_gostaram);
/*
Função que contabilza o numero de mulheres que participaram da pesquisa e sua opinião 
sobre o produto.
*/
void contador_homens(char * sexo, char * opiniao, int * qtd_homens, int * homens_nao_gostaram);
/*Função que checa se a alocação de memoria foi bem sucedida*/
void isAlloc(char* vetor){
    if (vetor == NULL){
        exit(1);
    }
}

int main(void){
    char * sexo; 
    char * opiniao;
    int num_entrevistados;
    int qtd_mulheres = 0, qtd_homens = 0;
    int mulheres_gostaram = 0, homens_nao_gostaram = 0;  

    printf("Informe o número de pessoas entrevistadas: ");
    scanf("%d", &num_entrevistados);
    
    sexo = inicializa_vetor_char(num_entrevistados);
    isAlloc(sexo);
    opiniao = inicializa_vetor_char(num_entrevistados);
    isAlloc(opiniao);


    for(int pessoa = 0; pessoa < num_entrevistados; pessoa++){
        char resposta;
        printf("Informe o seu sexo (F/M): ");
        scanf(" %c", &resposta);
        sexo[pessoa] = resposta;

        printf("Você gostou do produto? (S/N)");
        scanf(" %c", &resposta);
        opiniao[pessoa] = resposta;
       
        contador_mulheres(&sexo[pessoa], &opiniao[pessoa], &qtd_mulheres, &mulheres_gostaram);
        contador_homens(&sexo[pessoa], &opiniao[pessoa], &qtd_homens, &homens_nao_gostaram);
    }

    float porcentagem = 0.0;
    porcentagem = (mulheres_gostaram/qtd_mulheres)*100;
    printf("A quantidade de mulheres que gostaram do produto é de %2.f %% \n", porcentagem);

    porcentagem = (homens_nao_gostaram/qtd_homens)*100;
    printf("A quantidade de homens que não gostaram do produto é de %2.f %% \n", porcentagem);

    free(sexo);
    free(opiniao);
    return 0;
}      
    
char* inicializa_vetor_char(int tamanho){
    return (char *) malloc (tamanho * sizeof(char *));
}

void contador_mulheres(char * sexo, char * opiniao, int * qtd_mulheres, int * mulheres_gostaram){
    if(*sexo == 'F'){
            (*qtd_mulheres)++;
            if (*opiniao == 'S'){
                (*mulheres_gostaram)++;
        }
    }
}

void contador_homens(char * sexo, char * opiniao, int * qtd_homens, int * homens_nao_gostaram){
    if(*sexo == 'M'){
            (*qtd_homens)++;
            if (*opiniao == 'N'){
                (*homens_nao_gostaram)++;
        }
    }
}