'''
Função: Classificação de vetor usando o algoritmo de Seleção
Autor: Ayrton Rodrigues, Rian Lucas
Data: 20-05-2022
Descrição: Implementa a classificação de elementos de um vetor em ordem crescente usando o algoritmo de Seleção.
'''

import random

def classificar_por_selecao(vetor):
    tamanho = len(vetor)
    for i in range(tamanho - 1):
        indice_min = i
        for j in range(i + 1, tamanho):
            if vetor[j] < vetor[indice_min]:
                indice_min = j
        vetor[i], vetor[indice_min] = vetor[indice_min], vetor[i]
    return vetor

vetor = random.sample(range(1, 101), 10)  # Gera um vetor aleatório de 10 elementos

print(end="\n")
print("Vetor original:",", ".join(str(valor) for valor in vetor))

for i in range(len(vetor) - 1):
    subvetor = vetor[i:]
    subvetor = classificar_por_selecao(subvetor)
    vetor[i:] = subvetor
    if len(subvetor) == 1:
        break

print("Vetor ordenado:",", ".join(str(valor) for valor in vetor))
print(end="\n")

