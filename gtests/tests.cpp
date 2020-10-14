#include "matrix.h"
#include <gtest/gtest.h>

TEST(MatrixCreatingFromFileTest, NullPath) {
    ASSERT_EQ(NULL, create_matrix_from_file(NULL));
}

TEST(MatrixCreatingFromFileTest, EmptyPath) {
    ASSERT_EQ(NULL, create_matrix_from_file(""));
}

TEST(MatrixCreatingFromFileTest, NonExistentFile) {
    ASSERT_EQ(NULL, create_matrix_from_file("121481238.834838"));
    ASSERT_EQ(NULL, create_matrix_from_file("hello.world"));
    ASSERT_EQ(NULL, create_matrix_from_file("pretty-non.existent-file"));
}

TEST(MatrixCreatingFromFileTest, EmptyFile) {
    const char* file_path = "new_matrix_file_for_test_123123123123123.mat";
    FILE* new_matrix_file = fopen(file_path, "w+");
    fclose(new_matrix_file);
    ASSERT_EQ(NULL, create_matrix_from_file(file_path));
    remove(file_path);
}

TEST(MatrixCreatingFromFileTest, EmptyFileLine) {
    const char* file_path = "new_matrix_file_for_test_123123123123456.mat";
    FILE* new_matrix_file = fopen(file_path, "w+");
    fprintf(new_matrix_file, "1 1\n");
    fclose(new_matrix_file);
    ASSERT_EQ(NULL, create_matrix_from_file(file_path));
    remove(file_path);
}

TEST(MatrixCreatingTest, RowsColsCheck) {
    Matrix* matrix = create_matrix(5, 10);
    ASSERT_EQ(5, matrix->rows);
    ASSERT_EQ(10, matrix->cols);
    free_matrix(matrix);
}

TEST(MatrixCreatingFromFileTest, MatrixReadCheck) {
    const char* file_path = "new_matrix_file_for_test_123123123456123.mat";
    FILE* new_matrix_file = fopen(file_path, "w+");
    fprintf(new_matrix_file, "2 3\n4 5 6\n7 8 9\n");
    fclose(new_matrix_file);

    Matrix* matrix1 = create_matrix_from_file(file_path);
    Matrix* matrix2 = create_matrix(2, 3);
    matrix2->data[1][0] = 4;
    matrix2->data[1][1] = 5;
    matrix2->data[1][2] = 6;
    matrix2->data[2][0] = 7;
    matrix2->data[2][1] = 8;
    matrix2->data[2][2] = 9;

    ASSERT_EQ(0, check_matrices_for_equality(matrix1, matrix2));
    remove(file_path);
    free_matrix(matrix1);
    free_matrix(matrix2);
}

TEST(SplitMatrixTest, MainCheck) {
    Matrix* matrix = create_matrix(1, 3);
    matrix->data[0][0] = 1;
    matrix->data[0][1] = 2;
    matrix->data[0][2] = 3;
    
    Matrix** splitted_matrices = split_matrix(matrix);
    ASSERT_EQ(1, splitted_matrices[0]->data[0][0]);
    ASSERT_EQ(2, splitted_matrices[1]->data[0][0]);
    ASSERT_EQ(3, splitted_matrices[2]->data[0][0]);
}