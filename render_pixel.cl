#include "vector.c"
#include "intersection.c"

__kernel void	render_pixel(__global unsigned int *color, __global t_sphere *spheres, __global t_light *lights, __global t_ray *cam, __global int *number)
{
    int i = get_global_id(0);
    t_vec ray;
    t_vec cen;
    t_vec cen_cam = cam->cam;
    t_vec light_ray;
    t_vec light_pos;
    t_vec obj_point;
    double t;
    t_sphere sphere;
    double light_ratio;
    unsigned int color_point;
    t_vec normal_vec;
    t_vec r;
    double n_dot_l;
    double r_dot_v;
    double intens;
    color_point = 0;
    ray.x = (i % WIDTH) - 500;
    ray.y = (i / HEIGHT) - 500;
    ray.z = 1000;
    double t1;
    double t2;
    double discriminant;
    t_k k;
    t_vec oc;
    int j;
    j = 0;
    int num = number[0];
    t = -1;
    while(j != number[0])
    {
        cen = spheres->cen;
    	oc = vec_frompoint(cen_cam, cen);
    	k.k1 = vec_scal(ray, ray);
    	k.k2 = 2 * vec_scal(oc, ray);
    	k.k3 = vec_scal(oc, oc) - spheres->rad * spheres->rad;
    	discriminant = k.k2 * k.k2 - 4 * k.k1 * k.k3;
    	if (discriminant > 0)
    	{
    		t1 = (-k.k2 + sqrt(discriminant)) / 2 * k.k1;
    		t2 = (-k.k2 - sqrt(discriminant)) / 2 * k.k1;
    		if (t1 < t2)
    		{
    			if (t == -1 || t < t1) {
    				t = t1;
    				sphere = *spheres;
    				color_point = sphere.color;
    			}
    		}
    		if (t1 > t2)
    		{
    		    if (t == -1 || t < t2) {
    			    t = t2;
    			    sphere = *spheres;
    			    color_point = sphere.color;
    			}
    		}
    	}
    	spheres++;
    	j++;
    }
    light_ratio = 0;
    j = 0;
    obj_point = vec_mult(t, ray);
    while(j != number[1])
    {
        if (lights->type == ambient)
            light_ratio += lights->intens;
        else
            oc = vec_frompoint(cen_cam, cen);
        lights++;
        j++;
    }
    color[i] = color_point;
}


