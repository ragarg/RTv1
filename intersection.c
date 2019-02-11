#include "rtv1.h"

void	intersection_with_sphere(t_sphere sphere, int *t, t_sphere *spheres, t_vec ray)
{
	double t1;
	double t2;
	double discriminant;
	t_k k;
	t_vec oc;

	*t = -1;
	while(spheres)
	{
		oc = vec_multi(-1, spheres->cen)
		k.k1 = vec_scal(ray, ray);
		k.k2 = 2 * vec_scal(oc, ray);
		k.k3 = 2 * vec_scal(oc, oc) - spheres->rad;
		discriminant = k.k2 * k.k2 - 4 * k.k1 * k.k3;
		if (discriminant > 0)
		{
			t1 = (-k.k2 + sqrt(discriminant)) / 2 * k.k1;
			t2 = (-k.k2 - sqrt(discriminant)) / 2 * k.k1;
			if (t1 < t2)
			{
				if (*t == -1 || t > t1)
				{
					*t = t1;
					sphere = *spheres;
				}
			}
			else
				if (*t == -1 || t > t2)
				{
					*t = t2;
					sphere = *spheres;
				}
		}
		spheres++;
	}
}

int	shadow(t_vec point, t_sphere *spheres, t_vec light);
{
	double t1;
	double t2;
	double discriminant;
	t_k k;
	t_vec oc;

	while(spheres)
	{
		oc = vec_sum(point, vec_multi(-1, spheres.cen));
		k.k1 = vec_scal(light, light);
		k.k2 = 2 * vec_scal(oc, light);
		k.k3 = 2 * vec_scal(oc, oc) - spheres.rad;
		discriminant = k.k2 * k.k2 - 4 * k.k1 * k.k3;
		if (discriminant > 0)
		{
			t1 = (-k.k2 + sqrt(discriminant)) / 2 * k.k1;
			t2 = (-k.k2 - sqrt(discriminant)) / 2 * k.k1;
			if ((t1 > 0 && t1 <= 1) || (t2 > 0 && t2 <= 1))
				return (1);
		}
		spheres++;
	}
	return (0);
}

double	lighting(t_vec point, t_vec light_ray, t_sphere sphere, t_light light)
{
	t_vec = normal_vec;
	double n_dot_l;

	normal_vec = vec_sum(point, vec_multi(-1, sphere.cen));
	vec_multi(1 / vec_len(normal_vec), normal_vec);
	n_dot_l = vec_scal(normal_vec, light_ray);
	return (light.intensity * n_dot_l / (vec_len(normal_vec) * vec_len(normal_vec)));
}