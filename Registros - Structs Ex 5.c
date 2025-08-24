/******************************************************************************

Registros - Structs Ex: 5

Reescreva os exercício 2 sem usar variáveis globais.
Você vai precisar passar o vetor como parâmetro, nos códigos que usam função;

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

// Função para ler dados de UM aluno
void lerAluno(Aluno *aluno, int indice) {
    printf("\n=== ALUNO %d ===\n", indice + 1);
    
    printf("Nome: ");
    gets((*aluno).nome);
    
    printf("Telefone de Emergência: ");
    gets((*aluno).telefoneEmergencia);
    
    printf("Idade: ");
    scanf("%d", &(*aluno).idade);
    getchar();
    
    printf("Contato de Emergência: ");
    gets((*aluno).contatoEmergencia);
}

// Função para mostrar dados de UM aluno
void mostrarAluno(Aluno *aluno, int indice) {
    printf("\n=== DADOS DO ALUNO %d ===\n", indice + 1);
    printf("Nome: %s\n", (*aluno).nome);
    printf("Telefone de Emergência: %s\n", (*aluno).telefoneEmergencia);
    printf("Idade: %d anos\n", (*aluno).idade);
    printf("Contato de Emergência: %s\n", (*aluno).contatoEmergencia);
    printf("============================\n");
}

int main() {
    int i;
    Aluno alunos[5]; // Array local na main
    
    printf("=== CADASTRO DA PRÉ-ESCOLA ===\n");
    
    // Chama a função lerAluno 5 vezes, passando o array
    for(i = 0; i < 5; i++) {
        lerAluno(&alunos[i], i);
    }
    
    printf("\n=== EXIBINDO DADOS DOS ALUNOS ===\n");
    
    // Mostra os dados de todos os alunos
    for(i = 0; i < 5; i++) {
        mostrarAluno(&alunos[i], i);
    }
    
    return 0;
}