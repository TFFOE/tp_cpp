#include "array_processing.h"
#include <sys/sysinfo.h>

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

// void* thread_method(void * arg) {

//     return NULL;
// }

int checkSumArrayFromFile(char* path_to_file) {
    FILE* array_file = fopen(path_to_file, "r");
    if (array_file == NULL)
        return -1;
    int num_of_threads = get_nprocs_conf();
    printf("num = %d\n", num_of_threads);

    // for (int i = 0; i < num_of_threads; ++i) {
    //     pthread_t thread;
    //     pthread_create(&thread, NULL, thread_method, NULL);
    // }
    fclose(array_file);
    return 0;
}
