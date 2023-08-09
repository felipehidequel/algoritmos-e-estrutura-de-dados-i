import pandas as pd

nAlunos = int(input("Informe a quantidade de alunos: "))

colunas = ["Nome","notas"]
valores = []

notas = []
with open("alunos.txt", "w") as saida:
    for aluno in range(nAlunos):
        nome = input(f"Digite o nome para o aluno {aluno+1}: ")
        for unidade in range(3):
            while True:
                nota = float(input(f"Informe a nota da {unidade+1} unidade: "))
                if nota >= 0 and nota <= 10:                
                    notas.append(nota)
                    break
                else:
                    print("A nota informada deve ser estar no intervalo de 0 a 10.")

        valores.append([nome, notas])
        notas = []

    tabela = pd.DataFrame(columns=colunas, data=valores)
    saida.write(str(tabela))

print()
print(tabela)
