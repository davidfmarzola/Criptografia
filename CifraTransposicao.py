from math import ceil

chave = input("Entre com a chave: ")
registro = input("Entre com o registro: ")
numDeLinhas = ceil(len(registro) / len(chave)) # 3
numDeColunas = len(chave) # 4

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

def CriptografarRegistro(matrizComRegistro, chave):
    chaveOrdenada = sorted(chave)
    matrizCriptografada = []
    for j in range(numDeColunas):
        linha = []
        for i in range(numDeLinhas):
            if(matrizComRegistro[i][chaveOrdenada[j]]!= '\0'):
                linha.append(matrizComRegistro[i][chaveOrdenada[j]])
        matrizCriptografada.append(linha)
    return matrizCriptografada

matrizComRegistro = AtribuirRegistroAMatriz(registro, chave)
matrizCriptografada = CriptografarRegistro(matrizComRegistro, chave)
print(matrizComRegistro)
print(matrizCriptografada)