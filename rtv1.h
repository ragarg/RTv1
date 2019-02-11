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
	t_point			start;
	t_vec			direction;
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


