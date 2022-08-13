/*
Authored by paulo-santana <psergio-@student.42sp.org.br>
Copied and modified by vcwild <vcwild@gmail.com> without strict licensing permission.
*/

#include "munit/munit.h"
#include <tuple.h>
#include <canvas.h>
#include <math.h>

MunitResult canvas_test1(const MunitParameter params[], void *fixture)
{
	//test new canvas creation
	t_canvas *canvas = new_canvas(10, 20);
	munit_assert_int(canvas->width, ==, 10);
	munit_assert_int(canvas->height, ==, 20);

	return (MUNIT_OK);
}

MunitResult canvas_test2(const MunitParameter params[], void *fixture)
{
	//test every pixel in the canvas is set to black when create canvas
	t_canvas *canvas = new_canvas(10, 10);

	munit_assert_int(canvas->pixels[0][0]->r, ==, 0);
	munit_assert_int(canvas->pixels[0][0]->g, ==, 0);
	munit_assert_int(canvas->pixels[0][0]->b, ==, 0);
	free(canvas);
	return (MUNIT_OK);
}

MunitResult canvas_test3(const MunitParameter params[], void *fixture)
{
	//test write_pixel
	t_canvas *canvas = new_canvas(10, 10);

	write_pixel(canvas, 0, 0, new_color(1, 0, 0));
	munit_assert_int(canvas->pixels[0][0]->r, ==, 1);
	munit_assert_int(canvas->pixels[0][0]->g, ==, 0);
	munit_assert_int(canvas->pixels[0][0]->b, ==, 0);
	free(canvas);
	return (MUNIT_OK);
}

MunitResult canvas_test4(const MunitParameter params[], void *fixture)
{
	//test pixel_at
	t_canvas *canvas = new_canvas(10, 10);
	t_color *color = new_color(1, 0, 0);
	write_pixel(canvas, 0, 0, color);
	munit_assert_int(pixel_at(canvas, 0, 0)->r, ==, 1);
	munit_assert_int(pixel_at(canvas, 0, 0)->g, ==, 0);
	munit_assert_int(pixel_at(canvas, 0, 0)->b, ==, 0);
	free(canvas);
	return (MUNIT_OK);
}
