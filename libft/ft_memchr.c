/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:36:56 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 11:41:52 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*ptr_c;
	size_t			n;

	n = 0;
	ptr_c = (unsigned char*)ptr;
	while (num > n)
	{
		if (ptr_c[n] == (unsigned char)value)
			return ((void*)(ptr + n));
		n++;
	}
	return (NULL);
}
