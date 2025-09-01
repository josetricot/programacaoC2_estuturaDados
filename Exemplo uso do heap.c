#include <stdio.h>
#include <stdlib.h> // Para usar malloc e free

int main() {
    // Declara um ponteiro para um inteiro
    int *ptr;

    // Aloca memória no heap para um único inteiro
    // sizeof(int) retorna o tamanho de um inteiro em bytes
    ptr = (int*) malloc(sizeof(int)); 

    // Verifica se a alocação foi bem-sucedida
    if (ptr == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1; // Retorna com erro
    }

    // Atribui um valor à memória alocada
    *ptr = 100;

    printf("Valor alocado no heap: %d\n", *ptr);

    // Libera a memória alocada no heap
    free(ptr);
    ptr = NULL; // Boa prática para evitar ponteiros "pendurados" (dangling pointers)

    return 0;
}