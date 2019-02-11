/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_putpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:55:23 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/06 16:40:52 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		sdl_img_cpy(t_sdl *sdl, t_img *img, int x, int y)
{
	int		i;
	int		j;

	if (sdl->img.h > img->h + y && sdl->img.w > img->w + x)
	{
		i =	-1;
		while (++i < img->h)
		{
			j = -1;
			while (++j < img->w)
				sdl_putpix(sdl, x + j, y + i, *(img->img + i * img->w + j));
		}
	}
}

void		sdl_putpix(t_sdl *sdl, int x, int y, unsigned int color)
{
	if (x < sdl->img.w && y < sdl->img.h)
		*(sdl->img.img + y * sdl->img.w + x) = color;
}
