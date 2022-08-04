#include "matrix/matrix.h"
#include "munit/munit.h"
#include "shapes/shapes.h"
#include "structures.h"
#include "tuple/tuple.h"
#include "ray/ray.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

// a sphere is a shape
MunitResult sphere_test1(const MunitParameter params[], void *fixture)
{
	t_shape *shape = new_sphere();
	t_sphere *props = &shape->sphere_props;
	t_matrix *identity = identity_matrix();

	munit_assert_true(matrix_equals(shape->transform, identity));
	free(identity);
	destroy_sphere(shape);
	return (MUNIT_OK);
}

MunitResult sphere_test2(const MunitParameter params[], void *fixture)
{
	t_shape *sphere = new_sphere();
	t_ray *ray = new_ray(new_point(0, 0, -5), new_vector(0, 0, 1));
	t_matrix *t = translation(2, 3, 4);

	set_transform(sphere, t);
	munit_assert_ptr_equal(sphere->transform, t);
	destroy_sphere(sphere);
	destroy_ray(ray);
	return (MUNIT_OK);
}

// a sphere has a sphere intersection function
MunitResult sphere_test3(const MunitParameter params[], void *fixture)
{
	t_shape *sphere = new_sphere();
	t_ray *ray = new_ray(new_point(0, 0, -5), new_vector(0, 0, 1));
	t_matrix *s = scaling(2, 2, 2);
	t_intersections *xs;

	set_transform(sphere, s);
	xs = new_intersections_list();
	intersect(sphere, ray, xs);
	munit_assert_int(xs->count, ==, 2);
	munit_assert_float(xs->intersections[0]->t, ==, 3);
	munit_assert_float(xs->intersections[1]->t, ==, 7);
	destroy_sphere(sphere);
	destroy_intersections_list(xs);
	destroy_ray(ray);
	return (MUNIT_OK);
}

MunitResult sphere_test4(const MunitParameter params[], void *fixture)
{
	t_shape *sphere = new_sphere();
	t_tuple *point = new_point(1, 0, 0);
	t_tuple *expected = new_vector(1, 0, 0);

	t_tuple *normal = normal_at(sphere, point);
	munit_assert_true(tuple_equals(normal, expected));
	free(normal);
	free(expected);
	free(point);
	destroy_sphere(sphere);
	return (MUNIT_OK);
}

MunitResult sphere_test5(const MunitParameter params[], void *fixture)
{
	t_shape *sphere = new_sphere();
	t_tuple *point = new_point(0, 1, 0);
	t_tuple *expected = new_vector(0, 1, 0);

	t_tuple *normal = normal_at(sphere, point);
	munit_assert_true(tuple_equals(normal, expected));
	free(normal);
	free(expected);
	free(point);
	destroy_sphere(sphere);
	return (MUNIT_OK);
}

MunitResult sphere_test6(const MunitParameter params[], void *fixture)
{
	t_shape *sphere = new_sphere();
	t_tuple *point = new_point(0, 0, 1);
	t_tuple *expected = new_vector(0, 0, 1);

	t_tuple *normal = normal_at(sphere, point);
	munit_assert_true(tuple_equals(normal, expected));
	free(normal);
	free(expected);
	free(point);
	destroy_sphere(sphere);
	return (MUNIT_OK);
}

MunitResult sphere_test7(const MunitParameter params[], void *fixture)
{
	float value = sqrtf(3) / 3;
	t_shape *sphere = new_sphere();
	t_tuple *point = new_point(value, value, value);
	t_tuple *expected = new_vector(value, value, value);

	t_tuple *normal = normal_at(sphere, point);
	munit_assert_true(tuple_equals(normal, expected));
	free(normal);
	free(expected);
	free(point);
	destroy_sphere(sphere);
	return (MUNIT_OK);
}

MunitResult sphere_test8(const MunitParameter params[], void *fixture)
{
	t_shape *sphere = new_sphere();
	set_transform(sphere, translation(0, 1, 0));

	t_tuple *point = new_point(0, 1.70711, -0.70711);
	t_tuple *normal = normal_at(sphere, point);
	t_tuple *expected = new_vector(0, 0.70711, -0.70711);

	munit_assert_true(tuple_equals(normal, expected));
	free(normal);
	free(expected);
	free(point);
	destroy_sphere(sphere);
	return (MUNIT_OK);
}

MunitResult sphere_test9(const MunitParameter params[], void *fixture)
{
	t_shape *sphere = new_sphere();
	t_matrix *scale = scaling(1, 0.5, 1);
	t_matrix *rot = rotation_z(M_PI / 5);
	t_matrix *tr = matrix_multiply(scale, rot);
	set_transform(sphere, tr);

	t_tuple *point = new_point(0, sqrtf(M_PI) / 2, -sqrtf(M_PI) / 2);
	t_tuple *normal = normal_at(sphere, point);
	t_tuple *expected = new_vector(0, 0.97014, -0.24254);

	munit_assert_true(tuple_equals(normal, expected));
	free(point);
	free(normal);
	free(expected);
	free(rot);
	free(scale);
	destroy_sphere(sphere);
	return (MUNIT_OK);
}

// a sphere has a default material
MunitResult sphere_test10(const MunitParameter params[], void *fixture)
{
	t_shape *sphere = new_sphere();
	t_material *material = new_material();

	munit_assert_float(sphere->material->ambient->red, ==, material->ambient->red);
	munit_assert_float(sphere->material->ambient->green, ==, material->ambient->green);
	munit_assert_float(sphere->material->ambient->blue, ==, material->ambient->blue);
	munit_assert_float(sphere->material->diffuse, ==, material->diffuse);
	munit_assert_float(sphere->material->specular, ==, material->specular);
	munit_assert_float(sphere->material->shininess, ==, material->shininess);
	munit_assert_float(sphere->material->color->red, ==, material->color->red);
	munit_assert_float(sphere->material->color->green, ==, material->color->green);
	munit_assert_float(sphere->material->color->blue, ==, material->color->blue);
	destroy_sphere(sphere);
	free(material->color);
	free(material);
	return (MUNIT_OK);
}
