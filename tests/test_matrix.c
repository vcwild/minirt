/*
Authored by paulo-santana <psergio-@student.42sp.org.br>
Copied and modified by vcwild <vcwild@gmail.com> without strict licensing permission.
*/

#include "munit/munit.h"
#include "minirt.h"

MunitResult matrix_test1(const MunitParameter params[], void *fixture)
{
	double	initial[4][4] = {
		{    1,    2,    3,    4 },
		{  5.5,  6.5,  7.5,  8.5 },
		{    9,   10,   11,   12 },
		{ 13.5, 14.5, 15.5, 16.5 },
	};
	t_matrix	*matrix = new_matrix(4, initial);
	munit_assert_float(matrix->data[0][0], ==, 1);
	munit_assert_float(matrix->data[0][3], ==, 4);
	munit_assert_float(matrix->data[1][0], ==, 5.5);
	munit_assert_float(matrix->data[1][2], ==, 7.5);
	munit_assert_float(matrix->data[2][2], ==, 11);
	munit_assert_float(matrix->data[3][0], ==, 13.5);
	munit_assert_float(matrix->data[3][2], ==, 15.5);
	free(matrix);
	return (MUNIT_OK);
}

MunitResult matrix_test2(const MunitParameter params[], void *fixture)
{
	double	same[4][4] = {
		{    1,    2,    3,    4 },
		{  5.5,  6.5,  7.5,  8.5 },
		{    9,   10,   11,   12 },
		{ 13.5, 14.5, 15.5, 16.5 },
	};
	double	different[4][4] = {
		{    1,    2,    3,    4 },
		{  5.5,  6.5,  7.5,  8.5 },
		{    9,   10,   11,   12 },
		{ 13.5, 14.5, 15.6, 16.5 },
	};
	t_matrix	*matrix1 = new_matrix(4, same);
	t_matrix	*matrix2 = new_matrix(4, same);
	t_matrix	*matrix3 = new_matrix(4, different);

	munit_assert_true(matrix_equals(matrix1, matrix2));
	munit_assert_false(matrix_equals(matrix1, matrix3));
	munit_assert_false(matrix_equals(matrix2, matrix3));
	free(matrix1);
	free(matrix2);
	free(matrix3);
	return (MUNIT_OK);
}

MunitResult matrix_test3(const MunitParameter params[], void *fixture)
{
	double	same[4][4] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};
	double	different[4][4] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 8 },
	};
	t_matrix	*matrix1 = new_matrix(3, same);
	t_matrix	*matrix2 = new_matrix(3, same);
	t_matrix	*matrix3 = new_matrix(3, different);

	munit_assert_true(matrix_equals(matrix1, matrix2));
	munit_assert_false(matrix_equals(matrix1, matrix3));
	munit_assert_false(matrix_equals(matrix2, matrix3));
	free(matrix1);
	free(matrix2);
	free(matrix3);
	return (MUNIT_OK);
}

MunitResult matrix_test4(const MunitParameter params[], void *fixture)
{
	double	same[4][4] = {
		{ 1, 2 },
		{ 4, 5 },
	};
	double	different[4][4] = {
		{ 1, 2 },
		{ 4, 6 },
	};
	t_matrix	*matrix1 = new_matrix(2, same);
	t_matrix	*matrix2 = new_matrix(2, same);
	t_matrix	*matrix3 = new_matrix(2, different);

	munit_assert_true(matrix_equals(matrix1, matrix2));
	munit_assert_false(matrix_equals(matrix1, matrix3));
	munit_assert_false(matrix_equals(matrix2, matrix3));
	free(matrix1);
	free(matrix2);
	free(matrix3);
	return (MUNIT_OK);
}


MunitResult matrix_test5(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double[4][4]) {
			{ 1 , 2 , 3 , 4 },
			{ 5 , 6 , 7 , 8 },
			{ 9 , 8 , 7 , 6 },
			{ 5 , 4 , 3 , 2 },
			});
	t_matrix *b = new_matrix(4, (double[4][4]) {
			{ -2, 1, 2, 3 },
			{  3, 2, 1, -1},
			{  4, 3, 6, 5 },
			{  1, 2, 7, 8 },
			});
	t_matrix *expected = new_matrix(4, (double[4][4]) {
			{ 20, 22 , 50 , 48 },
			{ 44, 54 , 114, 108},
			{ 40, 58 , 110, 102},
			{ 16, 26 , 46 , 42 },
			});

	t_matrix *result = matrix_multiply(a, b);
	munit_assert_true(matrix_equals(result, expected));
	free(a);
	free(b);
	free(result);
	free(expected);
	return (MUNIT_OK);
}

MunitResult matrix_test6(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double[4][4]) {
			{ 1 , 2 , 3 , 4 },
			{ 2 , 4 , 4 , 2 },
			{ 8 , 6 , 4 , 1 },
			{ 0 , 0 , 0 , 1 },
			});
	t_tuple *b = new_tuple(1, 2, 3, 1);
	t_tuple *expected = new_tuple(18, 24, 33, 1);

	t_tuple *result = matrix_multiply_tuple(a, b);
	munit_assert_true(tuple_equals(result, expected));
	free(a);
	free(b);
	free(result);
	free(expected);
	return (MUNIT_OK);
}

MunitResult matrix_test7(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double[4][4]) {
			{ 0 , 1 , 2 , 3 },
			{ 1 , 2 , 4 , 8 },
			{ 2 , 4 , 8 , 16 },
			{ 4 , 8 ,16 , 32 },
			});
	t_matrix *b = identity_matrix();

	t_matrix *result = matrix_multiply(a, b);
	munit_assert_true(matrix_equals(result, a));
	free(a);
	free(b);
	free(result);
	return (MUNIT_OK);
}

MunitResult matrix_test8(const MunitParameter params[], void *fixture)
{
	t_matrix *a = identity_matrix();
	t_tuple *b = new_tuple(1, 2, 3, 4);

	t_tuple *result = matrix_multiply_tuple(a, b);
	munit_assert_true(tuple_equals(result, b));
	free(a);
	free(b);
	free(result);
	return (MUNIT_OK);
}

MunitResult matrix_test9(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double [4][4]) {
		{ 0 , 9 , 3 , 0 },
		{ 9 , 8 , 0 , 8 },
		{ 1 , 8 , 5 , 3 },
		{ 0 , 0 , 5 , 8 },
	});

	t_matrix *expected = new_matrix(4, (double [4][4]) {
		{ 0 , 9 , 1 , 0 },
		{ 9 , 8 , 8 , 0 },
		{ 3 , 0 , 5 , 5 },
		{ 0 , 8 , 3 , 8 },
	});
	t_matrix *result = transpose(a);
	munit_assert_true(matrix_equals(result, expected));
	free(expected);
	free(a);
	free(result);
	return (MUNIT_OK);
}

MunitResult matrix_test10(const MunitParameter params[], void *fixture)
{
	t_matrix *a = identity_matrix();
	t_matrix *b = identity_matrix();
	t_matrix *result = transpose(a);
	munit_assert_true(matrix_equals(result, b));
	free(a);
	free(b);
	free(result);
	return (MUNIT_OK);
}

MunitResult matrix_test11(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(2, (double [4][4]){
			{ 1, 5},
			{-3, 2},
		});
	float result = matrix_determinant(a);
	munit_assert_float(result, ==, 17);
	free(a);
	return (MUNIT_OK);
}

MunitResult matrix_test12(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(3, (double[4][4]) {
			{ 1 , 5 , 0 },
			{ -3, 2 , 7 },
			{ 0 , 6 , -3},
			});
	t_matrix *expected = new_matrix(2, (double[4][4]) {
			{ -3, 2 },
			{ 0 , 6 },
			});

	t_matrix *result = submatrix(a, 0, 2);
	munit_assert_true(matrix_equals(result, expected));
	free(a);
	free(expected);
	free(result);
	return (MUNIT_OK);
}

MunitResult matrix_test13(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double[4][4]) {
			{ -6 , 1 , 1 , 6 },
			{ -8 , 5 , 8 , 6 },
			{ -1 , 0 , 8 , 2 },
			{ -7 , 1 , -1, 1 },
			});
	t_matrix *expected = new_matrix(3, (double[4][4]) {
			{ -6 , 1 , 6 },
			{ -8 , 8 , 6 },
			{ -7 ,-1 , 1 },
			});

	t_matrix *result = submatrix(a, 2, 1);
	// munit_assert_float(result->data[0][0], ==, expected->data[0][0]);
	// munit_assert_float(result->data[0][1], ==, expected->data[0][1]);
	// munit_assert_float(result->data[0][2], ==, expected->data[0][2]);
	// munit_assert_float(result->data[1][0], ==, expected->data[1][0]);
	// munit_assert_float(result->data[1][1], ==, expected->data[1][1]);
	// munit_assert_float(result->data[1][2], ==, expected->data[1][2]);
	// munit_assert_float(result->data[2][0], ==, expected->data[2][0]);
	// munit_assert_float(result->data[2][1], ==, expected->data[2][1]);
	// munit_assert_float(result->data[2][2], ==, expected->data[2][2]);

	munit_assert_true(matrix_equals(result, expected));
	free(expected);
	free(result);
	free(a);
	return (MUNIT_OK);
}

MunitResult matrix_test14(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(3, (double[4][4]) {
			{ 3 , 5 , 0 },
			{ 2 ,-1 ,-7 },
			{ 6 ,-1 , 5 },
			});

	float result = minor(a, 1, 0);
	munit_assert_float(result, ==, 25);
	free(a);
	return (MUNIT_OK);
}

MunitResult matrix_test15(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(3, (double[4][4]){
		{ 3 ,  5 ,  0 },
		{ 2 , -1 , -7 },
		{ 6 , -1 ,  5 },
		});

	munit_assert_float(minor(a, 0, 0), ==, -12);
	munit_assert_float(cofactor(a, 0, 0), ==, -12);
	munit_assert_float(minor(a, 1, 0), ==, 25);
	munit_assert_float(cofactor(a, 1, 0), ==, -25);
	free(a);
	return (MUNIT_OK);
}

MunitResult matrix_test16(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(3, (double[4][4]) {
			{ 1 , 2 , 6 },
			{ -5, 8 , -4},
			{ 2 , 6 , 4 },
			});
	munit_assert_float(cofactor(a, 0, 0), ==, 56);
	munit_assert_float(cofactor(a, 0, 1), ==, 12);
	munit_assert_float(cofactor(a, 0, 2), ==, -46);
	munit_assert_float(matrix_determinant(a), ==, -196);
	free(a);
	return (MUNIT_OK);
}

MunitResult matrix_test17(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double[4][4]){
			{ -2, -8,  3,  5 },
			{ -3,  1,  7,  3 },
			{  1,  2, -9,  6 },
			{ -6,  7,  7, -9 },
			});

	munit_assert_float(cofactor(a, 0, 0), ==, 690);
	munit_assert_float(cofactor(a, 0, 1), ==, 447);
	munit_assert_float(cofactor(a, 0, 2), ==, 210);
	munit_assert_float(cofactor(a, 0, 3), ==, 51);
	munit_assert_float(matrix_determinant(a), ==, -4071);
	free(a);
	return (MUNIT_OK);
}

MunitResult matrix_test18(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double[4][4]){
			{ 6 , 4 , 4 , 4 },
			{ 5 , 5 , 7 , 6 },
			{ 4 , -9, 3 , -7},
			{ 9 , 1 , 7 , -6},
			});
	munit_assert_float(matrix_determinant(a), ==, -2120);
	munit_assert_true(matrix_is_invertible(a));
	free(a);
	return (MUNIT_OK);
}

MunitResult matrix_test19(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double[4][4]){
			{ -4, 2 ,-2 , -3},
			{ 9 , 6 , 2 , 6 },
			{ 0 ,-5 , 1 , -5},
			{ 0 , 0 , 0 , 0 },
			});

	munit_assert_float(matrix_determinant(a), ==, 0);
	munit_assert_false(matrix_is_invertible(a));
	free(a);
	return (MUNIT_OK);
}

MunitResult matrix_test20(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double[4][4]){
			{-5 ,  2 ,  6 , -8 },
			{ 1 , -5 ,  1 ,  8 },
			{ 7 ,  7 , -6 , -7 },
			{ 1 , -3 ,  7 ,  4 },
			});

	t_matrix *expected = new_matrix(4, (double[4][4]){
			{  0.21805,  0.45113,  0.24060, -0.04511 },
			{ -0.80827, -1.45677, -0.44361,  0.52068 },
			{ -0.07895, -0.22368, -0.05263,  0.19737 },
			{ -0.52256, -0.81391, -0.30075,  0.30639 },
			});
 	t_matrix *b = invert(a);
	munit_assert_float(matrix_determinant(a), ==, 532);
	munit_assert_float(cofactor(a, 2, 3), ==, -160);
	munit_assert_float(b->data[3][2], ==, -160/532.0);
	munit_assert_float(cofactor(a, 3, 2), ==, 105);
	munit_assert_float(b->data[2][3], ==, 105/532.0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			munit_assert_float(round_to(b->data[i][j]), ==, expected->data[i][j]);
		}
	}
	free(a);
	free(b);
	free(expected);
	return (MUNIT_OK);
}

MunitResult matrix_test21(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double[4][4]){
			{  8, -5,  9,  2 },
			{  7,  5,  6,  1 },
			{ -6,  0,  9,  6 },
			{ -3,  0, -9, -4 },
			});
	t_matrix *expected = new_matrix(4, (double[4][4]){
			{ -0.15385, -0.15385, -0.28205, -0.53846 },
			{ -0.07692,  0.12308,  0.02564,  0.03077 },
			{  0.35897,  0.35897,  0.43590,  0.92308 },
			{ -0.69231, -0.69231, -0.76923, -1.92308 },
			});
	t_matrix *b = invert(a);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			munit_assert_float(round_to(b->data[i][j]), ==, expected->data[i][j]);
		}
	}
	// munit_assert_true(matrix_equals(b, expected));
	free(a);
	free(b);
	free(expected);
	return (MUNIT_OK);
}

MunitResult matrix_test22(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double[4][4]){
			{  9 ,  3 ,  0 ,  9 },
			{ -5 , -2 , -6 , -3 },
			{ -4 ,  9 ,  6 ,  4 },
			{ -7 ,  6 ,  6 ,  2 },
			});
	t_matrix *expected = new_matrix(4, (double[4][4]){
			{ -0.04074 , -0.07778 ,  0.14444 , -0.22222 },
			{ -0.07778 ,  0.03333 ,  0.36667 , -0.33333 },
			{ -0.02901 , -0.14630 , -0.10926 ,  0.12963 },
			{  0.17778 ,  0.06667 , -0.26667 ,  0.33333 },
			});
	t_matrix *b = invert(a);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			munit_assert_float(round_to(b->data[i][j]), ==, expected->data[i][j]);
		}
	}
	// munit_assert_true(matrix_equals(b, expected));
	free(a);
	free(b);
	free(expected);
	return (MUNIT_OK);
}

MunitResult matrix_test23(const MunitParameter params[], void *fixture)
{
	t_matrix *a = new_matrix(4, (double[4][4]){
			{  3 , -9 ,  7 ,  3 },
			{  3 , -8 ,  2 , -9 },
			{ -4 ,  4 ,  4 ,  1 },
			{ -6 ,  5 , -1 ,  1 },
			});
	t_matrix *b = new_matrix(4, (double[4][4]){
			{ 8 ,  2 , 2 , 2 },
			{ 3 , -1 , 7 , 0 },
			{ 7 ,  0 , 5 , 4 },
			{ 6 , -2 , 0 , 5 },
			});
	t_matrix *c = matrix_multiply(a, b);
	t_matrix *a_result = matrix_multiply(c, invert(b));

	munit_assert_true(matrix_equals(a_result, a));
	free(a);
	free(b);
	free(c);
	free(a_result);
	return (MUNIT_OK);
}

