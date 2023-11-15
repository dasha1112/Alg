#include "Matrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length) {
    ASSERT_NO_THROW(TMatrix<int> m(5, 6));
}


TEST(TMatrix, throws_when_create_matrix_with_negative_length) {
	ASSERT_ANY_THROW(TMatrix<int> m(-5, 0));
}

TEST(TMatrix, can_create_copied_matrix) {
	TMatrix<int> m(5, 2);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one) {
	TMatrix<int> m(5, 2);
	TMatrix<int> n(1, 3);
	EXPECT_NE(m, n);
	n = TMatrix<int>(m);
	EXPECT_EQ(m, n);
}

TEST(TMatrix, can_sum_matrix)
{
	TMatrix<int> matrix(3, 3);
	matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
	matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
	matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

	TMatrix<int> result = matrix + 1;
	ASSERT_EQ(result[0][0], 2);
	ASSERT_EQ(result[0][1], 3);
	ASSERT_EQ(result[0][2], 4);
	ASSERT_EQ(result[1][0], 5);
	ASSERT_EQ(result[1][1], 6);
	ASSERT_EQ(result[1][2], 7);
	ASSERT_EQ(result[2][0], 8);
	ASSERT_EQ(result[2][1], 9);
	ASSERT_EQ(result[2][2], 10);
}

TEST(TMatrix, can_sum_matrixs)
{
	TMatrix<int> matrix(3, 3);
	matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
	matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
	matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

	TMatrix<int> matrix_1(3, 3);
	matrix_1[0][0] = 1; matrix_1[0][1] = 2; matrix_1[0][2] = 3;
	matrix_1[1][0] = 4; matrix_1[1][1] = 5; matrix_1[1][2] = 6;
	matrix_1[2][0] = 7; matrix_1[2][1] = 8; matrix_1[2][2] = 9;

	TMatrix<int> result = matrix + matrix_1;
	ASSERT_EQ(result[0][0], 2);
	ASSERT_EQ(result[0][1], 4);
	ASSERT_EQ(result[0][2], 6);
	ASSERT_EQ(result[1][0], 8);
	ASSERT_EQ(result[1][1], 10);
	ASSERT_EQ(result[1][2], 12);
	ASSERT_EQ(result[2][0], 14);
	ASSERT_EQ(result[2][1], 16);
	ASSERT_EQ(result[2][2], 18);
}

TEST(TMatrix, can_min_matrixs)
{
	TMatrix<int> matrix(3, 3);
	matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
	matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
	matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

	TMatrix<int> matrix_1(3, 3);
	matrix_1[0][0] = 1; matrix_1[0][1] = 2; matrix_1[0][2] = 3;
	matrix_1[1][0] = 4; matrix_1[1][1] = 5; matrix_1[1][2] = 6;
	matrix_1[2][0] = 7; matrix_1[2][1] = 8; matrix_1[2][2] = 9;

	TMatrix<int> result = matrix - matrix_1;
	ASSERT_EQ(result[0][0], 0);
	ASSERT_EQ(result[0][1], 0);
	ASSERT_EQ(result[0][2], 0);
	ASSERT_EQ(result[1][0], 0);
	ASSERT_EQ(result[1][1], 0);
	ASSERT_EQ(result[1][2], 0);
	ASSERT_EQ(result[2][0], 0);
	ASSERT_EQ(result[2][1], 0);
	ASSERT_EQ(result[2][2], 0);
}

TEST(TMatrix, can_multiply_matrices)
{
	TMatrix<int> matrix1(2, 2);
	matrix1[0][0] = 1; matrix1[0][1] = 2;
	matrix1[1][0] = 3; matrix1[1][1] = 4;

	TMatrix<int> matrix2(2, 2);
	matrix2[0][0] = 5; matrix2[0][1] = 6;
	matrix2[1][0] = 7; matrix2[1][1] = 8;

	TMatrix<int> result = matrix1 * matrix2;

	ASSERT_EQ(result[0][0], 19);
	ASSERT_EQ(result[0][1], 22);
	ASSERT_EQ(result[1][0], 43);
	ASSERT_EQ(result[1][1], 50);
}

TEST(TMatrix, can_detect_error_on_invalid_multiplication)
{
	TMatrix<int> matrix1(1, 3);
	TMatrix<int> matrix2(3, 2);

	try {
		TMatrix<int> result = matrix1 * matrix2;
		FAIL() << "Expected an error"; 
	}
	catch (const char* error) {
		EXPECT_STREQ("Îøèáêà", error); 
	}
	catch (...) {
		FAIL() << "Expected a specific error"; 
	}
}