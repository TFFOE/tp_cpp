#ifndef PROJECT_LIBS_ARRAY_PROCESSING_H_
#define PROJECT_LIBS_ARRAY_PROCESSING_H_
#include <unistd.h>
#define THREADS sysconf(_SC_NPROCESSORS_ONLN)

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fillArrayRandom(int *array, size_t length);
int createArray(int **array, size_t length);
int calculateChecksum(int *array, size_t size);
int checkSumArrayFromFile(char* path_to_file);

#endif  // PROJECT_LIBS_ARRAY_PROCESSING_H_
