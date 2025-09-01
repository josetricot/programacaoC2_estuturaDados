/******************************************************************************

Alocacao Dinamica Ex 1

No exemplo de código disponível slide anterior, não é verificado se a função malloc retornou zero (ocorre quando não foi possível alocar a memória). 
Altere o exemplo para realizar esta verificação.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h> // para usar malloc e free
#include <string.h> // para manipular string
#include <stddef.h> // para offsetof

typedef struct{
    char nome[40];
    char telefone[15];
} contato;

int main(){
    contato *teste; //declaracao do ponteiro
    // esse ponteiro nao aponta para nenhum lugar especifico ainda
    //mas foi projetado para armazenar o endereco de uma estrutura do tipo contato
    teste = (contato*)malloc(sizeof(contato));
    // sizeof calcula quantos bytes ocupa a var contato
    // como var vetor, 40 + 15 = 55 bites
    // malloc pede para OS reservar na memoria os bytes
    // se conseguir devolve um ponteiro para primeiro endereco de memoria
    // malloc retorna void* um ponteiro generico, sem tipo
    // contato* = trate como ponteiro para contato, serve para compilador
    //poder acessar os campos .nome .telefone
    // teste= guarda o endereco dessa memoria em teste
    // agora teste aponta para uma área de memória que pode armazenar contato

    // antes do malloc
    // teste   --->   (não aponta para nada válido)
    // depois de malloc(sizeof(contato))
    // teste   --->   [ memória reservada: nome[40] | telefone[15] ]

    if (teste == NULL) { // verifica se a alocação foi bem-sucedida
        printf("Erro de alocação!\n");
        return 1;
    }

    printf("Digite seu nome: ");
    gets((*teste).nome); //acessa o campo nome dentro da estrutura
    // le linha e armazena em nome

    strcpy((*teste).telefone, "1234567"); //copia para telefone

    printf("Nome = %s\nTelefone = %s\n", (*teste).nome, (*teste).telefone);
    // imprime valores armazenados no campos
    // pode usar teste->nome e teste->telefone
    
    //printf("Valor alocado no heap: %d\n", *teste); //retona número estranho
    // endereço de memória ou um valor "lixo" interpretado de forma incorreta
    
    printf("Tamanho ocupado por contato: %zu bytes\n", sizeof(contato));
    //ou ainda
    printf("Tamanho ocupado por *teste: %zu bytes\n", sizeof(*teste));

    printf("Endereço da memória alocada: %p\n", (void*)teste);
    
    printf("Offset de nome: %zu\n", offsetof(contato, nome)); //nome comeca em
    printf("Offset de telefone: %zu\n", offsetof(contato, telefone)); // telefone comeaca em
    printf("sizeof(contato) = %zu\n", sizeof(contato)); //a struct termina em 
    
    free(teste);
    return 0;
}

// padding (preenchimento) eh muito importante para entender por que o compilador
// nao nao monstra sempre o exatamento o espeado quando sizeof(contato)
// os procesadores trabalham melhor com multiplos de 2 4 8 
//o compilador pode inserir padding para deixar a struct mais eficiente

// da para visualizar usando offsetof
