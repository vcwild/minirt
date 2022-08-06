#include "munit/munit.h"
#include "../sources/structures.h"
#include "../sources/minirt.h"
#include "ray/ray.h"
#include "tuple/tuple.h"
#include "lights/lights.h"
#include <math.h>

// a point light has a position and intensity
//

MunitResult light_test1(const MunitParameter params[], void *fixture)
{
	t_color *intensity = new_color(1, 1, 1);
	t_tuple *pos = new_point(0, 0, 0);

	t_point_light *light = new_point_light(pos, intensity);
	munit_assert_ptr_equal(light->position, pos);
	munit_assert_ptr_equal(light->intensity, intensity);

	destroy_point_light(light);
	return (MUNIT_OK);
}
