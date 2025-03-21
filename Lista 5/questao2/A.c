// 2º Implemente os dois algoritmos de busca vistos em sala(Sequencial e Binária) e em seguida compare seus tempos de busca nos seguintes cenários:
// a) Array com 1000 elementos

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Busca Sequencial
int sequentialSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Retorna o índice se o elemento for encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Busca Binária (requer que o array esteja ordenado)
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid; // Retorna o índice se o elemento for encontrado
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Função para ordenar o array (usando Quick Sort para preparar a busca binária)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para gerar um array aleatório
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
}

// Função para medir o tempo de busca
void measureSearchTime(int (*searchFunction)(int[], int, int), int arr[], int n, int key, char* searchName) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int result = searchFunction(arr, n, key);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (result != -1) {
        printf("%s encontrou o elemento %d no índice %d em %f segundos.\n", searchName, key, result, cpu_time_used);
    } else {
        printf("%s não encontrou o elemento %d. Tempo: %f segundos.\n", searchName, key, cpu_time_used);
    }
}

int main() {
    int n1 = 1000, n2 = 100000, n3 = 1000000;
    int arr1[n1], arr2[n2], arr3[n3];

    // Gerar arrays aleatórios
    generateRandomArray(arr1, n1);
    generateRandomArray(arr2, n2);
    generateRandomArray(arr3, n3);

    // Ordenar os arrays para a busca binária
    quickSort(arr1, 0, n1 - 1);
    quickSort(arr2, 0, n2 - 1);
    quickSort(arr3, 0, n3 - 1);

    // Escolher um elemento aleatório para buscar
    int key1 = arr1[rand() % n1];
    int key2 = arr2[rand() % n2];
    int key3 = arr3[rand() % n3];

    // Medir tempo de busca para cada algoritmo
    printf("Array com 1000 elementos:\n");
    measureSearchTime(sequentialSearch, arr1, n1, key1, "Busca Sequencial");
    measureSearchTime(binarySearch, arr1, 0, n1 - 1, key1, "Busca Binária");

    printf("\nArray com 100000 elementos:\n");
    measureSearchTime(sequentialSearch, arr2, n2, key2, "Busca Sequencial");
    measureSearchTime(binarySearch, arr2, 0, n2 - 1, key2, "Busca Binária");

    printf("\nArray com 1000000 elementos:\n");
    measureSearchTime(sequentialSearch, arr3, n3, key3, "Busca Sequencial");
    measureSearchTime(binarySearch, arr3, 0, n3 - 1, key3, "Busca Binária");

return (0);
}