/******************************************************************************

Registros - Structs Ex: 2 resolução professor

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
#include <stdlib.h>

#define MAX 5

typedef struct{
	char nome[150];
	char telefone[15];
	int idade;
	char contato[150];
} aluno;

aluno vet[MAX];

void leitura(int i){
	printf("Digite o nome do aluno: ");	
	gets(vet[i].nome);
	printf("Digite a idade do aluno: ");
	scanf("%d",&vet[i].idade); getchar();
	printf("Nome do Contato de emergencia: ");
	gets(vet[i].contato);
	printf("Digite o Telefone do Contato: ");
	gets(vet[i].telefone);
}

void imprime(int i){
	printf("Nome: %s\t Idade: %d anos\n",vet[i].nome, vet[i].idade);
	printf("Contato: %s \tTelefone:%s\n",vet[i].contato, vet[i].telefone);
}

int main(int argc, char *argv[]) {
	int i,num;
	for(i=0;i<MAX;i++) leitura(i);
	
	do{
		printf("\nDigite um numero de 1 a %d:",MAX);
		scanf("%d",&num);
		imprime( num-1);
	} while(num);
	return 0;
}
