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
    ASSERT_EQ(NULL, create_matrix_from_file(file_path));
    remove(file_path);
}