/*
#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
*/

//armazena dados a cada nó
typedef struct{
    char nome[100];
    char email[150];
    char fone[15];
} contato;

//estrutura cada nó com dados e ponteiro
typedef struct { //ou typedef struct no
	contato c;
	struct no* prox; //ponteiro para próximo elemento
} no;

//estrutura pilha (repesentaada pelo seu topo)
typedef struct{
     no *topo;
} pilha;

int push(pilha *p, contato c) {
    //aloca memória
    no *novo = (no*) malloc(sizeof(no));

    //verificar se alocação ocorreu
    if (novo == NULL) {
        return 0; //falha
    } else {
        //insere/copia dados no novo nó usando srtcpy para strings
        strcpy(novo->c.nome, c.nome);
        strcpy(novo->c.email, c.email);
        strcpy(novo->c.fone, c.fone); 
    }

    //novo aponta para topo antigo
    novo->prox = p->topo;

    //topo aponta para novo
    p->topo = novo;
    return 1;
    // retorna 1 se o empilhamento deu certo; retorna 0 se o empilhamento deu errado
    // recebe como parametro um contato c, os dados dessa struct devem ser copiados para o novo elemento criado
}

int pop(pilha *p, contato *c) {
    //verifica se não está vazia
    if (empty(p)) {// (p->topo == NULL) {
        return 0; // Falha, pilha vazia
    } else {
        no *auxiliar;
        auxiliar = p->topo;
        //ou no *auxiliar = p->topo;
    
    // armazenar dado do topo no ponteiro 'c'
    strcpy(c->nome, auxiliar->c.nome);
    strcpy(c->email, auxiliar->c.email);
    strcpy(c->fone, auxiliar->c.fone);

    //topo aponta para próximo do topo
    p->topo = auxiliar->prox;

    //libera memória do topo removido
    free(auxiliar);
    return 1; // Sucesso
    }
    //retorna 1 se a remoção deu certo, retorna 0 se deu errado;
    //recebe como parametro um ponteiro para um contato c, que deve receber as informações removidas da pilha
}

int top  (pilha *p, contato *c) {
    if (empty(p)) {
        return 0;    
    } else {
        strcpy(c->nome, p->topo->c.nome);
        strcpy(c->email, p->topo->c.email);
        strcpy(c->fone, p->topo->c.fone);
        return 1;
    }
} // mesmo que o pop, mas não remove;

int tamanho(pilha *p) {
    int contador = 0;
    no *aux = p->topo;
    while(aux != NULL) {
        contador++;
        aux = aux->prox;
    }
    return contador;
}

int empty(pilha *p) { //retorna 1 se está vazia (checando se topo se topo é nulo, senão retorna 0;
    if (p->topo == NULL) {
        return 1; //vazia
    } else {
        return 0;
    }
}
void inicializar(pilha *p) {
    p->topo = NULL; //uma pilha vazia tem o topo apontado para NADA (NULL)
}// atribui nulo para o ponteiro topo da pilha

//#endif /* PILHA_H */