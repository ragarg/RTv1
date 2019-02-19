#include "rtv1.h"
#include <stdio.h>


void intersection_with_sphere(t_sphere *sphere, double *t, t_param *param, t_vec ray)
{
	t_k k;
	double t1;
	double t2;
	double dis;
	int i;
	t_vec oc;

	i = 0;
	*t = -1;
	while(i < param->sp_count)
	{
		oc = vec_frompoint(param->ray.cam, (param->sp + i)->cen);
		k.k1 = vec_scal(ray, ray);
		k.k2 = 2 * vec_scal(oc, ray);
		k.k3 = vec_scal(oc, oc) - (param->sp + i)->rad * (param->sp + i)->rad;
		dis = k.k2 * k.k2 - 4 * k.k1 * k.k3;
		if (dis >= 0)
		{
			t1 = (-k.k2 + sqrt(dis)) / (2 * k.k1);
			t2 = (-k.k2 - sqrt(dis)) / (2 * k.k1);
			if (t1 < t2)
			{
				if ((*t == -1 || *t > t1) && t1 > 1)
				{
					*t = t1;
					*sphere = *(param->sp + i);
				}
			}
			else
			if ((*t == -1 || *t > t2) && t2 > 1)
			{
				*t = t2;
				*sphere = *(param->sp + i);
			}
		}
		i++;
	}
}

unsigned int new_color(unsigned int color, double light_ratio)
{
	int x;
	int y;
	int z;

	x = color / 256 / 256;
	y = (color / 256) % 256;
	z = color % 256;
	x *= light_ratio;
	y *= light_ratio;
	z *= light_ratio;
	if (x > 255)
		x = 255;
	if (y > 255)
		y = 255;
	if (z > 255)
		z = 255;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (z < 0)
		z = 0;
	return (x * 256 * 256 + y * 256 + z);
}

int is_shadow(t_param *param, t_vec p, t_vec light_ray)
{
	t_k k;
	double dis;
	double t1;
	double t2;
	int i;
	t_vec oc;

	i = 0;

	while(i < param->sp_count)
	{
		oc = vec_frompoint(p, (param->sp + i)->cen);
		k.k1 = vec_scal(light_ray, light_ray);
		k.k2 = 2 * vec_scal(oc, light_ray);
		k.k3 = vec_scal(oc, oc) - (param->sp + i)->rad * (param->sp + i)->rad;
		dis = k.k2 * k.k2 - 4 * k.k1 * k.k3;
		if (dis >= 0)
		{
			t1 = (-k.k2 + sqrt(dis)) / (2 * k.k1);
			t2 = (-k.k2 - sqrt(dis)) / (2 * k.k1);
			if(t2 > 0.0001 && t2 < 1)
				return 0;
			if(t1 > 0.0001 && t1 < 1)
				return 0;
		}
		i++;
	}
	return 1;
}

unsigned int color_with_light(t_param *param, double t, t_vec ray, t_sphere sphere)
{
	double intensity;
	int i;
	t_vec light_ray;
	t_vec normal_vec;
	t_vec r;
	t_vec p;
	double n_dot_l;
	double r_dot_v;

	i = 0;
	intensity = 0;
	p = vec_sum(param->ray.cam, vec_mult(t, ray));
	normal_vec = vec_frompoint(p, sphere.cen);
	normal_vec = vec_mult(1/ vec_len(normal_vec), normal_vec);
	while (i < param->l_count)
	{
		if ((param->l + i)->type == ambient)
			intensity += (param->l + i)->intens;

		else
		{
			if ((param->l + i)->type == direct)
				light_ray = (param->l + i)->dir;
			if ((param->l + i)->type == point)
				light_ray = vec_frompoint((param->l + i)->pos, p);
			if (is_shadow(param, p, light_ray))
			{
				n_dot_l = vec_scal(normal_vec, light_ray);
				if (n_dot_l > 0)
					intensity += (param->l + i)->intens * n_dot_l / (vec_len(normal_vec) * vec_len(light_ray));
				if (sphere.specular != -1)
				{
					r = vec_frompoint(vec_mult(2 * n_dot_l, normal_vec), light_ray);
					r_dot_v = vec_scal(r, vec_mult(-1, ray));
					if (r_dot_v > 0)
						intensity += (param->l + i)->intens *
									 pow(r_dot_v / (vec_len(r) * vec_len(vec_mult(-1, ray))), sphere.specular);
				}
			}
		}
		i++;
	}
	return (new_color(sphere.color, intensity));
}

int	render(t_sdl *sdl, t_param *param) {
	int x;
	int y;
	t_vec ray;

	t_sphere sphere;
	double t;

	unsigned int color = 0;

	x = -(WIDTH / 2);
	while (x < WIDTH / 2)
	{
		y = -(HEIGHT / 2);
		while (y < HEIGHT /2)
		{
			color = 0;
			ray = vec_new(x, y, 1000);
			intersection_with_sphere(&sphere, &t, param, ray);

			if (t != -1)
				color = color_with_light(param, t, ray, sphere);
			sdl->img.img[(x +  WIDTH / 2) + (y +  HEIGHT / 2) * HEIGHT] = color;
			y++;
		}
		x++;
	}
	return (0);
}