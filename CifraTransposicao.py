from math import ceil

chave = input("Entre com a chave: ")
registro = input("Entre com o registro: ")
numDeLinhas = ceil(len(registro) / len(chave)) 
numDeColunas = len(chave)

def AtribuirRegistroAMatriz(registro, chave):
    indRegistro = 0 
    matriz = []
    for i in range(numDeLinhas):
        linha = []
        for j in range(numDeColunas):
            if(indRegistro < len(registro)):
                linha.append(registro[indRegistro])
                indRegistro += 1
        matriz.append(linha)
    return matriz

def OrdenarIndiceChaveLexicograficamente(chave, chaveOrdenada):
    indiceChaveOrdenada = []
    for j in range(len(chave)):
        k=0
        for i in range(len(chave)):
            if(chave[i] == chaveOrdenada[j]):
                indiceChaveOrdenada.append(i)
                k+=1
        j=k-1
    return indiceChaveOrdenada

def CriptografarRegistro(matrizComRegistro, chave):
    matriz = []
    for j in range(numDeColunas):
        linha = []
        for i in range(numDeLinhas):
            try:
                linha.append(matrizComRegistro[i][indiceChaveOrdenada[j]])
            except IndexError:
                continue
        matriz.append(linha)
    return matriz

def DescriptografarRegistro(matrizCriptografada, chave):
    matriz = []
    for j in range(numDeColunas):
        linha = []
        for i in range(numDeLinhas):
            try:
                print(f'matrizCriptografada[{i}][{j}] = ', matrizCriptografada[i][j])
            except IndexError:
                print(f'matrizCriptografada[{i}][{j}] = ')
                continue
    return matriz


matrizComRegistro = AtribuirRegistroAMatriz(registro, chave)
# print(matrizComRegistro)

chaveOrdenada = sorted(chave)
indiceChaveOrdenada = OrdenarIndiceChaveLexicograficamente(chave, chaveOrdenada)
matrizCriptografada = CriptografarRegistro(matrizComRegistro, indiceChaveOrdenada)
print(matrizCriptografada)

matrizDescriptografada = DescriptografarRegistro(matrizCriptografada, chave)
# print(matrizDescriptografada)