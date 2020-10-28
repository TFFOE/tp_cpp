#include "utils.h"
#include "array_processing.h"
#include <time.h>
#include <stdio.h>

int main() 
{
    srand(time(NULL));

    clock_t begin = clock();
    //=============Начало============
    const size_t size = 100 * 1024 * 1024 / 8 / sizeof(int);
    int *array;
    if (!createArray(&array, size))
        return 1;
    fillArrayRandom(array, size);
    int sum = calculateChecksum(array, size);
    
    printf("%d\n", sum);
    free(array);
    //=============Конец==============
    clock_t end = clock();
    double time_spent = (end - begin) / CLOCKS_PER_SEC;
    printf("time spent: %lf\n", time_spent);
    return 0;
}