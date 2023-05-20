/*
   Função:
   Autor: 
   Data: 
   Observações:
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[50];
    Data data_nascimento;
    char RG[15];
    Data data_admissao;
    float salario;
} Empregado;

void lerEmpregado(Empregado *empregado) {
    printf("Digite o nome: ");
    scanf("%s", empregado->nome);
    printf("Digite a data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &empregado->data_nascimento.dia, &empregado->data_nascimento.mes, &empregado->data_nascimento.ano);
    printf("Digite o RG: ");
    scanf("%s", empregado->RG);
    printf("Digite a data de admissao (dd mm aaaa): ");
    scanf("%d %d %d", &empregado->data_admissao.dia, &empregado->data_admissao.mes, &empregado->data_admissao.ano);
    printf("Digite o salario: ");
    scanf("%f", &empregado->salario);
}

void escreverEmpregado(const Empregado *empregado) {
    printf("Nome: %s\n", empregado->nome);
    printf("Data de nascimento: %02d/%02d/%04d\n", empregado->data_nascimento.dia, empregado->data_nascimento.mes, empregado->data_nascimento.ano);
    printf("RG: %s\n", empregado->RG);
    printf("Data de admissao: %02d/%02d/%04d\n", empregado->data_admissao.dia, empregado->data_admissao.mes, empregado->data_admissao.ano);
    printf("Salario: %.2f\n", empregado->salario);
}

int main() {
    int n;
    printf("Digite o numero de empregados: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Numero de empregados invalido.\n");
        return 1;
    }

    Empregado *vetor_empregados = (Empregado*) malloc(n * sizeof(Empregado));

    if (vetor_empregados == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\n=== Cadastro do Empregado %d ===\n", i + 1);
        lerEmpregado(&vetor_empregados[i]);
    }

    printf("\n=== Dados dos Empregados ===\n");
    for (int i = 0; i < n; i++) {
        printf("\n--- Empregado %d ---\n", i + 1);
        escreverEmpregado(&vetor_empregados[i]);
    }

    free(vetor_empregados);

    return 0;
}
