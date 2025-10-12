#include <stdio.h>
#include <stdlib.h> //necessário para o malloc e free
#include "fila.h""

void inicializar(tFila *f) {
    f->head = NULL;
    f->tail = NULL;
    f->size = 0;
}

int vazia(tFila *f) {
    //retorna 1 (verdadeiro) se a fila estiver vazia, e 0 (falso) caso contrário.
    return (f->head == NULL);
}

int inserir(tFila *f, int d) {
    //alocar novo nó
    tipoNo *novo = (tipoNo*) malloc(sizeof(tipoNo));
    if (novo == NULL) {
        return 0; //erro: falha na alocação de memória
    }

    novo->dado = d; //atribui o dado ao novo nó
    novo->prox = NULL; //o próximo do novo nó é sempre NULL, pois ele é o último
    novo->ant = f->tail; //o anterior do novo nó aponta para quem ERA o último

    //verifica se a fila estava vazia
    if (vazia(f)) {
        f->head = novo; //se vazia, a cabeça também é o novo nó
    } else {
        f->tail->prox = novo; //se não, o próximo do antigo último aponta para o novo
    }

    //final da fila (tail) agora é o novo nó
    f->tail = novo;

    //incrementar o tamanho
    f->size++;

    return 1; // Sucesso
}

void imprimeFila(tFila *f) {
    tipoNo *aux = f->head;
    printf("Fila: [ ");
    while(aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}

int remover(tFila *f, int *d) {
    //verifica se a fila está vazia
    if (vazia(f)) {
        return 0; //erro: não se pode remover de uma fila vazia
    }

    //guarda um ponteiro para o nó que será removido (o primeiro)
    tipoNo *aux = f->head;

    //copia o dado do nó a ser removido para a variável de retorno
    *d = aux->dado;

    //verifica se era o único elemento na fila
    if (f->head == f->tail) {
        f->head = NULL;
        f->tail = NULL;
    } else {
        //se não era o único, a cabeça avança para o próximo
        f->head = f->head->prox;
        //e o anterior da nova cabeça se torna nulo
        f->head->ant = NULL;
    }

    //decrementa o tamanho
    f->size--;
    //libera a memória do nó que foi removido
    free(aux);

    return 1; //sucesso
}

int tamanho(tFila *f) {
    //apenas retorna o valor do contador 'size' da fila.
    return f->size;
}