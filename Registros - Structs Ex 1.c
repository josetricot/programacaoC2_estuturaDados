/******************************************************************************

Registros - Structs Ex: 1

Sua empresa o contratou para desenvolver uma agenda para uma pessoa solitária
que tem apenas o telefone da mãe e um amigo.
Esta agenda deve ter capacidade para armazenar o nome, telefone fixo, celular,
endereço e aniversário.
A agenda deve ser capaz de inserir os dados de todos os contatos
(máx 3: A mãe, o amigo e ele mesmo)
Após a inserção de todos os contatos deve perguntar ao usuário
o número do contato que ele quer visualizar, caso o número esteja fora
do intervalo (1 a 3), o programa termina, caso contrário o programa escreve
na tela os dados e pergunta novamente.
Este programa nao precisa ter funções além da principal


*******************************************************************************/
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    char telefoneFixo[15];
    char telefoneCelular[15];
    char endereco[100];
    char aniversario[11]; // formato: DD/MM/AAAA
} Contato;

int main() {
    Contato agenda[3]; // Mãe, amigo e ele mesmo
    int i, opcao;
    
    // Inserção dos dados dos 3 contatos
    printf("=== INSERÇÃO DE CONTATOS ===\n");
    
    for(i = 0; i < 3; i++) {
        printf("\nContato %d:\n", i + 1);
        
        printf("Nome: ");
        gets(agenda[i].nome);
        
        printf("Telefone Fixo: ");
        gets(agenda[i].telefoneFixo);
        
        printf("Telefone Celular: ");
        gets(agenda[i].telefoneCelular);
        
        printf("Endereço: ");
        gets(agenda[i].endereco);
        
        printf("Aniversário (DD/MM/AAAA): ");
        gets(agenda[i].aniversario);
    }
    
    // Sistema de consulta
    printf("\n=== CONSULTA DE CONTATOS ===\n");
    
    do {
        printf("\nDigite o número do contato que deseja visualizar (1-3) ou qualquer outro número para sair: ");
        scanf("%d", &opcao);
        
        if(opcao >= 1 && opcao <= 3) {
            int indice = opcao - 1;
            
            printf("\n=== DADOS DO CONTATO %d ===\n", opcao);
            printf("Nome: %s\n", agenda[indice].nome);
            printf("Telefone Fixo: %s\n", agenda[indice].telefoneFixo);
            printf("Telefone Celular: %s\n", agenda[indice].telefoneCelular);
            printf("Endereço: %s\n", agenda[indice].endereco);
            printf("Aniversário: %s\n", agenda[indice].aniversario);
        }
        
    } while(opcao >= 1 && opcao <= 3); // Continua enquanto estiver entre 1-3
    
    printf("Programa finalizado.\n");
    return 0;
}