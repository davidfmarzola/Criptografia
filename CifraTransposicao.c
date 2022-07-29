#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

void **descriptografarMatriz(char **matrizCriptografada, char chave[15], double c){
    int numeroLinhas = (int)ceil(c);
    int *indiceChaveOrdenado = OrdenarChaveLexicograficamente(chave);
    int numeroColunas = (int) strlen(chave) - 1;

    char **matrizDescriptografada; 
    matrizDescriptografada = malloc(numeroLinhas * sizeof(int));//alocando linhas
    for(int k = 0; k < numeroLinhas; k++) {
        matrizDescriptografada[k] = malloc(numeroColunas * sizeof(int));//alocando colunas para cada linha
    }

    for(int j = 0; j < numeroColunas; j++) { //coluna
        for(int i = 0; i < numeroLinhas; i++){ // linha
            if (matrizCriptografada[i][j] != '\0') {
                matrizDescriptografada[i][indiceChaveOrdenado[j]] = matrizCriptografada[i][j];
            }
        }
    }
}

void **criptografarMatriz(char **matrizComRegistro, char chave[15], double c){
    int numeroLinhas = (int)ceil(c);
    int *indiceChaveOrdenado = OrdenarChaveLexicograficamente(chave);
    int numeroColunas = (int) strlen(chave) - 1;

    char **matriz; 
    matriz = malloc(numeroLinhas * sizeof(int));//alocando linhas
    for(int k = 0; k < numeroLinhas; k++) {
        matriz[k] = malloc(numeroColunas * sizeof(int));//alocando colunas para cada linha
    }
    descriptografarMatriz(matriz, chave, c);
}

char **ColocarRegistroNaMatriz(char *registro, char chave[15]) {
    int tamanhoRegistro = (int)strlen(registro) - 1;
    int tamanhoChaveNumColunas = (int)strlen(chave) - 1;
    double c = (double)tamanhoRegistro / tamanhoChaveNumColunas;

    char **matriz; 
    matriz = malloc((int)ceil(c) * sizeof(int));//alocando linhas
    for(int k = 0; k<(int)ceil(c); k++) {
        matriz[k] = malloc(tamanhoChaveNumColunas * sizeof(int));//alocando colunas para cada linha
    }

    int i = 0;
    for (int linha = 0; linha < (int)ceil(c); linha++){
        for (int coluna = 0; i < tamanhoRegistro && coluna < tamanhoChaveNumColunas; coluna++){
            matriz[linha][coluna] = registro[i++];
        }
    }
   criptografarMatriz(matriz, chave, c);
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