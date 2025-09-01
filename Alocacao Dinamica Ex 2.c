/******************************************************************************

Alocacao Dinamica Ex 2

Ex2. Com base no código disponível no Moodle, responda:
a -  quantos bytes o vetor alunos ocupa? dica: use sizeof
b - quantos bytes uma variável do tipo aluno ocupa?
c - quanto de memória (em bytes) foi alocado para este programa?

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct{
	char nome[150];char telefone[15];int idade;char contato[150];
} aluno;

void leitura(aluno *a){
	printf("Digite o nome do aluno: ");	gets((*a).nome);
	printf("Digite a idade do aluno: ");scanf("%d",&(*a).idade); getchar();
	printf("Nome do Contato de emergencia: ");gets((*a).contato);
	printf("Digite o Telefone do Contato: ");gets(a->telefone);
}
void imprime(aluno a){
	printf("Nome: %s\t Idade: %d anos\n",a.nome,a.idade);
	printf("Contato: %s \tTelefone:%s\n",a.contato,a.telefone);
}

int main(int argc, char *argv[]) {
	aluno* alunos[MAX];	
	int i,num;
	
	for(i=0;i<MAX;i++)alunos[i]=0;
	
	for(i=0;i<MAX;i++) {
		alunos[i]=(aluno*)malloc(sizeof(aluno));
		if(alunos[i]!=0)
			leitura(alunos[i]);
	}
	do{
		printf("Digite um numero de 1 a %d:",MAX);
		scanf("%d",&num);
		imprime(*alunos[num-1]);
	} while(num);
	
	for(i=0;i<MAX;i++){
		if(alunos[i]!=0) free(alunos[i]);
	}
	
	return 0;
}
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h> // para usar malloc e free
#include <string.h> // para manipular string
#include <stddef.h> // para offsetof

#define MAX 5
typedef struct{
	char nome[150];char telefone[15];int idade;char contato[150];
} aluno;

void leitura(aluno *a){
	printf("Digite o nome do aluno: ");	gets((*a).nome);
	printf("Digite a idade do aluno: ");scanf("%d",&(*a).idade); getchar();
	printf("Nome do Contato de emergencia: ");gets((*a).contato);
	printf("Digite o Telefone do Contato: ");gets(a->telefone);
}
void imprime(aluno a){
	printf("Nome: %s\t Idade: %d anos\n",a.nome,a.idade);
	printf("Contato: %s \tTelefone:%s\n",a.contato,a.telefone);
}

int main(int argc, char *argv[]) {
	aluno* alunos[MAX];	//vetor com 5 ponteiros
	int i,num;
	
	for(i=0;i<MAX;i++)alunos[i]=0;
	
	for(i=0;i<MAX;i++) {
		alunos[i]=(aluno*)malloc(sizeof(aluno)); //é alocado dinamicamente são 5 estruturas aluno via malloc
		if(alunos[i]!=0)
			leitura(alunos[i]);
	}
	
// a - quantos bytes o vetor alunos ocupa? dica: use sizeof
// alunos[MAX] acessa um elemento além do vetor (índice inválido).
// O correto para medir o vetor inteiro é sizeof(alunos), porque alunos é um vetor 
//de 5 ponteiros para aluno.
printf("a) O vetor alunos ocupa %zu bytes\n", sizeof(alunos));

// Em máquina 32 bits → cada ponteiro ocupa 4 bytes → 5 × 4 = 20 bytes
// Em máquina 64 bits → cada ponteiro ocupa 8 bytes → 5 × 8 = 40 bytes

// b - quantos bytes uma variável do tipo aluno ocupa?
printf("b) Uma variável do tipo aluno ocupa %zu bytes\n", sizeof(aluno));

// Esse valor deve ser 150 + 15 + 4 + 150 = 319 bytes teóricos, mas o compilador 
//provavelmente arredonda (padding) para 320 ou até 324.

// c - quanto de memória (em bytes) foi alocado para este programa? considere
//apenas a função principal e a alocação dinamica

//Então a conta é:
//sizeof(alunos) (vetor de ponteiros na stack)
//5 × sizeof(aluno) (structs no heap)
printf("c) Total de memória alocada: %zu (vetor alunos) + %d * %zu (cada aluno) = %zu bytes\n",
       sizeof(alunos), MAX, sizeof(aluno),
       sizeof(alunos) + MAX * sizeof(aluno));
       
//Exemplo típico (em 64 bits, supondo sizeof(aluno) = 320):
//sizeof(alunos) = 40 bytes
//5 × 320 = 1600 bytes
	
	do{
		printf("Digite um numero de 1 a %d:",MAX);
		scanf("%d",&num);
		imprime(*alunos[num-1]);
	} while(num);
	
	for(i=0;i<MAX;i++){
		if(alunos[i]!=0) free(alunos[i]);
	}
	
	return 0;
}
