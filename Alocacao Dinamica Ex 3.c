/******************************************************************************

Alocacao Dinamica Ex 3 - Agenda

Ex3. Criar agenda:
Cada registro deve ter capacidade para armazenar o nome, telefone, celular, endereço e aniversário.
A agenda deve apresentar as opções: 
1- inserir / 2-visualizar os dados de uma posição (perguntar a posição) / 3-sair; (ficar em laço até o usuário escolher sair). 
Máximo de 100 registros. (criar vetor de 100 posições, cada posição é um ponteiro para contato).
Cada contato é criado dinamicamente ocupando as posições no vetor sequencialmente.
Não esqueça de liberar a memória no final do programa, antes de sair.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h> // para usar malloc e free
#include <string.h> // para manipular string
#include <stddef.h> // para offsetof

#define MAX 100

typedef struct{
    char nome[150];
    char telefone[15];
    char celular[15];
    char endereco[150];
    char aniversario[11];
} contato;

// Função para ler os dados do contato
void leitura(contato *a){
    printf("Digite o nome do contato: ");
    gets(a->nome);

    printf("Digite o telefone do contato: ");
    gets(a->telefone);

    printf("Digite o celular do contato: ");
    gets(a->celular);

    printf("Endereço do contato: ");
    gets(a->endereco);

    printf("Digite o aniversário (dd/mm/aaaa): ");
    gets(a->aniversario);
}

// Função para imprimir os dados do contato
void imprime(contato *a){
    printf("\nNome: %s\nTelefone: %s\nCelular: %s\nEndereço: %s\nAniversário: %s\n",
           a->nome, a->telefone, a->celular, a->endereco, a->aniversario);
}

int main() {
    contato* contatos[MAX];	// vetor com 100 ponteiros
    int escolha, posicao;
    int count = 0; // contador de contatos inseridos
    int i;

    // inicializa vetor de ponteiros com NULL
    for(i=0;i<MAX;i++) contatos[i] = 0;

    do {
        printf("\n1- Inserir\n2- Visualizar\n3- Sair\nEscolha: ");
        scanf("%d", &escolha);
        getchar(); // consome '\n' do scanf

        switch (escolha) {
            case 1:
                if(count < MAX){
                    // Alocação dinâmica de um novo contato
                    contatos[count] = (contato*) malloc(sizeof(contato)); 
                    if(contatos[count] != NULL){
                        leitura(contatos[count]);
                        count++;
                    } else {
                        printf("Erro de alocação!\n");
                    }
                } else {
                    printf("Agenda cheia!\n");
                }
                break;

            case 2:
                printf("Digite a posição (1 a %d): ", count);
                scanf("%d", &posicao);
                getchar();
                if(posicao >= 1 && posicao <= count){
                    imprime(contatos[posicao-1]);
                } else {
                    printf("Posição inválida!\n");
                }
                break;

            case 3:
                printf("Saindo...\n");
                break;

            default:
                printf("Digite apenas 1, 2 ou 3!\n");
        }

    } while(escolha != 3);

    // a - quantos bytes o vetor contatos ocupa? dica: use sizeof
    // contatos[MAX] acessa um elemento além do vetor (índice inválido).
    // O correto para medir o vetor inteiro é sizeof(contatos), porque contatos é um vetor 
    // de 100 ponteiros para contato.
    printf("a) O vetor contatos ocupa %zu bytes\n", sizeof(contatos));

    // Em máquina 32 bits → cada ponteiro ocupa 4 bytes → 100 × 4 = 400 bytes
    // Em máquina 64 bits → cada ponteiro ocupa 8 bytes → 100 × 8 = 800 bytes

    // b - quantos bytes uma variável do tipo contato ocupa?
    printf("b) Uma variável do tipo contato ocupa %zu bytes\n", sizeof(contato));

    // Esse valor deve ser teórico, mas o compilador pode arredondar (padding)

    // c - quanto de memória (em bytes) foi alocado para este programa? considere
    // apenas a função principal e a alocação dinamica

    // Então a conta é:
    // sizeof(contatos) (vetor de ponteiros na stack)
    // count × sizeof(contato) (structs no heap)
    printf("c) Total de memória alocada: %zu (vetor contatos) + %d * %zu (cada contato) = %zu bytes\n",
           sizeof(contatos), count, sizeof(contato),
           sizeof(contatos) + count * sizeof(contato));

    // libera memória alocada dinamicamente
    for(i = 0; i < count; i++){
        if(contatos[i] != 0) free(contatos[i]);
    }

    return 0;
}
