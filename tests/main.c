/*
Authored by paulo-santana <psergio-@student.42sp.org.br>
Copied and modified by vcwild <vcwild@gmail.com> without strict licensing permission.
*/

#include "munit/munit.h"
#include "minirt.h"

#define PARAMS const MunitParameter params[], void *fixture

MunitResult matrix_test1(PARAMS);
MunitResult matrix_test2(PARAMS);
MunitResult matrix_test3(PARAMS);
MunitResult matrix_test4(PARAMS);
MunitResult matrix_test5(PARAMS);
MunitResult matrix_test6(PARAMS);
MunitResult matrix_test7(PARAMS);
MunitResult matrix_test8(PARAMS);
MunitResult matrix_test9(PARAMS);
MunitResult matrix_test10(PARAMS);
MunitResult matrix_test11(PARAMS);
MunitResult matrix_test12(PARAMS);
MunitResult matrix_test13(PARAMS);
MunitResult matrix_test14(PARAMS);
MunitResult matrix_test15(PARAMS);
MunitResult matrix_test16(PARAMS);
MunitResult matrix_test17(PARAMS);
MunitResult matrix_test18(PARAMS);
MunitResult matrix_test19(PARAMS);
MunitResult matrix_test20(PARAMS);
MunitResult matrix_test21(PARAMS);
MunitResult matrix_test22(PARAMS);
MunitResult matrix_test23(PARAMS);

MunitResult tuple_test1(PARAMS);
MunitResult tuple_test2(PARAMS);
MunitResult tuple_test3(PARAMS);
MunitResult tuple_test4(PARAMS);
MunitResult tuple_test5(PARAMS);
MunitResult tuple_test6(PARAMS);
MunitResult tuple_test7(PARAMS);
MunitResult tuple_test8(PARAMS);
MunitResult tuple_test9(PARAMS);
MunitResult tuple_test10(PARAMS);
MunitResult tuple_test11(PARAMS);
MunitResult tuple_test12(PARAMS);
MunitResult tuple_test13(PARAMS);
MunitResult tuple_test14(PARAMS);
MunitResult tuple_test15(PARAMS);
MunitResult tuple_test16(PARAMS);
MunitResult tuple_test17(PARAMS);
MunitResult tuple_test18(PARAMS);
MunitResult tuple_test19(PARAMS);
MunitResult tuple_test20(PARAMS);
MunitResult tuple_test21(PARAMS);
MunitResult tuple_test22(PARAMS);
MunitResult tuple_test23(PARAMS);
MunitResult tuple_test24(PARAMS);
MunitResult tuple_test25(PARAMS);

MunitResult canvas_test1(PARAMS);
MunitResult canvas_test2(PARAMS);
MunitResult canvas_test3(PARAMS);
MunitResult canvas_test4(PARAMS);

MunitResult matrix_transform_test1(PARAMS);
MunitResult matrix_transform_test2(PARAMS);
MunitResult matrix_transform_test3(PARAMS);
MunitResult matrix_transform_test4(PARAMS);
MunitResult matrix_transform_test5(PARAMS);
MunitResult matrix_transform_test6(PARAMS);
MunitResult matrix_transform_test7(PARAMS);
MunitResult matrix_transform_test8(PARAMS);
MunitResult matrix_transform_test9(PARAMS);
MunitResult matrix_transform_test10(PARAMS);
MunitResult matrix_transform_test11(PARAMS);
MunitResult matrix_transform_test12(PARAMS);
MunitResult matrix_transform_test13(PARAMS);
MunitResult matrix_transform_test14(PARAMS);
MunitResult matrix_transform_test15(PARAMS);
MunitResult matrix_transform_test16(PARAMS);
MunitResult matrix_transform_test17(PARAMS);

MunitResult ray_test1(PARAMS);
MunitResult ray_test2(PARAMS);
MunitResult ray_test3(PARAMS);
MunitResult ray_test4(PARAMS);
MunitResult ray_test5(PARAMS);
MunitResult ray_test6(PARAMS);
MunitResult ray_test7(PARAMS);
MunitResult ray_test8(PARAMS);
MunitResult ray_test9(PARAMS);
MunitResult ray_test10(PARAMS);
MunitResult ray_test11(PARAMS);
MunitResult ray_test12(PARAMS);
MunitResult ray_test13(PARAMS);
MunitResult ray_test14(PARAMS);
MunitResult ray_test15(PARAMS);

MunitResult sphere_test1(PARAMS);
MunitResult sphere_test2(PARAMS);
MunitResult sphere_test3(PARAMS);
MunitResult sphere_test4(PARAMS);
MunitResult sphere_test5(PARAMS);
MunitResult sphere_test6(PARAMS);
MunitResult sphere_test7(PARAMS);
MunitResult sphere_test8(PARAMS);
MunitResult sphere_test9(PARAMS);
MunitResult sphere_test10(PARAMS);

// MunitResult plane_test1(PARAMS);
// MunitResult plane_test2(PARAMS);
// MunitResult plane_test3(PARAMS);
// MunitResult plane_test4(PARAMS);
// MunitResult plane_test5(PARAMS);

// MunitResult shape_test1(PARAMS);
// MunitResult shape_test2(PARAMS);
// MunitResult shape_test3(PARAMS);
// MunitResult shape_test4(PARAMS);
// MunitResult shape_test5(PARAMS);
// MunitResult shape_test6(PARAMS);

// MunitResult cylinder_test1(PARAMS);
// MunitResult cylinder_test2(PARAMS);
// MunitResult cylinder_test3(PARAMS);
// MunitResult cylinder_test4(PARAMS);

// MunitResult light_test1(PARAMS);

MunitResult material_test1(PARAMS);
MunitResult material_test2(PARAMS);
MunitResult material_test3(PARAMS);
MunitResult material_test4(PARAMS);
MunitResult material_test5(PARAMS);
MunitResult material_test6(PARAMS);
// MunitResult material_test7(PARAMS);

MunitResult world_test1(PARAMS);
MunitResult world_test2(PARAMS);
MunitResult world_test3(PARAMS);
MunitResult world_test4(PARAMS);
MunitResult world_test5(PARAMS);
MunitResult world_test6(PARAMS);
MunitResult world_test7(PARAMS);
MunitResult world_test8(PARAMS);
MunitResult world_test9(PARAMS);
MunitResult world_test10(PARAMS);
MunitResult world_test11(PARAMS);

MunitResult camera_test1(PARAMS);
MunitResult camera_test2(PARAMS);
// MunitResult camera_test3(PARAMS);
// MunitResult camera_test4(PARAMS);
// MunitResult camera_test5(PARAMS);
// MunitResult camera_test6(PARAMS);

MunitTest test(char *desc, MunitTestFunc the_test)
{
	MunitTest setup;

	// setup = malloc(sizeof(MunitTest));
	setup.name = desc;
	setup.test = the_test;
	setup.setup = NULL;
	setup.tear_down = NULL;
	setup.options = 0;
	setup.parameters = NULL;
	return (setup);
}

int main(int argc, char **argv) {
	MunitTest tuple_tests[] = {
		test("/a simple test", tuple_test1),
		test("/is_point() and is_vector()", tuple_test1),
		test("/is_point() and is_vector()", tuple_test2),
		test("/new_point() creates a point", tuple_test3),
		test("/new_vector() creates a vector", tuple_test4),
		test("/add_tuples() point + vector", tuple_test5),
		test("/add_tuples() vector + vector", tuple_test6),
		test("/add_tuples() point + point makes no sense", tuple_test7),
		test("/subtract_tuples() point - point = vector", tuple_test8),
		test("/subtract_tuples() point - vector = point", tuple_test9),
		test("/negate_tuple() neagtes a vector", tuple_test10),
		test("/multiply_scalar() multplies a tuple by a scalar value", tuple_test11),
		test("/multiply_scalar() multplies a tuple by a fraction", tuple_test12),
		test("/divide_scalar() divides a tuple by a scalar value", tuple_test13),
		test("/magnitude() calculates correctly", tuple_test14),
		test("/normalize() calculates correctly", tuple_test15),
		test("/the magnitude of a normalized vector is 1", tuple_test16),
		test("/dot()", tuple_test17),
		test("/cross()", tuple_test18),
		test("/new_color()", tuple_test19),
		test("/add_colors()", tuple_test20),
		test("/subtract_colors()", tuple_test21),
		test("/multiply_scalar_color()", tuple_test22),
		test("/multiply_colors()", tuple_test23),
		test("/reflect() a point approaching at 45º", tuple_test24),
		test("/reflect() a point off a slanted surface", tuple_test25),
		{ NULL, NULL, NULL, NULL, 0, NULL },
	};

	MunitTest matrix_tests[] = {
		test("/new_matrix(size, initial_values)", matrix_test1),
		test("/matrix_equals(4x4, 4x4)", matrix_test2),
		test("/matrix_equals(3x3, 3x3)", matrix_test3),
		test("/matrix_equals(2x2, 2x2)", matrix_test4),
		test("/matrix_multiply(4x4, 4x4)", matrix_test5),
		test("/matrix_multiply_tuple(4x4, tuple)", matrix_test6),
		test("/identity_matrix()", matrix_test7),
		test("/identity_matrix() multiply a tuple", matrix_test8),
		test("/transponse()", matrix_test9),
		test("/transponse(identity_matrix)", matrix_test10),
		test("/matrix_determinant(2x2)", matrix_test11),
		test("/submatrix(3x3) == 2x2", matrix_test12),
		test("/submatrix(4x4) == 3x3", matrix_test13),
		test("/minor(3x3)", matrix_test14),
		test("/cofactor(3x3)", matrix_test15),
		test("/matrix_determinant(3x3)", matrix_test16),
		test("/matrix_determinant(4x4)", matrix_test17),
		test("/is_invertible(4x4)", matrix_test18),
		test("/is_invertible(4x4) returns false", matrix_test19),
		test("/invert() works", matrix_test20),
		test("/invert() works again", matrix_test21),
		test("/invert() works again again", matrix_test22),
		test("/multiplying by the invert() is the same as dividing", matrix_test23),
		{ NULL, NULL, NULL, NULL, 0, NULL },
	};

	MunitTest canvas_tests[] = {
		test("/new_canvas", canvas_test1),
		test("/new_canvas", canvas_test2),
		test("/new_canvas and write_pixel()", canvas_test3),
		test("/new_canvas and pixel_at()", canvas_test4),
		{ NULL, NULL, NULL, NULL, 0, NULL },
	};

	MunitTest matrix_transform_tests[] = {
		test("/translation() moves a point", matrix_transform_test1),
		test("/invserse(translation()) moves a point to the oposite direction", matrix_transform_test2),
		test("/translation() * a vector doesn't change it", matrix_transform_test3),
		test("/scaling() scales a point", matrix_transform_test4),
		test("/scaling() scales a vector", matrix_transform_test5),
		test("/invert(scaling()) inverts the scaling", matrix_transform_test6),
		test("/rotation_x()", matrix_transform_test7),
		test("/invert(rotation_x())", matrix_transform_test8),
		test("/rotation_y()", matrix_transform_test9),
		test("/rotation_z()", matrix_transform_test10),
		test("/individual transformations", matrix_transform_test11),
		test("/chained transformations", matrix_transform_test12),
		test("/chained n transformations", matrix_transform_test13),
		test("/view_transform()", matrix_transform_test14),
		test("/view_transform() looking to +z", matrix_transform_test15),
		test("/view_transform() moves the world", matrix_transform_test16),
		test("/view_transform() moves the world arbitrary", matrix_transform_test17),
		{ NULL, NULL, NULL, NULL, 0, NULL },
	};

	MunitTest ray_tests[] = {
		test("/new_ray()", ray_test1),
		test("/position()", ray_test2),
		test("/a ray intersect() a sphere at two points", ray_test3),
		test("/a ray intersect() a sphere at a tangent", ray_test4),
		test("/a ray misses the sphere", ray_test5),
		test("/a ray originates inside a sphere", ray_test6),
		test("/a sphere is behind a ray", ray_test7),
		test("/an intersection encapsulates t and object", ray_test8),
		test("/intersect() sets the object on the intersection", ray_test9),
		test("/hit() when all inters are positive", ray_test10),
		test("/hit() when some are negative", ray_test11),
		test("/hit() when all inters are negative", ray_test12),
		test("/hit() with a scrambled order", ray_test13),
		test("/tranform() a ray with a translation matrix", ray_test14),
		test("/tranform() a ray with a scaling matrix", ray_test15),
		{ NULL, NULL, NULL, NULL, 0, NULL },
	};

	MunitTest sphere_tests[] = {
		test("/new_sphere() has a transform matrix", sphere_test1),
		test("/set_transform() sets a new sphere transform matrix", sphere_test2),
		test("/intersect() uses the sphere transform matrix", sphere_test3),
		test("/get_normal() at a point on the x axis", sphere_test4),
		test("/get_normal() at a point on the y axis", sphere_test5),
		test("/get_normal() at a point on the z axis", sphere_test6),
		test("/get_normal() at a nonaxial point", sphere_test7),
		test("/get_normal() with a translated sphere", sphere_test8),
		test("/get_normal() with a scaled and rotated sphere", sphere_test9),
		test("/a new sphere has a default material", sphere_test10),
		{ NULL, NULL, NULL, NULL, 0, NULL },
	};

	// MunitTest light_tests[] = {
	// 	test("/new_point_light() returns a light", light_test1),
	// 	{ NULL, NULL, NULL, NULL, 0, NULL },
	// };

	MunitTest material_tests[] = {
		test("/new_material() returns a default material", material_test1),
		test("/lighting() calculates the shade of a point", material_test2),
		test("/lighting() with the eye offseted 45º", material_test3),
		test("/lighting() with the light offseted 45º", material_test4),
		test("/lighting() with the eye in the path of the reflection", material_test5),
		test("/lighting() with the light behind the surface", material_test6),
	// 	test("/lighting() with shadows", material_test7),
		{ NULL, NULL, NULL, NULL, 0, NULL },
	};

	MunitTest world_tests[] = {
		test("/new_world() creates a world", world_test1),
		test("/default_world() might be a useless function", world_test2),
		test("/intersect_world() intersect a world with a ray", world_test3),
		test("/precomputing the state of an intersection", world_test4),
		test("/the hit, eye outside", world_test5),
		test("/the hit, eye inside", world_test6),
		test("/shading an intersection", world_test7),
		test("/shading an intersection from the inside", world_test8),
		test("/the color when a ray misses", world_test9),
		test("/the color when a ray hits", world_test10),
		test("/the color with an intersection behind the ray", world_test11),
		{ NULL, NULL, NULL, NULL, 0, NULL },
	};

	MunitTest camera_tests[] = {
		test("/new_camera() creates a camera", camera_test1),
		test("/the pixel size for a vertical canvas", camera_test2),
	// 	test("/ray_to_pixel() at the center of the canvas", camera_test3),
	// 	test("/ray_to_pixel() at the corner of the canvas", camera_test4),
	// 	test("/ray_to_pixel() with a transformed camera", camera_test5),
	// 	test("/render() rendering a world with a camera", camera_test6),
		{ NULL, NULL, NULL, NULL, 0, NULL },
	};

	// MunitTest shape_tests[] = {
	// 	test("/a shape has a default transformation", shape_test1),
	// 	test("/assign a tranformation to a shape", shape_test2),
	// 	test("/a shape has a default material", shape_test3),
	// 	test("/assigning a material", shape_test4),
	// 	test("/computing the normal on a translated shape", shape_test5),
	// 	test("/computing the normal on a transformed shape", shape_test6),
	// 	{ NULL, NULL, NULL, NULL, 0, NULL },
	// };

	// MunitTest plane_tests[] = {
	// 	test("/the normal of a plane is constant everywhere", plane_test1),
	// 	test("/intersect with a ray parallel to the plane", plane_test2),
	// 	test("/intersect with a coplanar ray", plane_test3),
	// 	test("/intersecting a plane from above", plane_test4),
	// 	test("/intersecting a plane from below", plane_test5),
	// 	{ NULL, NULL, NULL, NULL, 0, NULL },
	// };

	// MunitTest cylinder_tests[] = {
	// 	test("/a ray misses a cylinder", cylinder_test1),
	// 	test("/a ray strikes a cylinder", cylinder_test2),
	// 	test("/normal vector on a cylinder", cylinder_test3),
	// 	test("/intersecting a constrained cylinder", cylinder_test4),
	// 	{ NULL, NULL, NULL, NULL, 0, NULL },
	// };

	#define OPTIONS NULL, 1, MUNIT_SUITE_OPTION_NONE
	MunitSuite tuple_suite =            { "/tuples", tuple_tests, OPTIONS };
	MunitSuite canvas_suite =            { "/canvas", canvas_tests, OPTIONS };
	MunitSuite matrix_suite =           { "/matrices", matrix_tests, OPTIONS };
	MunitSuite matrix_transform_suite = { "/matrices/transform", matrix_transform_tests, OPTIONS };
	MunitSuite ray_suite =              { "/rays", ray_tests, OPTIONS };
	MunitSuite sphere_suite =           { "/spheres", sphere_tests, OPTIONS };
	MunitSuite material_suite =         { "/materials", material_tests, OPTIONS };
	MunitSuite world_suite =            { "/world", world_tests, OPTIONS };
	MunitSuite camera_suite =           { "/camera", camera_tests, OPTIONS };
	// MunitSuite light_suite =            { "/lights", light_tests, OPTIONS };
	// MunitSuite shape_suite =            { "/shapes", shape_tests, OPTIONS };
	// MunitSuite plane_suite =            { "/planes", plane_tests, OPTIONS };
	// MunitSuite cylinder_suite =         { "/cylinders", cylinder_tests, OPTIONS };

	MunitSuite suites[] = {
		tuple_suite,
		canvas_suite,
		matrix_suite,
		matrix_transform_suite,
		ray_suite,
		sphere_suite,
		material_suite,
		world_suite,
		camera_suite,
		// light_suite,
		// shape_suite,
		// plane_suite,
		// cylinder_suite,
		NULL,
	};

	MunitSuite suite = {
		"",
		NULL,
		suites,
		1,
		MUNIT_SUITE_OPTION_NONE,
	};
	return (munit_suite_main(&suite, NULL, argc, argv));
}
