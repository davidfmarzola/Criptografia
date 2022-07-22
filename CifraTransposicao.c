#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define boolean short
#define true 1
#define false 0

void criptografarMatriz(char matriz[100][100], char *chave){
    
}

void ColocarRegistroNaMatriz(char *registro, char *chave){
    int tamanhoRegistro = (int)strlen(registro);
    int tamanhoChaveNumColunas = (int)strlen(chave);
    double c = (double) tamanhoRegistro / tamanhoChaveNumColunas;
    char matriz[100][100]; int i = 0;

    for (int linha = 0; linha < (int)ceil(c); linha++){
        for (int coluna = 0; i < strlen(registro) && coluna < tamanhoChaveNumColunas; coluna++){
            matriz[linha][coluna] = registro[i++];
        }
    }
    criptografarMatriz(matriz, chave);
}

int main()
{
    char *chave = (char *)malloc(sizeof(char) * 15); // aloco 15 espaços na memória
    char *registro = (char *)malloc(sizeof(char) * 100);
    printf("Entre com a chave: ");
    fgets(chave, 15, stdin); // lê até a quebra de linha ('\n')
    printf("Entre com a registro: ");
    fgets(registro, 100, stdin); 
    ColocarRegistroNaMatriz(registro, chave);


    return 0;
}