/*
   Função: 
   Autor: 
   Data: 
   Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char sigla[4];
    char cidade[51];
    char pais[31];
    float taxa;
    int capacidade;
} Aeroporto;

void lerAeroporto(Aeroporto *aeroporto) {
    printf("Digite a sigla do aeroporto: ");
    scanf("%s", aeroporto->sigla);
    printf("Digite a cidade do aeroporto: ");
    scanf(" %[^\n]", aeroporto->cidade);
    printf("Digite o país do aeroporto: ");
    scanf(" %[^\n]", aeroporto->pais);
    printf("Digite a taxa do aeroporto: ");
    scanf("%f", &aeroporto->taxa);
    printf("Digite a capacidade do aeroporto: ");
    scanf("%d", &aeroporto->capacidade);
}

void escreverAeroporto(const Aeroporto *aeroporto) {
    printf("Sigla: %s\n", aeroporto->sigla);
    printf("Cidade: %s\n", aeroporto->cidade);
    printf("País: %s\n", aeroporto->pais);
    printf("Taxa: %.2f\n", aeroporto->taxa);
    printf("Capacidade: %d\n", aeroporto->capacidade);
}

void excluirAeroporto(Aeroporto *aeroporto) {
    free(aeroporto);
}

int main() {
    int n;
    printf("Digite o número de aeroportos: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Número de aeroportos inválido.\n");
        return 1;
    }

    Aeroporto **vetor_aeroportos = (Aeroporto**) malloc(n * sizeof(Aeroporto*));

    if (vetor_aeroportos == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n=== Cadastro do Aeroporto %d ===\n", i + 1);
        vetor_aeroportos[i] = (Aeroporto*) malloc(sizeof(Aeroporto));
        if (vetor_aeroportos[i] == NULL) {
            printf("Erro na alocação de memória para o Aeroporto %d.\n", i + 1);
            return 1;
        }
        lerAeroporto(vetor_aeroportos[i]);
    }

    printf("\n=== Dados dos Aeroportos ===\n");
    for (int i = 0; i < n; i++) {
        printf("\n--- Aeroporto %d ---\n", i + 1);
        escreverAeroporto(vetor_aeroportos[i]);
    }

    for (int i = 0; i < n; i++) {
        excluirAeroporto(vetor_aeroportos[i]);
    }
    free(vetor_aeroportos);

    return 0;
}
