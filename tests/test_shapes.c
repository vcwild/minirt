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
#include "utils.h"

t_tuple *test_normal_at(t_shape *shape, t_tuple *p)
{
	return (new_vector(p->x, p->y, p->z));
}

t_shape *new_test_shape(void)
{
	t_shape *shape = new_shape();
	shape->normal_at = test_normal_at;
	return (shape);
}

void destroy_shape(void *data)
{
	t_shape	*shape;

	shape = data;
	free(shape->transform);
	free(shape->inverse_transform);
	destroy_material(shape->material);
	free(shape);
}

// the default transformation
MunitResult shape_test1(const MunitParameter params[], void *fixture)
{
	t_shape *shape = new_test_shape();

	t_matrix *identity = identity_matrix();
	munit_assert_true(matrix_equals(shape->transform, identity));
	destroy_shape(shape);
	free(identity);
	return MUNIT_OK;
}

// assigning a transformation
MunitResult shape_test2(const MunitParameter params[], void *fixture)
{
	t_shape *shape = new_test_shape();

	t_matrix *t = translation(2, 3, 4);
	set_transform(shape, t);
	munit_assert_true(matrix_equals(shape->transform, t));
	destroy_shape(shape);
	return MUNIT_OK;
}

// the default material
MunitResult shape_test3(const MunitParameter params[], void *fixture)
{
	t_shape *shape = new_test_shape();

	t_material *m = new_material();
	munit_assert_true(material_equals(shape->material, m));
	destroy_shape(shape);
	return MUNIT_OK;
}

// assignin a material
MunitResult shape_test4(const MunitParameter params[], void *fixture)
{
	t_shape *shape = new_test_shape();

	t_material *m = new_material();
	free(m->ambient);
	m->ambient = new_color(1, 1, 1);
	set_material(shape, m);
	munit_assert_true(material_equals(shape->material, m));
	destroy_shape(shape);
	return MUNIT_OK;
}

// computing the normal on a translated shape
MunitResult shape_test5(const MunitParameter params[], void *fixture)
{
	t_shape	*shape = new_test_shape();
	t_tuple	*point;
	t_tuple	*result;
	t_tuple	*expected;

	expected = new_vector(0, 0.70711, -0.70711);
	set_transform(shape, translation(0, 1, 0));
	point = new_point(0, 1.70711, -0.70711);
	result = normal_at(shape, point);

	munit_assert_true(tuple_equals(result, expected));
	free(result);
	free(expected);
	free(point);
	destroy_shape(shape);
	return MUNIT_OK;
}

// computing the normal on a transformed shape
MunitResult shape_test6(const MunitParameter params[], void *fixture)
{
	t_shape *shape = new_test_shape();

	t_matrix *scale = scaling(1, .5, 1);
	t_matrix *rotation = rotation_z(M_PI / 5);

	t_matrix *trans = matrix_multiply(scale, rotation);
	set_transform(shape, trans);

	t_tuple *p = new_point(0, M_SQRT2 / 2, -M_SQRT2 / 2);
	t_tuple *normal = normal_at(shape, p);
	t_tuple *expected = new_vector(0, 0.97014, -0.24254);

	munit_assert_true(tuple_equals(normal, expected));
	return MUNIT_OK;
}
