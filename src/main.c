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

void	param_init(t_param *param)
{
	param->plane = NULL;
	param->l = NULL;
	param->sp = NULL;
	param->con = NULL;
	param->cyl = NULL;
	param->l_count = 0;
	param->sp_count = 0;
	param->plane_count = 0;
	param->con_count = 0;
	param->cyl_count = 0;
}

int		main(int argc, char **argv)
{
	t_sdl		*sdl;
	SDL_Event	event;
	int			running;
	t_param		param;
	running = 1;

	if (argc != 2)
		return (0);
	param_init(&param);
	read_file(&param, argv[1]);
	param.ray.cam = vec_new(0, 0, 0);
	param.ray.cos_b = 1;
	param.ray.cos_a = vec_scal(vec_mult(-1, param.ray.cam), vec_new(-param.ray.cam.x, 0, -param.ray.cam.z)) / vec_len(param.ray.cam) / vec_len(vec_new(-param.ray.cam.x, 0, -param.ray.cam.z));
	sdl = sdl_init(700, 200, WIDTH, HEIGHT);
	printf("%f ", param.ray.cos_b);
	printf("%f", param.ray.cos_a);
	render(sdl, &param);
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