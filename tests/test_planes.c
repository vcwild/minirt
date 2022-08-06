#include "munit/munit.h"
#include "ray/ray.h"
#include "shapes/shapes.h"
#include "structures.h"
#include "tuple/tuple.h"
#include <math.h>


// the normal of a plane is constant everywhere
MunitResult plane_test1(const MunitParameter params[], void *fixture)
{
	t_shape *plane = new_plane();

	t_tuple *p1 = new_point(0, 0, 0);
	t_tuple *p2 = new_point(10, 0, -10);
	t_tuple *p3 = new_point(-5, 0, 150);

	t_tuple *expected = new_vector(0, 1, 0);

	t_tuple *n1 = plane->normal_at(plane, p1);
	t_tuple *n2 = plane->normal_at(plane, p2);
	t_tuple *n3 = plane->normal_at(plane, p3);

	munit_assert_true(tuple_equals(n1, expected));
	munit_assert_true(tuple_equals(n2, expected));
	munit_assert_true(tuple_equals(n3, expected));
	free(n1);
	free(n2);
	free(n3);
	free(p1);
	free(p2);
	free(p3);
	free(expected);
	plane->destroy_fn(plane);
	return MUNIT_OK;
}

// intersect with a ray parallel to the plane
MunitResult plane_test2(const MunitParameter params[], void *fixture)
{
	t_shape *pl = new_plane();

	t_tuple *origin = new_point(0, 10, 0);
	t_tuple *direction = new_point(0, 0, 1);
	t_ray *ray = new_ray(origin, direction);
	t_intersections *xs = new_intersections_list();

	pl->intersect(pl, ray, xs);

	munit_assert_int(xs->count, ==, 0);
	return MUNIT_OK;
}

// intersect with a coplanar ray
MunitResult plane_test3(const MunitParameter params[], void *fixture)
{
	t_shape *pl = new_plane();

	t_tuple *origin = new_point(0, 0, 0);
	t_tuple *direction = new_point(0, 0, 1);
	t_ray *ray = new_ray(origin, direction);
	t_intersections *xs = new_intersections_list();

	pl->intersect(pl, ray, xs);

	munit_assert_int(xs->count, ==, 0);
	return MUNIT_OK;
}

// a ray intersecting a plane from above
MunitResult plane_test4(const MunitParameter params[], void *fixture)
{
	t_shape *pl = new_plane();

	t_tuple *origin = new_point(0, 1, 0);
	t_tuple *direction = new_point(0, -1, 0);
	t_ray *ray = new_ray(origin, direction);
	t_intersections *xs = new_intersections_list();

	pl->intersect(pl, ray, xs);

	munit_assert_int(xs->count, ==, 1);
	munit_assert_double(xs->intersections[0]->t, ==, 1);
	munit_assert_ptr(xs->intersections[0]->object, ==, pl);
	return MUNIT_OK;
}

// a ray intersecting a plane from below
MunitResult plane_test5(const MunitParameter params[], void *fixture)
{
	t_shape *pl = new_plane();

	t_tuple *origin = new_point(0, -1, 0);
	t_tuple *direction = new_point(0, 1, 0);
	t_ray *ray = new_ray(origin, direction);
	t_intersections *xs = new_intersections_list();

	pl->intersect(pl, ray, xs);

	munit_assert_int(xs->count, ==, 1);
	munit_assert_double(xs->intersections[0]->t, ==, 1);
	munit_assert_ptr(xs->intersections[0]->object, ==, pl);
	return MUNIT_OK;
}
