

int	shadow(t_vec point, t_sphere *spheres, t_vec light)
{
	double t1;
	double t2;
	double discriminant;
	t_k k;
	t_vec oc;

	while(spheres)
	{
		oc = vec_sum(point, vec_mult(-1, spheres->cen));
		k.k1 = vec_scal(light, light);
		k.k2 = 2 * vec_scal(oc, light);
		k.k3 = 2 * vec_scal(oc, oc) - spheres->rad;
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

double	lighting(t_vec point, t_vec light_ray, t_sphere sphere, t_light light, t_vec ray)
{
	t_vec normal_vec;
	t_vec r;
	double n_dot_l;
	double r_dot_v;
	double light_ratio;

	normal_vec = vec_sum(point, vec_mult(-1, sphere.cen));
	normal_vec = vec_mult(1 / vec_len(normal_vec), normal_vec);
	n_dot_l = vec_scal(normal_vec, light_ray);
	light_ratio = 0;
	light_ratio = light.intens * n_dot_l / (vec_len(normal_vec) * vec_len(normal_vec));
	if (sphere.specular != -1)
	{
		r = vec_sum(vec_mult(2 , vec_mult(vec_scal(normal_vec, light_ray) , normal_vec)),  vec_mult(-1, light_ray));
		r_dot_v = vec_scal(r, vec_mult(-1, ray));
		if (r_dot_v > 0)
			light_ratio += light.intens * pow(r_dot_v/(vec_len(r)*vec_len(ray)), sphere.specular);
	}
	return (light_ratio);
}

/*t_vec rotate(t_vec ray, double x, double y)
{
	double a;

	a = ray.y * cos(x) - ray.z * sin(x);
	ray.z = ray.y * sin(x) + ray.z * cos(x);
	ray.y = a;
	a = ray.x * cos(y) + ray.z * sin(y);
	ray.z =  - ray.x * sin(y) + ray.z * cos(y);
	ray.x = a;
	return (ray);
}*/

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
