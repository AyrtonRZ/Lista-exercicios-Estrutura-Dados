'''
Programa: Conjectura de Goldbach Personalizada
Autor: [Seu nome]
Data: [Data atual]
Descrição: Verifica a Conjectura de Goldbach para números pares de 2 até um número N informado pelo usuário.
'''

def eh_primo(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def conjectura_goldbach_personalizada(n):
    for num in range(2, n+1, 2):
        primos = []
        for i in range(2, num // 2 + 1):
            if eh_primo(i) and eh_primo(num - i):
                primos.append(i)
                primos.append(num - i)
                break
        if len(primos) == 2:
            print(f"{num} = {primos[0]} + {primos[1]}")
        else:
            print(f"Não foi possível encontrar uma decomposição em primos para o número {num}.")

n = int(input("Digite o número máximo (N): "))
conjectura_goldbach_personalizada(n)
