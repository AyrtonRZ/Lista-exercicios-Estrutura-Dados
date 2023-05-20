// Função: realiza aritmética com números complexos
// Autor: Ayrton Rodrigues e Rian Lucas
// Data: 05/20
// Descrição: O projeto implementa um Tipo Abstrato de Dado (TAD) chamado "Complexo"
//            em C, permitindo a criação, destruição e operações aritméticas com 

#include <stdio.h>

typedef struct {
    double real;
    double imaginario;
} Complexo;

Complexo criarComplexo(double real, double imaginario) {
    Complexo numeroComplexo;
    numeroComplexo.real = real;
    numeroComplexo.imaginario = imaginario;
    return numeroComplexo;
}

Complexo somarComplexos(Complexo c1, Complexo c2) {
    double real = c1.real + c2.real;
    double imaginario = c1.imaginario + c2.imaginario;
    return criarComplexo(real, imaginario);
}

Complexo subtrairComplexos(Complexo c1, Complexo c2) {
    double real = c1.real - c2.real;
    double imaginario = c1.imaginario - c2.imaginario;
    return criarComplexo(real, imaginario);
}

Complexo multiplicarComplexos(Complexo c1, Complexo c2) {
    double real = c1.real * c2.real - c1.imaginario * c2.imaginario;
    double imaginario = c1.real * c2.imaginario + c1.imaginario * c2.real;
    return criarComplexo(real, imaginario);
}

Complexo dividirComplexos(Complexo c1, Complexo c2) {
    double divisor = c2.real * c2.real + c2.imaginario * c2.imaginario;
    double real = (c1.real * c2.real + c1.imaginario * c2.imaginario) / divisor;
    double imaginario = (c1.imaginario * c2.real - c1.real * c2.imaginario) / divisor;
    return criarComplexo(real, imaginario);
}

void mostrarComplexo(Complexo numeroComplexo) {
    printf("(%lf, %lf)\n", numeroComplexo.real, numeroComplexo.imaginario);
}

int main() {
    Complexo c1 = criarComplexo(2, 3);
    Complexo c2 = criarComplexo(4, 5);

    Complexo soma = somarComplexos(c1, c2);
    Complexo subtracao = subtrairComplexos(c1, c2);
    Complexo multiplicacao = multiplicarComplexos(c1, c2);
    Complexo divisao = dividirComplexos(c1, c2);

    printf("Soma: ");
    mostrarComplexo(soma);

    printf("Subtração: ");
    mostrarComplexo(subtracao);

    printf("Multiplicação: ");
    mostrarComplexo(multiplicacao);

    printf("Divisão: ");
    mostrarComplexo(divisao);

    return 0;
}