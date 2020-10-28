#include "array_processing.h"

void fillArrayRandom(int *array, size_t size) {
    uint seed = time(NULL);
    for (size_t i = 0; i < size; ++i) {
        array[i] = rand_r(&seed);
    }
}

int createArray(int **array, size_t size) {
    *array = (int *)malloc(size * sizeof(int));
    return *array != NULL;
}

int calculateChecksum(int *array, size_t size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum = (sum + array[i] % 1024) % 1024;
    }
    return sum;
}
