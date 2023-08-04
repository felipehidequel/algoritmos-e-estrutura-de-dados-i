vetor = []

with open('entrada_q2.txt', 'r') as entrada:
    for linha in range(10):
        vetor.append(entrada.readline())

    vetor = [int(elemento.strip()) for elemento in vetor]

minVetor = min(vetor)
maxVetor = max(vetor)
media = sum(vetor) / len(vetor)

with open('saida_q2.txt', 'w') as saida:
    saida.write(f'menor elemento: {minVetor}\n')
    saida.write(f'maior elemento: {maxVetor}\n')
    saida.write(f'media dos elementos: {media}')
