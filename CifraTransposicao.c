#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define boolean short
#define true 1
#define false 0

char **ColocarRegistroNaMatriz(char registro[100], char chave[15]){
    return NULL;
}

int main() 
{
    char chave[15] = "";
    char registro[100] = "";
    printf("Entre com a chave: ");
    scanf("%s", chave);
    printf("Entre com a registro: ");
    scanf("%s", registro);

    int numDeLinhas = ceil(sizeof(registro)/sizeof(chave));    
    char matrizComRegistro[numDeLinhas][sizeof(chave)];
    matrizComRegistro = ColocarRegistroNaMatriz(registro, chave);
    return 0;
}