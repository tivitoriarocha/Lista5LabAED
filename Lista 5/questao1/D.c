// 1º Implemente os algoritmos de ordenação vistos na disciplina(bubble, insertion, merge, quick) e compare seus tempos de execução nos seguintes cenários:
// d) Array de Caracteres

// Quase o mesmo código da alternativa 'a', 'b' e 'c'. Dessa vez, foi necessário fazer alterações nas variáveis para que comportem a movimentação de char!
// Também foi preciso usar alocação de memória para a memória temporária do merge sort.
// Considerei o tamanho da arrey de caracteres = 100000.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Função para trocar dois elementos
void trocar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
// Compara elementos adjacentes e os troca se estiverem na ordem errada
// Complexidade: O(n²)
void bubble_sort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                trocar(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
// Insere cada elemento na posição correta na parte já ordenada do array
// Complexidade: O(n²)
void insertion_sort(char arr[], int n) {
    for (int i = 1; i < n; i++) {
        char chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

// Merge Sort - Função para mesclar duas metades
void mesclar(char arr[], int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    char *E = malloc(n1 * sizeof(char));
    char *D = malloc(n2 * sizeof(char));

    for (int i = 0; i < n1; i++)
        E[i] = arr[esquerda + i];
    for (int i = 0; i < n2; i++)
        D[i] = arr[meio + 1 + i];

    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) {
            arr[k] = E[i];
            i++;
        } else {
            arr[k] = D[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = E[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = D[j];
        j++;
        k++;
    }

    free(E);
    free(D);
}

// Merge Sort - Função principal
// Divide o array em duas metades, ordena cada metade recursivamente e combina as duas metades ordenadas
// Complexidade: O(n log n)
void merge_sort(char arr[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        merge_sort(arr, esquerda, meio);
        merge_sort(arr, meio + 1, direita);
        mesclar(arr, esquerda, meio, direita);
    }
}

// Quick Sort - Função de partição
int particionar(char arr[], int baixo, int alto) {
    char pivo = arr[alto];
    int i = baixo - 1;

    for (int j = baixo; j < alto; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i + 1], &arr[alto]);
    return i + 1;
}

// Quick Sort - Função principal
// Escolhe um pivô e rearranja os elementos menores que o pivô para a esquerda e os maiores para a direita
// Complexidade: O(n log n) no caso médio, O(n²) no pior caso
void quick_sort(char arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto);
        quick_sort(arr, baixo, pi - 1);
        quick_sort(arr, pi + 1, alto);
    }
}

int main() {
    // Array fixa de 100.000 caracteres ("falsos aleatórios")
    int n = 100000;
    char arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 'a' + (i % 26); 
    }

    clock_t inicio = clock();
    bubble_sort(arr, n);
    clock_t fim = clock();
    double tempo_bubble = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo do Bubble Sort: %.6f segundos\n", tempo_bubble);

    // Resetar o array para o estado original
    for (int i = 0; i < n; i++) {
        arr[i] = 'a' + (i % 26);
    }

    inicio = clock();
    insertion_sort(arr, n);
    fim = clock();
    double tempo_insertion = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo do Insertion Sort: %.6f segundos\n", tempo_insertion);

    for (int i = 0; i < n; i++) {
        arr[i] = 'a' + (i % 26);
    }

    inicio = clock();
    merge_sort(arr, 0, n - 1);
    fim = clock();
    double tempo_merge = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo do Merge Sort: %.6f segundos\n", tempo_merge);

    for (int i = 0; i < n; i++) {
        arr[i] = 'a' + (i % 26);
    }

    inicio = clock();
    quick_sort(arr, 0, n - 1);
    fim = clock();
    double tempo_quick = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo do Quick Sort: %.6f segundos\n", tempo_quick);

    return 0;
}