/******************************************************************************

Registros - Structs Ex: 5 resolução professor

Reescreva os exercício 2 sem usar variáveis globais.
Você vai precisar passar o vetor como parâmetro, nos códigos que usam função;

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

void leitura(aluno vet[], int i){
	printf("Digite o nome do aluno: ");	
	gets(vet[i].nome);
	printf("Digite a idade do aluno: ");
	scanf("%d",&vet[i].idade); getchar();
	printf("Nome do Contato de emergencia: ");
	gets(vet[i].contato);
	printf("Digite o Telefone do Contato: ");
	gets(vet[i].telefone);
}
void imprime(aluno vet[], int i){
	printf("Nome: %s\t Idade: %d anos\n",vet[i].nome,vet[i].idade);
	printf("Contato: %s \tTelefone:%s\n",vet[i].contato,vet[i].telefone);
}

int main(int argc, char *argv[]) {
	aluno alunos[MAX];	
	int i,num;
	
	for(i=0;i<MAX;i++) leitura(alunos, i);
	
	do{
		printf("\nDigite um numero de 1 a %d:",MAX);
		scanf("%d",&num);
		imprime(alunos, num-1);
	} while(num);
	return 0;
}