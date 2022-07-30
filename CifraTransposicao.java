import java.util.Scanner;
import java.time.Duration;
import java.time.Instant;
import java.util.Arrays;

public class CifraTransposicao {
    static Scanner scan = new Scanner(System.in);

    public static int[] RetornarIndiceChaveOrdenado(String chave) {
        char[] vcChave = chave.toCharArray();
        char[] vcChaveOrdenada = chave.toCharArray();
        int[] indicesDaChaveOrdenados = new int[vcChave.length];
        Arrays.sort(vcChaveOrdenada);

        for (int j = 0, k = 0; j < vcChave.length; j++) {
            for (int i = 0; i < vcChave.length; i++) {
                if (vcChave[i] == vcChaveOrdenada[j]) {
                    indicesDaChaveOrdenados[k] = i;
                    k++;
                }
            }
            j = k - 1;
        }
        return indicesDaChaveOrdenados;
    }

    public static char[][] AtribuirRegistroAMatriz(String registro, char[] vcChave) {
        int numDeLinhas = registro.length() / vcChave.length;
        if (registro.length() % vcChave.length > 0)
            numDeLinhas++;
        int numDeColunas = vcChave.length;
        int indRegistro = 0;
        char[][] MatrizComRegistro = new char[numDeLinhas][vcChave.length];
        char[] vcRegistro = registro.toCharArray();

        for (int i = 0; i < numDeLinhas && indRegistro < registro.length(); i++) {// linha
            for (int j = 0; j < numDeColunas && indRegistro < registro.length(); j++) {// coluna
                MatrizComRegistro[i][j] = vcRegistro[indRegistro++];
            }
        }
        return MatrizComRegistro;
    }

    public static char[][] CriptografarRegistro(char[][] matrizComRegistro, String chave) {
        int[] viPosicaoOrdenada = RetornarIndiceChaveOrdenado(chave);
        char[][] matriz = new char[matrizComRegistro.length][viPosicaoOrdenada.length];

        for (int j = 0; j < viPosicaoOrdenada.length; j++) { // coluna
            for (int i = 0; i < matrizComRegistro.length; i++) {// linha
                if (matrizComRegistro[i][viPosicaoOrdenada[j]] != '\0') {
                    matriz[i][j] = matrizComRegistro[i][viPosicaoOrdenada[j]];
                }
            }
        }
        return matriz;
    }

    public static char[][] DescriptografarRegistro(char[][] matrizCriptografada, String chave) {
        int[] viPosicaoOrdenada = RetornarIndiceChaveOrdenado(chave);
        char[][] matrizDescriptografada = new char[matrizCriptografada.length][viPosicaoOrdenada.length];

        for (int j = 0; j < viPosicaoOrdenada.length; j++) { // coluna
            for (int i = 0; i < matrizCriptografada.length; i++) {// linha
                matrizDescriptografada[i][viPosicaoOrdenada[j]] = matrizCriptografada[i][j];
            }
        }
        return matrizDescriptografada;
    }

    public static void main(String[] args) {
        long tempoInicial = System.currentTimeMillis();

        System.out.println("Entre com a chave");
        String chave = scan.nextLine();
        System.out.println("Entre com o registro");
        String registro = scan.nextLine();

        char[] vcChave = chave.toCharArray();
        char[][] matrizComRegistro = AtribuirRegistroAMatriz(registro, vcChave);
        char[][] matrizCriptografada = CriptografarRegistro(matrizComRegistro, chave);
        char[][] registroDescriptografado = DescriptografarRegistro(matrizCriptografada, chave);

        System.out
                .println("O método foi executado em " + (System.currentTimeMillis() - tempoInicial) + " ms.");
    }
}