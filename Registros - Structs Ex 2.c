/******************************************************************************

Registros - Structs Ex: 2

Uma pré escola tem 5 alunos, crie uma estrutura que armazena nome, telefone de
emergencia, idade, contato de emergência;
Crie um vetor com 5 dessas estruturas
Crie uma função para ler as informações de UM aluno; chame a função 5 vezes.
Crie uma função que recebe como parâmetro o índice do aluno e escreva todos os
dados na tela de maneira organizada.
As funções acima recebem o índice do aluno como parâmetro e alteram o array
global que contém os alunos.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

// Definição da estrutura
typedef struct {
    char nome[100];
    char telefoneEmergencia[15];
    int idade;
    char contatoEmergencia[100];
} Aluno;

// Array global (conforme solicitado)
Aluno alunos[5];

// Função para ler dados de UM aluno
void lerAluno(int indice) {
    printf("\n=== ALUNO %d ===\n", indice + 1);
    
    printf("Nome: ");
    gets(alunos[indice].nome);
    
    printf("Telefone de Emergência: ");
    gets(alunos[indice].telefoneEmergencia);
    
    printf("Idade: ");
    scanf("%d", &alunos[indice].idade);
    getchar(); // Limpa o buffer do teclado após o scanf
    
    printf("Contato de Emergência: ");
    gets(alunos[indice].contatoEmergencia);
}

// Função para mostrar dados de UM aluno
void mostrarAluno(int indice) {
    printf("\n=== DADOS DO ALUNO %d ===\n", indice + 1);
    printf("Nome: %s\n", alunos[indice].nome);
    printf("Telefone de Emergência: %s\n", alunos[indice].telefoneEmergencia);
    printf("Idade: %d anos\n", alunos[indice].idade);
    printf("Contato de Emergência: %s\n", alunos[indice].contatoEmergencia);
    printf("============================\n");
}

int main() {
    int i;
    
    printf("=== CADASTRO DA PRÉ-ESCOLA ===\n");
    
    // Chama a função lerAluno 5 vezes
    for(i = 0; i < 5; i++) {
        lerAluno(i);
    }
    
    printf("\n=== EXIBINDO DADOS DOS ALUNOS ===\n");
    
    // Mostra os dados de todos os alunos
    for(i = 0; i < 5; i++) {
        mostrarAluno(i);
    }
    
    return 0;
}
