
class Fruta:
    def __init__(self, nome, preco):
        self.nome = nome
        self.preco = preco

def main():
    while True:
        nome = input("Digite o nome da fruta (ou 'sair' para encerrar a execução): ")

        if nome.lower() == 'sair':
            break

        preco = float(input("Digite o preço: "))

        fruta = Fruta(nome, preco)

        with open("frutas_py.txt", "a") as arquivo:
            arquivo.write(f'{fruta.nome} R$ {fruta.preco:.2f}\n')
    
    print("Informações registradas na no arquivo 'frutas_py.txt'")

if __name__ == "__main__":
    main()