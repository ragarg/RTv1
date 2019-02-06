/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:41:55 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/06 15:24:14 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

void	test_grad(t_sdl *sdl)
{
	int				x;
	int				y;
	unsigned int	color;

	y = -1;
	while (++y < sdl->img.h)
	{
		x = -1;
		while (++x < sdl->img.w)
		{
			color = 0;
			color |= (int)(255 * (float)x / sdl->img.w) << 16;
			color |= (int)(255 * (float)y / sdl->img.h) << 8;
			color |= 55;
			sdl_putpix(sdl, x, y, color);
		}
	}
}

int		main(int argc, char **argv)
{
	t_sdl		*sdl;
	SDL_Event	event;
	int			running;

	running = 1;
	sdl = sdl_init(700, 200, 1000, 1000);
	test_grad(sdl);
	while (running)
	{
		sdl_print(sdl);
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;
		}
	}
	sdl = sdl_destroy(sdl);
	return (0);
}
