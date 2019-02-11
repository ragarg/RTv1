/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:33:12 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/28 06:21:13 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	unsigned char	*srcc;
	unsigned char	*dstc;
	size_t			n;

	n = -1;
	if (dst == src)
		return (NULL);
	srcc = (unsigned char *)src;
	dstc = (unsigned char *)dst;
	if (srcc < dstc)
		while ((int)(--num) >= 0)
			*(dstc + num) = *(srcc + num);
	else
		while (++n < num)
			*(dstc + n) = *(srcc + n);
	return (dst);
}
