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
    chaveOrdenada = sorted(chave)
    indiceChaveOrdenada = OrdenarIndiceChaveLexicograficamente(chave, chaveOrdenada)
    matrizCriptografada = []
    for j in range(numDeColunas):
        for i in range(numDeLinhas):
            # IndexError: list index out of range
            matrizCriptografada.append(matrizComRegistro[i][indiceChaveOrdenada[j]])
    return matrizCriptografada

matrizComRegistro = AtribuirRegistroAMatriz(registro, chave)
print(matrizComRegistro)
matrizCriptografada = CriptografarRegistro(matrizComRegistro, chave)
print(matrizCriptografada)