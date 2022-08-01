#ifndef TUPLE_H
# define TUPLE_H
# define EPSILON 0.0000001

#include <stdlib.h>
#include <math.h>

typedef struct s_tuple {
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

t_tuple	*new_tuple(double x, double y, double z, double w);
t_tuple	*new_point(double x, double y, double z);
t_tuple	*new_vector(double x, double y, double z);

int		is_point(t_tuple *t);
int		is_vector(t_tuple *t);
int		is_tuple(t_tuple *t);
int		dequals(double a, double b);
int		tuple_equals(t_tuple *a, t_tuple *b);

t_tuple	*add_tuples(t_tuple *a, t_tuple *b);
t_tuple	*subtract_tuples(t_tuple *a, t_tuple *b);
t_tuple	*negate_tuple(t_tuple *a);
t_tuple	*multiply_scalar(t_tuple *t, double v);
t_tuple	*divide_scalar(t_tuple *t, double v);

double	dot(t_tuple *a, t_tuple *b);
double	magnitude(t_tuple *a);
t_tuple	*normalize(t_tuple *a);
t_tuple	*cross(t_tuple *a, t_tuple *b);
t_tuple	*reflect(t_tuple *v, t_tuple *n);

#endif
