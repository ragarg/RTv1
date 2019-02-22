#include "rtv1.h"
#include <stdio.h>

t_vec			rot(double angle, t_vec u, t_vec v)
{

	t_quat quat;
	t_quat t;

	quat = create_quat(u, angle);
	t = quat_mul_vector(quat, v);
	t = quat_mul_quat(t, quat_invert(quat));
	return(vec_new(t.x, t.y, t.z));
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
	double		angle_1;
	double		angle_2;

	angle_1 = acos(param->ray.cos_a);
	angle_2 = acos(param->ray.cos_b);
	printf("%f", angle_2);
	x = -(WIDTH / 2);
	while (x < WIDTH / 2)
	{
		y = -HEIGHT / 2;
		while (y < HEIGHT / 2)
		{
			ray = vec_new(x, y, 1000);
			if (angle_1 != 0)
				ray = rot(-angle_1, param->ray.ray, ray);
			if (angle_2 != 0)
				ray = rot(angle_2, param->ray.ray2, ray);
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
