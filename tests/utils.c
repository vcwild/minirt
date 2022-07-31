#include "../src/structures.h"
#include "matrix/matrix.h"
#include "tuple/tuple.h"
#include "../src/utils/utils.h"
#include "debug.h"
#include <stdio.h>

void print_world(t_world *world)
{
	int i;
	printf("world:\n");

	i = 0;
	while (i < world->objects.sphere_count)
	{
		printf("  sphere %d\n", i);
		printf("    position: ");
		print_tuple(world->objects.spheres->content);
		i++;
	}
}

int color_equals(t_color *c1, t_color *c2)
{
	if (c1 == NULL || c2 == NULL)
		if (c1 != c2)
			return (0);
	return (dequals(c1->red, c2->red)
			&& dequals(c1->green, c2->green)
			&& dequals(c1->blue, c2->blue));
}

int light_equals(t_point_light *l1, t_point_light *l2)
{
	if (l1 == NULL || l2 == NULL)
		if (l1 != l2)
			return (0);
	return (tuple_equals(l1->position, l2->position)
			&& color_equals(l1->intensity, l2->intensity));
}

int material_equals(t_material *m1, t_material *m2)
{
	if (m1 == NULL || m2 == NULL)
		if (m1 != m2)
			return (0);
	return (color_equals(m1->ambient, m2->ambient)
		&& dequals(m1->diffuse, m2->diffuse)
		&& dequals(m1->shininess, m2->shininess)
		&& dequals(m1->specular, m2->specular)
		&& color_equals(m1->color, m2->color)
		);
}

int sphere_equals(t_shape *s1, t_shape *s2)
{
	if (s1 == NULL || s2 == NULL)
		if (s1 != s2)
			return (0);
	return (dequals(s1->sphere_props.radius, s2->sphere_props.radius)
		&& matrix_equals(s1->transform, s2->transform)
		&& matrix_equals(s1->inverse_transform, s2->inverse_transform)
		&& tuple_equals(&s1->sphere_props.position, &s2->sphere_props.position)
		&& material_equals(s1->material, s2->material)
   );
}

int world_equals(t_world *w1, t_world *w2)
{
	int		i;
	t_list *list;
	t_list *list2;

	i = 0;
	list = w1->objects.spheres;
	list2 = w2->objects.spheres;
	while (list->next)
	{
		if (list->content)
		{
			if (list2 == NULL)
				return (0);
			if (!sphere_equals(list->content, list2->content))
				return (0);
			list = list->next;
			list2 = list2->next;
		}
	}

	list = w1->lights;
	list2 = w2->lights;
	while (list->next)
	{
		if (list->content)
		{
			if (list2 == NULL)
				return (0);
			if (!light_equals(list->content, list2->content))
				return (0);
			list = list->next;
			list2 = list2->next;
		}
	}
	return ( w1->objects.total == w2->objects.total
			&& w1->objects.sphere_count == w2->objects.sphere_count
		);
}
