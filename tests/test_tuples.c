#include "munit/munit.h"
#include <tuple.h>
#include <canvas.h>
#include <math.h>

MunitResult tuple_test1(const MunitParameter params[], void *fixture)
{
	t_tuple *a = new_tuple(4.3, -4.2, 3.1, 1);

	munit_assert_float(a->x, ==, 4.3);
	munit_assert_float(a->y, ==, -4.2);
	munit_assert_float(a->z, ==, 3.1);
	munit_assert_float(a->w, ==, 1.0);
	munit_assert_true(is_point(a));
	munit_assert_false(is_vector(a));
	free(a);
	return (MUNIT_OK);
}

MunitResult tuple_test2(const MunitParameter params[], void *fixture)
{
	t_tuple *a = new_tuple(4.3, -4.2, 3.1, 0);

	munit_assert_float(a->x, ==, 4.3);
	munit_assert_float(a->y, ==, -4.2);
	munit_assert_float(a->z, ==, 3.1);
	munit_assert_float(a->w, ==, 0.0);
	munit_assert_false(is_point(a));
	munit_assert_true(is_vector(a));
	free(a);
	return (MUNIT_OK);
}

MunitResult tuple_test3(const MunitParameter params[], void *fixture)
{
	t_tuple *result = new_point(4.3, -4.2, 3.1);
	t_tuple *expected = new_tuple(4.3, -4.2, 3.1, 1.0);

	munit_assert_true(tuple_equals(result, expected));
	free(result);
	free(expected);
	return (MUNIT_OK);
}

MunitResult tuple_test4(const MunitParameter params[], void *fixture)
{
	t_tuple *result = new_vector(4.3, -4.2, 3.1);
	t_tuple *expected = new_tuple(4.3, -4.2, 3.1, 0.0);

	munit_assert_true(tuple_equals(result, expected));
	free(result);
	free(expected);
	return (MUNIT_OK);
}

MunitResult tuple_test5(const MunitParameter params[], void *fixture)
{
	t_tuple *a = new_tuple(3, -2 , 5, 1);
	t_tuple *b = new_tuple(-2, 3 , 1, 0);

	t_tuple *result = add_tuples(a, b);
	t_tuple *expected = new_tuple(1, 1, 6, 1);

	munit_assert_true(tuple_equals(result, expected));
	free(result);
	free(expected);
	free(a);
	free(b);
	return (MUNIT_OK);
}

MunitResult tuple_test6(const MunitParameter params[], void *fixture)
{
	t_tuple *a = new_tuple(3, -2 , 5, 0);
	t_tuple *b = new_tuple(-2, 3 , -1, 0);

	t_tuple *result = add_tuples(a, b);
	t_tuple *expected = new_tuple(1, 1, 4, 0);

	munit_assert_true(tuple_equals(result, expected));
	free(result);
	free(expected);
	free(a);
	free(b);
	return (MUNIT_OK);
}

MunitResult tuple_test7(const MunitParameter params[], void *fixture)
{
	t_tuple *a = new_tuple(3, -2 , 5, 1);
	t_tuple *b = new_tuple(-2, 3 , -1, 1);

	t_tuple *result = add_tuples(a, b);

	munit_assert_false(is_point(result));
	munit_assert_false(is_vector(result));
	free(result);
	free(a);
	free(b);
	return (MUNIT_OK);
}

MunitResult tuple_test8(const MunitParameter params[], void *fixture)
{
	t_tuple *a = new_point(3, 2, 1);
	t_tuple *b = new_point(5, 6, 7);

	t_tuple *result = subtract_tuples(a, b);
	t_tuple *expected = new_vector(-2, -4, -6);

	munit_assert_true(tuple_equals(result, expected));
	free(result);
	free(expected);
	free(a);
	free(b);
	return (MUNIT_OK);
}

MunitResult tuple_test9(const MunitParameter params[], void *fixture)
{
	t_tuple *a = new_point(3, 2, 1);
	t_tuple *b = new_vector(5, 6, 7);

	t_tuple *result = subtract_tuples(a, b);
	t_tuple *expected = new_point(-2, -4, -6);

	munit_assert_true(tuple_equals(result, expected));
	free(result);
	free(expected);
	free(a);
	free(b);
	return (MUNIT_OK);
}

MunitResult tuple_test10(const MunitParameter params[], void *fixture)
{
	t_tuple *a = new_tuple(1, -2, 3, -4);

	t_tuple *result = negate_tuple(a);
	t_tuple *expected = new_tuple(-1, 2, -3, 4);

	munit_assert_true(tuple_equals(result, expected));
	free(result);
	free(expected);
	free(a);
	return (MUNIT_OK);
}

MunitResult tuple_test11(const MunitParameter params[], void *fixture)
{
	t_tuple *a = new_tuple(1, -2, 3, -4);

	t_tuple *result = multiply_scalar(a, 3.5);
	t_tuple *expected = new_tuple(3.5, -7, 10.5, -14);

	munit_assert_true(tuple_equals(result, expected));
	free(result);
	free(expected);
	free(a);
	return (MUNIT_OK);
}

MunitResult tuple_test12(const MunitParameter params[], void *fixture)
{
	t_tuple *a = new_tuple(1, -2, 3, -4);

	t_tuple *result = multiply_scalar(a, 0.5);
	t_tuple *expected = new_tuple(0.5, -1, 1.5, -2);

	munit_assert_true(tuple_equals(result, expected));
	free(result);
	free(expected);
	free(a);
	return (MUNIT_OK);
}

MunitResult tuple_test13(const MunitParameter params[], void *fixture)
{
	t_tuple *a = new_tuple(1, -2, 3, -4);

	t_tuple *result = divide_scalar(a, 2);
	t_tuple *expected = new_tuple(0.5, -1, 1.5, -2);

	munit_assert_true(tuple_equals(result, expected));
	free(result);
	free(expected);
	free(a);
	return (MUNIT_OK);
}

MunitResult tuple_test14(const MunitParameter params[], void *fixture)
{
	float result, expected;
	t_tuple *a;

	a = new_vector(1, 0, 0);
	result = magnitude(a);
	expected = 1.0;
	munit_assert_float(result, ==, expected);
	free(a);

	a = new_vector(0, 1, 0);
	result = magnitude(a);
	expected = 1.0;
	munit_assert_float(result, ==, expected);
	free(a);

	a = new_vector(0, 0, 1);
	result = magnitude(a);
	expected = 1.0;
	munit_assert_float(result, ==, expected);
	free(a);

	a = new_vector(1, 2, 3);
	result = magnitude(a);
	expected = sqrt(14);
	munit_assert_float(result, ==, expected);
	free(a);

	a = new_vector(-1, -2, -3);
	result = magnitude(a);
	expected = sqrt(14);
	munit_assert_float(result, ==, expected);
	free(a);
	return (MUNIT_OK);
}


MunitResult tuple_test15(const MunitParameter params[], void *fixture)
{
	t_tuple *a, *norm, *expected;

	a = new_vector(4, 0, 0);
	norm = normalize(a);
	expected = new_vector(1, 0, 0);
	munit_assert_true(tuple_equals(norm, expected));
	free(a);
	free(norm);
	free(expected);

	a = new_vector(1, 2, 3);
	norm = normalize(a);
	expected = new_vector(0.26726, 0.53452, 0.80178);
	munit_assert_true(tuple_equals(norm, expected));
	free(a);
	free(norm);
	free(expected);

	return (MUNIT_OK);
}

MunitResult tuple_test16(const MunitParameter params[], void *fixture)
{
	t_tuple *a, *norm;

	a = new_vector(1, 2, 3);
	norm = normalize(a);
	munit_assert_true(dequals(magnitude(norm), 1));
	free(a);
	free(norm);

	return (MUNIT_OK);
}

MunitResult tuple_test17(const MunitParameter params[], void *fixture)
{
	t_tuple *a, *b;

	a = new_vector(1, 2, 3);
	b = new_vector(2, 3, 4);
	munit_assert_float(dot(a, b), ==, 20);
	free(a);
	free(b);

	return (MUNIT_OK);
}

MunitResult tuple_test18(const MunitParameter params[], void *fixture)
{
	t_tuple *a, *b, *expected, *result;

	a = new_vector(1, 2, 3);
	b = new_vector(2, 3, 4);
	result = cross(a, b);
	expected = new_vector(-1, 2, -1);
	munit_assert_true(tuple_equals(result, expected));
	free(expected);
	free(result);

	result = cross(b, a);
	expected = new_vector(1, -2, 1);
	munit_assert_true(tuple_equals(result, expected));
	free(expected);
	free(result);
	free(a);
	free(b);

	return (MUNIT_OK);
}

MunitResult tuple_test19(const MunitParameter params[], void *fixture)
{
	t_color	*color;

	color = new_color(-0.5, 0.4, 1.7);
	munit_assert_float(color->r, ==, -0.5);
	munit_assert_float(color->g, ==, 0.4);
	munit_assert_float(color->b, ==, 1.7);
	free(color);
	return (MUNIT_OK);
}

MunitResult tuple_test20(const MunitParameter params[], void *fixture)
{
	t_color	*a, *b, *result, *expected;

	a = new_color(0.9, 0.6, 0.75);
	b = new_color(0.7, 0.1, 0.25);
	result = add_colors(a, b);
	expected = new_color(1.6, 0.7, 1);
	munit_assert_true(dequals(result->r, expected->r));
	munit_assert_true(dequals(result->g, expected->g));
	munit_assert_true(dequals(result->b, expected->b));
	free(a);
	free(result);
	free(expected);
	free(b);
	return (MUNIT_OK);
}

MunitResult tuple_test21(const MunitParameter params[], void *fixture)
{
	t_color	*a, *b, *result, *expected;

	a = new_color(0.9, 0.6, 0.75);
	b = new_color(0.7, 0.1, 0.25);
	result = subtract_colors(a, b);
	expected = new_color(0.2, 0.5, 0.5);
	munit_assert_true(dequals(result->r, expected->r));
	munit_assert_true(dequals(result->g, expected->g));
	munit_assert_true(dequals(result->b, expected->b));
	free(a);
	free(result);
	free(expected);
	free(b);
	return (MUNIT_OK);
}

MunitResult tuple_test22(const MunitParameter params[], void *fixture)
{
	t_color	*a, *result, *expected;

	a = new_color(0.2, 0.3, 0.4);
	result = multiply_scalar_color(a, 2);
	expected = new_color(0.4, 0.6, 0.8);
	munit_assert_true(dequals(result->r, expected->r));
	munit_assert_true(dequals(result->g, expected->g));
	munit_assert_true(dequals(result->b, expected->b));
	free(a);
	free(result);
	free(expected);
	return (MUNIT_OK);
}

MunitResult tuple_test23(const MunitParameter params[], void *fixture)
{
	t_color	*a, *b, *result, *expected;

	a = new_color(1, 0.2, 0.4);
	b = new_color(0.9, 1, 0.1);
	result = multiply_colors(a, b);
	expected = new_color(0.9, 0.2, 0.04);
	munit_assert_true(dequals(result->r, expected->r));
	munit_assert_true(dequals(result->g, expected->g));
	munit_assert_true(dequals(result->b, expected->b));
	free(a);
	free(b);
	free(result);
	free(expected);
	return (MUNIT_OK);
}

// reflecting a vector approaching at 45º
MunitResult tuple_test24(const MunitParameter params[], void *fixture)
{
	t_tuple *v, *n, *result, *expected;

	v = new_vector(1, -1, 0);
	n = new_vector(0, 1, 0);
	expected = new_vector(1, 1, 0);

	result = reflect(v, n);

	munit_assert_true(tuple_equals(result, expected));

	free(v);
	free(n);
	free(result);
	free(expected);
	return (MUNIT_OK);
}

// reflecting a vector off a slanted surface
MunitResult tuple_test25(const MunitParameter params[], void *fixture)
{
	t_tuple *v, *n, *result, *expected;

	v = new_vector(0, -1, 0);
	n = new_vector(M_SQRT2 / 2, M_SQRT2 / 2, 0);
	expected = new_vector(1, 0, 0);

	result = reflect(v, n);

	munit_assert_true(tuple_equals(result, expected));

	free(v);
	free(n);
	free(result);
	free(expected);
	return (MUNIT_OK);
}
