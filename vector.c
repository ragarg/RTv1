#include "rtv1.h"

t_vec		vec_frompoint(t_vec p1, t_vec p2)
{
	t_vec	res;

	res.x = p2.x - p1.x;
	res.y = p2.y - p1.y;
	res.z = p2.z - p1.z;
	return (res);
}
t_vec		vec_new(double x, double y, double z)
{
	t_vec new_vec;

	new_vec.x = x;
	new_vec.y = y;
	new_vec.z = z;
	return (new_vec);
}

t_vec		vec_sum(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vec		vec_mult(double a, t_vec res)
{
	res.x *= a;
	res.y *= a;
	res.z *= a;
	return (res);
}

double			vec_scal(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double			vec_len(t_vec v)
{
	return ((int)sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

