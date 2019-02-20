#include "rtv1.h"
#include <stdio.h>

void intersection_with_sphere(t_figure *sphere, double *t, t_param *param, t_vec ray, double t_min, double t_max, t_vec source)
{
	t_k k;
	double t1;
	double t2;
	double dis;
	int i;
	t_vec oc;

	i = 0;
	while(i < param->sp_count)
	{
		oc = vec_frompoint(source, (param->sp + i)->cen);
		k.k1 = vec_scal(ray, ray);
		k.k2 = 2 * vec_scal(oc, ray);
		k.k3 = vec_scal(oc, oc) - (param->sp + i)->rad * (param->sp + i)->rad;
		dis = k.k2 * k.k2 - 4 * k.k1 * k.k3;
		if (dis >= 0)
		{
			t1 = (-k.k2 + sqrt(dis)) / (2 * k.k1);
			t2 = (-k.k2 - sqrt(dis)) / (2 * k.k1);
			if (t1 > t2)
			{
				t1 = t2;
			}
			if ((*t == -1 || *t > t1) && t1 > t_min && (t_max == -1 || t1 < t_max))
			{
				*t = t1;
				sphere->p = vec_sum(source, vec_mult(*t, ray));
				sphere->norm_vec = vec_frompoint(sphere->p, (param->sp + i)->cen);
				sphere->norm_vec = vec_mult(1 / vec_len(sphere->norm_vec), sphere->norm_vec);
				sphere->color = (param->sp + i)->color;
				sphere->specular = (param->sp + i)->specular;
			}
		}
		i++;
	}
}

void intersection_with_cone(t_figure *sphere, double *t, t_param *param, t_vec ray, double t_min, double t_max, t_vec source)
{
	t_k k;
	double t1;
	double t2;
	double dis;
	double p;
	int i;
	t_vec oc;

	i = 0;
	while(i < param->con_count)
	{
		(param->con + i)->dir = vec_mult(1 / vec_len((param->con + i)->dir), (param->con + i)->dir);
		oc = vec_frompoint(source, (param->con + i)->cen);
		k.k1 = vec_scal(ray, ray) - (1 + pow(tan((param->con + i)->cos), 2)) * pow(vec_scal(ray, (param->con + i)->dir), 2);
		k.k2 = 2 * (vec_scal(ray, oc) - (1 + pow(tan((param->con + i)->cos), 2)) * vec_scal(ray, (param->con + i)->dir) * vec_scal(oc, (param->con + i)->dir));
		k.k3 = vec_scal(oc, oc) - (1 + pow(tan((param->con + i)->cos), 2)) *  pow(vec_scal(oc, (param->con + i)->dir), 2);
		dis = k.k2 * k.k2 - 4 * k.k1 * k.k3;
		if (dis >= 0)
		{
			t2 = (-k.k2 + sqrt(dis)) / (2 * k.k1);
			t1 = (-k.k2 - sqrt(dis)) / (2 * k.k1);
			if (t1 > t2)
				t1 = t2;
			if ((*t == -1 || *t > t1) && t1 > t_min && (t_max == -1 || t1 < t_max))
			{
				*t = t1;
				sphere->p = vec_sum(source, vec_mult(*t, ray));
				p = vec_len(vec_frompoint(sphere->p, (param->con + i)->cen)) / cos((param->con + i)->cos) / vec_len((param->con + i)->dir);
				if (vec_scal((param->con + i)->dir, vec_frompoint(sphere->p, (param->con + i)->cen)) / (vec_len((param->con + i)->dir) * vec_len(vec_frompoint(sphere->p, (param->con + i)->cen))) > 0)
					p *= -1;
				sphere->norm_vec = vec_sum(vec_mult(p, (param->con + i)->dir), vec_frompoint(sphere->p, (param->con + i)->cen));
				sphere->norm_vec = vec_mult(1 / vec_len(sphere->norm_vec), sphere->norm_vec);
				sphere->color = (param->con + i)->color;
				sphere->specular = (param->con + i)->specular;
			}
		}
		i++;
	}
}

void intersection_with_cylinder(t_figure *sphere, double *t, t_param *param, t_vec ray, double t_min, double t_max, t_vec source)
{
	t_k k;
	double t1;
	double t2;
	double dis;
	double p;
	int i;
	t_vec oc;

	i = 0;
	while(i < param->cyl_count)
	{
		(param->cyl + i)->dir = vec_mult(1 / vec_len((param->cyl + i)->dir), (param->cyl + i)->dir);
		oc = vec_frompoint(source, (param->cyl + i)->cen);
		k.k1 = vec_scal(ray, ray) - pow(vec_scal(ray, (param->cyl + i)->dir), 2);
		k.k2 = 2 * (vec_scal(ray, oc) - vec_scal(ray, (param->cyl + i)->dir) * vec_scal(oc, (param->cyl + i)->dir));
		k.k3 = vec_scal(oc, oc) - pow(vec_scal(oc, (param->cyl + i)->dir), 2) - pow((param->cyl + i)->rad, 2);
		dis = k.k2 * k.k2 - 4 * k.k1 * k.k3;
		if (dis >= 0)
		{
			t2 = (-k.k2 + sqrt(dis)) / (2 * k.k1);
			t1 = (-k.k2 - sqrt(dis)) / (2 * k.k1);
			if (t1 > t2)
				t1 = t2;
			if ((*t == -1 || *t > t1) && t1 > t_min && (t_max == -1 || t1 < t_max))
			{
				*t = t1;
				sphere->p = vec_sum(source, vec_mult(*t, ray));
				p = sqrt((pow(vec_len(vec_frompoint(sphere->p, (param->cyl + i)->cen)), 2) - pow((param->cyl + i)->rad, 2))) / vec_scal((param->cyl + i)->dir, (param->cyl + i)->dir);
				if(vec_scal((param->cyl + i)->dir, vec_frompoint(sphere->p, (param->cyl + i)->cen)) / vec_len(vec_frompoint(sphere->p, (param->cyl + i)->cen)) < 0)
					p *= -1;
				sphere->norm_vec = vec_sum(vec_mult(p, (param->cyl + i)->dir), vec_frompoint((param->cyl + i)->cen, sphere->p));
				sphere->norm_vec = vec_mult(-1 / vec_len(sphere->norm_vec), sphere->norm_vec);
				sphere->color = (param->cyl + i)->color;
				sphere->specular = (param->cyl + i)->specular;
			}
		}
		i++;
	}
}

void intersection_with_plane(t_figure *sphere, double *t, t_param *param, t_vec ray, double t_min, double t_max, t_vec source)
{
	double t1;
	int i;

	i = 0;
	while(i < param->plane_count)
	{
		if (1)
		{
			t1 = vec_scal(source, (param->plane + i)->norm);
			t1 += -vec_scal((param->plane + i)->point, (param->plane + i)->norm);
			t1 /= -vec_scal(ray, (param->plane + i)->norm);
			if ((*t == -1 || *t > t1) && t1 > t_min && (t_max == -1 || t1 < t_max)) {
				//ft_putnbr(i);
				*t = t1;
				sphere->p = vec_sum(source, vec_mult(*t, ray));
				sphere->norm_vec = (param->plane + i)->norm;
				sphere->norm_vec = vec_mult(1 / vec_len(sphere->norm_vec), sphere->norm_vec);
				sphere->color = (param->plane + i)->color;
				sphere->specular = (param->plane + i)->specular;
			}
		}
		i++;
	}
}

void intersection(t_figure *sphere, double *t, t_param *param, t_vec ray, double t_min, double t_max)
{
	*t = -1;
	t_max = -1;
	t_min = 1;
	intersection_with_sphere(sphere, t, param, ray, t_min, t_max, param->ray.cam);
	intersection_with_cone(sphere, t, param, ray, t_min, t_max, param->ray.cam);
	intersection_with_cylinder(sphere, t, param, ray, t_min, t_max, param->ray.cam);
	intersection_with_plane(sphere, t, param, ray, t_min, t_max, param->ray.cam);
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
	t_figure sphere;
	double t = -1;
	intersection_with_sphere(&sphere, &t, param, light_ray, 0.0001, 1, p);
	if (t != -1)
		return 0;
	intersection_with_cone(&sphere, &t, param, light_ray, 0.00001, -1, p);
	if (t != -1)
		return 0;
	//intersection_with_cylinder(&sphere, &t, param, light_ray, 0.0001, 1, p);
	if (t != -1)
		return 0;
	intersection_with_plane(&sphere, &t, param, light_ray, 0.0001, 1, p);
	if (t == -1)
		return 1;
	return 0;
}

unsigned int color_with_light(t_param *param, t_vec ray, t_figure sphere)
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
	p = sphere.p;
	normal_vec = sphere.norm_vec;
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

t_vec	rot(t_vec ray, double cos_a, double cos_b)
{
	t_vec vec_1;
	t_vec vec_2;


	vec_1 = vec_new(ray.x, ray.y * cos_a - ray.z * sqrt(1 - cos_a * cos_a), ray.z * cos_a + ray.y * sqrt(1 - cos_a * cos_a));
	cos_a = cos_b;
	vec_2 = vec_new(ray.x * cos_a - ray.z * sqrt(1 - cos_a * cos_a), ray.y, ray.z * cos_a + ray.x * sqrt(1 - cos_a * cos_a));
	return(vec_sum(vec_1, vec_2));
}

int	render(t_sdl *sdl, t_param *param) {
	int x;
	int y;
	t_vec ray;

	t_figure sphere;
	double t;

	unsigned int color = 0;
	x = -(WIDTH / 2);
	while (x < WIDTH / 2)
	{
		y = -HEIGHT / 2;
		while (y < HEIGHT / 2)
		{
			color = 0;
			ray = vec_new(x, y, 1000);
			//ray = rot(ray, param->ray.cos_a, param->ray.cos_b);
			intersection(&sphere, &t, param, ray, 1, 1);
			if (t != -1)
				color = color_with_light(param, ray, sphere);
			sdl_putpix(sdl, x + WIDTH / 2, y + HEIGHT / 2, color);
			y++;
		}
		x++;
	}
	return (0);
}