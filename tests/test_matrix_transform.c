/*
Authored by paulo-santana <psergio-@student.42sp.org.br>
Copied and modified by vcwild <vcwild@gmail.com> without strict licensing permission.
*/

#include "munit/munit.h"
#include "minirt.h"

MunitResult matrix_transform_test1(const MunitParameter params[], void *fixture)
{
	t_matrix *transform = translation(5, -3, 2);
	t_tuple *p = new_point(-3, 4, 5);

	t_tuple *result = matrix_multiply_tuple(transform, p);
	t_tuple *expected = new_point(2, 1, 7);

	munit_assert_true(tuple_equals(result, expected));

	free(transform);
	free(p);
	free(result);
	free(expected);
	return (MUNIT_OK);
}


MunitResult matrix_transform_test2(const MunitParameter params[], void *fixture)
{
	t_matrix *transform = translation(5, -3, 2);
	t_matrix *inv = invert(transform);
	t_tuple *p = new_point(-3, 4, 5);

	t_tuple *result = matrix_multiply_tuple(inv, p);
	t_tuple *expected = new_point(-8, 7, 3);

	munit_assert_true(tuple_equals(result, expected));

	free(transform);
	free(p);
	free(inv);
	free(result);
	free(expected);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test3(const MunitParameter params[], void *fixture)
{
	t_matrix *transform = translation(5, -3, 2);
	t_tuple *p = new_vector(-3, 4, 5);

	t_tuple *result = matrix_multiply_tuple(transform, p);
	t_tuple *expected = new_vector(-3, 4, 5);

	munit_assert_true(tuple_equals(result, expected));

	free(transform);
	free(p);
	free(result);
	free(expected);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test4(const MunitParameter params[], void *fixture)
{
	t_matrix *transform = scaling(2, 3, 4);
	t_tuple *p = new_point(-4, 6, 8);
	t_tuple *expected = new_point(-8, 18, 32);

	t_tuple *result = matrix_multiply_tuple(transform, p);

	munit_assert_true(tuple_equals(result, expected));

	free(transform);
	free(p);
	free(result);
	free(expected);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test5(const MunitParameter params[], void *fixture)
{
	t_matrix *transform = scaling(2, 3, 4);
	t_tuple *v = new_vector(-4, 6, 8);
	t_tuple *expected = new_vector(-8, 18, 32);

	t_tuple *result = matrix_multiply_tuple(transform, v);

	munit_assert_true(tuple_equals(result, expected));

	free(transform);
	free(v);
	free(result);
	free(expected);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test6(const MunitParameter params[], void *fixture)
{
	t_matrix *transform = scaling(2, 3, 4);
	t_matrix *inv = invert(transform);
	t_tuple *v = new_vector(-4, 6, 8);
	t_tuple *expected = new_vector(-2, 2, 2);

	t_tuple *result = matrix_multiply_tuple(inv, v);

	munit_assert_true(tuple_equals(result, expected));

	free(transform);
	free(v);
	free(inv);
	free(result);
	free(expected);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test7(const MunitParameter params[], void *fixture)
{
	t_tuple *p = new_point(0, 1, 0);
	t_matrix *half_quarter = rotation_x(M_PI_4);
	t_matrix *full_quarter = rotation_x(M_PI_2);

	t_tuple *half_quarter_expected = new_point(0, M_SQRT2 / 2, M_SQRT2 / 2);
	t_tuple *full_quarter_expected = new_point(0, 0, 1);

	t_tuple *half_quarter_result = matrix_multiply_tuple(half_quarter, p);
	t_tuple *full_quarter_result = matrix_multiply_tuple(full_quarter, p);

	munit_assert_true(tuple_equals(half_quarter_result, half_quarter_expected));
	munit_assert_true(tuple_equals(full_quarter_result, full_quarter_expected));

	free(p);
	free(half_quarter);
	free(full_quarter);
	free(half_quarter_expected);
	free(full_quarter_expected);
	free(half_quarter_result);
	free(full_quarter_result);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test8(const MunitParameter params[], void *fixture)
{
	t_tuple *p = new_point(0, 1, 0);
	t_matrix *half_quarter = rotation_x(M_PI_4);
	t_matrix *inv = invert(half_quarter);

	t_tuple *expected = new_point(0, M_SQRT2 / 2, -M_SQRT2 / 2);

	t_tuple *result = matrix_multiply_tuple(inv, p);

	munit_assert_true(tuple_equals(result, expected));

	free(half_quarter);
	free(p);
	free(inv);
	free(result);
	free(expected);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test9(const MunitParameter params[], void *fixture)
{
	t_tuple *p = new_point(0, 0, 1);
	t_matrix *half_quarter = rotation_y(M_PI_4);
	t_matrix *full_quarter = rotation_y(M_PI_2);

	t_tuple *half_quarter_expected = new_point(M_SQRT2 / 2, 0, M_SQRT2 / 2);
	t_tuple *full_quarter_expected = new_point(1, 0, 0);

	t_tuple *half_quarter_result = matrix_multiply_tuple(half_quarter, p);
	t_tuple *full_quarter_result = matrix_multiply_tuple(full_quarter, p);

	munit_assert_true(tuple_equals(half_quarter_result, half_quarter_expected));
	munit_assert_true(tuple_equals(full_quarter_result, full_quarter_expected));

	free(p);
	free(half_quarter);
	free(full_quarter);
	free(half_quarter_expected);
	free(full_quarter_expected);
	free(half_quarter_result);
	free(full_quarter_result);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test10(const MunitParameter params[], void *fixture)
{
	t_tuple *p = new_point(0, 1, 0);
	t_matrix *half_quarter = rotation_z(M_PI_4);
	t_matrix *full_quarter = rotation_z(M_PI_2);

	t_tuple *half_quarter_expected = new_point(-M_SQRT2 / 2, M_SQRT2 / 2, 0);
	t_tuple *full_quarter_expected = new_point(-1, 0, 0);

	t_tuple *half_quarter_result = matrix_multiply_tuple(half_quarter, p);
	t_tuple *full_quarter_result = matrix_multiply_tuple(full_quarter, p);

	munit_assert_true(tuple_equals(half_quarter_result, half_quarter_expected));
	munit_assert_true(tuple_equals(full_quarter_result, full_quarter_expected));

	free(p);
	free(half_quarter);
	free(full_quarter);
	free(half_quarter_expected);
	free(full_quarter_expected);
	free(half_quarter_result);
	free(full_quarter_result);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test11(const MunitParameter params[], void *fixture)
{
	t_tuple *p = new_point(1, 0, 1);
	t_matrix *A = rotation_x(M_PI_2);
	t_matrix *B = scaling(5, 5, 5);
	t_matrix *C = translation(10, 5, 7);

	t_tuple *p2 = matrix_multiply_tuple(A, p);
	t_tuple *p2_expected = new_point(1, -1, 0);
	munit_assert_true(tuple_equals(p2, p2_expected));

	t_tuple *p3 = matrix_multiply_tuple(B, p2);
	t_tuple *p3_expected = new_point(5, -5, 0);
	munit_assert_true(tuple_equals(p3, p3_expected));

	t_tuple *p4 = matrix_multiply_tuple(C, p3);
	t_tuple *p4_expected = new_point(15, 0, 7);
	munit_assert_true(tuple_equals(p4, p4_expected));

	free(p);
	free(A);
	free(B);
	free(C);
	free(p2);
	free(p3);
	free(p4);
	free(p2_expected);
	free(p3_expected);
	free(p4_expected);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test12(const MunitParameter params[], void *fixture)
{
	t_tuple *p = new_point(1, 0, 1);
	t_matrix *A = rotation_x(M_PI_2);
	t_matrix *B = scaling(5, 5, 5);
	t_matrix *C = translation(10, 5, 7);

	t_matrix *T = matrix_multiply_3(A, B, C);

	t_tuple *p2 = matrix_multiply_tuple(T, p);
	t_tuple *p2_expected = new_point(15, 0, 7);

	munit_assert_true(tuple_equals(p2, p2_expected));

	free(p);
	free(A);
	free(B);
	free(C);
	free(T);
	free(p2);
	free(p2_expected);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test13(const MunitParameter params[], void *fixture)
{
	t_tuple *p = new_point(1, 0, 1);
	t_matrix *A = rotation_x(M_PI_2);
	t_matrix *B = scaling(5, 5, 5);
	t_matrix *C = translation(10, 5, 7);

	t_matrix **Ts = malloc(sizeof(t_matrix *) * 4);
	Ts[0] = A;
	Ts[1] = B;
	Ts[2] = C;
	Ts[3] = NULL;
	t_matrix *T = matrix_multiply_n(Ts);

	t_tuple *p2 = matrix_multiply_tuple(T, p);
	t_tuple *p2_expected = new_point(15, 0, 7);
	munit_assert_true(tuple_equals(p2, p2_expected));

	free(p);
	free(A);
	free(B);
	free(C);
	free(T);
	free(Ts);
	free(p2);
	free(p2_expected);
	return (MUNIT_OK);
}

// The below content comes from chapter 7 of the book.
MunitResult matrix_transform_test14(const MunitParameter params[], void *fixture)
{
	t_tuple *from = new_point(0, 0, 0);
	t_tuple *to = new_point(0, 0, -1);
	t_tuple *up = new_vector(0, 1, 0);
	t_matrix *t = view_transform(from, to, up);

	t_matrix *expected = identity_matrix();

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			munit_assert_float(t->data[i][j], ==, expected->data[i][j]);
		}
	}
	free(from);
	free(to);
	free(up);
	free(t);
	free(expected);
	return (MUNIT_OK);
}


MunitResult matrix_transform_test15(const MunitParameter params[], void *fixture)
{
	t_tuple *from = new_point(0, 0, 0);
	t_tuple *to = new_point(0, 0, 1);
	t_tuple *up = new_vector(0, 1, 0);
	t_matrix *t = view_transform(from, to, up);

	t_matrix *expected = scaling(-1, 1, -1);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			munit_assert_float(round_to(t->data[i][j]), ==, expected->data[i][j]);
		}
	}
	free(expected);
	free(t);
	free(up);
	free(to);
	free(from);
	return (MUNIT_OK);
}


MunitResult matrix_transform_test16(const MunitParameter params[], void *fixture)
{
	t_tuple *from = new_point(0, 0, 8);
	t_tuple *to = new_point(0, 0, 0);
	t_tuple *up = new_vector(0, 1, 0);
	t_matrix *t = view_transform(from, to, up);

	t_matrix *expected = translation(0, 0, -8);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			munit_assert_float(t->data[i][j], ==, expected->data[i][j]);
		}
	}
	free(expected);
	free(t);
	free(up);
	free(to);
	free(from);
	return (MUNIT_OK);
}

MunitResult matrix_transform_test17(const MunitParameter params[], void *fixture)
{
	t_tuple *from = new_point(1, 3, 2);
	t_tuple *to = new_point(4, -2, 8);
	t_tuple *up = new_vector(1, 1, 0);
	t_matrix *t = view_transform(from, to, up);

	t_matrix *expected = new_matrix(4, (double[4][4]){
		{ -0.50709, 0.50709,  0.67612, -2.36643},
		{  0.76772, 0.60609,  0.12122, -2.82843},
		{ -0.35857, 0.59761, -0.71714,  0.00000},
		{  0.00000, 0.00000,  0.00000,  1.00000},
	});

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			munit_assert_float(round_to(t->data[i][j]), ==, expected->data[i][j]);
		}
	}

	free(expected);
	free(t);
	free(up);
	free(to);
	free(from);
	return (MUNIT_OK);
}
