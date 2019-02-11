/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:22:22 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 14:28:35 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int n;

	if (!s || !f)
		return ;
	n = 0;
	if (s && f)
	{
		while (s[n])
		{
			f(n, s + n);
			n++;
		}
	}
}