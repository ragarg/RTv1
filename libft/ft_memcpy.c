/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:20:25 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 11:29:44 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t num)
{
	char	*dest_c;
	char	*src_c;
	size_t	n;

	n = 0;
	dest_c = (char*)dest;
	src_c = (char*)src;
	while (num > n)
	{
		dest_c[n] = src_c[n];
		n++;
	}
	return (dest);
}
