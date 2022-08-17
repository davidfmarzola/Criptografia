from math import ceil
import time
tempo_inicial = (time.time())
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

def matriz_nula():
    m = []
    for i in range(numDeLinhas):
        linha=[0]*numDeColunas
        if i == numDeLinhas-1:
            nposicoesembranco=(numDeLinhas*numDeColunas)-len(registro)
            nposicoesultimalinha=numDeColunas-nposicoesembranco
            linha=[0]*(nposicoesultimalinha)
        m.append(linha)
    return m

def DescriptografarRegistro(matrizCriptografada, chave):
    matriz = matriz_nula()
    for j in range(numDeColunas):
        for i in range(numDeLinhas):
            try:
                matriz[i][indiceChaveOrdenada[j]] = matrizCriptografada[j][i]
            except IndexError:
                continue
    return matriz

matrizComRegistro = AtribuirRegistroAMatriz(registro, chave)

chaveOrdenada = sorted(chave)
indiceChaveOrdenada = OrdenarIndiceChaveLexicograficamente(chave, chaveOrdenada)
matrizCriptografada = CriptografarRegistro(matrizComRegistro, indiceChaveOrdenada)

matrizDescriptografada = DescriptografarRegistro(matrizCriptografada, chave)
tempo_final=(time.time())
print(f'Execution time: {(tempo_final - tempo_inicial)*1000} milissegundos')
