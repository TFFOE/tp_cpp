#include "matrix.h"
#include <gtest/gtest.h>

TEST(MatrixCreatingTest, NullPath) {
    ASSERT_EQ(NULL, create_matrix_from_file(NULL));
}

TEST(MatrixCreatingTest, EmptyPath) {
    ASSERT_EQ(NULL, create_matrix_from_file(""));
}

TEST(MatrixCreatingTest, NonExistentFile) {
    ASSERT_EQ(NULL, create_matrix_from_file("121481238.834838"));
    ASSERT_EQ(NULL, create_matrix_from_file("hello.world"));
    ASSERT_EQ(NULL, create_matrix_from_file("pretty-non.existent-file"));
}

