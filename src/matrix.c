#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

enum FUNCTION_RETURN_INFO {
    FAILURE = -1,
    SUCCESS = 0
};

Matrix* create_matrix(size_t rows, size_t cols) {
    if (rows < 1 || cols < 1) {
        return NULL;
    }
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double**)malloc(rows * sizeof(double*));
    size_t i = 0;
    for (; i < rows; ++i) {
        matrix->data[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

Matrix* create_matrix_from_file(const char* file_path) {
    if (file_path == NULL)
        return NULL;

    FILE* matrix_file = fopen(file_path, "r");
    if (matrix_file == NULL) {
        return NULL;
    }

    int rows, cols;
    if (fscanf(matrix_file, "%10d %10d", &rows, &cols) == -1) {
        fclose(matrix_file);
        return NULL;
    }

    Matrix* matrix = create_matrix(rows, cols);
    int i = 0;
    for (; i < rows; ++i) {
        int j = 0;
        for (j = 0; j < cols; ++j) {
            double value;
            if (fscanf(matrix_file, "%308lf", &value) == -1) {
                fclose(matrix_file);
                free_matrix(matrix);
                return NULL;
            }
            matrix->data[i][j] = value;
        }
    }
    fclose(matrix_file);
    return matrix;
}

void free_matrix(Matrix* matrix) {
    if (matrix == NULL)
        return;
    size_t i = 0;
    for (; i < matrix->rows; ++i)
        free(matrix->data[i]);
    free(matrix->data);
    free(matrix);
}

Matrix** split_matrix(Matrix* matrix) {
    if (matrix == NULL)
        return NULL;

    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    if (rows == 0 || cols == 0)
        return NULL;

    Matrix* matrix1 = create_matrix(rows, (cols + 2) / 3);
    Matrix* matrix2 = create_matrix(rows, (cols + 1) / 3);
    Matrix* matrix3 = create_matrix(rows, cols / 3);
    size_t i = 0;
    for (; i < rows; ++i) {
        size_t j = 0;
        for (; j < cols; ++j) {
            if (j % 3 == 0) {
                matrix1->data[i][j / 3] = matrix->data[i][j];
            } else if (j % 3 == 1) {
                matrix2->data[i][j / 3] = matrix->data[i][j];
            } else {
                matrix3->data[i][j / 3] = matrix->data[i][j];
            }
        }
    }

    Matrix** result = (Matrix**)malloc(3 * sizeof(Matrix*));
    result[0] = matrix1;
    result[1] = matrix2;
    result[2] = matrix3;
    return result;
}

void print_matrix(Matrix* matrix) {
    if (matrix == NULL)
        return;
    if (matrix->cols < 1 || matrix->rows < 1)
        return;
    printf("\n");
    size_t i = 0;
    for (; i < matrix->rows; ++i) {
        size_t j = 0;
        for (; j < matrix->cols; ++j) {
            printf("%3.3lf ", matrix->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_matrices_for_equality(Matrix* matrix1, Matrix* matrix2) {
    if (matrix1 == NULL || matrix2 == NULL)
        return 0;

    if (!(matrix1->rows == matrix2->rows && matrix1->cols == matrix2->cols))
        return 0;

    int i = 0;
    for (; i < matrix1->rows; ++i) {
        int j = 0;
        for (; j < matrix1->cols; ++j) {
            if (matrix1->data[i][j] != matrix2->data[i][j])
                return 0;
        }
    }
    return 1;
}
