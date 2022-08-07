/*
Authored by paulo-santana <psergio-@student.42sp.org.br>
Copied and modified by vcwild <vcwild@gmail.com> without strict licensing permission.
*/

#ifndef TEST_UTILS_H
# define TEST_UTILS_H

#include "../includes/structures.h"

int world_equals(t_world *w1, t_world *w2);
int sphere_equals(t_sphere *s1, t_sphere *s2);
int material_equals(t_material *m1, t_material *m2);
int light_equals(t_point_light *l1, t_point_light *l2);
int color_equals(t_color *c1, t_color *c2);

#endif
