#include "munit/munit.h"
#include "ray/ray.h"
#include "shapes/shapes.h"
#include "structures.h"
#include "tuple/tuple.h"
#include "utils/utils.h"

void	cylinder_intersect(t_shape *cylinder, t_ray *ray, t_intersections *xs);
t_tuple	*cylinder_normal_at(t_shape *cylinder, t_tuple *point);

// a ray misses a cylinder
MunitResult cylinder_test1(const MunitParameter params[], void *fixture)
{
	t_shape *cylinder = new_cylinder();

	t_tuple p1 = (t_tuple){1,0,0,1};
	t_tuple p2 = (t_tuple){0,0,0,1};
	t_tuple p3 = (t_tuple){0,0,-5,1};

	t_tuple v1 = (t_tuple){0,1,0,0};
	t_tuple v2 = (t_tuple){0,1,0,0};
	t_tuple v3 = (t_tuple){1,1,1,0};

	t_tuple *direction1 = normalize(&v1);
	t_tuple *direction2 = normalize(&v2);
	t_tuple *direction3 = normalize(&v3);

	t_ray *ray1 = new_ray(&p1, direction1);
	t_ray *ray2 = new_ray(&p2, direction2);
	t_ray *ray3 = new_ray(&p3, direction3);

	t_intersections *xs = new_intersections_list();

	cylinder_intersect(cylinder, ray1, xs);
	munit_assert_int(xs->count, ==, 0);

	cylinder_intersect(cylinder, ray2, xs);
	munit_assert_int(xs->count, ==, 0);

	cylinder_intersect(cylinder, ray3, xs);
	munit_assert_int(xs->count, ==, 0);

	free(direction3);
	free(direction2);
	free(direction1);
	return (MUNIT_OK);
}

// a ray strikes a cylinder
MunitResult cylinder_test2(const MunitParameter params[], void *fixture)
{
	t_shape *cylinder = new_cylinder();

	t_tuple p1 = (t_tuple){1,   0, -5, 1};
	t_tuple p2 = (t_tuple){0,   0, -5, 1};
	t_tuple p3 = (t_tuple){0.5, 0, -5, 1};

	t_tuple v1 = (t_tuple){0,   0, 1, 0};
	t_tuple v2 = (t_tuple){0,   0, 1, 0};
	t_tuple v3 = (t_tuple){0.1, 1, 1, 0};

	t_tuple *direction1 = normalize(&v1);
	t_tuple *direction2 = normalize(&v2);
	t_tuple *direction3 = normalize(&v3);

	t_ray *ray1 = new_ray(&p1, direction1);
	t_ray *ray2 = new_ray(&p2, direction2);
	t_ray *ray3 = new_ray(&p3, direction3);

	t_intersections *xs;

	xs = new_intersections_list();
	cylinder_intersect(cylinder, ray1, xs);
	munit_assert_int(xs->count, ==, 2);
	destroy_intersections_list(xs);

	xs = new_intersections_list();
	cylinder_intersect(cylinder, ray2, xs);
	munit_assert_int(xs->count, ==, 2);
	destroy_intersections_list(xs);

	xs = new_intersections_list();
	cylinder_intersect(cylinder, ray3, xs);
	munit_assert_int(xs->count, ==, 2);
	destroy_intersections_list(xs);

	free(direction3);
	free(direction2);
	free(direction1);
	return (MUNIT_OK);
}

// normal vector on a cylinder
MunitResult cylinder_test3(const MunitParameter params[], void *fixture)
{
	t_shape *cyl = new_cylinder();
	
	t_tuple point1 = (t_tuple){1, 0, 0, 1};
	t_tuple *normal = cylinder_normal_at(cyl, &point1);
	t_tuple expected = (t_tuple){1, 0, 0, 0};
	munit_assert_true(tuple_equals(normal, &expected));
	free(normal);
	
	point1 = (t_tuple){0, 5, -1, 1};
	normal = cylinder_normal_at(cyl, &point1);
	expected = (t_tuple){0, 0, -1, 0};
	munit_assert_true(tuple_equals(normal, &expected));
	free(normal);
	
	point1 = (t_tuple){0, -2, 1, 1};
	normal = cylinder_normal_at(cyl, &point1);
	expected = (t_tuple){0, 0, 1, 0};
	munit_assert_true(tuple_equals(normal, &expected));
	free(normal);
	
	point1 = (t_tuple){-1, 1, 0, 1};
	normal = cylinder_normal_at(cyl, &point1);
	expected = (t_tuple){-1, 0, 0, 0};
	munit_assert_true(tuple_equals(normal, &expected));
	free(normal);

	return (MUNIT_OK);
}

// normal vector on a cylinder
MunitResult cylinder_test4(const MunitParameter params[], void *fixture)
{
	t_shape *cyl = new_cylinder();
	t_intersections *xs;

	cyl->cylinder_props.min = 1;
	cyl->cylinder_props.max = 2;

	t_tuple points[] = {
		{0, 1.5, 0, 1}, // from inside, escaping without hitting
		{0, 3, -5, 1}, // perpendicular to y axis, above
		{0, 0, -5, 1}, // perpendicular to y axis, below
		{0, 2, -5, 1}, // literal edge case
		{0, 1, -5, 1}, // another edge case
		{0, 1.5, -2, 1}, // hit in the middle
	};

	t_tuple directions[] = {
		{0.1, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0},
		{0, 0, 1, 0},
	};
	
	int results[] = {0, 0, 0, 0, 0, 2};

	for (int i = 0; i < 6; i++)
	{
		t_ray *ray = new_ray(&points[i], normalize(&directions[i]));
		xs = new_intersections_list();
		cylinder_intersect(cyl, ray, xs);
		munit_assert_int(xs->count, ==, results[i]);
		destroy_intersections_list(xs);
		free(ray->direction);
		free(ray);
	}
	

	return (MUNIT_OK);
}
