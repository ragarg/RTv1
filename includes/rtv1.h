/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:25:54 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/06 14:28:51 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <SDL.h>
# include <math.h>
# include "libft.h"

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# define WIDTH 1000
# define HEIGHT 1000
# define STOP exit(0);
# define sdl_image SDL_Surface
# define MAX_SOURCE_SIZE (0x100000)


typedef struct	s_img
{
	int				w;
	int				h;
	unsigned int	*img;
}				t_img;

typedef struct	s_im
{
	int	*img;
}				t_im;

typedef struct	s_cl
{
	cl_platform_id platform_id;
	cl_device_id device_id;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;
	cl_int ret;
	cl_context context;
	cl_command_queue command_queue;
	cl_mem b_mem_obj;
	cl_mem a_mem_obj;
	cl_program program;
	cl_kernel kernel;
	size_t global_item_size;
}				t_cl;

typedef struct	s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
	t_img			img;
}				t_sdl;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
}				t_point;

typedef struct	s_vec
{
	double		i;
	double		j;
	double		k;
}				t_vec;

typedef struct	s_sphere
{
	t_point			cen;
	int				rad;
	unsigned int	color;
}				t_sphere;

typedef struct	s_ray
{
	t_point			*start;
	t_vec			*direction;
}				t_ray;

typedef struct	s_cam
{
	t_point		*position;
}				t_cam;

typedef struct	s_param
{
	t_point		cam;
	int			cx;
	int			cy;
	int			cz;
	int			wx;
	int			wy;
	int			wz;
}				t_param;

t_vec			vec_frompoint(t_point p1, t_point p2);
t_vec 			vec_sum(t_vec v1, t_vec v2);
t_vec			vec_multi(int a, t_vec);
double			vec_scal(t_vec v1, t_vec v2);
double			vec_len(t_vec v);

int				trace_sphere(t_sphere s, t_point cam, t_point p);

void			sdl_img_init(t_img *img, int w, int h);
void			sdl_img_destroy(t_img *img);
t_sdl			*sdl_init(int x, int y, int w, int h);
void			*sdl_destroy(t_sdl *sdl);
void			sdl_print(t_sdl *sdl);
void			read_cl(char **source_str, size_t *source_size);
void			free_cl(t_cl **cl_ptrs);
void			cl_init(t_cl *cl_ptrs, int *x, char *source_str, size_t source_size, t_sdl *sdl);

void			sdl_img_cpy(t_sdl *sdl, t_img *img, int x, int y);
void			sdl_putpix(t_sdl *sdl, int x, int y, unsigned int color);
int				render(t_sdl *sdl, int *x);

#endif
