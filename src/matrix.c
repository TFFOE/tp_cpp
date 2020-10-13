#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
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
    for (size_t i = 0; i < rows; ++i) {
        matrix->data[i] = (double*)malloc(cols * sizeof(double));
    }
    return matrix;
}

Matrix* create_matrix_from_file(const char* path_file) {
    assert(path_file == NULL && "PATH FILE IS NULL");
    if (path_file == NULL)
        return NULL;

    FILE* matrix_file = fopen(path_file, "r");
    assert(matrix_file == NULL && "MATRIX FILE IS NULL");
    if (matrix_file == NULL)
        return NULL;

    int rows, cols;
    if (fscanf(matrix_file, "%d %d", &rows, &cols) == -1) {
        fclose(matrix_file);
        return NULL;
    }

    Matrix* matrix = create_matrix(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            double value;
            if (fscanf(matrix_file, "%lf", &value) == -1) {
                fclose(matrix_file);
                free_matrix(matrix);
                return NULL;
            }
            matrix->data[i][j] = value;
        }
    fclose(matrix_file);
    return matrix;
}

int free_matrix(Matrix* matrix) {
    if (matrix == NULL)
        return SUCCESS;
    for (size_t i = 0; i < matrix->rows; ++i)
        free(matrix->data[i]);
    free(matrix->data);
    free(matrix);
    return SUCCESS;
}
Matrix** split_matrix(Matrix* matrix) {
    size_t rows = matrix->rows;
    size_t cols = matrix->cols;

    if (rows == 0 || cols == 0)
        return NULL;

    Matrix* matrix1 = create_matrix(rows, (cols + 2) / 3);
    Matrix* matrix2 = create_matrix(rows, (cols + 1) / 3);
    Matrix* matrix3 = create_matrix(rows, cols / 3);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
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
    for (size_t i = 0; i < matrix->rows; ++i) {
        for (size_t j = 0; j < matrix->cols; ++j) {
            printf("%3.3lf ", matrix->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
