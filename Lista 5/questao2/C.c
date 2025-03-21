// 2º Implemente os dois algoritmos de busca vistos em sala(Sequencial e Binária) e em seguida compare seus tempos de busca nos seguintes cenários:
// c) Array com 1000000

// Mesmo código da alternativa 'a' e 'b', apenas alterando a quantidade de elementos.

#include <stdio.h>
#include <time.h>

int buscaSequencial(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            // Retorna o índice do elemento encontrado
            return i; 
        }
    }
    // Retorna -1 se o elemento não for encontrado
    return -1; 
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int buscaBinaria(int arr[], int esquerda, int direita, int x) {
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (arr[meio] == x) {
            // Retorna o índice do elemento encontrado
            return meio; 
        }
        if (arr[meio] < x) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    // Retorna -1 se o elemento não for encontrado
    return -1; 
}

int main() {
    // Array fixa com 1.000.000 elementos ("falsos aleatórios")
    int n = 1000000;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = (i * 37) % 1000000;
    }

    // Ordena o array com Bubble Sort
    bubbleSort(arr, n);

    // Elemento a ser encontrado
    int x = 500;

    clock_t inicioSequencial = clock();
    int resultadoSequencial = buscaSequencial(arr, n, x);
    clock_t fimSequencial = clock();
    double tempoSequencial = (double)(fimSequencial - inicioSequencial) / CLOCKS_PER_SEC;

    clock_t inicioBinario = clock();
    int resultadoBinario = buscaBinaria(arr, 0, n - 1, x);
    clock_t fimBinario = clock();
    double tempoBinario = (double)(fimBinario - inicioBinario) / CLOCKS_PER_SEC;

    printf("Busca Sequencial: %s em %.6f segundos.\n", (resultadoSequencial != -1 ? "Encontrado" : "Nao encontrado"), tempoSequencial);
    printf("Busca Binaria: %s em %.6f segundos.\n", (resultadoBinario != -1 ? "Encontrado" : "Nao encontrado"), tempoBinario);

return (0);
}