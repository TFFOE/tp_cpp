#if !defined(PROJECT_INCLUDE_ARRAY_PROCESSING_H)
#define PROJECT_INCLUDE_ARRAY_PROCESSING_H

#include <stdlib.h>

void fillArrayRandom(int *array, size_t length);
int createArray(int **array, size_t length);
int calculateChecksum(int *array, size_t size);

#endif // PROJECT_INCLUDE_ARRAY_PROCESSING_H
