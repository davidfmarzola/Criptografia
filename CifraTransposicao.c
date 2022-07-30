#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void OrdenarIndiceChave(int indiceChaveOrdenado[15], int i, int j){
    indiceChaveOrdenado[i] = j;
    indiceChaveOrdenado[j] = i;
}

void Swap(char chaveOrdenada[15], char chave[15], int j, int i){
    char tmp = chaveOrdenada[i];
    chaveOrdenada[i] = chave[j];
    chaveOrdenada[j] = tmp;
}

int *OrdenarIndiceChaveLexicograficamente(char chave[15]){
    char *chaveOrdenada = (char*)malloc(sizeof(char)*15);
    strcpy(chaveOrdenada, chave);
    int tamanhoChave = (int) strlen(chave)-1;//ao remover o '\0'
    int *indiceChaveOrdenado = (int*)malloc(sizeof(int)*tamanhoChave);

    for (int i = 0; i < tamanhoChave - 1; i++){
        for (int j = i + 1; j < tamanhoChave; j++){
            if (chaveOrdenada[i] > chave[j]){
                OrdenarIndiceChave(indiceChaveOrdenado, i, j);
                Swap(chaveOrdenada, chave, j, i);  
            }
        }
    }
    return indiceChaveOrdenado;
}

char **DescriptografarRegistro(char **matrizCriptografada, char chave[15], double c){
    int numeroLinhas = (int)ceil(c);
    int *indiceChaveOrdenado = OrdenarIndiceChaveLexicograficamente(chave);
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
    return matrizDescriptografada;
}

char **CriptografarRegistro(char **matrizComRegistro, char chave[15], double c){
    int numeroLinhas = (int)ceil(c);
    int *indiceChaveOrdenado = OrdenarIndiceChaveLexicograficamente(chave);
    int numeroColunas = (int) strlen(chave) - 1;

    char **matriz; 
    matriz = malloc(numeroLinhas * sizeof(int));//alocando linhas
    for(int k = 0; k < numeroLinhas; k++) {
        matriz[k] = malloc(numeroColunas * sizeof(int));//alocando colunas para cada linha
    }
    for(int j = 0; j < numeroColunas; j++) { //coluna
        for(int i = 0; i < numeroLinhas; i++){ // linha
            if (matrizComRegistro[i][indiceChaveOrdenado[j]] != '\0') {
                matriz[i][j] = matrizComRegistro[i][indiceChaveOrdenado[j]];
            }
        }
    }
    return matriz;
}

char **AtribuirRegistroAMatriz(char *registro, char chave[15]) {
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
    return matriz;
}

int main(){
    clock_t begin = clock();

    char chave[15]; 
    char *registro = (char *)malloc(sizeof(char) * 100);
    int tamanhoRegistro = (int)strlen(registro) - 1;
    int tamanhoChaveNumColunas = (int)strlen(chave) - 1;
    double c = (double)tamanhoRegistro / tamanhoChaveNumColunas;

    printf("Entre com a chave: ");
    fgets(chave, 15, stdin);
    printf("Entre com a registro: ");
    fgets(registro, 100, stdin);

    char **matrizRegistrada = AtribuirRegistroAMatriz(registro, chave);
    char **matrizCriptografada = CriptografarRegistro(matrizRegistrada, chave, c);
    char **registroDescriptografado = DescriptografarRegistro(matrizCriptografada, chave, c);

    clock_t end = clock();
    double time_spent = (double)(end - begin) * 1000.0/ CLOCKS_PER_SEC;
    printf("Time spent: %g ms.\n", time_spent);
    return 0;
}