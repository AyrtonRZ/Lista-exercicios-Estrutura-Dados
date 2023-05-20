'''
Programa: Cálculo da Raiz Quadrada com o Método de Newton-Raphson
Autor: Ayrton Rodrigues, Rian Lucas
Data: 20-05-2022
Descrição: Calcula a raiz quadrada de um número com aproximação de 0.0001 usando o Método de Newton-Raphson.
'''

def raiz_quadrada(n):
    x = n / 2  
    precisao = 0.0001

    while True:
        f = x**2 - n  
        f_derivada = 2 * x  

        if abs(f) < precisao:
            break

        x = x - f / f_derivada

    return x

numero = float(input("Digite o número para calcular a raiz quadrada: "))
resultado = raiz_quadrada(numero)
print(f"A raiz quadrada de {numero} é aproximadamente: {resultado:.4f}")
