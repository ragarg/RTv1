/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:30:43 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/23 12:50:21 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t num)
{
	unsigned char	*dest_c;
	unsigned char	*src_c;
	size_t			n;

	n = 0;
	dest_c = (unsigned char*)dest;
	src_c = (unsigned char*)src;
	while (num > n)
	{
		dest_c[n] = src_c[n];
		if (src_c[n] == (unsigned char)c)
			return (dest + n + 1);
		n++;
	}
	return (NULL);
}
