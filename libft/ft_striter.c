/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:26:52 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/26 22:26:54 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striter(char *s, void (*f)(char *))
{
	unsigned int n;

	if (!s || !f)
		return ;
	n = 0;
	if (s && f)
	{
		while (s[n])
		{
			f(s + n);
			n++;
		}
	}
}