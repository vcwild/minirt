/*
Authored by paulo-santana <psergio-@student.42sp.org.br>
Copied and modified by vcwild <vcwild@gmail.com> without strict licensing permission.
*/

#include "munit/munit.h"
#include "minirt.h"
#include <math.h>

// the pixel size for a horizontal canvas
MunitResult camera_test1(const MunitParameter params[], void *fixture)
{
	t_camera *camera = new_camera(200, 125, M_PI_2);

	munit_assert_float(camera->pixel_size, ==, 0.01);

	destroy_camera(camera);
	return (MUNIT_OK);
}

// the pixel size for a vertical canvas
MunitResult camera_test2(const MunitParameter params[], void *fixture)
{
	t_camera *camera = new_camera(125, 200, M_PI_2);

	munit_assert_float(camera->pixel_size, ==, 0.01);

	destroy_camera(camera);
	return (MUNIT_OK);
}

// constructing a ray through the center of the canvas
MunitResult camera_test3(const MunitParameter params[], void *fixture)
{
	t_camera *camera = new_camera(201, 101, M_PI_2);
	t_ray *ray = ray_to_pixel(camera, 100, 50);

	t_tuple *expected_origin = new_point(0, 0, 0);
	t_tuple *expected_direction = new_vector(0, 0, -1);

	munit_assert_float(round_to(ray->origin->x), ==, expected_origin->x);
	munit_assert_float(round_to(ray->origin->y), ==, expected_origin->y);
	munit_assert_float(round_to(ray->origin->z), ==, expected_origin->z);
	munit_assert_float(round_to(ray->origin->w), ==, expected_origin->w);
	munit_assert_float(round_to(ray->direction->x), ==, expected_direction->x);
	munit_assert_float(round_to(ray->direction->y), ==, expected_direction->y);
	munit_assert_float(round_to(ray->direction->z), ==, expected_direction->z);
	munit_assert_float(round_to(ray->direction->w), ==, expected_direction->w);

	destroy_camera(camera);
	destroy_ray(ray);
	free(expected_direction);
	free(expected_origin);
	return (MUNIT_OK);
}

// constructing a ray through the corner of the canvas
MunitResult camera_test4(const MunitParameter params[], void *fixture)
{
	t_camera *camera = new_camera(201, 101, M_PI_2);
	t_ray *ray = ray_to_pixel(camera, 0, 0);

	t_tuple *expected_origin = new_point(0, 0, 0);
	t_tuple *expected_direction = new_vector(0.66519, 0.33259, -0.66851);

	munit_assert_float(round_to(ray->origin->x), ==, expected_origin->x);
	munit_assert_float(round_to(ray->origin->y), ==, expected_origin->y);
	munit_assert_float(round_to(ray->origin->z), ==, expected_origin->z);
	munit_assert_float(round_to(ray->origin->w), ==, expected_origin->w);
	munit_assert_float(round_to(ray->direction->x), ==, expected_direction->x);
	munit_assert_float(round_to(ray->direction->y), ==, expected_direction->y);
	munit_assert_float(round_to(ray->direction->z), ==, expected_direction->z);
	munit_assert_float(round_to(ray->direction->w), ==, expected_direction->w);

	destroy_camera(camera);
	destroy_ray(ray);
	free(expected_direction);
	free(expected_origin);
	return (MUNIT_OK);
}

// constructing a ray when the camera is transformed
MunitResult camera_test5(const MunitParameter params[], void *fixture)
{
	t_camera *camera = new_camera(201, 101, M_PI_2);
	t_matrix *rot = rotation_y(M_PI_4);
	t_matrix *trans = translation(0, -2, 5);
	set_camera_transform(camera, matrix_multiply(rot, trans));
	t_ray *ray = ray_to_pixel(camera, 100, 50);

	t_tuple *expected_origin = new_point(0, 2, -5);
	t_tuple *expected_direction = new_vector(M_SQRT2 / 2, 0, -M_SQRT2 / 2);

	munit_assert_float(ray->origin->x, ==, expected_origin->x);
	munit_assert_float(ray->origin->y, ==, expected_origin->y);
	munit_assert_float(ray->origin->z, ==, expected_origin->z);
	munit_assert_float(ray->origin->w, ==, expected_origin->w);
	munit_assert_float(ray->direction->x, ==, expected_direction->x);
	munit_assert_float(ray->direction->y, ==, expected_direction->y);
	munit_assert_float(ray->direction->z, ==, expected_direction->z);
	munit_assert_float(ray->direction->w, ==, expected_direction->w);
	destroy_camera(camera);
	destroy_ray(ray);
	free(expected_direction);
	free(expected_origin);
	free(rot);
	free(trans);
	return (MUNIT_OK);
}


// rendering a world with a camera
MunitResult camera_test6(const MunitParameter params[], void *fixture)
{
	t_world *world = default_world();
	t_camera *camera = new_camera(11, 11, M_PI_2);
	t_tuple *from = new_point(0, 0, -5);
	t_tuple *to = new_point(0, 0, 0);
	t_tuple *up = new_vector(0, 1, 0);
	set_camera_transform(camera, view_transform(from, to, up));
	t_canvas *image = render(camera, world);

	t_color *color = get_pixel(image, 5, 5);
	t_color *expected_color = new_color(0.38066, 0.47583, 0.2855);

	munit_assert_float(round_to(color->r), ==, expected_color->r);
	munit_assert_float(round_to(color->g), ==, expected_color->g);
	munit_assert_float(round_to(color->b), ==, expected_color->b);

	free(color);
	free(expected_color);
	free(from);
	free(to);
	free(up);
	destroy_camera(camera);
	destroy_world(world);
	free(image);
	return (MUNIT_OK);
}

