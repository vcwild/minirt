#include "lights/lights.h"
#include "matrix/matrix.h"
#include "munit/munit.h"
#include "../src/structures.h"
#include "../src/minirt.h"
#include "ray/ray.h"
#include "shapes/shapes.h"
#include "tuple/tuple.h"
#include "../libft/libft.h"
#include "../src/world/world.h"
#include "utils.h"
#include <math.h>
#include "debug.h"

// creating a world
MunitResult world_test1(const MunitParameter params[], void *fixture)
{
	t_world	*world = new_world();

	munit_assert_true(world->lights == NULL);
	munit_assert_true(world->objects.total == 0);
	munit_assert_true(world->objects.sphere_count == 0);
	destroy_world(world);
	return (MUNIT_OK);
}

// the default world
// NOTE: this will have to change
MunitResult world_test2(const MunitParameter params[], void *fixture)
{
	t_point_light *light = new_point_light(
			new_point(-10, 10, -10),
			new_color(1, 1, 1)
		);
	t_shape *s1 = new_sphere();
	s1->material->diffuse = 0.7;
	s1->material->specular = 0.2;
	free(s1->material->color);
	s1->material->color = new_color(0.8, 1.0, 0.6);

	t_shape *s2 = new_sphere();
	t_matrix *t = scaling(0.5, 0.5, 0.5);
	set_transform(s2, t);
	t_world	*world = default_world();

	t_world *expected = new_world();
	add_light(expected, light);
	add_sphere(expected, s1);
	add_sphere(expected, s2);

	munit_assert_true(world_equals(expected, world));
	munit_assert_true(world->objects.total == 2);
	munit_assert_true(world->objects.sphere_count == 2);
	destroy_world(expected);
	destroy_world(world);
	return (MUNIT_OK);
}

// intersect a world with a ray
MunitResult world_test3(const MunitParameter params[], void *fixture)
{
	t_world *w = default_world();
	t_ray *ray = new_ray(new_point(0, 0, -5), new_vector(0, 0, 1));

	t_intersections *xs = intersect_world(w, ray);

	munit_assert_int(xs->count, ==, 4);
	munit_assert_float(xs->intersections[0]->t, ==, 4);
	munit_assert_float(xs->intersections[1]->t, ==, 4.5);
	munit_assert_float(xs->intersections[2]->t, ==, 5.5);
	munit_assert_float(xs->intersections[3]->t, ==, 6);
	destroy_intersections_list(xs);
	destroy_ray(ray);
	destroy_world(w);
	return (MUNIT_OK);
}

// intersect a world with a ray
MunitResult world_test4(const MunitParameter params[], void *fixture)
{
	t_ray *ray = new_ray(new_point(0, 0, -5), new_vector(0, 0, 1));
	t_shape *sphere = new_sphere();
	t_intersection *i = new_intersection(4, sphere, OBJ_SPHERE);

	t_computations *comps = prepare_computations(i, ray);

	t_tuple *expected_point = new_point(0, 0, -1);
	t_tuple *expected_eyev = new_vector(0, 0, -1);
	t_tuple *expected_normalv = new_vector(0, 0, -1);

	munit_assert_float(comps->t, ==, i->t);
	munit_assert_ptr_equal(comps->object, i->object);
	munit_assert_true(tuple_equals(comps->point, expected_point));
	munit_assert_true(tuple_equals(comps->eyev, expected_eyev));
	munit_assert_true(tuple_equals(comps->normalv, expected_normalv));
	destroy_ray(ray);
	destroy_sphere(sphere);
	destroy_computations(comps);
	free(i);
	free(expected_point);
	free(expected_eyev);
	free(expected_normalv);
	return (MUNIT_OK);
}

// the hit, when an intersection occurs on the outside
MunitResult world_test5(const MunitParameter params[], void *fixture)
{
	t_ray *ray = new_ray(new_point(0, 0, -5), new_vector(0, 0, 1));
	t_shape *sphere = new_sphere();
	t_intersection *i = new_intersection(4, sphere, OBJ_SPHERE);
	t_computations *comps = prepare_computations(i, ray);

	munit_assert_true(comps->inside == 0);
	destroy_computations(comps);
	free(i);
	destroy_sphere(sphere);
	destroy_ray(ray);
	return (MUNIT_OK);
}

// the hit, when an intersection occurs on the inside
MunitResult world_test6(const MunitParameter params[], void *fixture)
{
	t_ray *ray = new_ray(new_point(0, 0, 0), new_vector(0, 0, 1));
	t_shape *sphere = new_sphere();
	t_intersection *i = new_intersection(1, sphere, OBJ_SPHERE);
	t_computations *comps = prepare_computations(i, ray);

	t_tuple *expected_normalv = new_vector(0, 0, -1);

	munit_assert_true(comps->inside == 1);
	munit_assert_true(tuple_equals(comps->normalv, expected_normalv));
	free(i);
	destroy_sphere(sphere);
	destroy_ray(ray);
	destroy_computations(comps);
	free(expected_normalv);
	return (MUNIT_OK);
}

// shading an intersection
MunitResult world_test7(const MunitParameter params[], void *fixture)
{
	t_world *world = default_world();
	t_ray *ray = new_ray(new_point(0, 0, -5), new_vector(0, 0, 1));
	t_sphere *sphere = world->objects.spheres->content;
	t_intersection *intersection = new_intersection(4, sphere, OBJ_SPHERE);
	t_computations *comps = prepare_computations(intersection, ray);


	t_color *color = shade_hit(world, comps);
	t_color *expected_color = new_color(0.38066, 0.47583, 0.2855);

	munit_assert_true(color_equals(color, expected_color));
	destroy_ray(ray);
	destroy_world(world);
	free(color);
	free(expected_color);
	free(intersection);
	destroy_computations(comps);
	return (MUNIT_OK);
}

// shading an intersection from the inside
MunitResult world_test8(const MunitParameter params[], void *fixture)
{
	t_world *world = default_world();
	destroy_point_light(world->lights->content);
	world->lights->content = new_point_light(new_point(0, 0.25, 0), new_color(1, 1, 1));
	t_ray *ray = new_ray(new_point(0, 0, 0), new_vector(0, 0, 1));
	t_sphere *sphere = world->objects.spheres->next->content;
	t_intersection *intersection = new_intersection(0.5, sphere, OBJ_SPHERE);

	t_computations *comps = prepare_computations(intersection, ray);
	t_color *color = shade_hit(world, comps);

	t_color *expected_color = new_color(0.90498, 0.90498, 0.90498);

	munit_assert_true(color_equals(color, expected_color));
	destroy_ray(ray);
	destroy_world(world);
	free(color);
	free(expected_color);
	free(intersection);
	destroy_computations(comps);
	return (MUNIT_OK);
}

// the color when a ray misses
MunitResult world_test9(const MunitParameter params[], void *fixture)
{
	t_world *world = default_world();
	t_ray *ray = new_ray(new_point(0, 0, -5), new_vector(0, 1, 0));
	t_color *expected = new_color(0, 0, 0);

	t_color *color = color_at(world, ray);

	munit_assert_true(color_equals(color, expected));
	destroy_ray(ray);
	destroy_world(world);
	free(color);
	free(expected);
	return (MUNIT_OK);
}

// the color when a ray hits
MunitResult world_test10(const MunitParameter params[], void *fixture)
{
	t_world *world = default_world();
	t_ray *ray = new_ray(new_point(0, 0, -5), new_vector(0, 0, 1));
	t_color *expected = new_color(.38066, .47583, .2855);

	t_color *color = color_at(world, ray);

	munit_assert_true(color_equals(color, expected));
	destroy_ray(ray);
	destroy_world(world);
	free(color);
	free(expected);
	return (MUNIT_OK);
}

// the color with an intersection behind the ray
MunitResult world_test11(const MunitParameter params[], void *fixture)
{
	t_world *world = default_world();
	t_ray *ray = new_ray(new_point(0, 0, .75), new_vector(0, 0, -1));
	t_shape *outer = world->objects.spheres->content;
	outer->material->ambient = new_color(1, 1, 1);
	t_shape *inner = world->objects.spheres->next->content;
	inner->material->ambient = new_color(1, 1, 1);
	t_color *expected = inner->material->color;

	t_color *color = color_at(world, ray);

	munit_assert_true(color_equals(color, expected));
	destroy_ray(ray);
	destroy_world(world);
	free(color);
	return (MUNIT_OK);
}

// there is no shadow when nothing is collinear with point and light
MunitResult world_test12(const MunitParameter params[], void *fixture)
{
	t_world *world = default_world();
	t_tuple *point = new_point(0, 10, 0);

	munit_assert_false(is_shadowed(world, point, world->lights->content));
	destroy_world(world);
	free(point);
	return (MUNIT_OK);
}

// the shadow when an object is between the point and the light
MunitResult world_test13(const MunitParameter params[], void *fixture)
{
	t_world *world = default_world();
	t_tuple *point = new_point(10, -10, 10);

	munit_assert_true(is_shadowed(world, point, world->lights->content));
	destroy_world(world);
	free(point);
	return (MUNIT_OK);
}

// there's no shadown when an object is behind the light
MunitResult world_test14(const MunitParameter params[], void *fixture)
{
	t_world *world = default_world();
	t_tuple *point = new_point(-20, 20, -20);

	munit_assert_false(is_shadowed(world, point, world->lights->content));
	destroy_world(world);
	free(point);
	return (MUNIT_OK);
}

// there's no shadown when an object is behind the light
MunitResult world_test15(const MunitParameter params[], void *fixture)
{
	t_world *world = default_world();
	t_tuple *point = new_point(-2, 2, -2);

	munit_assert_false(is_shadowed(world, point, world->lights->content));
	destroy_world(world);
	free(point);
	return (MUNIT_OK);
}
