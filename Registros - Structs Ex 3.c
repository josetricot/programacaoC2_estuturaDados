/******************************************************************************

Registros - Structs Ex: 3

Crie uma estrutura que armazene o nome de um aluno, número de matrícula, 4 notas
e faltas.
Crie um vetor para armazenar 5 alunos.
Crie uma função para ler os dados de um aluno.
Crie uma função para  na tela os dados de um aluno
Crie uma função que retorne a média do aluno
Crie uma função que escreva a situação do aluno 
#define MEDIA 7
#define FALTAS 4
if(nota<MEDIA) printf("Reprovado");
if(faltas<FALTAS && nota>MEDIA)
 printf("Aprovado");
As funções acima recebem o índice do aluno como parâmetro e alteram o array
global que contém os alunos.

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

// Array global
Aluno alunos[5];

// Função para ler dados de UM aluno
void lerAluno(int indice) {
    int i;
    
    printf("\n=== ALUNO %d ===\n", indice + 1);
    
    printf("Nome: ");
    gets(alunos[indice].nome);
    
    printf("Número de Matrícula: ");
    scanf("%d", &alunos[indice].matricula);
    
    printf("Digite as 4 notas:\n");
    for(i = 0; i < 4; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &alunos[indice].notas[i]);
    }
    
    printf("Faltas: ");
    scanf("%d", &alunos[indice].faltas);
    getchar(); // Limpa o buffer do teclado
}

// Função para mostrar dados de UM aluno
void mostrarAluno(int indice) {
    int i;
    
    printf("\n=== DADOS DO ALUNO %d ===\n", indice + 1);
    printf("Nome: %s\n", alunos[indice].nome);
    printf("Matrícula: %d\n", alunos[indice].matricula);
    printf("Notas: ");
    for(i = 0; i < 4; i++) {
        printf("%.1f ", alunos[indice].notas[i]);
    }
    printf("\nFaltas: %d\n", alunos[indice].faltas);
    printf("Média: %.1f\n", calcularMedia(indice));
    printf("Situação: ");
    verificarSituacao(indice);
    printf("============================\n");
}

// Função que retorna a média do aluno
float calcularMedia(int indice) {
    float soma = 0;
    int i;
    
    for(i = 0; i < 4; i++) {
        soma += alunos[indice].notas[i];
    }
    
    return soma / 4;
}

// Função que escreve a situação do aluno
void verificarSituacao(int indice) {
    float media = calcularMedia(indice);
    
    if(alunos[indice].faltas >= MAX_FALTAS) {
        printf("Reprovado por faltas\n");
    } else if(media < MEDIA) {
        printf("Reprovado por nota\n");
    } else {
        printf("Aprovado\n");
    }
}

int main() {
    int i;
    
    printf("=== SISTEMA ACADÊMICO ===\n");
    
    // Chama a função lerAluno 5 vezes
    for(i = 0; i < 5; i++) {
        lerAluno(i);
    }
    
    printf("\n=== RELATÓRIO DOS ALUNOS ===\n");
    
    // Mostra os dados de todos os alunos
    for(i = 0; i < 5; i++) {
        mostrarAluno(i);
    }
    
    return 0;
}