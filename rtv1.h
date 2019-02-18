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

# define WIDTH 1000
# define HEIGHT 1000

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


