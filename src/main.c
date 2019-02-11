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

t_param init_cam();

int		main()
{
	t_sdl		*sdl;
	SDL_Event	event;
	int			running;
	int x=0;
	running = 1;
	int y  = 10;

	sdl = sdl_init(700, 200, 1000, 1000);
	while (running)
	{
		if (x == 500)
			y = -10;
		if (x == -400)
			y = 10;
		x = (x + y);
		render(sdl, &x);
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
