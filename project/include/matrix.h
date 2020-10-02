#ifndef PROJECT_INCLUDE_MATRIX_H_
#define PROJECT_INCLUDE_MATRIX_H_

typedef struct Matrix {
    double** data;
    size_t cols;
    size_t rows;
} Matrix;

Matrix* create_matrix(size_t rows, size_t cols);
Matrix* create_matrix_from_file()
int free_matrix(Matrix* matrix);

Matrix* split_matrix(Matrix* matrix);

#endif // PROJECT_INCLUDE_MATRIX_H
