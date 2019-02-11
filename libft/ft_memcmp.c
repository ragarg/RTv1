/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeera-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:42:31 by kmeera-r          #+#    #+#             */
/*   Updated: 2018/11/21 11:45:32 by kmeera-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *memptr1, const void *memptr2, size_t num)
{
	unsigned char	*memptr1_c;
	unsigned char	*memptr2_c;
	size_t			n;

	n = 0;
	memptr1_c = (unsigned char*)memptr1;
	memptr2_c = (unsigned char*)memptr2;
	while (num > n && memptr1_c[n] == memptr2_c[n])
		n++;
	if (num == n)
		return (0);
	return (memptr1_c[n] - memptr2_c[n]);
}
