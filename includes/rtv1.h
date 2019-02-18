/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:25:54 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/13 14:10:50 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <SDL.h>
# include <math.h>
# include "get_next_line.h"
# include "libft.h"
# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# define WIDTH 1000
# define HEIGHT 1000
# define STOP {printf("Error\n"); exit(0);}
# define sdl_image SDL_Surface
# define MAX_SOURCE_SIZE (0x100000)

typedef struct s_k
{
	double k1;
	double k2;
	double k3;
}				t_k;

typedef enum	e_light_type
{
	ambient = 0,
	point,
	direct
}				t_light_type;

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_light
{
	t_light_type	type;
	double			intens;
	t_vec			pos;
	t_vec			dir;
}				t_light;

typedef struct	s_img
{
	int				w;
	int				h;
	unsigned int	*img;
}				t_img;

typedef struct	s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
	t_img			img;
}				t_sdl;

typedef struct	s_ray
{
	t_vec	cam;
	double	x;
	double	y;
}				t_ray;

typedef struct	s_screen
{
	t_vec		cor;
	t_vec		hor;
	t_vec		ver;
}				t_screen;

typedef struct	s_sphere
{
	t_vec			cen;
	double			rad;
	unsigned int	color;
	double			specular;
}				t_sphere;

typedef struct	s_param
{
	t_ray		ray;
	t_screen	scr;
	t_vec		cam;
	int			sp_count;
	int			l_count;
	t_sphere	*sp;
	t_light		*l;
}				t_param;

typedef struct	s_cl
{
	cl_platform_id platform_id;
	cl_device_id device_id;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;
	cl_int ret;
	cl_context context;
	cl_command_queue command_queue;
	cl_mem mem_sph;
	cl_mem mem_img;
	cl_mem mem_light;
	cl_mem mem_cam;
	cl_mem mem_num;
	cl_program program;
	cl_kernel kernel;
	size_t global_item_size;
}				t_cl;

t_vec			vec_new(double x, double y, double z);
t_vec			vec_frompoint(t_vec p1, t_vec p2);
t_vec 			vec_sum(t_vec v1, t_vec v2);
t_vec			vec_mult(double a, t_vec);
double			vec_scal(t_vec v1, t_vec v2);
double			vec_len(t_vec v);
t_vec			ray_par(t_ray r, double t);
t_vec			vec_plus(double a, t_vec res);
t_vec			vec_unit(t_vec v);

void			trace_sphere(t_sdl *sdl, t_param *p);

void			sdl_img_init(t_img *img, int w, int h);
void			sdl_img_destroy(t_img *img);
t_sdl			*sdl_init(int x, int y, int w, int h);
void			*sdl_destroy(t_sdl *sdl);
void			sdl_print(t_sdl *sdl);

void			sdl_img_cpy(t_sdl *sdl, t_img *img, int x, int y);
void			sdl_putpix(t_sdl *sdl, int x, int y, unsigned int color);

double			get_double(char *line);
t_vec			get_vec(char *line);
void			l_real(t_param *p);
void			sp_real(t_param *p);
char			*get_word(char *line);
void			read_file(t_param *p, char *filename);
int				render(t_sdl *sdl, t_param *param);

#endif
