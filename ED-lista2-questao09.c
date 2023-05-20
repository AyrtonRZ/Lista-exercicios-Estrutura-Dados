// Função:  ordenar elementos de um vetor usando o "método BubbleSort"
// Autor: Ayrton Rodrigues e Rian Lucas
// Data: 05/20
// Descrição: O programa utiliza o algoritmo Bubble Sort para ordenar um vetor de 
//            elementos inteiros, contando o número de comparações e trocas realizadas.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int vetor[], int tamanho, int *numComparacoes, int *numTrocas) {
    int i, j;
    for (i = 0; i < tamanho-1; i++) {
        for (j = 0; j < tamanho-i-1; j++) {
            (*numComparacoes)++; 
            if (vetor[j] > vetor[j+1]) {

                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                (*numTrocas)++; 
            }
        }
    }
}

int main() {
    int tamanho;
    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int*)malloc(tamanho * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; 
    }

    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int numComparacoes = 0;
    int numTrocas = 0;

    bubbleSort(vetor, tamanho, &numComparacoes, &numTrocas);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    printf("Número de comparações (if's): %d\n", numComparacoes);
    printf("Número de trocas: %d\n", numTrocas);

    free(vetor);

    return 0;
}