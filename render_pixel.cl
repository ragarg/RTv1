#include "vector.c"
#include "interection.c"

__kernel void	render_pixel(__global unsigned int *color, __global t_sphere *spheres, __global t_light *lights)
{
    int i = get_global_id(0);
    t_vec ray;
    t_vec light_ray;
    t_vec point;
    int t;
    t_sphere sphere;
    double light_ratio;

    ray.x = WIDTH / 2 + i % WIDTH;
    ray.y = HEIGHT / 2 + i % HEIGHT;
    ray.z = 1000;
    sphere = intersection_with_sphere(sphere, t, spheres, ray);
    while(lights)
    {
        point = vec_multi(t, ray);
        light_ray = vec_sum(point, vec_multi(-1, light));
        if (!shadow(point, spheres, light_ray))
        {
            light_ratio += lighting(point, light_ray, sphere, *lights);
        }
        lights++;
    }
    color[i] = new_color(color[i], light_ratio);
}


