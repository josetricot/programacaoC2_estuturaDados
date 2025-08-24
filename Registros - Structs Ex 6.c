/******************************************************************************

Registros - Structs Ex: 6

Reescreva os exercício 3 sem usar variáveis globais.
Você vai precisar passar o vetor como parâmetro, nos códigos que usam função;

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MEDIA 7
#define MAX_FALTAS 4

// Definição da estrutura
typedef struct {
    char nome[100];
    int matricula;
    float notas[4];
    int faltas;
} Aluno;

// Função para ler dados de UM aluno
void lerAluno(Aluno *aluno, int indice) {
    int i;
    
    printf("\n=== ALUNO %d ===\n", indice + 1);
    
    printf("Nome: ");
    gets((*aluno).nome);
    
    printf("Número de Matrícula: ");
    scanf("%d", &(*aluno).matricula);
    getchar();
    
    printf("Digite as 4 notas:\n");
    for(i = 0; i < 4; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &(*aluno).notas[i]);
    }
    
    printf("Faltas: ");
    scanf("%d", &(*aluno).faltas);
    getchar();
}

// Função para mostrar dados de UM aluno
void mostrarAluno(Aluno *aluno, int indice) {
    int i;
    
    printf("\n=== DADOS DO ALUNO %d ===\n", indice + 1);
    printf("Nome: %s\n", (*aluno).nome);
    printf("Matrícula: %d\n", (*aluno).matricula);
    printf("Notas: ");
    for(i = 0; i < 4; i++) {
        printf("%.1f ", (*aluno).notas[i]);
    }
    printf("\nFaltas: %d\n", (*aluno).faltas);
    printf("Média: %.1f\n", calcularMedia(aluno));
    printf("Situação: ");
    verificarSituacao(aluno);
    printf("============================\n");
}

// Função que retorna a média do aluno
float calcularMedia(Aluno *aluno) {
    float soma = 0;
    int i;
    
    for(i = 0; i < 4; i++) {
        soma += (*aluno).notas[i];
    }
    
    return soma / 4;
}

// Função que escreve a situação do aluno
void verificarSituacao(Aluno *aluno) {
    float media = calcularMedia(aluno);
    
    if((*aluno).faltas >= MAX_FALTAS) {
        printf("Reprovado por faltas\n");
    } else if(media < MEDIA) {
        printf("Reprovado por nota\n");
    } else {
        printf("Aprovado\n");
    }
}

int main() {
    int i;
    Aluno alunos[5]; // Array local na main
    
    printf("=== SISTEMA ACADÊMICO ===\n");
    
    // Chama a função lerAluno 5 vezes, passando o array
    for(i = 0; i < 5; i++) {
        lerAluno(&alunos[i], i);
    }
    
    printf("\n=== RELATÓRIO DOS ALUNOS ===\n");
    
    // Mostra os dados de todos os alunos
    for(i = 0; i < 5; i++) {
        mostrarAluno(&alunos[i], i);
    }
    
    return 0;
}