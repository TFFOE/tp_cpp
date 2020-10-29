#include "array_processing.h"

void fillArrayRandom(int *array, size_t size) {
    unsigned int seed = time(NULL);
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

int checkSumArrayFromFile(char* path_to_file) {
    FILE* array_file = fopen(path_to_file, "r");
    int result = 0;
    if (array_file == NULL)
        return -1;
    int n = 0;
    fscanf(array_file, "%15d", &n);
    for (int i = 0; i < n; ++i) {
        int current_dgt = 0;
        fscanf(array_file, "%15d", &current_dgt);
        result = (result + current_dgt % 1024) % 1024;
    }
    fclose(array_file);
    return result;
}
