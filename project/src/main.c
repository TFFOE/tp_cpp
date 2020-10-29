#include "utils.h"
#include "array_processing.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/sysinfo.h>

// void* thread_func(void* i) {
//     pthread_mutex_t *mutex = &sum.mutex;


//     int errflag = 0;
//     errflag = pthread_mutex_lock(mutex);

//     if (errflag != 0) {
//         printf("mutex busy");
//     }

//     sum.value += 1;

//     errflag = pthread_mutex_unlock(mutex);
//     if (errflag != 0) {
//         printf("cant free mutex");
//     }


//     printf("sum = %d\n", sum.value);
//     return NULL;
// }

int main() {
    clock_t begin = clock();
    int checks = 0;
    checks = checkSumArrayFromFile("test.arr");
    clock_t end = clock();
    double time_spent = (end - begin);
    printf("time spent: %lf clocks\n", time_spent);
    printf("chechSum = %d\n", checks);

    // errflag = pthread_create(&thread, NULL, thread_func, k_void_ptr);

    //=============Начало============
    const size_t size = 100 * 1024 * 1024 / 8 / sizeof(int);
    int *array;
    if (!createArray(&array, size))
        return 1;
    fillArrayRandom(array, size);
    int sum = calculateChecksum(array, size);
    printf("sum is %d\n", sum);
    free(array);
    //=============Конец==============

    return 0;
}
