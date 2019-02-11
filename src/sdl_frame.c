/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:57:39 by jcorwin           #+#    #+#             */
/*   Updated: 2019/02/06 13:55:41 by jcorwin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		*sdl_destroy(t_sdl *sdl)
{
	if (!sdl)
		return (NULL);
//	if (sdl->surf)
//		SDL_FreeSurface(sdl->surf);
	if (sdl->img.img)
		free(sdl->img.img);
	if (sdl->tex)
		SDL_DestroyTexture(sdl->tex);
	if (sdl->ren)
		SDL_DestroyRenderer(sdl->ren);
	if (sdl->win)
		SDL_DestroyWindow(sdl->win);
	free(sdl);
	SDL_Quit();
	return (NULL);
}

//sdl_image	*sdl_create_image(int w, int h)
//{
//	return (SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0));
//}

//void		sdl_destroy_image(sdl_image *surf)
//{
//	if (surf)
//		SDL_FreeSurface(surf);
//}

t_sdl		*sdl_init(int x, int y, int w, int h)
{
	t_sdl	*sdl;

	if ((sdl = (t_sdl *)malloc(sizeof(t_sdl))) == NULL)
		return (NULL);
	sdl->win = NULL;
	sdl->ren = NULL;
	sdl->tex = NULL;
	sdl->img.img = NULL;
//	sdl->surf = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		return (sdl_destroy(sdl));
	if (!(sdl->win = SDL_CreateWindow("RTv1", x, y, w, h, SDL_WINDOW_SHOWN)))
		return (sdl_destroy(sdl));
	sdl->ren = SDL_CreateRenderer(sdl->win, -1, SDL_RENDERER_ACCELERATED |
											SDL_RENDERER_PRESENTVSYNC);
	if (sdl->ren == NULL)
		return (sdl_destroy(sdl));
	sdl->tex = SDL_CreateTexture(sdl->ren, SDL_PIXELFORMAT_ARGB8888,
									SDL_TEXTUREACCESS_STATIC, w, h);
	if (sdl->tex == NULL)
		return (sdl_destroy(sdl));
	sdl->img.img = (unsigned int *)malloc(sizeof(unsigned int) * (w * h));
	if (sdl->img.img == NULL)
		return (sdl_destroy(sdl));
	sdl->img.h = h;
	sdl->img.w = w;
//	sdl->surf = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
//	if (sdl->surf == NULL)
//		return (sdl_destroy(sdl));
	return (sdl);
}

void		sdl_print(t_sdl *sdl)
{
//	if (sdl->tex)
//		SDL_DestroyTexture(sdl->tex);
//	sdl->tex = SDL_CreateTextureFromSurface(sdl->ren, sdl->surf);
//	if (!sdl->tex)
//		STOP;
	if (SDL_UpdateTexture(sdl->tex, NULL, sdl->img.img,
									sizeof(unsigned int) * sdl->img.w))
	{
		printf("olol\n");
		exit(0);
	}
	if (SDL_RenderCopy(sdl->ren, sdl->tex, NULL, NULL))
	{
		printf("lol\n");
		STOP;
	}
	SDL_RenderPresent(sdl->ren);
}
