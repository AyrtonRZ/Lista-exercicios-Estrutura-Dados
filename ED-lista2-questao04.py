'''
Programa: Conjectura de Goldbach
Autor: Ayrton Rodrigues, Rian Lucas
Data: 20-05-2023
Descrição: Verifica a Conjectura de Goldbach para números pares entre 700 e 1100.
'''

def eh_primo(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def conjectura_goldbach():
    for num in range(700, 1101, 2):
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

conjectura_goldbach()
