'''
Programa: Classificação de vetor usando o algoritmo Quicksort
Autor: Ayrton Rodrigues, Rian Lucas
Data: 20-05-2022
Descrição: Implementa a classificação de elementos de um vetor em ordem crescente usando o algoritmo Quicksort.
'''

import random

def quicksort(vetor):
    if len(vetor) <= 1:
        return vetor

    indice_pivo = len(vetor) // 2
    pivo = vetor[indice_pivo]

    menores = [elemento for indice, elemento in enumerate(vetor) if indice != indice_pivo and elemento <= pivo]
    maiores = [elemento for indice, elemento in enumerate(vetor) if indice != indice_pivo and elemento > pivo]

    vetor_ordenado = quicksort(menores) + [pivo] + quicksort(maiores)

    return vetor_ordenado

vetor = random.sample(range(100), 10)
print("Vetor original:", vetor)
vetor_ordenado = quicksort(vetor)
print("Vetor ordenado:", vetor_ordenado)
