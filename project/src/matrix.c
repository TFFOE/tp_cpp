#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

enum FUNCTION_RETURN_INFO {
    FAILURE = -1,
    SUCCESS = 0
};

Matrix* create_matrix(size_t rows, size_t cols) {
    if (rows < 1 || cols < 1)
        return NULL;
    Matrix* matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * sizeof(double*));
    for (size_t i = 0; i < rows; ++i) {
        matrix->data[i] = malloc(cols * sizeof(double));
    }
    return matrix;
}

Matrix* create_matrix_from_file(const char* path_file) {
    if (path_file == NULL)
        return NULL;
    FILE* matrix_file = fopen(path_file, "r");
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
    for (size_t i = 0; i < matrix->rows; ++i)
        free(matrix->data[i]);
    free(matrix->data);
    free(matrix);
    return SUCCESS;
}

Matrix* split_matrix(Matrix* matrix) {
    
}