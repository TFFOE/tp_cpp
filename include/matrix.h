#ifndef INCLUDE_MATRIX_H_
#define INCLUDE_MATRIX_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct Matrix {
    double** data;
    size_t cols;
    size_t rows;
} Matrix;

Matrix* create_matrix(size_t rows, size_t cols);
Matrix* create_matrix_from_file(const char* path_file);
void free_matrix(Matrix* matrix);
void print_matrix(Matrix* matrix);
int check_matrices_for_equality(Matrix* matrix1, Matrix* matrix2);

Matrix** split_matrix(Matrix* matrix);

#endif  // INCLUDE_MATRIX_H_
