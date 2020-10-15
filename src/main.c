#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(int argc, char** argv) {
    Matrix* matrix = create_matrix_from_file("../matrix.mat");
    if (!matrix) {
        free_matrix(matrix);
        return 0;
    }

    Matrix** matrices = split_matrix(matrix);

    print_matrix(matrix);

    print_matrix(matrices[0]);
    print_matrix(matrices[1]);
    print_matrix(matrices[2]);

    free_matrix(matrix);
    free_matrix(matrices[0]);
    free_matrix(matrices[1]);
    free_matrix(matrices[2]);
    free(matrices);

    return 0;
}