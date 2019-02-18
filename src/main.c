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

int		main(int argc, char **argv)
{
	t_sdl		*sdl;
	SDL_Event	event;
	int			running;
	t_param		param;
	running = 1;

	if (argc != 2)
		return (0);
	param.l = NULL;
	param.sp = NULL;
	param.l_count = 0;
	param.sp_count = 0;
	read_file(&param, argv[1]);
	param.ray.cam = vec_new(0, 0, 0);
	param.ray.x = 0;
	param.ray.y = 0;
	sdl = sdl_init(700, 200, 1000, 1000);

	while (running)
	{
		render(sdl, &param);
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