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

void	cam_init(t_param *param)
{
	param->ray.cam = vec_new(0, 0, -1);
	param->ray.ray = vec_frompoint(vec_new(0, 0, 0), param->ray.cam);
	param->ray.ray.y = 0;
	param->ray.cos_a = vec_scal(vec_new(0, 0 ,1), param->ray.ray) / vec_len(param->ray.ray);
	param->ray.ray2 = vec_frompoint(vec_new(0, 0, 0), param->ray.cam);
	param->ray.cos_b = vec_scal(param->ray.ray2, param->ray.ray) / vec_len(param->ray.ray) / vec_len(param->ray.ray2);
	param->ray.ray = vec_cross(param->ray.ray, vec_new(0, 0 , 1));
	param->ray.ray2 = vec_cross(param->ray.ray, param->ray.ray2);
}

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
	cam_init(&param);
	sdl = sdl_init(700, 200, WIDTH, HEIGHT);
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