// 2º Implemente os dois algoritmos de busca vistos em sala(Sequencial e Binária) e em seguida compare seus tempos de busca nos seguintes cenários:
// d) Buscando uma palavra em um texto

// Quase o mesmo código das alternativas 'a', 'b' e 'c'. Dessa vez, foi necessário fazer alterações nas variáveis para que comportem a movimentação de char!
// Vale salientar que o código indica a palavra a ser buscada e um array pré-definido com 10 palavras. 

// Diante dos resultados, observa-se que a busca binária é claramente superior em termos de eficiência para arrays ordenados, 
// enquanto a busca sequencial é mais simples e não requer ordenação prévia. A escolha entre elas 
// depende do contexto e dos requisitos do problema.

#include <stdio.h>
#include <time.h>
#include <string.h> 

int buscaSequencial(char *texto[], int n, char *palavra) {
    for (int i = 0; i < n; i++) {
        if (strcmp(texto[i], palavra) == 0) {
            // Retorna o índice da palavra encontrada
            return i;
        }
    }
    // Retorna -1 se a palavra não for encontrada
    return -1;
}

void bubbleSort(char *texto[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(texto[j], texto[j + 1]) > 0) {
                char *temp = texto[j];
                texto[j] = texto[j + 1];
                texto[j + 1] = temp;
            }
        }
    }
}

int buscaBinaria(char *texto[], int esquerda, int direita, char *palavra) {
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        int comparacao = strcmp(texto[meio], palavra);

        if (comparacao == 0) {
            // Retorna o índice da palavra encontrada
            return meio;
        }
        if (comparacao < 0) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    // Retorna -1 se a palavra não for encontrada
    return -1;
}

int main() {
    // Array fixa com 10 palavras
    char *texto[] = {
        "sal", "acucar", "oleo", "margarina", "ovos",
        "farinha", "macarrao", "cafe", "leite", "bolacha"
    };

    int n = 10;

    // Ordena o texto com Bubble Sort
    bubbleSort(texto, n);

    // Palavra a ser encontrada
    char *palavra = "cafe";

    clock_t inicioSequencial = clock();
    int resultadoSequencial = buscaSequencial(texto, n, palavra);
    clock_t fimSequencial = clock();
    double tempoSequencial = (double)(fimSequencial - inicioSequencial) / CLOCKS_PER_SEC;

    clock_t inicioBinario = clock();
    int resultadoBinario = buscaBinaria(texto, 0, n - 1, palavra);
    clock_t fimBinario = clock();
    double tempoBinario = (double)(fimBinario - inicioBinario) / CLOCKS_PER_SEC;

    printf("Busca Sequencial: %s em %.6f segundos.\n", (resultadoSequencial != -1 ? "Encontrado" : "Nao encontrado"), tempoSequencial);
    printf("Busca Binaria: %s em %.6f segundos.\n", (resultadoBinario != -1 ? "Encontrado" : "Nao encontrado"), tempoBinario);

return (0);
}

