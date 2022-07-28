#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define boolean short
#define true 1
#define false 0

void RetornarIndiceChaveOrdenado(int indiceChaveOrdenado[15], int i, int j){
    indiceChaveOrdenado[i] = j;
    indiceChaveOrdenado[j] = i;
}

void swap(char chaveOrdenada[15], char chave[15], int j, int i){
    char tmp = chaveOrdenada[i];
    chaveOrdenada[i] = chave[j];
    chaveOrdenada[j] = tmp;
}

int *OrdenarChaveLexicograficamente(char chave[15]){
    char *chaveOrdenada = (char*)malloc(sizeof(char)*15);
    strcpy(chaveOrdenada, chave);
    int tamanhoChave = (int) strlen(chave)-1;//ao remover o '\0'
    int *indiceChaveOrdenado = (int*)malloc(sizeof(int)*tamanhoChave);

    for (int i = 0; i < tamanhoChave - 1; i++){
        for (int j = i + 1; j < tamanhoChave; j++){
            if (chaveOrdenada[i] > chave[j]){
                RetornarIndiceChaveOrdenado(indiceChaveOrdenado, i, j);
                swap(chaveOrdenada, chave, j, i);  
            }
        }
    }
    return indiceChaveOrdenado;
}

void criptografarMatriz(char matriz[100][100], char chave[15]){
    int *indiceChaveOrdenado = OrdenarChaveLexicograficamente(chave);
}

void ColocarRegistroNaMatriz(char *registro, char chave[15]) {
    int tamanhoRegistro = (int)strlen(registro);
    int tamanhoChaveNumColunas = (int)strlen(chave);
    double c = (double)tamanhoRegistro / tamanhoChaveNumColunas;
    char matriz[100][100];
    int i = 0;

    for (int linha = 0; linha < (int)ceil(c); linha++){
        for (int coluna = 0; i < strlen(registro) && coluna < tamanhoChaveNumColunas; coluna++){
            matriz[linha][coluna] = registro[i++];
        }
    }
    criptografarMatriz(matriz, chave);
}

int main(){
    char chave[15]; // aloco 15 espaços na memória
    char *registro = (char *)malloc(sizeof(char) * 100);
    printf("Entre com a chave: ");
    fgets(chave, 15, stdin); // lê até a quebra de linha ('\n')
    printf("Entre com a registro: ");
    fgets(registro, 100, stdin);
    ColocarRegistroNaMatriz(registro, chave);

    return 0;
}