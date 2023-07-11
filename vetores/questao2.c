// Questão 2) Escreva um programa para corrigir provas de múltipla escolha. Cada prova tem N
// questões e cada questão vale 10/N pontos. Os primeiros dados a serem lidos são o número de
// questões e o gabarito da prova. Em seguida, serão lidas as respectivas respostas de um total de
// 10 alunos matriculados. Calcule e mostre:
// a) a nota obtida para cada aluno;
// b) a porcentagem de aprovação, sabendo-se que a nota mínima para ser aprovado é 6

#include <stdio.h>
#include <stdlib.h>

#define ALUNOS 10
// função que inicializa vetor
char* inicializa_vetor(int tamanho){
    return (char*) malloc (tamanho *sizeof(char*));
}
// função que checa se vetor char foi alocado corretamente
void isAlloc(char* vetor){
    if(vetor==NULL){
        exit(0);
    }
}

int main(void){
    int num_questoes, num_aprovados = 0, questoes_acertadas = 0;
    float peso_notas;
    char* gabarito;

    printf("Digite o número de questões: ");
    scanf("%d", &num_questoes);
    if (num_questoes==0){
        print("Entrada invalida");
        exit(1);
    }
    peso_notas = 10/num_questoes;

    gabarito = inicializa_vetor(num_questoes);
    isAlloc(gabarito);

    // adquirindo gabarito
    char resposta;
    printf("Informe o gabarito da prova: \n");
    for (int questao = 0; questao < num_questoes; questao++){
        printf("Resposta da questão %d:", questao+1);
        scanf(" %c", &resposta);
        gabarito[questao] = resposta;
    }

    // calculando a nota de cada aluno
    float nota_aluno;
    for (int aluno = 0; aluno < ALUNOS; aluno++){
        for (int questao = 0; questao < num_questoes; questao++){
            printf("A resposta da questao %d do aluno %d: ", questao+1, aluno);
            scanf(" %c", &resposta);
            if (resposta == gabarito[questao]){
                questoes_acertadas++;
            }                        
        }
        nota_aluno = questoes_acertadas * peso_notas;
        if (nota_aluno >= 6.0){
            num_aprovados++;
        }
        printf("%d\n", num_aprovados);
        printf("A nota do aluno %d é %f\n", aluno, nota_aluno);
        questoes_acertadas = 0;
    }

    float porcentagem = (num_aprovados/(float)ALUNOS) * 100.0;
    printf("A porcertagem de aprovação da turma é de %2.f %%", porcentagem);

    free(gabarito);

    return 0;  
}