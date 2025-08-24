/******************************************************************************

Registros - Structs Ex: 5 resolução professor 2

Reescreva os exercício 2 sem usar variáveis globais.
Você vai precisar passar o vetor como parâmetro, nos códigos que usam função;

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct{
	char nome[150];
	char telefone[15];
	int idade;
	char contato[150];
} aluno;


//void leitura(aluno vet[MAX], int i){
 void leitura (aluno *a)  {
	printf("Digite o nome do aluno: ");	
	gets((*a).nome);
	printf("Digite a idade do aluno: ");
	scanf("%d",&(*a).idade); getchar();
	printf("Nome do Contato de emergencia: ");
	gets((*a).contato);
	printf("Digite o Telefone do Contato: ");
	gets((*a).telefone);
}

void imprime(aluno a){
	printf("Nome: %s\t Idade: %d anos\n",a.nome, a.idade);
	printf("Contato: %s \tTelefone:%s\n",a.contato, a.telefone);
}

int main(int argc, char *argv[]) {
	int i,num;
    aluno alunos[MAX];
	for(i=0;i<MAX;i++) leitura(&alunos[i]);
	do{
		printf("\nDigite um numero de 1 a %d:",MAX);
		scanf("%d",&num);
		imprime( alunos[num-1]);
	} while(num);
	return 0;
}