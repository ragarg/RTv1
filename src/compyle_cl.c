#include "rtv1.h"
#include <stdio.h>

t_vec			rot(t_vec ray, double cos_a, double cos_b)
{
	t_vec vec_1;
	t_vec vec_2;

	vec_1 = vec_new(ray.x, ray.y * cos_a - ray.z * sqrt(1 - cos_a\
	* cos_a), ray.z * cos_a + ray.y * sqrt(1 - cos_a * cos_a));
	cos_a = cos_b;
	vec_2 = vec_new(ray.x * cos_a - ray.z * sqrt(1 - cos_a * cos_a),\
	ray.y, ray.z * cos_a + ray.x * sqrt(1 - cos_a * cos_a));
	return (vec_sum(vec_1, vec_2));
}

void		intersection_with_plane(t_figure *sphere,\
double *t, t_intersection2 j)
{
	double	t1;
	int		i;

	i = 0;
	while (i < j.param->plane_count)
	{
		t1 = vec_scal(j.source, (j.param->plane + i)->norm);
		t1 += -vec_scal((j.param->plane + i)->point,\
		(j.param->plane + i)->norm);
		t1 /= -vec_scal(j.ray, (j.param->plane + i)->norm);
		if ((*t == -1 || *t > t1) && t1 > j.t_min &&\
		(j.t_max == -1 || t1 < j.t_max))
		{
			*t = t1;
			sphere->p = vec_sum(j.source, vec_mult(*t, j.ray));
			sphere->norm_vec = (j.param->plane + i)->norm;
			sphere->norm_vec = vec_mult(1 /\
			vec_len(sphere->norm_vec), sphere->norm_vec);
			sphere->color = (j.param->plane + i)->color;
			sphere->specular = (j.param->plane + i)->specular;
		}
		i++;
	}
}

void			intersection(t_figure *sphere, double *t,\
t_param *param, t_vec ray)
{
	t_intersection2 j;

	*t = -1;
	j.t_max = -1;
	j.t_min = 1;
	j.source = param->ray.cam;
	j.param = param;
	j.ray = ray;
	intersection_with_sphere(sphere, t, j);
	intersection_with_cone(sphere, t, j);
	intersection_with_cylinder(sphere, t, j);
	intersection_with_plane(sphere, t, j);
}

int				render(t_sdl *sdl, t_param *param)
{
	int			x;
	int			y;
	t_vec		ray;
	t_figure	sphere;
	double		t;

	x = -(WIDTH / 2);
	while (x < WIDTH / 2)
	{
		y = -HEIGHT / 2;
		while (y < HEIGHT / 2)
		{
			ray = vec_new(x, y, 1000);
			intersection(&sphere, &t, param, ray);
			if (t != -1)
				sdl_putpix(sdl, x + WIDTH / 2, y + HEIGHT / 2, \
				color_with_light(param, ray, sphere));
			else
				sdl_putpix(sdl, x + WIDTH / 2, y + HEIGHT / 2, 0);
			y++;
		}
		x++;
	}
	return (0);
}
